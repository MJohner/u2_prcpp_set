#include "OrderedSet.h"
#include <algorithm>
using namespace std;

OrderedSet::OrderedSet(): Set()
{
	cout << "os std-ctor" << endl;
}

OrderedSet::OrderedSet(const Set& set2): Set(set2)
{
	// sort set
	int* beg = begin();
	sort(beg, beg + m_size);
	cout << "os copy ctor: copy values " << *this << " Size: " << m_size << endl;
}
OrderedSet::OrderedSet(const OrderedSet& set2) : Set(set2)
{
	m_start = set2.m_start;
	// sort set
	int* beg = begin();
	sort(beg, beg + m_size);
	cout << "os copy(os) ctor: copy values " << *this << " Size: " << m_size << endl;
}

OrderedSet::OrderedSet(initializer_list<int> iniList): Set(iniList)
{
	// sort set
	int* beg = begin();
	sort(beg, beg + m_size);
	cout << "os conv ctor: copy values " << *this <<  " Size: " << m_size << endl;
}

OrderedSet::~OrderedSet()
{
	cout << "os destructor: " << *this << endl;
}

int* OrderedSet::begin() const
{
	return m_values.get() + m_start;
}

Set OrderedSet::merge(const Set& set) const
{
	// type check for OrderedSet
	const OrderedSet *os = dynamic_cast<const OrderedSet*>(&set);
	if (os == nullptr) {
		return Set::merge(set);
	}

	// create result set
	OrderedSet result(m_size + set.m_size);
	size_t i = 0, j = 0;
	while (i < m_size && j < set.m_size) {
		if ((*this)[i] == set[j]) {
			result[result.m_size++] = (*this)[i];
			i++, j++;
		}
		else if ((*this)[i] < set[j]) {
			result[result.m_size++] = (*this)[i++];
		}
		else {
			result[result.m_size++] = set[j++];
		}
	}

	if (i < m_size) {
		copy_n(begin()+i, m_size-i, result.begin()+result.m_size);
		result.m_size += m_size - i;
	}
	else if (j < set.m_size) {
		copy_n(set.begin()+j, set.m_size-j, result.begin()+result.m_size);
		result.m_size += set.m_size - j;
	}

	return result;
}


// Contains with binary search
bool OrderedSet::contains(int e) const
{
	size_t left = 0;
	size_t right = m_size - 1;

	while (left <= right) {
		size_t middle = left + ((right - left) / 2);
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
	size_t left = 0;
	size_t right = m_size - 1;
	OrderedSet os = OrderedSet(*this);
	// check edge case x <= first element
	if (x <= (*this)[left]) {
		os.m_size = 0;
		return os;
	}
	size_t middle = left + ((right - left) / 2);
	while (left <= right && (*this)[middle] != x) {
		middle = left + ((right - left) / 2);
		if ((*this)[middle] > x) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	// exclisive condition
	if ((*this)[middle] != x) {
		middle++;
	}
	os.m_size = middle;
	return os;
}

OrderedSet OrderedSet::getLarger(int x) const
{
	size_t left = 0;
	size_t right = m_size - 1;
	OrderedSet os = OrderedSet(*this);
	// check edge case x < first element
	if (x < (*this)[left]) {
		return os;
	}
	size_t middle = left + ((right - left) / 2);
	while (left <= right && (*this)[middle] != x) {
		middle = left + ((right - left) / 2);
		if ((*this)[middle] > x) {
			right = middle - 1;
		}
		else {
			left = middle + 1;
		}
	}
	// exclisive condition
	if ((*this)[middle] <= x) {
		middle++;
	}
	os.m_start += middle;
	os.m_size -= middle;
	return os;
}
