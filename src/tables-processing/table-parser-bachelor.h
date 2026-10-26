#ifndef TABLEPARSERBACHELOR_H
#define TABLEPARSERBACHELOR_H

#include <xlsxdocument.h>

#include <QDebug>
#include <QFile>
#include <QHash>
#include <QList>
#include <QMap>
#include <QTextStream>
#include <expected>
#include <memory>

#include "../applicants-faculty-priority/applicant.h"
#include "../applicants-faculty-priority/namespaces.h"

enum class TableParserError {
    noError,
    valueError,
    noSuchColumn,
};

class TableParserBachelor {

public:
    void setTablePath(const QString& path);
    void parseTable();
    std::shared_ptr<QList<Applicant>> getApplicants(ApplicantsFilterFlags flag,
                                                    StudyType priorityToDelete) const;

    QString builtPhoneNumber(const QString& number);

    void readColumnNamesFromDB();
    void setEntryCommisionInfo(const QString& entryCommisionName, bool isBachelor, int year);
    std::expected<QVariant, TableParserError> getValueInTable(const int rowIndex, const QString& columnName) const;

    QString extractCode(const QString& str);
    QString extractName(const QString& str);
    StudyForm extractStudyForm(const QString& str);
    StudyType extractStudyType(const QString& str);

    QString m_tablePath;
    QString m_columnsNamesFilePath;
    QString m_entryCommisionName;
    bool m_isBachelor;
    int m_year;

    QMap<QString, int> m_columnsNames;
    std::unique_ptr<QXlsx::Document> m_applicantsTable;
    std::shared_ptr<QList<Applicant>> m_applicantsList;
};

#endif  // TABLEPARSERBACHELOR_H
