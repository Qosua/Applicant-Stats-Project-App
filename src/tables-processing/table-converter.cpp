#include "table-converter.h"

#include <QDir>

void TableConverter::toTableForBot(const QList<FacultyDirection> &data, const QString &tableDirSavePath)
{
    QXlsx::Document doc;
    int rowIndex = 2;

    doc.write(1, 1, "id");
    doc.write(1, 2, "faculty");
    doc.write(1, 3, "code");
    doc.write(1, 4, "name");
    doc.write(1, 5, "priority-number");
    doc.write(1, 6, "number-in-group");
    doc.write(1, 7, "ege-score");

    for (auto faculty : data) {
        for (int i = 0; i < faculty.pool().size(); ++i) {
            int columnIndex = 1;

            const PriorityInfo &priority = faculty.pool()[i].first;
            const Applicant &applicant = faculty.pool()[i].second;

            doc.write(rowIndex, columnIndex++, applicant.id());
            doc.write(rowIndex, columnIndex++, priority.division());
            doc.write(rowIndex, columnIndex++, priority.code());
            doc.write(rowIndex, columnIndex++, priority.name());
            doc.write(rowIndex, columnIndex++, priority.priorityNumber());
            doc.write(rowIndex, columnIndex++, faculty.pool().size() - i);
            doc.write(rowIndex, columnIndex, priority.egeScore());

            rowIndex += 1;
        }
    }

    if (!QDir().mkpath(tableDirSavePath) or !doc.saveAs(QDir::cleanPath(tableDirSavePath) + "/table-for-bot.xlsx"))
        qCritical() << "Converted table save error";
}