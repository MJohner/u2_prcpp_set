#pragma once
#include <ostream>
#include <iostream>
#include "MySet.h"



class OrderedSet : public Set {
	using Set::Set;
protected:
	size_t m_start = 0;
	// protected constructor
	explicit OrderedSet(size_t capacity) : Set(capacity) {
		cout << "os private-ctor called: len = " << m_size << endl;
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

	OrderedSet(const OrderedSet& set2);

	// type convert constructor
	OrderedSet(initializer_list<int> iniList);

	// Destructor
	~OrderedSet();

	bool contains(int e) const override;
	bool containsAll(const Set& set) const override;

	OrderedSet getSmaller(int x) const;

	OrderedSet getLarger(int x) const;
};

