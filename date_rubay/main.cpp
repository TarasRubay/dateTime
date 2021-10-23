#include "date.h"
void main() {
	date dat;
	date dat2;
	do {
		cout << "enter year: ";
		cin >> dat.year;
	} while (dat.year < 1);
	dat.fill_array();
	for (int i = 0; i < 12; i++)cout << dat.arr[i] << " ";
	cout << "\n";
	do {
		cout << "enter mount: ";
		cin >> dat.mount;
	} while (dat.mount < 1 || dat.mount > 12);

	do {
		cout << "enter day: ";
		cin >> dat.day;
	} while (dat.check_day());
	dat.get_date();

	cout << "++dat:\n";
	++dat;
	dat.get_date();

	cout << "dat++:\n";
	dat++;
	dat.get_date();

	cout << "--dat:\n";
	--dat;
	dat.get_date();

	cout << "dat--:\n";
	dat--;
	dat.get_date();
	cout << "dat - dat2. Enter parameter dat2\n";
	do {
		cout << "enter year: ";
		cin >> dat2.year;
	} while (dat2.year < 1);
	dat2.fill_array();
	for (int i = 0; i < 12; i++)cout << dat2.arr[i] << " ";
	cout << "\n";
	do {
		cout << "enter mount: ";
		cin >> dat2.mount;
	} while (dat2.mount < 1 || dat2.mount > 12);

	do {
		cout << "enter day: ";
		cin >> dat2.day;
	} while (dat2.check_day());
	dat2.get_date();
	cout << "dat - dat2 = " << dat - dat2 << endl;
	int tmp;
	do {
		cout << "enter number. dat + N_day: ";
		cin >> tmp;
	} while (tmp < 1);

	
	cout << setw(2) << dat2.day << "." << setw(2) << dat2.mount << "." << setw(4) << dat2.year;
	cout << " + "<< tmp <<" = ";
	dat2 + tmp;
	dat2.get_date();
	cout << endl;

	//date r(10,12,2020); для перевірки конструкторів
	//date q;
	//q = dat;
	//dat = dat;

	cout << setw(2) << dat.day << "." << setw(2) << dat.mount << "." << setw(4) << dat.year << "\t\t\t" << setw(2) << dat2.day << "." << setw(2) << dat2.mount << "." << setw(4) << dat2.year << endl;
	cout  <<"dat\t\t<\t\td\at2 " << boolalpha << (dat < dat2) << endl;
	cout << "dat\t\t>\t\tdat2 " << boolalpha << (dat > dat2) << endl;
	cout << "dat\t\t<=\t\tdat2 " << boolalpha << (dat <= dat2) << endl;
	cout << "dat\t\t>=\t\tdat2 " << boolalpha << (dat >= dat2) << endl;
	cout << "dat\t\t==\t\tdat2 " << boolalpha << (dat == dat2) << endl;
	cout << "dat\t\t!=\t\tdat2 " << boolalpha << (dat != dat2) << endl;
}
