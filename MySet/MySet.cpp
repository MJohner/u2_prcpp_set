// MySet.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "MySet.h"
#include <iostream>

using namespace std;
// default constructor
Set::Set() {
	m_size = 0;
	cout << "default-ctor called" << endl;
}

// protected constructor 
explicit Set::Set(size_t capacity): m_values(make_unique<int[]>(capacity)), m_size(0)
{
	cout << "private-ctor called" << endl;
}

// copy constructor
Set::Set(const Set &set2): Set(set2.m_size)
{
	m_values = set2.m_values;
	cout << "copy-ctor called" << endl;
}

// type convert constructor
Set::Set(initializer_list<int> iniList): Set(iniList.size())
{
	cout << "type-convert-ctor called" << endl;
	;
	// iterate over given list
	for (int value : iniList) {
		// check if the set conatins the current value
		if (!contains(value)) {
			// add the value if not in set
			m_values[m_size] = value;
			m_size++;
		}
	}
}




// destructor
Set::~Set()
{
	cout << "destructor called" << endl;
}


int* Set::begin() const
{
	return nullptr;
}

int& Set::operator[](size_t i)
{
	// TODO: insert return statement here
}

int Set::operator[](size_t i) const
{
	return 0;
}

Set Set::merge(const Set& set) const
{
	Set result(m_size + set.m_size);
	std::copy_n(begin(), m_size, result.begin());
	result.m_size = m_size;
	for (size_t i = 0; i < set.m_size; i++) {
		if (!contains(set[i])) result[result.m_size++] = set[i];
	}
	return result;
}

Set Set::difference(const Set& set) const
{
	return Set();
}

Set Set::intersection(const Set& set) const
{
	return Set();
}

bool Set::contains(int e) const
{
	return false;
}

bool Set::constainsAll(const Set& set) const
{
	return false;
}

bool Set::isEmpty() const
{
	return false;
}

size_t Set::size() const
{
	return size_t();
}
