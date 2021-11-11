#include <iostream>
#include <cmath>
#include "Fraction.h"
using namespace std;

Fraction::Fraction(int _n, int _d) :n(_n), d(_d)
{
	if (_d == 0) { throw "Division by zero"; }
	simplify();
}

Fraction::Fraction() {}
Fraction::~Fraction() {}
int Fraction::getN() const { return n; }
int Fraction::getD() const { return d; }
void Fraction::setN (int _n) { n = _n; }

void Fraction::setD (int _d) 
{ 
	if (_d == 0) { throw "Exception"; }
	d = _d;
}

const Fraction Fraction::operator+(const Fraction& fraction)
{
	Fraction result(this->n * fraction.getD() + fraction.getN() * this->d, this->d * fraction.getD());
	result.simplify();
	return result;
}

const Fraction Fraction::operator-(const Fraction& fraction) 
{
	Fraction result(this->n * fraction.getD() - fraction.n * this->getD(), this->d * fraction.getD());
	result.simplify();
	return result;
}

const Fraction Fraction::operator*(const Fraction& fraction)
{
	Fraction result(this->n * fraction.getN(), this->d * fraction.getN());
	result.simplify();
	return result;
}

const Fraction Fraction::operator/(const Fraction& fraction)
{
	if (fraction.n == 0) { throw "Exception"; }
	Fraction result(this->n * fraction.getD(), this->d * fraction.getN());
	result.simplify();
	return result;
}

istream& operator >>(istream& in, Fraction& fraction)
{
	in >> fraction.n;
	in >> fraction.d;
	if (fraction.d == 0) { throw "Exception"; }
	return in;
}

ostream& operator<< (ostream& out, const Fraction& fraction)
{
	out << fraction.n << '/' << fraction.d << endl;
	return out;
}

void Fraction::simplify()
{
	int divisor;
	divisor = min(n, d);
	
	for (int i = 2; i <= divisor;)
	{
		if ((n % i == 0) && (d % i == 0))
		{
			n = n / i;
			d = d / i;
		}
		else
		{
			i++;
		}
	}
}
