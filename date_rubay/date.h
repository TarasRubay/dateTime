#pragma once
#include <iostream>
#include <iomanip>
using namespace std;
struct date {
	int year;
	int mount;
	int day;
	int arr[12];
	void fill_array();
	void get_date();
	bool check_day();
	date(int _day,int _mount,int _year);
	date();
	~date();
	date& operator=(date &_tmp);
	date operator++();
	date operator++(int val);
	date operator--();
	date operator--(int val);
	int operator-(date _dat);
	date operator+(int _val);
	bool operator<(date& _dat);
	bool operator>(date& _dat);
	bool operator<=(date& _dat);
	bool operator>=(date& _dat);
	bool operator==(date& _dat);
	bool operator!=(date& _dat);
};