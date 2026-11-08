#pragma once

#include <QHash>
#include <QPair>
#include <QVector>

class PhoneNumber 
{
    QString parsedNumber;
    bool valid = false;

public:
    QString buildPhoneNumber(const QString& strNumber);
    QString number();

    bool isValid();

    PhoneNumber() = default;
    ~PhoneNumber() = default;
};
