#include "date.h"	
void date::fill_array()
{
	for (int i = 0; i < 12; i++)
	{
		if (i == 1 && (this->year % 4 == 0) && (this->year % 100 != 0 || this->year % 100 == 0 && this->year % 400 == 0))this->arr[i] = 29;
		else if (i == 3 || i == 5 || i == 10 || i == 8)this->arr[i] = 30;
		else if (i == 0 || i == 2 || i == 4 || i == 6 || i == 7 || i == 9 || i == 11)this->arr[i] = 31;
		else this->arr[i] = 28;
	}
}

void date::get_date()
{
	cout << setw(2) << this->day << "." << setw(2) << this->mount << "." << setw(4) << this->year << endl;
}

bool date::check_day()
{
	if (this->day >= 1 && this->day <= this->arr[mount - 1])
		return false;
	else return true;
}

date::date(int _day, int _mount, int _year)
{
	this->day = _day;
	this->mount = _mount;
	this->year = _year;
}

date::date()
{
}

date::~date()
{
}

date& date::operator=(date &_tmp)
{
	if (this == &_tmp)throw exception("error memory");
	else return _tmp;
}

date date::operator++()
{
	if (this->day + 1 > this->arr[mount - 1]) {
		if (this->mount + 1 > 12) {
			this->year = this->year + 1;
			this->fill_array();
			this->mount = 1;
			this->day = 1;
			return *this;
		}
		else
		{
			this->mount = this->mount + 1;
			this->day = 1;
			return *this;
		}
	}
	else
	{
		this->day = this->day + 1;
		return *this;
	}
}

date date::operator++(int val)
{
	date tmp(*this);
	if (this->day + 1 > this->arr[mount - 1]) {
		if (this->mount + 1 > 12) {
			this->year = this->year + 1;
			this->fill_array();
			return operator++();
		}
		else
		{
			this->mount = this->mount + 1;
			this->day = 1;
			return tmp;
		}
	}
	else
	{
		this->day = this->day + 1;
		return tmp;
	}
}

date date::operator--()
{
	if (this->day - 1 < 1) {
		if (this->mount - 1 < 1) {
			this->year = this->year - 1;
			this->fill_array();
			this->mount = 12;
			this->day = 31;
			return *this;
		}
		else
		{
			this->mount = this->mount - 1;
			this->day = this->arr[mount - 1];
			return *this;
		}
	}
	else
	{
		this->day = this->day - 1;
		return *this;
	}
}
	date date::operator--(int val)
{
	date tmp(*this);
	if (this->day - 1 < 1) {
		if (this->mount - 1 < 1) {
			this->year = this->year - 1;
			this->fill_array();
			this->mount = 12;
			this->day = 31;
			return tmp;
		}
		else
		{
			this->mount = this->mount - 1;
			this->day = this->arr[mount - 1];
			return tmp;
		}
	}
	else
	{
		this->day = this->day - 1;
		return tmp;
	}
}

int date::operator-(date _dat)
{
	int tmp = (this->day + this->mount + this->year) - (_dat.day + _dat.mount + _dat.year);
	return tmp;
}

date date::operator+(int _val)
{
	for (int i = 0; i < _val; i++)
	{
		this->operator++();
	}
	return *this;
}

bool date::operator<(date& _dat)
{
	if ((this->day + this->mount + this->year) < (_dat.day + _dat.mount + _dat.year))return true;
	else return false;
}

bool date::operator>(date& _dat)
{
	return !operator<(_dat);
}

bool date::operator<=(date& _dat)
{
	if ((this->day + this->mount + this->year) <= (_dat.day + _dat.mount + _dat.year))return true;
	else return false;
}

bool date::operator>=(date& _dat)
{
	return !operator<=(_dat);
}

bool date::operator==(date& _dat)
{
	if ((this->day + this->mount + this->year) == (_dat.day + _dat.mount + _dat.year))return true;
	else return false;
}

bool date::operator!=(date& _dat)
{
	return !operator==(_dat);
}

