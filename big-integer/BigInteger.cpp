#include <iostream>
#include "BigInteger.h"

using namespace std;

const char digit_space[MAX_BASE] = {'0','1','2','3','4','5',
									'6','7','8','9','A','B',
									'C','D','E','F','G','H',
									'I','J','K','L','M','N',
									'O','P','Q','R','S','T',
									'U','V','W','X','Y','Z'};

BigInteger::BigInteger() {
	negative = false;
	base = 10;
	number = 0;
	digit_count = 0; // initialize

	digits = new char[MAX_BASE];
	encoded_number = new char[MAX_DIGITS];
	encoded_digits = new int[MAX_DIGITS];

	if (digits == NULL || encoded_number == NULL || encoded_digits == NULL) {
		cout << "Not enough memory!" << endl;
	}
	else {
		initialize_arrays();
		populate_digitlist(base);
		encode_number();
	}
}

BigInteger::BigInteger(int number, int base) {
	negative = number < 0;
	this->base = base;
	this->number = number;
	digit_count = 0; // to initialize

	digits = new char[MAX_BASE];
	encoded_number = new char[MAX_DIGITS];
	encoded_digits = new int[MAX_DIGITS];

	if (digits == NULL || encoded_number == NULL || encoded_digits == NULL) {
		cout << "Not enough memory!" << endl;
	}
	else {
		initialize_arrays();
		populate_digitlist(base);
		encode_number();
	}
}

BigInteger::BigInteger(const BigInteger& other) {
	negative = other.number < 0;
	this->base = other.base;
	this->number = other.number;
	digit_count = 0; // to initialize

	
	digits = new char[MAX_BASE];
	encoded_number = new char[MAX_DIGITS];
	encoded_digits = new int[MAX_DIGITS];

	if (digits == NULL || encoded_number == NULL || encoded_digits == NULL) {
		cout << "Not enough memory!" << endl;
	}
	else {
		initialize_arrays();
		populate_digitlist(base);
		encode_number();
	}
}

BigInteger::~BigInteger() {
	delete[] digits;
	delete[] encoded_digits;
	delete[] encoded_number;
}

void BigInteger::populate_digitlist(int b) {
	for (int i = 0; i < b; ++i) {
		digits[i] = digit_space[i];
	}
}

void BigInteger::initialize_arrays() {
	for (int i = 0; i < MAX_DIGITS; i++) {
		encoded_number[i] = -1;
		encoded_digits[i] = -1;
	}
}

void BigInteger::encode_number() {

	int quotient = number;
	if (quotient < 0)
		quotient *= -1;
	int count = 0;
	int temp[MAX_DIGITS];
	while (quotient != 0) {
		temp[count] = quotient % base;
		quotient = (int)quotient / base;
		count++;
	}
	for (int i = 0; i < count; i++) {
		encoded_number[i] = digits[temp[count - 1 - i]];
		encoded_digits[i] = temp[count - 1 - i];
	}
	digit_count = count;

}

int BigInteger::num_digits() {
	return digit_count;
}

bool BigInteger::add_digit(char d) {
	int enc_num = convert_to_int(d);
	if (enc_num > base - 1 || enc_num < 0) {
		cout << "You can't insert a digit out of base bounds!\n";
		return false;
	}

	encoded_digits[digit_count] = enc_num;
	encoded_number[digit_count] = d;
	digit_count++;
	update_number();
	return true;
}

bool BigInteger::insert_digit(char num, int pos) {
	int enc_num = convert_to_int(num);
	if (enc_num > base - 1 || enc_num < 0) {
		cout << "You can't insert a digit out of base bounds!\n";
		return false;
	}
	if (pos < 0 || pos > digit_count - 1) {
		cout << "You can't insert at a position out of bounds!\n";
		return false;
	}

	int temp_ints[MAX_DIGITS];
	char temp_chars[MAX_DIGITS];
	int count = 0;

	for (int i = digit_count - pos; i <= digit_count; i++) {
		if (i == digit_count - pos) {
			temp_chars[i] = num;
			temp_ints[i] = enc_num;
		}
		else {
			temp_ints[count] = encoded_digits[i - 1];
			temp_chars[count] = encoded_number[i - 1];
			count++;
		}
	}
	for (int b = 0; b < count; b++) {
		encoded_digits[digit_count - pos + b] = temp_ints[b];
		encoded_number[digit_count - pos + b] = temp_chars[b];
	}

	digit_count++;
	update_number();
	return true;
}

int BigInteger::get_number() {
	return number;
}

int BigInteger::get_base() {
	return base;
}


bool BigInteger::is_negative() {
	return negative;
}

// 234253 A 1 : 
// 23425A3

void BigInteger::remove_digit() {
	encoded_digits[digit_count - 1] = -1;
	encoded_number[digit_count - 1] = -1;
	digit_count--;
	update_number();
}

char BigInteger::operator [] (int index) {
	return encoded_digits[digit_count - 1 - index];
}

bool BigInteger::operator == (BigInteger other) const {
	return number == other.get_number();
}

bool BigInteger::operator != (BigInteger other) const {
	return !(number == other.get_number());
}

bool BigInteger::operator > (BigInteger other) const {
	return number > other.get_number();
}

bool BigInteger::operator >= (BigInteger other) const {
	return number >= other.get_number();
}

bool BigInteger::operator < (BigInteger other) const {
	return number < other.get_number();
}

bool BigInteger::operator <= (BigInteger other) const {
	return number <= other.get_number();
}

BigInteger& BigInteger::operator = (BigInteger other) {
	this->negative = other.negative;
	this->base = other.get_base();
	this->number = other.get_number();
	digit_count = 0; // to initialize

	char* temp_digits;
	int* temp_encoded_digits;
	char* temp_encoded_number;

	temp_digits = new char[MAX_BASE];
	temp_encoded_number = new char[MAX_DIGITS];
	temp_encoded_digits = new int[MAX_DIGITS];

	if (temp_digits == NULL || temp_encoded_digits == NULL|| temp_encoded_number == NULL) {
		cout << "Not enough memory!" << endl;
	}
	else {
		for (int i = 0; i < MAX_DIGITS; i++) {
			temp_encoded_number[i] = -1;
			temp_encoded_digits[i] = -1;
		}
		for (int i = 0; i < base; ++i) {
			digits[i] = digit_space[i];
		}
		int quotient = number;
		int count = 0;
		int temp[MAX_DIGITS];
		while (quotient != 0) {
			temp[count] = quotient % base;
			quotient = (int)quotient / base;
			count++;
		}
		for (int i = 0; i < count; i++) {
			temp_encoded_number[i] = digits[temp[count - 1 - i]];
			temp_encoded_digits[i] = temp[count - 1 - i];
		}
		digit_count = count;

		delete[] digits;
		delete[] encoded_digits;
		delete[] encoded_number;

		digits = temp_digits;
		encoded_digits = temp_encoded_digits;
		encoded_number = temp_encoded_number;

	}
	return *this;
}

BigInteger BigInteger::operator + (BigInteger other) {
	int result_int = number + other.get_number();
	BigInteger result = BigInteger(result_int, base);
	return result;
}

BigInteger BigInteger::operator - (BigInteger other) {
	int result_int = number - other.get_number();
	BigInteger result = BigInteger(result_int, base);
	return result;
}

BigInteger BigInteger::operator * (BigInteger other) {
	int result_int = number * other.get_number();
	BigInteger result = BigInteger(result_int, base);
	return result;
}

BigInteger BigInteger::operator / (BigInteger other) {
	int result_int = (int)number / other.get_number();
	BigInteger result = BigInteger(result_int, base);
	return result;
}

BigInteger BigInteger::operator % (BigInteger other) {
	int result_int = number % other.get_number();
	BigInteger result = BigInteger(result_int, base);
	return result;
}


BigInteger BigInteger::operator ++ (int a) {
	number++;
	encode_number();
	return (*this);
}

BigInteger BigInteger::operator ++ () {
	BigInteger result = (*this);
	number++;
	encode_number();
	return result;
}

BigInteger BigInteger::operator -- (int a) {
	number--;
	encode_number();
	return (*this);
}

BigInteger BigInteger::operator -- () {
	BigInteger result = (*this);
	number--;
	encode_number();
	return result;
}

ostream& operator << (ostream& out, BigInteger a) {
	if (a.negative == true) {
		out << "-";
	}
	for (int i = 0; i < a.digit_count; i++) {
		out << a.encoded_digits[i];
	}
	return out;
}

istream& operator >>(istream& in, BigInteger& f)
{
	int b, num;
	cout << "Input the number: ";
	in >> num;
	cout << "\nInput the base: ";
	in >> b;
	if (b > 36) {
		cout << "Maximum base 36 is allowed. Considering base 36.\n";
		b = 36;
	}

	f.number = num;
	f.base = b;

	f.digits = new char[MAX_BASE];
	f.encoded_number = new char[MAX_DIGITS];
	f.encoded_digits = new int[MAX_DIGITS];

	if (f.digits == NULL || f.encoded_number == NULL || f.encoded_digits == NULL) {
		cout << "Not enough memory!" << endl;
	}
	else {
		f.initialize_arrays();
		f.populate_digitlist(f.base);
		f.encode_number();
	}

	return in;

}


int BigInteger::convert_to_int(char c) {
	int count = 0;
	char temp = -1;
	while (temp != c) {
		temp = digit_space[count];
		count++;
	}

	return count;
}

char BigInteger::convert_to_char(int i) {
	return digit_space[i];
}

void BigInteger::update_number() {
	int temp = 0;
	int p;
	for (int i = 0; i < digit_count; i++) {
		p = digit_count - i - 1;
		temp = temp + power(base, p) * encoded_number[i];
	}
	number = temp;
}

int BigInteger::power(int num, int pow) {
	int result = 1;
	for (int i = 1; i <= pow; i++) {
		result = result * num;
	}
	return result;
}