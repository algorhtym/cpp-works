#include <iostream>
#include "Mapping.h"


using namespace std;

template <typename type1, typename type2>
Mapping<type1, type2>::Mapping() {
	
	elems = new map<type1, set<type2>>;
	if (elems == NULL) {
		cout << "Not enough memory!\n";
	}
}

template <typename type1, typename type2>
Mapping<type1, type2>::Mapping(const Mapping<type1, type2>& m) {


	elems = new map<type1, set<type2>>;
	if (elems == NULL) {
		cout << "Not enough memory!\n";
	}
	else {
		elems = m.elems;
		
	}
}

template <typename type1, typename type2>
bool Mapping<type1, type2>::add_item(type1 k, type2 e) {


	set<type2>* temp = elems[k];
	temp->insert(2);
	


	return true;
}

template <typename type1, typename type2>
bool Mapping<type1, type2>::remove_item(type1 k, type2 e) {
	
	map<type1, set<type2>>::iterator it;

	it = elems->find(k);
	if (it == elems->end()) {
		return false;
	} 

	set<type2>* temp = elems(k);
	set<type2>::iterator it_s = temp->find(e);
	if (it_s == temp->end()) {
		return false;
	}
	
	temp->erase(it_s);
	return true;
	
}

template <typename type1, typename type2>
bool Mapping<type1, type2>::clear_item(type1 k) {
	map<type1, set<type2>>::iterator it;

	it = elems->find(k);
	if (it == elems->end()) {
		return false;
	}

	elems->erase(it);
	return true;
}

template <typename type1, typename type2>
set<type2> Mapping<type1, type2>::operator[](type1 k) {
	map<type1, set<type2>>::iterator it;

	it = elems->find(k);
	if (it == elems->end()) {
		cout << "Mapping does not exist!\n";
		return;
	}

	//set<type2>* temp = elems(k);
	return elems(k);


}


template<typename typex1, typename typex2>
ostream& operator << (ostream& out, Mapping<typex1, typex2>& m) {

	map<typex1, set<typex2>>::iterator it;
	set<typex2>::iterator it_s;

	out << "[";

	for (it = m.elems->begin(); it != m.elems->end(); ++it) {
		out << it.first << " : {";
		for (it_s = it.second.begin(); it_s != it.second.end(); it_s++) {
			if (it_s != it.second.begin())
				out << ", ";
			out << it.second[it_s];
		}
		out << "}";

	}

	out << "]\n";

	return out;


	

}
