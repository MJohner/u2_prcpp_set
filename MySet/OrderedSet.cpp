#include "OrderedSet.h"

using namespace std;

OrderedSet::OrderedSet()
{
	m_start = 0;
	m_size = 0;
	cout << "std-ctor_os" << endl;
}

OrderedSet::OrderedSet(const Set& set2)
{
	m_start = 0;
	m_size = set2.size();

}

OrderedSet::OrderedSet(initializer_list<int> iniList)
{
}

OrderedSet::~OrderedSet()
{
}

int* OrderedSet::begin() const
{
	return nullptr;
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



bool OrderedSet::contains(int e) const
{
	return false;
}
