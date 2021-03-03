#pragma once
#include "RBTree.hpp"

// set ÖĞ·ÀÖ¹µÄÊÇ
template<class K>
class set
{

	typedef K ValueType;
	struct KOFP
	{
		const K& operator()(const ValueType& data)
		{
			return data;
		}
	};
	typedef RBTree<ValueType, KOFP> RBT;
	typedef typename RBT::iterator iterator;
public:
	set() :_t(){}

	// iterator
	iterator begin()
	{
		return _t.begin();
	}
	iterator end()
	{
		return _t.end();
	}

	// capacity
	size_t size()
	{
		return _t.size();
	}
	bool empty()
	{
		return _t.empty();
	}

	// modify
	pair<iterator, bool> insert(const ValueType& data)
	{
		return _t.insert(data);
	}
	void swap(set<K>& s)
	{
		_t.swap(s._t);
	}
	void clear()const
	{
		_t.clear();
	}
	iterator find(const K& key)
	{
		return _t.find(key);
	}

private:
	RBT _t;
};

void testSet()
{
	set<string> s;
	s.insert("8");
	s.insert("2");
	s.insert("3");
	s.insert("4");
	s.insert("6");
	s.insert("5");
	s.insert("7");
	s.insert("1");

	cout << s.size() << endl;
	cout << s.empty() << endl;

	for(auto e : s)
		cout << e << " ";
	cout << endl;

	auto ret = s.insert("apple");
	if (ret.second)
		cout << "apple is in set" << endl;
	else
		cout << "apple is not in set" << endl;
}