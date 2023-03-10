#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>



using namespace std;

struct student {
	string firstname;
	string lastname;
	int student_ID;
	double labs; //11
	double as1; //5 (initially 30)
	double as2;
	double as3;
	double as4;
	double as5;
	double term_test; //15
	double midterm; //20
	double final; //30
	double total_mark; //100
	char* letter;
	
};

int main() {
	static const char DELIM = ';';
	//student *students;
	
	//students = new student[100];
	vector<student> all;


	fstream frr("CSI2372.info", ios::binary | ios::in);

	if (!frr.is_open()) {
		cout << "File not found!\n";
		return 0;
	}
	int i = 0;
	while (!frr.eof()) {
	//while (i == 0) {
		student temp;
		string tempName, tempLastname;
		int tempID;
		double tempLabs, t_as1, t_as2, t_as3, t_as4, t_as5;
		double t_term_test, t_midterm, t_final, t_total_mark;
		temp.letter = new char[2];

		getline(frr, tempName, DELIM);
		//cout << tempName << endl;
		temp.firstname = tempName;

		string tempLastName;
		getline(frr, tempLastName, DELIM);
		//cout << tempLastName << endl;
		temp.lastname = tempLastName;

		frr.read((char*)&tempID, sizeof(int));
		temp.student_ID = tempID;
		//cout << tempID << endl;

		frr.read((char*)&tempLabs, sizeof(double));
		//cout << tempLabs << endl;
		temp.labs = tempLabs;

		frr.read((char*)&t_as1, sizeof(double));
		//cout << t_as1 << endl;
		temp.as1 = t_as1 * 5 / 30;
		//cout << temp.as1 << endl;

		frr.read((char*)&t_as2, sizeof(double));
		//cout << t_as2 << endl;
		temp.as2 = t_as2 * 5 / 30;
		//cout << temp.as2 << endl;

		frr.read((char*)&t_as3, sizeof(double));
		//cout << t_as3 << endl;
		temp.as3 = t_as3 * 5 / 30;
		//cout << temp.as3 << endl;


		frr.read((char*)&t_as4, sizeof(double));
		//cout << t_as4 << endl;
		temp.as4 = t_as4 * 5 / 30;
		//cout << temp.as4 << endl;

		frr.read((char*)&t_as5, sizeof(double));
		//cout << t_as5 << endl;
		temp.as5 = t_as5 * 5 / 30;
		//cout << temp.as5 << endl;

		frr.read((char*)&t_term_test, sizeof(double));
		//cout << t_term_test << endl;
		temp.term_test = t_term_test;

		frr.read((char*)&t_midterm, sizeof(double));
		//cout << t_midterm << endl;
		temp.midterm = t_midterm;

		frr.read((char*)&t_final, sizeof(double));
		//cout << t_final << endl;
		temp.final = t_final;

		temp.total_mark = temp.labs +
			temp.as1 + temp.as2 + temp.as3 + temp.as4 +
			temp.as5 + temp.term_test + temp.midterm + temp.final;

		if (temp.total_mark >= 90) {
			temp.letter[0] = 'A';
			temp.letter[1] = '+';
		}
		else if (temp.total_mark >= 85) {
			temp.letter[0] = 'A';
			temp.letter[1] = ' ';
		}
		else if (temp.total_mark >= 80) {
			temp.letter[0] = 'A';
			temp.letter[1] = '-';
		}
		else if (temp.total_mark >= 75) {
			temp.letter[0] = 'B';
			temp.letter[1] = '+';
		}
		else if (temp.total_mark >= 70) {
			temp.letter[0] = 'B';
			temp.letter[1] = ' ';
		}
		else if (temp.total_mark >= 65) {
			temp.letter[0] = 'C';
			temp.letter[1] = '+';
		}
		else if (temp.total_mark >= 60) {
			temp.letter[0] = 'C';
			temp.letter[1] = ' ';
		}
		else if (temp.total_mark >= 55) {
			temp.letter[0] = 'D';
			temp.letter[1] = '+';
		}
		else if (temp.total_mark >= 50) {
			temp.letter[0] = 'D';
			temp.letter[1] = ' ';
		}
		else if (temp.total_mark >= 40) {
			temp.letter[0] = 'E';
			temp.letter[1] = ' ';
		}
		else {
			temp.letter[0] = 'F';
			temp.letter[1] = ' ';
		}




		//cout << temp.total_mark << endl;
		//cout << temp.letter << endl;

		all.push_back(temp);

		i++;
	}		
	
	frr.close();

	cout << i << " students examined. \n\n";


	fstream frw("CSI2372_Final.info", ios::binary | ios::out);

	if (!frw.is_open()) {
		cout << "File not found!\n";
		return 0;
	}

	vector<student>::iterator it;
	int j = 0;
	for (it = all.begin(); it != all.end(); it++) {
		int nameLen = (*it).firstname.size();
		frw.write((char*)&nameLen, sizeof(int));
		frw.write((*it).firstname.c_str(), (*it).firstname.size());


		int lastnameLen = (*it).lastname.size();
		frw.write((char*)&lastnameLen, sizeof(int));
		frw.write((*it).lastname.c_str(), (*it).lastname.size());

		frw.write((char*)&(*it).student_ID, sizeof(int));

		frw.write((char*)&(*it).labs, sizeof(double));

		frw.write((char*)&(*it).as1, sizeof(double));
		frw.write((char*)&(*it).as2, sizeof(double));
		frw.write((char*)&(*it).as3, sizeof(double));
		frw.write((char*)&(*it).as4, sizeof(double));
		frw.write((char*)&(*it).as5, sizeof(double));

		frw.write((char*)&(*it).term_test, sizeof(double));
		frw.write((char*)&(*it).midterm, sizeof(double));
		frw.write((char*)&(*it).final, sizeof(double));
		frw.write((char*)&(*it).total_mark, sizeof(double));
		frw.write((char*)&(*it).letter, 2* sizeof(char));

		//cout << (*it).total_mark << endl;
		//cout << (*it).letter << endl;
		j++;


	}

	frr.close();

	cout << j << " students added. \n\n";

	/* NOTE: code following this point is for testing the code until this point. 
		     They should be commmented/uncommented accordingly.
	*/

	fstream test("CSI2372_Final.info", ios::binary | ios::in);

	if (!test.is_open()) {
		cout << "File not found!\n";
		return 0;
	}
	//int len;
	//char* tmp; 
	int i = 0;
	
	while (!test.eof()) {
		i++;
		cout << i << ": ";
		char tmp[100];
		int len;
		string a, b;
		
		test.read((char*)&len, sizeof(int));
	
		test.read(tmp, len);
		//cout << "haha";
		tmp[len] = 0;
		a = tmp;
		cout << a << "| ";
		
		test.read((char*)&len, sizeof(int));
		test.read(tmp, len);
		//cout << "haha";
		tmp[len] = 0;
		
		b = tmp;
		
		cout << b << " | ";
		
		
		int stnum;
		test.read((char*)&stnum, sizeof(int));
		cout << stnum << " | ";

		double val;
		test.read((char*)&val, sizeof(double)); //labs
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //a1
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //a2
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //a3
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //a4
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //a5
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //termtest
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //midterm
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //final
		cout << val << " | ";

		test.read((char*)&val, sizeof(double)); //total mark
		cout << val << " | ";

		char letter[2];
		test.read(letter, 2 * sizeof(char)); //letter
		cout << letter << " |\n";
		
		





		
	}

	test.close();
	

}