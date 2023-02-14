#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;
#define LINE_D for (size_t i = 0; i < 6; i++)cout<<'-';
class Fraction
{
	int integer; // целая часть
	int numerator;// числитель
	int denominator;//знаменатель
public:
	// Type-cast operator
	explicit operator int()const;
	explicit operator double()const;
	// Методы
	int Get_integer()const;
	int Get_numerator()const;
	int Get_denominator()const;
	void Set_integer(int integer);
	void Set_numerator(int numerator);
	void Set_denominator(int denominator);
	std::ostream& Print(std::ostream& os);
	Fraction(double decimal);
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction& swap();
	// Операторы 
	Fraction& operator()(int integer, int numerator, int denominator);
	Fraction operator=(Fraction& Drob);
	Fraction operator+=(Fraction& Drob);
	Fraction operator-=(Fraction& Drob);
	Fraction operator*=(Fraction& Drob);
	Fraction operator/=(Fraction& Drob);
};

std::istream& operator>>(std::istream& is, Fraction& obj);
std::ostream& operator<<(std::ostream& os, Fraction& obj);
Fraction operator+(Fraction& Drob1, Fraction& Drob2);
Fraction operator-(Fraction& Drob1, Fraction& Drob2);
Fraction operator* (Fraction& Drob1, Fraction& Drob2);
Fraction operator/(Fraction& Drob1, Fraction& Drob2);
// Comparison operator
bool operator==(Fraction left, Fraction right);
bool operator!=(const Fraction left, const Fraction right);
bool operator>(Fraction left, Fraction right);
bool operator<(Fraction left, Fraction right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);