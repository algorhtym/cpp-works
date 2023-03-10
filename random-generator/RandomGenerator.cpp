#include <iostream>
#include <cstdlib>
#include "RandomGenerator.h"

RandomGenerator::RandomGenerator() {
	s = 4; 
	unsigned long long r1 = randRange(1000,9999);
	unsigned long long r2 = randRange(1000,9999);
	
	size = 2;
	elements = new unsigned long long[MAX_SIZE];
	if (elements == NULL) {
		cout << "not enough memory" << endl;
	}
	else {
		elements[0] = r1;
		elements[1] = r2;
	}

}

RandomGenerator::RandomGenerator(int si, int r1i, int r2i) {
	s = si;
	unsigned long long r1 = mid_seq(s, r1i);
	unsigned long long r2 = mid_seq(s, r2i);
	

	size = 2;
	elements = new unsigned long long[MAX_SIZE];
	if (elements == NULL) {
		cout << "not enough memory" << endl;
	}
	else {
		elements[0] = r1;
		elements[1] = r2;
	}


}

int mid_seq(int s, unsigned long long a) {
	unsigned long long result = a;
	result = (unsigned long long) (result / pow(10,(s/2)));
	result = result % power(10,s);
	return result;
}

unsigned long long randRange(int low, int high) {
	return (rand() % (high - low)) + low;
}

unsigned long long power(int num, int pow) {
	unsigned long long result = 1;
	for (int i = 0; i < pow; i++) {
		result = result * num;
	}
	return result;
}




