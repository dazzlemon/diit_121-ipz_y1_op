#ifndef __BIGINT_H__
#define __BIGINT_H__

//class that represents arbitrary precision integer using two way linked list
//no digits represent NaN
//+-0 is still 0

#include <string>
#include <compare>

struct digit {
	char value;//0-9
	digit* next, * prev;
};

class BigInt {//tail <-> digits <-> head
public:
	BigInt();
	~BigInt();
	BigInt(const std::string& rhs);
	BigInt(const BigInt& rhs);

	BigInt& operator=(const std::string& rhs);
	BigInt& operator=(const BigInt& rhs);
	BigInt operator+() const;//pass
	BigInt operator-() const;//reverse isPositive

	friend std::string BigIntToStr(const BigInt& toString);
	friend int operator<=>(const BigInt& lhs, const BigInt& rhs);

	friend BigInt operator+(const BigInt& a, const BigInt& b);
	friend BigInt operator-(const BigInt& a, const BigInt& b);
	friend BigInt operator*(const BigInt& a, const BigInt& b);
	friend BigInt operator/(const BigInt& a, const BigInt& b);

	friend BigInt absVal(const BigInt& a);
private:
	digit* head, * tail;//if head = tail = NULL then NaN
	bool isPositive;//0 can be both negative and positive

	void addToTail(const char& value);
	void deleteTail();
	void deleteDigits();
};

std::string BigIntToStr(const BigInt& toString);//return string representation in base10////sign unnecessary <-> tail <-> digits <-> head
int operator<=>(const BigInt& lhs, const BigInt& rhs);//three-way comparison

BigInt operator+(const BigInt& a, const BigInt& b);
BigInt operator-(const BigInt& a, const BigInt& b);
BigInt operator*(const BigInt& a, const BigInt& b);
BigInt operator/(const BigInt& a, const BigInt& b);

BigInt absVal(const BigInt& a);

#endif