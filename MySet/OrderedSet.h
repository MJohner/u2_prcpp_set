#pragma once
#include <ostream>
#include <iostream>
#include "MySet.h"



class OrderedSet : Set {
	using Set::Set;
protected:
	size_t m_start;
	// protected constructor
	explicit OrderedSet(size_t capacity) : Set(capacity) {
		m_start = 0;
	};

	int *begin() const override;

	Set merge(const Set& set) const override;
	Set difference(const Set& set) const override;
	Set difference(Set&& set) const override;
	Set intersection(const Set& set) const override;
	Set intersection(Set&& set) const override;

public:
	// default constructor
	OrderedSet();

	// copy constructor
	OrderedSet(const Set& set2);

	// type convert constructor
	OrderedSet(initializer_list<int> iniList);

	// Destructor
	~OrderedSet();

	bool contains(int e) const override;
};

