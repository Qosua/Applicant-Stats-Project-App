#include "phone-number.h"

void PhoneNumber::dropNumber(const QString& smpfldN) {
    this->nationalNumber = smpfldN.toLongLong();
    this->regionCode = -1;
    this->subRegionCode = -1;
}

void PhoneNumber::buildPhoneNumber(const QString& strNumber) {
    QString simplefiledNumber = "";
    for (int i = 0; i < strNumber.length(); ++i) {
	if (strNumber[i] >= '0' and strNumber <= '9') {
	    simplefiledNumber += strNumber[i];
	}
    }

    if (simplefiledNumber.length() < 4)
    {
        return;
    }

    //Проверка на российский номер


    if (simplefiledNumber[0] == '8' or simplefiledNumber[0] == '7')
    {
        if (simplefiledNumber.length() == 11)
        {
            this->regionCode = 7;
            this->nationalNumber = simplefiledNumber.sliced(1).toLongLong();
            return;
        }
    }

    if (strNumber[0] != '+') {
	dropNumber(simplefiledNumber);
	return;
    }

    // Пытаемся определить код региогна по списку
    int potentialCode;
    bool flag = false;
    int sliceCount;
    for (sliceCount = 3; sliceCount > 0; --sliceCount) {
	flag = true;

	potentialCode = simplefiledNumber.sliced(0, sliceCount).toInt();
	auto res = this->rgsHshTbl.find(potentialCode);
	if (res == this->rgsHshTbl.end()) {
	    flag = false;
	} else {
	    break;
	}
    }

    if (!flag) {
	dropNumber(simplefiledNumber);
	return;
    }

    this->regionCode = potentialCode;
    simplefiledNumber.slice(sliceCount);

    // Проверка на то, требуется ли определение уточняющего региона

    if (this->rgsHshTbl[regionCode].size() == 1) {
	this->nationalNumber = simplefiledNumber.toLongLong();
	return;
    }

    flag = false;

    for (sliceCount = 4; sliceCount > 0; --sliceCount) {
	flag = true;

	potentialCode = simplefiledNumber.sliced(0, sliceCount).toInt();
	auto res = this->rgsHshTbl[this->regionCode].find(potentialCode);
	if (res == this->rgsHshTbl[this->regionCode].end()) {
	    flag = false;
	} else {
	    break;
	}
    }

    if (!flag) {
	// не удалось сопоставить уточняющий регион. Выставляем значение по умолчанию если оно есть

	if (this->rgsHshTbl[this->regionCode].find(-1) != this->rgsHshTbl[this->regionCode].end()) {
	    this->nationalNumber = simplefiledNumber.toLongLong();
	    return;
	}
	dropNumber(QString::number(this->regionCode) + simplefiledNumber);
	return;
    }

    this->subRegionCode = potentialCode;
    simplefiledNumber.slice(sliceCount);
    this->nationalNumber = simplefiledNumber.toLongLong();
}

int PhoneNumber::getRegionCode() { return this->regionCode; }

int PhoneNumber::getSubRegionCode() { return this->subRegionCode; }

int PhoneNumber::getNationalNumber() { return this->nationalNumber; }

QString PhoneNumber::asSimplefiedE164() {
    QString sE164 = "";
    sE164 += ('+' + QString::number(this->regionCode) + ' ');
    if (this->subRegionCode != -1)
	sE164 += (QString::number(this->subRegionCode) + ' ');
    return sE164 + QString::number(this->nationalNumber);
}

bool PhoneNumber::isValid() {
    if (this->regionCode == -1) {
	return false;
    }
    return true;
}

PhoneNumber::Country PhoneNumber::getCountry() { return this->rgsHshTbl[this->regionCode][this->subRegionCode]; }
