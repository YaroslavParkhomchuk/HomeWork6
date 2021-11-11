#pragma once
using namespace std;

class Fraction
{
public:
	Fraction(int, int);
	Fraction();
	~Fraction();
	const Fraction operator+(const Fraction& fraction);
	const Fraction operator-(const Fraction& fraction);
	const Fraction operator*(const Fraction& fraction);
	const Fraction operator/(const Fraction& fraction);
	int getN() const;
	int getD() const;
	void setN (int _n);
	void setD(int _d);
	friend istream& operator>>(istream& in, Fraction& fraction);
	friend ostream& operator<< (ostream& out, const Fraction& fraction);

private:
	int n;
	int d;
	void simplify();
};
