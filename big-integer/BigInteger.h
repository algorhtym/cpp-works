#pragma once

#include <iostream>

#define MAX_BASE 36
#define MAX_DIGITS 100


using namespace std;

extern const char digit_space[];

class BigInteger {
private:
	int base;
	int number;
	int digit_count;
	char* digits;
	char* encoded_number;
	int* encoded_digits;
	bool negative;
	
	void populate_digitlist(int);
	void encode_number();
	int convert_to_int(char);
	char convert_to_char(int);
	void update_number();
	void initialize_arrays();
	
public:
	BigInteger();
	BigInteger(int, int);
	BigInteger(const BigInteger&);
	~BigInteger();
	int num_digits();
	bool add_digit(char);
	void remove_digit();
	bool insert_digit(char,int); 
	char operator [] (int);
	bool operator == (BigInteger) const;
	bool operator != (BigInteger) const;
	bool operator > (BigInteger) const;
	bool operator < (BigInteger) const;
	bool operator >= (BigInteger) const;
	bool operator <= (BigInteger) const;
	BigInteger& operator = (BigInteger);
	BigInteger operator + (BigInteger);
	BigInteger operator - (BigInteger);
	BigInteger operator * (BigInteger);
	BigInteger operator ++();
	BigInteger operator ++(int);
	BigInteger operator --();
	BigInteger operator --(int);
	BigInteger operator / (BigInteger);
	BigInteger operator % (BigInteger);
	int get_number();
	int get_base();
	bool is_negative();
	int power(int, int);

	friend ostream& operator << (ostream& , BigInteger);
	friend istream& operator >> (istream&, BigInteger&);


	

};