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
	cout << "std-ctor" << endl;
}

// copy constructor
Set::Set(const Set& set2)
{
	m_values = set2.m_values;
	m_size = set2.m_size;
	cout << "copy-ctor: "<< *this << endl;
}

// type convert constructor
Set::Set(initializer_list<int> iniList): Set(iniList.size())
{
	
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
	cout << "conv ctor: copy values " << *this << endl;
}

// destructor
Set::~Set()
{
	cout << "destructor: " << *this << endl;
}


int* Set::begin() const
{
	return m_values.get();
}

int& Set::operator[](size_t i)
{
	return *(begin()+i);
}

int Set::operator[](size_t i) const
{
	return *(begin()+i);
}

Set Set::merge(const Set &set) const
{
	Set result(m_size + set.m_size);
	copy_n(begin(), m_size, result.begin());
	result.m_size = m_size;
	for (size_t i = 0; i < set.m_size; ++i) {
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

Set Set::difference(Set&& set) const
{
	if (set.m_values.use_count() == 1) {
		set.m_size = 0;
		for (size_t i = 0; i < m_size; i++) {
			if (!contains(set[i])) set[set.m_size++] = set[i];
		}
		return set;
	}
	else {
		return difference(set);
	}
}

Set Set::intersection(const Set& set) const
{
	// use the smaller set for the result and loop
	Set result((m_size < set.m_size) ? m_size : set.m_size);
	if (m_size < set.m_size) {
		for (size_t i = 0; i < m_size; i++) {
			if (set.contains((*this)[i])) result[result.m_size++] = (*this)[i]; // this[i] does not work
		}
	} else {
		for (size_t i = 0; i < set.m_size; i++) {
			if (contains(set[i])) result[result.m_size++] = set[i];
		}
	}
	return result;
}

Set Set::intersection(Set&& set) const {
	if (set.m_values.use_count() == 1) {
		set.m_size = 0;
		for (size_t i = 0; i < m_size; i++) {
			if (contains(set[i])) set[set.m_size++] = set[i];
		}
		cout << set << endl;
		return set;
	}
	else {
		return intersection(set);
	}
}

bool Set::contains(int e) const
{
	for (size_t i = 0; i < m_size; i++) {
		if ((*this)[i] == e) {
			return true;
		}
	}
	return false;
}

bool Set::containsAll(const Set& set) const
{
	for (size_t i = 0; i < set.m_size; i++) {
		if (!contains(set[i])) {
			return false;
		}
	}
	return true;
}

bool Set::isEmpty() const
{
	return m_values == nullptr || m_size == 0;
}

size_t Set::size() const
{
	return m_size;
}
