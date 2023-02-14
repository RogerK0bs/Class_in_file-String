#include "Fraction.h"

void main()
{
	Fraction IND1;
	setlocale(LC_ALL, "");
	cout << R"(Эта программа работает с дробями.
			  Введите дробь = )" << endl;
	cin >> IND1;
	cout << IND1;
	IND1.to_proper();
	IND1.to_improper();
	cout << "\nДля ввода 2 дроби нажмите любую клавишу...";
	_getch();
	Fraction IND2;
	system("cls");
	cout << "Вторая дробь = ";
	cin >> IND2;
	cout << "Дробь №1 = " << IND1;
	cout << "Дробь №2 = " << IND2;
	IND1 += IND2;
	IND1.to_improper();
	cout << IND1;


	_getch();
}