#include "OrderedSet.h"
#include <algorithm>
using namespace std;

OrderedSet::OrderedSet(): Set()
{
	m_start = 0;
	cout << "os std-ctor" << endl;
}

OrderedSet::OrderedSet(const Set& set2): Set(set2)
{
	m_start = 0;
	// sort set
	int* beg = begin();
	std:sort(beg, beg + m_size);
	cout << "os copy ctor: copy values " << *this << " Size: " << m_size << endl;
}

OrderedSet::OrderedSet(initializer_list<int> iniList): Set(iniList)
{
	m_start = 0;
	// sort set
	int* beg = begin();
	std::sort(beg, beg + m_size);
	cout << "os conv ctor: copy values " << *this <<  " Size: " << m_size << endl;
}

OrderedSet::~OrderedSet()
{
	cout << "os destructor: " << *this << endl;
}

int* OrderedSet::begin() const
{
	return m_values.get()+m_start;
}

Set OrderedSet::merge(const Set& set) const
{
	return Set();
}

Set OrderedSet::difference(const Set& set) const
{
	return Set();
}

Set OrderedSet::difference(Set&& set) const
{
	return Set();
}

Set OrderedSet::intersection(const Set& set) const
{
	return Set();
}

Set OrderedSet::intersection(Set&& set) const
{
	return Set();
}


// Contains with binary search
bool OrderedSet::contains(int e) const
{
	int left = m_start;
	int right = m_size - 1;

	while (left <= right) {
		int middle = left + ((right - left) / 2);
		if ((*this)[middle] == e) {
			return true;
		}
		else {
			if ((*this)[middle] > e) {
				right = middle - 1;
			}
			else {
				left = middle + 1;
			}
		}
	}
	return false;
}

bool OrderedSet::containsAll(const Set& set) const
{
	for (size_t i = 0; i < set.m_size; i++) {
		if (!contains(set[i])) {
			return false;
		}
	}
	return true;
}

OrderedSet OrderedSet::getSmaller(int x) const
{
	int left = m_start;
	int right = m_size - 1;
	OrderedSet os = OrderedSet(*this);
	// check edge case x <= first element
	if (x <= (*this)[left]) {
		os.m_size = 0;
		return os;
	}
	int middle = left + ((right - left) / 2);
	while (left <= right && (*this)[middle] != x) {
		middle = left + ((right - left) / 2);
		if ((*this)[middle] > x) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	if ((*this)[middle] != x) {
		middle++;
	}
	os.m_size = middle;
	return os;
}

OrderedSet OrderedSet::getLarger(int x) const
{
	return OrderedSet();
}
