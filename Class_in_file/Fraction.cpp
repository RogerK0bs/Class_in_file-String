#include "Fraction.h"

// Type-cast operator
 Fraction::operator int()const
{
	return Fraction(*this).to_proper().integer;
}
Fraction::operator double()const
{
	return integer + (double)numerator / denominator;
}

// Методы
int Fraction::Get_integer()const
{
	return integer;
}
int Fraction::Get_numerator()const
{
	return numerator;
}
int Fraction::Get_denominator()const
{
	return denominator;
}
void Fraction::Set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::Set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::Set_denominator(int denominator)
{
	if (denominator == 0)denominator = 1;
	this->denominator = denominator;
}
std::ostream& Fraction::Print(std::ostream& os)
{
	//cout << " \t   " << numerator << "\n\t " << integer << "----\n" << " \t   " << denominator << endl;
	cout << " \n\n\t   " << numerator << "\n\t " << integer; LINE_D;
	cout << "\n \t   " << denominator << endl;
	return os;
}
Fraction::Fraction(double decimal)
{
	decimal += 1e-17;
	this->integer = decimal; // сохранение целового числа
	decimal -= integer; // убираем 10ую часть из дроби
	this->denominator = 1e+9;
	this->numerator = decimal * denominator;
	//reduce();// ?????
}
Fraction& Fraction::to_proper()
{
	if (integer > 0)
	{
		int a = integer * denominator + numerator;
		integer = 0;
		numerator = a;
		//cout << "\nЦелая часть интегрируется в числитель = ";
	//	Print();
		return *this;
	}
	//else cout << "to_proper() - целая часть отсутствует!";
}
Fraction& Fraction::to_improper()
{
	if (numerator > denominator)
	{
		do
		{
			this->numerator -= denominator;
			this->integer++;
		} while (numerator >= denominator);
		//	cout << "\nВыделение целой части из числителя = ";
	//	Print();
		return *this;
	}
	else
	{
		if (numerator == denominator)
		{
			this->integer++;
			this->numerator -= denominator;
			//	cout << "\nВыделение целой части из числителя = ";
		//	Print();
			return *this;
		}
		//	else cout << "\nto_improper() - числитель меньше знаменателя!";

	}
}
Fraction& Fraction::swap()
{
	if (integer > 0) { numerator = integer * denominator + numerator; integer = 0; }
	int buffer = numerator;
	this->numerator = denominator;
	this->denominator = buffer;
	return *this;
}
// Операторы 
Fraction& Fraction::operator()(int integer, int numerator, int denominator)
{
	Set_integer(integer);
	Set_numerator(numerator);
	Set_denominator(denominator);
	if (denominator == 0)this->denominator = 1;
	return *this;
}
Fraction Fraction::operator=(Fraction& Drob)
{
	this->numerator = Drob.numerator;
	this->denominator = Drob.denominator;
	if (Drob.Get_integer() > 0)this->integer = Drob.integer;
	return *this;
}
Fraction Fraction::operator+=(Fraction& Drob)
{
	if (Drob.Get_integer() > 0)Drob.to_proper();
	if (integer > 0) { numerator = integer * denominator + numerator; integer = 0; }
	int buffer = numerator;
	this->numerator = ((numerator * Drob.Get_denominator()) + (Drob.Get_numerator() * denominator));
	this->denominator = ((denominator * Drob.Get_numerator()) + (Drob.Get_denominator() * buffer));
	return *this;
}
Fraction Fraction::operator-=(Fraction& Drob)
{
	if (Drob.Get_integer() > 0)Drob.to_proper();
	if (integer > 0) { numerator = integer * denominator + numerator; integer = 0; }
	int buffer = numerator;
	this->numerator = ((numerator * Drob.Get_denominator()) - (Drob.Get_numerator() * denominator));
	this->denominator = ((denominator * Drob.Get_numerator()) - (Drob.Get_denominator() * buffer));
	return *this;
}
Fraction Fraction::operator*=(Fraction& Drob)
{
	if (Drob.Get_integer() > 0)Drob.to_proper();
	if (integer > 0) { numerator = integer * denominator + numerator; integer = 0; }
	int buffer = numerator;
	this->numerator = numerator * Drob.Get_numerator();
	this->denominator = denominator * Drob.Get_denominator();
	return *this;
}
Fraction Fraction::operator/=(Fraction& Drob)
{
	if (Drob.Get_integer() > 0)Drob.to_proper();
	if (integer > 0) { numerator = integer * denominator + numerator; integer = 0; }
	int buffer = numerator; Drob.swap();
	this->numerator *= Drob.Get_numerator();
	this->denominator *= Drob.Get_denominator();
	return *this;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	cout << "\nЧислитель = "; is >> numerator;
	cout << "\nЗнаменатель = "; is >> denominator;
	cout << "\nЦелая часть = "; is >> integer;
	obj(integer, numerator, denominator);
	system("cls");
	return is;
}
std::ostream& operator<<(std::ostream& os, Fraction& obj)
{
	return obj.Print(os);
}
Fraction operator+(Fraction& Drob1, Fraction& Drob2)
{
	Fraction result;
	if (Drob1.Get_denominator() == Drob2.Get_denominator())
	{
		result.Set_integer(Drob1.Get_integer() + Drob2.Get_integer());
		result.Set_numerator(Drob1.Get_numerator() + Drob1.Get_numerator());
		return result;
	}
	else
	{
		Drob1.to_proper();
		Drob2.to_proper();
		result.Set_numerator(((Drob1.Get_numerator() * Drob2.Get_denominator()) + (Drob2.Get_numerator() * Drob1.Get_denominator())));
		result.Set_denominator(((Drob1.Get_denominator() * Drob2.Get_numerator()) + (Drob2.Get_denominator() * Drob1.Get_numerator())));
		result.Set_integer(0);
		return result;
	}

}
Fraction operator-(Fraction& Drob1, Fraction& Drob2)
{
	Fraction result;
	if (Drob1.Get_denominator() == Drob2.Get_denominator())
	{
		result.Set_integer(Drob1.Get_integer() - Drob2.Get_integer());
		result.Set_numerator(Drob1.Get_numerator() - Drob1.Get_numerator());
		return result;
	}
	else
	{
		Drob1.to_proper();
		Drob2.to_proper();
		result.Set_numerator(((Drob1.Get_numerator() * Drob2.Get_denominator()) - (Drob2.Get_numerator() * Drob1.Get_denominator())));
		result.Set_denominator(((Drob1.Get_denominator() * Drob2.Get_numerator()) - (Drob2.Get_denominator() * Drob1.Get_numerator())));
		result.Set_integer(0);
		return result;
	}
}
Fraction operator* (Fraction& Drob1, Fraction& Drob2)
{
	Fraction result;
	Drob1.to_proper();
	Drob2.to_proper();
	result.Set_numerator(Drob1.Get_numerator() * Drob2.Get_numerator());
	result.Set_denominator(Drob1.Get_denominator() * Drob2.Get_denominator());
	result.to_improper();
	return result;
}
Fraction operator/(Fraction& Drob1, Fraction& Drob2)
{
	Drob2.swap();
	return Drob1 * Drob2;
}
// Comparison operator
bool operator==(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return left.Get_numerator() * right.Get_denominator() ==
		right.Get_numerator() * left.Get_denominator();
	//
	//
	//return left.integer()==right.integer()&&
	//       left.numenator() == right.numenator()&&
	//       left.denominator() == right.denominator();
}
bool operator!=(const Fraction left, const Fraction right)
{
	return !(left == right); // не равно
}
bool operator>(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return left.Get_numerator() * right.Get_denominator() >
		right.Get_numerator() * left.Get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return left.Get_numerator() * right.Get_denominator() <
		right.Get_numerator() * left.Get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right); // Больше или равно - это не меньше!
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left > right); // Больше или равно - это не меньше!
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	cout << "\nЧислитель = "; is >> numerator;
	cout << "\nЗнаменатель = "; is >> denominator;
	cout << "\nЦелая часть = "; is >> integer;
	obj(integer, numerator, denominator);
	system("cls");
	return is;
}
std::ostream& operator<<(std::ostream& os, Fraction& obj)
{
	return obj.Print(os);
}
Fraction operator+(Fraction& Drob1, Fraction& Drob2)
{
	Fraction result;
	if (Drob1.Get_denominator() == Drob2.Get_denominator())
	{
		result.Set_integer(Drob1.Get_integer() + Drob2.Get_integer());
		result.Set_numerator(Drob1.Get_numerator() + Drob1.Get_numerator());
		return result;
	}
	else
	{
		Drob1.to_proper();
		Drob2.to_proper();
		result.Set_numerator(((Drob1.Get_numerator() * Drob2.Get_denominator()) + (Drob2.Get_numerator() * Drob1.Get_denominator())));
		result.Set_denominator(((Drob1.Get_denominator() * Drob2.Get_numerator()) + (Drob2.Get_denominator() * Drob1.Get_numerator())));
		result.Set_integer(0);
		return result;
	}

}
Fraction operator-(Fraction& Drob1, Fraction& Drob2)
{
	Fraction result;
	if (Drob1.Get_denominator() == Drob2.Get_denominator())
	{
		result.Set_integer(Drob1.Get_integer() - Drob2.Get_integer());
		result.Set_numerator(Drob1.Get_numerator() - Drob1.Get_numerator());
		return result;
	}
	else
	{
		Drob1.to_proper();
		Drob2.to_proper();
		result.Set_numerator(((Drob1.Get_numerator() * Drob2.Get_denominator()) - (Drob2.Get_numerator() * Drob1.Get_denominator())));
		result.Set_denominator(((Drob1.Get_denominator() * Drob2.Get_numerator()) - (Drob2.Get_denominator() * Drob1.Get_numerator())));
		result.Set_integer(0);
		return result;
	}
}
Fraction operator* (Fraction& Drob1, Fraction& Drob2)
{
	Fraction result;
	Drob1.to_proper();
	Drob2.to_proper();
	result.Set_numerator(Drob1.Get_numerator() * Drob2.Get_numerator());
	result.Set_denominator(Drob1.Get_denominator() * Drob2.Get_denominator());
	result.to_improper();
	return result;
}
Fraction operator/(Fraction& Drob1, Fraction& Drob2)
{
	Drob2.swap();
	return Drob1 * Drob2;
}
// Comparison operator
bool operator==(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return left.Get_numerator() * right.Get_denominator() ==
		right.Get_numerator() * left.Get_denominator();
	//
	//
	//return left.integer()==right.integer()&&
	//       left.numenator() == right.numenator()&&
	//       left.denominator() == right.denominator();
}
bool operator!=(const Fraction left, const Fraction right)
{
	return !(left == right); // не равно
}
bool operator>(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return left.Get_numerator() * right.Get_denominator() >
		right.Get_numerator() * left.Get_denominator();
}
bool operator<(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	return left.Get_numerator() * right.Get_denominator() <
		right.Get_numerator() * left.Get_denominator();
}
bool operator>=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left < right); // Больше или равно - это не меньше!
}
bool operator<=(const Fraction& left, const Fraction& right)
{
	//return left > right || left == right;
	return !(left > right); // Больше или равно - это не меньше!
}