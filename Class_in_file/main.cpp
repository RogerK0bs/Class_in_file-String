#include "Fraction.h"

void main()
{
	Fraction IND1;
	setlocale(LC_ALL, "");
	cout << R"(��� ��������� �������� � �������.
			  ������� ����� = )" << endl;
	cin >> IND1;
	cout << IND1;
	IND1.to_proper();
	IND1.to_improper();
	cout << "\n��� ����� 2 ����� ������� ����� �������...";
	_getch();
	Fraction IND2;
	system("cls");
	cout << "������ ����� = ";
	cin >> IND2;
	cout << "����� �1 = " << IND1;
	cout << "����� �2 = " << IND2;
	IND1 += IND2;
	IND1.to_improper();
	cout << IND1;


	_getch();
}