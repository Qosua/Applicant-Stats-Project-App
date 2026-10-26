#ifndef APPLICANTSTATSPROJECT_TABLECONVERTER_H
#define APPLICANTSTATSPROJECT_TABLECONVERTER_H

#include <xlsxdocument.h>

#include "../applicants-faculty-priority/faculty-direction.h"


class TableConverter {

public:
    static void toTableForBot(const QList<FacultyDirection>& data, const QString& tablePath);



};

#endif  // APPLICANTSTATSPROJECT_TABLECONVERTER_H
