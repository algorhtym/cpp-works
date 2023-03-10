#include <iostream>
#include "Relation_Template.h"
#include <algorithm>

//Kemal Kilic 300143720



using namespace std;

template <typename typex>
ostream& operator << (ostream& out, Relation<typex>& r) {

	out << "{";
	typename vector<Pair<typex>>::iterator it = r.elements.begin();


	while (it != r.elements.end()) {
		if (it != r.elements.begin()) {
			out << ", ";
		}
		out << "(" << (*it).first << ", " << (*it).second << ")";
		++it;
	}

	out << "}";

	return out;

}

template <typename type>
Relation<type>::Relation() {
	size = 0;
}

template <typename type> 
Relation<type>::Relation(const Relation<type>& r) {
	size = r.size;
	root = r.root;
	elements = r.elements;
}

template <typename type>
Relation<type>::~Relation() {
	root.clear();
	elements.clear();
}



template <typename type>
int Relation<type>::cardinality() {
	return size;
}


template <typename type>
bool Relation<type>::add_to_set(type x) {
	typename set<type>::iterator it;
	pair<set<type>::iterator, bool> ret;

	ret = root.insert(x);
	if (ret.second == false) {
		return false;
	}
	else {
		return true;
	}
}



template <typename type>
bool Relation<type>::add_element(type a, type b) {
	//set<type>::iterator it = root.find(p.first)

	Pair<type> p;
	p.first = a;
	p.second = b;
	if (root.find(p.first) == root.end() || root.find(p.second) == root.end()) {
		return false;
	}

	typename vector<Pair<type>>::iterator it;
	for (it = elements.begin(); it != elements.end(); ++it) {
		if (( * it).first == p.first && (*it).second == p.second)
			return true;
	}

	elements.push_back(p);
	size++;
	return true;
}

template <typename type>
bool Relation<type>::remove_element(type a, type b) {
	Pair<type> p;
	p.first = a;
	p.second = b;

	if (root.find(p.first) == root.end() || root.find(p.second) == root.end()) {
		return false;
	}

	typename vector<Pair<type>>::iterator it = elements.begin();

	while (it != elements.end()) {
		if ((*it).first == p.first && (*it).second == p.second)
			break;
		++it;
	}

	if (it != elements.end()) {
		elements.erase(it);
		size--;
		return true;
	}

	return false;


}

template <typename type>
bool Relation<type>::is_member(type a, type b) {
	Pair<type> p;
	p.first = a;
	p.second = b;

	if (root.find(p.first) == root.end() || root.find(p.second) == root.end()) {
		return false;
	}

	typename vector<Pair<type>>::iterator it = elements.begin();

	while (it != elements.end()) {
		if ((*it).first == p.first && (*it).second == p.second) {
			break;
		}
		++it;
	}

	if (it != elements.end()) {
		return true;
	} 
	
	return false;
}

template <typename type>
bool Relation<type>::subset(Relation<type> r) {
	typename vector<Pair<type>>::iterator it = elements.begin();

	while (it != elements.end()) {
		if (!r.is_member((*it).first, (*it).second)) {
			return false;
		}

		++it;
	}

	return true;
}

template <typename type>
bool Relation<type>::operator== (Relation<type> r) {
	if (subset(r) && r.subset(*this)) {
		return true;
	}
	
	return false;
}

template <typename type>
vector<type> Relation<type>::operator[] (type x) {
	vector<type> ret; 
	if (root.find(x) == root.end()) {
		cout << "element not found in root set!\n";
		return ret;
	}

	typename vector<Pair<type>>::iterator it = elements.begin();

	while (it != elements.end()) {
		if ((*it).first == x) {
			//ret.push_back((*it).first);
			ret.push_back((*it).second);
		}

		if (it == elements.end())
			break;
		++it;
	}
	/*
	if (it == elements.end()) {
		cout << "Relation not found!\n";
		return ret;
	}
	*/
	

	//ret.push_back((*it).first);
	//ret.push_back((*it).second);

	return ret;


}

template <typename type>
bool Relation<type>::reflexive() {
	typename set<type>::iterator it;
	for (it = root.begin(); it != root.end(); ++it) {
		Pair<type> p;
		p.first = (*it);
		p.second = (*it);
		if (!is_member(p.first,p.second)) {
			return false;
		}
	}

	return true;
}

template <typename type>
bool Relation<type>::irreflexive() {
	typename set<type>::iterator it;
	for (it = root.begin(); it != root.end(); ++it) {
		Pair<type> p;
		p.first = (*it);
		p.second = (*it);
		if (is_member(p.first,p.second)) {
			return false;
		}
	}

	return true;
}

template <typename type>
bool Relation<type>::symmetric() {
	typename vector<Pair<type>>::iterator it;
	for (it = elements.begin(); it != elements.end(); ++it) {
		Pair<type> p;
		p.first = (*it).second;
		p.second = (*it).first;
		if (!is_member(p.first,p.second)) {
			return false;
		}
	}

	return true;

	
}


template <typename type>
bool Relation<type>::asymmetric() {
	typename vector<Pair<type>>::iterator it;
	for (it = elements.begin(); it != elements.end(); ++it) {
		Pair<type> p;
		p.first = (*it).second;
		p.second = (*it).first;
		if (is_member(p.first,p.second)) {
			return false;
		}
	}

	return true;
}


template <typename type>
bool Relation<type>::transitive() {
	typename vector<Pair<type>>::iterator it1;
	typename vector<Pair<type>>::iterator it2;

	for (it1 = elements.begin(); it1 != elements.end(); ++it1) {

		for (it2 = elements.begin(); it2 != elements.end(); ++it2) {
			Pair<type> p;
			p.first = (*it1).first;
			p.second = (*it2).second;
			if (!is_member(p.first,p.second)) {
				return false;
			}
		}
	}

	return true;
}

template <typename type>
bool Relation<type>::is_function() {
	typename vector<Pair<type>>::iterator it1;
	typename vector<Pair<type>>::iterator it2;

	for (it1 = elements.begin(); it1 != elements.end(); ++it1) {

		for (it2 = elements.begin(); it2 != elements.end(); ++it2) {
			if ((*it1).first == (*it2).first && (*it1).second != (*it2).second) {
				return false;
			}
		}
	}

	return true;
	
}

template <typename type>
Relation<type> Relation<type>::inverse() {
	Relation<type> result;

	//result.root = root;
	typename set<type>::iterator s_it;
	for (s_it = root.begin(); s_it != root.end(); ++s_it) {
		result.add_to_set(*s_it);
	}
	
	typename vector<Pair<type>>::iterator it;
	for (it = elements.begin(); it != elements.end(); ++it) {
		Pair<type> p;
		p.first = (*it).second;
		p.second = (*it).first;
		result.add_element(p.first, p.second);
	}

	return result;
	
}

template <typename type>
Relation<type> Relation<type>::combination(Relation<type> r) {
	Relation<type> result;

	typename set<type>::iterator s_it;
	for (s_it = root.begin(); s_it != root.end(); ++s_it) {
		result.add_to_set(*s_it);
	}

	typename vector<Pair<type>>::iterator it1;
	typename vector<Pair<type>>::iterator it2;

	for (it1 = elements.begin(); it1 != elements.end(); ++it1) {

		for (it2 = r.elements.begin(); it2 != r.elements.end(); ++it2) {
			if ((*it1).second == (*it2).first) {
				Pair<type> p;
				p.first = (*it1).first;
				p.second = (*it2).second;
				result.add_element(p.first, p.second);
			}
		}
	}

	return result;
}


