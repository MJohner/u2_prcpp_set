#pragma once
#include <ostream>
#include <iostream>
using namespace std;
class Set {
protected:   
	// class variables
	shared_ptr<int[]> m_values;
	size_t m_size;
	
	// protected constructor 
	// protected constructor 
	explicit Set(size_t capacity) : m_values(make_unique<int[]>(capacity)), m_size(0)
	{
		cout << "private-ctor called" << endl;
	}

	// protected methods
	int *begin() const;
	int& operator[](size_t i);
	int operator[](size_t i) const;

	// Set operations
	Set merge(const Set& set) const;
	Set difference(const Set& set) const;
	Set intersection(const Set& set) const;

public:   
	// default constructor
	Set();

	// copy constructor
	Set(const Set &set2);

	// type convert constructor
	Set(initializer_list<int> iniList);

	// Destructor
	~Set();

	// instance methods
	bool contains(int e) const;
	bool containsAll(const Set& set) const;
	bool isEmpty() const;
	size_t size() const;

	bool operator==(const Set& set) const {
		return size() == set.size() && containsAll(set) && set.containsAll(*this);
	}
	
	// output operator
	friend ostream& operator<<(ostream& os, const Set& s) {
		const int* const vptr = s.begin();
		os << "{";
		if (!s.isEmpty()) os << vptr[0];
		for (size_t i = 1; i < s.m_size; i++) { os << ", " << vptr[i]; }
		os << "}";
		return os;
	}
	// class methods
	static Set merge(const Set& set1, const Set& set2) { return set1.merge(set2);}
	static Set difference(const Set& set1, const Set& set2) { return set2.difference(set1); }
	static Set intersection(const Set& set1, const Set& set2) { return set1.intersection(set2); }
};