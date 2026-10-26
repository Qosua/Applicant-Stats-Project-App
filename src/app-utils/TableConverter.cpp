#include "TableConverter.h"

void TableConverter::toTableForBot(const QList<FacultyDirection>& data, const QString& tablePath) {

    QXlsx::Document doc;
    int rowIndex = 2;

    doc.write(1, 1, "ID");
    doc.write(1, 2, "Faculty");
    doc.write(1, 3, "Code");
    doc.write(1, 4, "Name");
    doc.write(1, 5, "Priority number");
    doc.write(1, 6, "Number in group");
    doc.write(1, 7, "EGE score");

    for (auto faculty : data) {
        for (int i = 0; i < faculty.pool().size(); ++i) {

            int columnIndex = 1;

            const PriorityInfo& priority = faculty.pool()[i].first;
            const Applicant& applicant = faculty.pool()[i].second;

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

    if (!doc.save())
        qCritical() << "Converted table save error";

}