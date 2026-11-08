#include "phone-number.h"

QString PhoneNumber::buildPhoneNumber(const QString& strNumber)
{
	valid = false;

	QString simplified = "";
	for (int i = 0; i < strNumber.length(); ++i)
	{
		if (strNumber[i] >= '0' and strNumber[i] <= '9')
		{
			simplified.push_back(strNumber[i]);
		}
	}

	if (simplified.isEmpty())
	{
		return "<Номер не распознан>";
	}
	
	if (simplified[0] == '8' or simplified[0] == '7')
	{
		if (simplified.length() == 11)
		{
			valid = true;
			QString res = "+7 ";
			res += (simplified.sliced(1, 3) + ' ');
			res += (simplified.sliced(4, 3) + ' ');
			res += (simplified.sliced(7, 2) + ' ');
			res += simplified.sliced(9, 2);

			parsedNumber = res;
			return number();
		}
	}

	return simplified;

}

QString PhoneNumber::number()
{
	return parsedNumber;
}

bool PhoneNumber::isValid()
{
	return valid;
}
