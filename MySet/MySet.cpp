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
			begin()[m_size] = value;
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
	return m_values.get();
}

int& Set::operator[](size_t i)
{
	return  *(begin()+i);
}

int Set::operator[](size_t i) const
{
	return *(begin()+i);
}

Set Set::merge(const Set& set) const
{
	Set result(m_size + set.m_size);
	copy_n(begin(), m_size, result.begin());
	result.m_size = m_size;
	for (size_t i = 0; i < set.m_size; i++) {
		if (!contains(set[i])) result[result.m_size++] = set[i];
	}
	return result;
}

Set Set::difference(const Set& set) const
{
	Set result(set.m_size);
	for (size_t i = 0; i < set.m_size; i++) {
		if (!contains(set[i])) result[result.m_size++] = set[i];
	}
	return result;
}

Set Set::intersection(const Set& set) const
{
	// use the smaller set for the result and loop
	Set result((m_size < set.m_size) ? m_size : set.m_size);
	if (m_size < set.m_size) {
		for (size_t i = 0; i < m_size; i++) {
			if (set.contains(*(begin() + i))) result[result.m_size++] = *(begin() + i); // this[i] does not work
		}
	} else {
		for (size_t i = 0; i < set.m_size; i++) {
			if (contains(set[i])) result[result.m_size++] = set[i];
		}
	}
	
	return result;
}

bool Set::contains(int e) const
{
	for (size_t i = 0; i < m_size; i++) {
		if (*(begin() + i) == e) {
			return true;
		}
	}
	return false;
}

bool Set::containsAll(const Set& set) const
{
	for (size_t i = 0; i < set.m_size; i++) {
		if (contains(set[i])) {
			return true;
		}
	}
	return false;
}

bool Set::isEmpty() const
{
	return m_values == nullptr || m_size == 0;
}

size_t Set::size() const
{
	return m_size;
}
