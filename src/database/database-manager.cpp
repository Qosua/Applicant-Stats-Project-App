#include "database-manager.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

#include "../app-utils/app-paths-manager.h"

DataBaseManager& DataBaseManager::instance() {
    static DataBaseManager inst;
    return inst;
}

bool DataBaseManager::init() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(AppPathsManager::appDbPath);

    if (!m_db.open()) {
	qCritical() << "SQL ERROR"  << "Database error";
	return false;
    }

    QSqlQuery("PRAGMA foreign_keys = ON;", m_db);
    return createDatabase();
}

QSqlDatabase& DataBaseManager::db() { return m_db; }

QList<QVariantList> DataBaseManager::getEntryCommisionsList() const {

    if (!m_db.isOpen())
	qCritical() << "SQL ERROR"  << "DatabaseManager could not open connection to database";

    QSqlQuery query(m_db);
    const QString strQuery = R"(SELECT uni_name, year, is_bachelor FROM entry_commisions;)";

    if (!query.exec(strQuery)) {
	qCritical() << "SQL ERROR"  << query.lastError().text();
	return {};
    }

    QList<QVariantList> list;
    while (query.next()) {
	list << QVariantList{query.value("uni_name").toString(),
	                     query.value("is_bachelor").toBool(), query.value("year").toInt()};
    }

    return list;
}

int DataBaseManager::getEntryCommissionsIndexForTable(const QString& tableName) const {

    if (!m_db.isOpen()) {
	qCritical() << "SQL ERROR"  << "DatabaseManager could not open connection to database";
	return -1;
    }

    QSqlQuery query(m_db);
    if (!query.prepare(
            R"(SELECT entry_commision_id FROM current_table_presets WHERE tableName = :tName)")) {
	qCritical() << "SQL ERROR"  << query.lastError().text();
	return -1;
    }
    query.bindValue(":tName", tableName);

    if (!query.exec()) {
	qCritical() << "SQL ERROR"  << query.lastError().text();
	return -1;
    }

    if (query.next())
	return query.value(0).toInt();

    return -1;
}

bool DataBaseManager::isTableExist(const QString& tableName) const {

    QSqlQuery query(m_db);
    query.prepare(
        R"(SELECT EXISTS(SELECT 1 FROM current_table_presets WHERE tableName = :tableName);)");
    query.bindValue(":tableName", tableName);

    if (!query.exec()) {
	qCritical() << "SQL ERROR"  << query.lastError().text();
	return false;
    }

    if (query.next() and query.value(0).toInt() == 1)
	return true;

    return false;
}
QList<QString> DataBaseManager::getEntryCommisionColumnsNamesListFromDb(const QString& name,
                                                                        bool isBachelor,
                                                                        int year) const {

    QSqlQuery query(m_db);
    query.prepare(R"(
        select unique_code, score, achivments_score, subject_one, subject_two, subject_three, priority_number, consent, competition_group, phone_number, email, FIO, BVI, faculty_name, isAttended
        from columns_mapping
        where entry_commision_id = (select id
        from entry_commisions
        where uni_name = :name and
              is_bachelor = :isBachelor and
              year = :year
            );
    )");
    query.bindValue(":name", name);
    query.bindValue(":isBachelor", isBachelor);
    query.bindValue(":year", year);

    if (!query.exec()) {
	qCritical() << "SQL ERROR" << query.lastError().text();
	return {};
    }

    QList<QString> strList;
    if (query.next()) {
	strList.append(query.value(0).toString());
	strList.append(query.value(1).toString());
	strList.append(query.value(2).toString());
	strList.append(query.value(3).toString());
	strList.append(query.value(4).toString());
	strList.append(query.value(5).toString());
	strList.append(query.value(6).toString());
	strList.append(query.value(7).toString());
	strList.append(query.value(8).toString());
	strList.append(query.value(9).toString());
	strList.append(query.value(10).toString());
	strList.append(query.value(11).toString());
	strList.append(query.value(12).toString());
	strList.append(query.value(13).toString());
	strList.append(query.value(14).toString());
    }

    return strList;
}
QSqlQuery* DataBaseManager::getKCP(const QString& name, const bool& isBachelor, int year) const {

    QSqlQuery* query = new QSqlQuery(m_db);
    query->prepare(R"(
        select *
        from kcp
        where entry_commision_id = (select id
                                    from entry_commisions
                                    where uni_name = :name and
                                          is_bachelor = :isBachelor and
                                          year = :year
                                    );
    )");
    query->bindValue(":name", name);
    query->bindValue(":isBachelor", isBachelor);
    query->bindValue(":year", year);

    if (!query->exec()) {
	qCritical() << "SQL ERROR"  << query->lastError().text();
	return nullptr;
    }

    return query;
}

bool DataBaseManager::changeEntryCommissionsIndexForTable(const QString& tableName, int index) {
    if (!m_db.isOpen()) {
	qCritical() << "SQL ERROR" << "DatabaseManager could not open connection to database";
	return false;
    }

    QSqlQuery query(m_db);
    if (!query.prepare(R"(
            UPDATE current_table_presets
            SET entry_commision_id = :newID
            WHERE tableName = :tName )")) {

	qCritical() << "SQL ERROR"  << query.lastError().text();
	return false;
    }
    query.bindValue(":tName", tableName);
    query.bindValue(":newID", index);

    if (!query.exec()) {
	qCritical() << "SQL ERROR"  << query.lastError().text();
	return false;
    }

    return true;
}

void DataBaseManager::addNewTablePreset(const QString& tableName, int commisionIndex) {

    if (isTableExist(tableName)) {
	changeEntryCommissionsIndexForTable(tableName, commisionIndex);
	return;
    }

    QSqlQuery query(m_db);

    query.prepare(R"(
        INSERT INTO current_table_presets (tableName, entry_commision_id)
        VALUES (:tableName, :entry_commision_id) ON CONFLICT(id) DO UPDATE SET
        tableName = excluded.tableName,
        entry_commision_id = :entry_commision_id;
    )");
    query.bindValue(":tableName", tableName);
    query.bindValue(":entry_commision_id", commisionIndex);

    if (!query.exec()) {
	qCritical() << "SQL ERROR" << query.lastError().text();
	return;
    }
}

bool DataBaseManager::createDatabase() {

    QSqlQuery query(m_db);

    if (!query.exec(readFile(":/src/database/sql-queries/create-columns_mapping-table.sql"))) {
        qCritical()  << "SQL ERROR - DATABASE CREATION FAILED" << query.lastError().text();
        return false;
    }

    if (!query.exec(readFile(":/src/database/sql-queries/create-current_table_presets-table.sql"))) {
        qCritical()  << "SQL ERROR - DATABASE CREATION FAILED" << query.lastError().text();
        return false;
    }

    if (!query.exec(readFile(":/src/database/sql-queries/create-entry_commisions-table.sql"))) {
        qCritical()  << "SQL ERROR - DATABASE CREATION FAILED" << query.lastError().text();
        return false;
    }

    if (!query.exec(readFile(":/src/database/sql-queries/create-kcp-table.sql"))) {
        qCritical()  << "SQL ERROR - DATABASE CREATION FAILED" << query.lastError().text();
        return false;
    }

    if (!query.exec(readFile(":/src/database/sql-queries/create-kcp-indexes.sql"))) {
        qCritical()  << "SQL ERROR - INDEXES CREATION FAILED" << query.lastError().text();
        return false;
    }

    return true;
}

QString DataBaseManager::readFile(const QString& fileName) {

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Can not open sql query file:" << fileName << file.errorString();
        return QString();
    }

    QTextStream in(&file);

    in.setEncoding(QStringConverter::Utf8);
    return in.readAll();
}
