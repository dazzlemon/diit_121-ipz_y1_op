#include "BigInt.h"

#include <sstream>//stringstream

BigInt::BigInt() {
	this->head = this->tail = NULL;
}

int operator<=>(const BigInt& lhs, const BigInt& rhs) {
	BigInt zero;
	zero = "0";
	int result = 1;

	if ((BigIntToStr(lhs) == BigIntToStr(rhs)) || ((BigIntToStr(absVal(lhs)) == "0") && (BigIntToStr(absVal(rhs)) == "0")) || (BigIntToStr(lhs) == "NaN") || (BigIntToStr(rhs) == "NaN"))//a=b, a=+-0, b=+-0 or one of them is NaN
		result = 0;
	else if (lhs.isPositive && !rhs.isPositive)//a>0, b<0, a>b
		result = 1;
	else if (!lhs.isPositive && rhs.isPositive)//a<0, b>0, a<b
		result = -1;
	else if (!lhs.isPositive && !rhs.isPositive)//a,b<0
		result = -1 * (absVal(lhs) <=> absVal(rhs));
	else {//a,b>0
		if (BigIntToStr(lhs).length() > BigIntToStr(rhs).length())//a>b
			result =  1;
		else if (BigIntToStr(lhs).length() < BigIntToStr(rhs).length())//a<b
			result = -1;
		else {//same length
			result = 0;
			std::string lhsStr = BigIntToStr(lhs);
			std::string rhsStr = BigIntToStr(rhs);
			int digitsAmount = lhsStr.length();
			for (int i = 0; i < digitsAmount && result == 0; i++) {
				if (lhsStr[i] > rhsStr[i])
					result = 1;
				if (lhsStr[i] < rhsStr[i])
					result = -1;
			}
		}
	}
	return result;
}

BigInt& BigInt::operator= (const std::string& rhs) {
	this->deleteDigits();
	for (int i = rhs.size() - 1; i > 0; i--)
		this->addToTail(rhs[i] - '0');
	if (rhs[0] == '+')
		this->isPositive = true;
	else if (rhs[0] == '-')
		this->isPositive = false;
	else {//char is digit//actually any other char
		this->isPositive = true;
		addToTail(rhs[0] - '0');
	}
	return *this;
}

std::string BigIntToStr(const BigInt& toString) {
	std::string string_;
	std::stringstream sstring_;
	if (!toString.isPositive)
		sstring_ << '-';
	digit* currentDigit = toString.tail;
	if (currentDigit) {
		while (currentDigit) {
			sstring_ << static_cast<char>(currentDigit->value + '0');
			currentDigit = currentDigit->prev;
		}
		string_ = sstring_.str();
		if (string_ == "-0")
			string_ = "0";
	}
	else
		string_ = "NaN";
	return string_;
}

void BigInt::addToTail(const char& value) {
	digit* newDigit = new digit;
	newDigit->value = value;
	newDigit->next = NULL;
	if (this->tail) {//if BigInt is !empty
		newDigit->prev = tail;
		tail->next = newDigit;
	}
	else {
		newDigit->prev = NULL;
		this->head = newDigit;
	}
	this->tail = newDigit;
}

BigInt operator+(const BigInt& a, const BigInt& b) {
	digit* currentDigitA = a.head, * currentDigitB= b.head;
	BigInt sum;
	int digitsSum, leftover = 0;
	if (!a.head || !b.head)
		sum = sum;//NaN
	else if ((absVal(a) <=> (BigInt)"0") == 0)//a=0
		sum = b;
	else if (((absVal(b) <=> (BigInt)"0") == 0))//b=0
		sum = a;
	else if ((a.isPositive && b.isPositive) || (!a.isPositive && !b.isPositive)) {//a+b or -(a+b)
		while (currentDigitA || currentDigitB) {//|a|+|b|//default case
			digitsSum = leftover;
			if (currentDigitA)
				digitsSum += currentDigitA->value;
			if (currentDigitB)
				digitsSum += currentDigitB->value;
			leftover = 0;
			while (digitsSum > 9) {
				digitsSum -= 10;
				leftover++;
			}
			sum.addToTail(digitsSum);
			if(currentDigitA)
				currentDigitA = currentDigitA->next;
			if(currentDigitB)
				currentDigitB = currentDigitB->next;
		}
		if (leftover > 0)
			sum.addToTail(leftover);
		sum.isPositive = a.isPositive;//optionally *-1
	}
	else if ((a.isPositive && !b.isPositive))//a-b
		sum = a - absVal(b);
	else if (!a.isPositive && b.isPositive)//-(a-b) = b-a
		sum = b - absVal(a);
	return sum;
}

BigInt BigInt::operator+() const {
	BigInt positiveThis;
	positiveThis = *this;
	return positiveThis;
}
BigInt BigInt::operator-() const {
	BigInt negativeThis;
	negativeThis = *this;
	negativeThis.isPositive = !negativeThis.isPositive;
	return negativeThis;
}

BigInt operator-(const BigInt& a, const BigInt& b) {
	digit* currentDigitA = a.head, * currentDigitB = b.head;
	BigInt difference;
	int digitsDifference, credit = 0;
	if (!a.head || !b.head)
		difference = difference;//already NaN
	else if ((absVal(a) <=> (BigInt)"0") == 0)
		difference = -b;
	else if (((absVal(b) <=> (BigInt)"0") == 0))
		difference = a;
	else if ((a.isPositive && b.isPositive) || (!a.isPositive && !b.isPositive)) {//a-b or -(a-b)=b-a
		if ((absVal(a) <=> absVal(b)) >= 0) {//a>=b
			while (currentDigitA) {
				digitsDifference = credit;
				digitsDifference += currentDigitA->value;
				if (currentDigitB)
					digitsDifference -= currentDigitB->value;
				credit = 0;
				while (digitsDifference < 0) {
					digitsDifference += 10;
					credit--;
				}
				difference.addToTail(digitsDifference);
				if (currentDigitA)
					currentDigitA = currentDigitA->next;
				if (currentDigitB)
					currentDigitB = currentDigitB->next;
			}
			difference.isPositive = a.isPositive;
		}
		else if ((absVal(a) <=> absVal(b)) == 0)
			difference = "0";
		else//a<b
			difference = - (b - a);
	}
	else if((a.isPositive && !b.isPositive) || (!a.isPositive && b.isPositive)){
		difference = absVal(a) + absVal(b);
		difference.isPositive = a.isPositive;
	}
	while ((difference.tail != difference.head) && difference.tail->value == 0)
		difference.deleteTail();
	return difference;
}

void BigInt::deleteDigits() {
	digit* currentDigit = this->head, *deletable;
	while (currentDigit) {
		deletable = currentDigit;
		currentDigit = currentDigit->next;
		delete deletable;
	}
	this->head = NULL;
	this->tail = NULL;
}

BigInt absVal(const BigInt& a) {
	BigInt absolute;
	absolute = a;
	absolute.isPositive = true;
	return absolute;
}

BigInt& BigInt::operator=(const BigInt& rhs) {
	if (&rhs != this) {
		this->deleteDigits();
		if (BigIntToStr(rhs) != "NaN")
			*this = BigIntToStr(rhs);
	}
	return *this;
}

BigInt::BigInt(const BigInt& rhs) {
	this->head = this->tail = NULL;
	*this = rhs;
}

BigInt::BigInt(const std::string& rhs) {
	this->head = this->tail = NULL;
	*this = rhs;
}

BigInt operator*(const BigInt& a, const BigInt& b) {
	BigInt product, operand1, operand2, zero, one;
	product = zero = "0";
	one = "1";

	if (!a.head || !b.head)
		product = operand1;//NaN
	else if (((a <=> zero) == 0) || ((b <=> zero) == 0))
		product = product;//0
	else if ((a <=> zero) < 0) {
		product = absVal(a) * b;
		product.isPositive = !product.isPositive;
	}
	else if ((b <=> zero) < 0) {
		product = a * absVal(b);
		product.isPositive = !product.isPositive;
	}
	else {//a,b>0
		operand1 = a;
		operand2 = b;
		if (operand1 > operand2) {
			BigInt tmp = operand2;
			operand2 = operand1;
			operand1 = tmp;
		}
		for (operand1; (operand1 <=> zero) > 0; operand1 = operand1 - one)
			product = product + operand2;
	}
	return product;
}

void BigInt::deleteTail() {
	if (tail) {
		if (head == tail) {
			delete head;
			head = tail = NULL;
		}
		else {
			digit* tmp = tail->prev;
			delete tail;
			tmp->next = NULL;
			tail = tmp;
		}
	}
}

BigInt operator/(const BigInt& a, const BigInt& b) {
	BigInt quotient, newA, one, zero;
	quotient = zero = "0";
	one = "1";

	if (!a.head || !b.head)
		quotient = newA;//NaN
	else if ((absVal(b) <=> zero) == 0)
		quotient = newA;//NaN
	else if ((absVal(a) <=> zero) == 0)
		quotient = quotient;//already zero
	else if ((a <=> zero) < 0) {
		quotient = absVal(a) / b;
		quotient.isPositive = !quotient.isPositive;
	}
	else if ((b <=> zero) < 0) {
		quotient = a / absVal(b);
		quotient.isPositive = !quotient.isPositive;
	}
	else {
		newA = a;
		while ((newA <=> b) >= 0) {//a,b >0
			newA = newA - b;
			quotient = quotient + one;
		}
	}
	return quotient;
}

BigInt::~BigInt() {
	this->deleteDigits();
}