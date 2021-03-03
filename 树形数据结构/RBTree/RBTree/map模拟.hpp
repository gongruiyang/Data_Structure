#include "RBTree.hpp"

// map 中放置的是 K—V 模型
template<class K, class V>
class map
{
	typedef pair<K, V> ValueType;
	struct KOFP	// 为了方便红黑树中的插入：比较的是K而不是Pair结构体地址
	{
		const K& operator()(const ValueType& data)
		{
			return data.first;
		}
	};

	typedef RBTree<ValueType, KOFP> RBT;
public:
	// iterator可能是红黑树中的类型，也可能是静态成员变量，需要显式说明
	typedef typename RBT::iterator iterator;

	map() :_t(){}

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
	void swap(map<K, V>& m)
	{
		_t.swap(m._t);
	}
	void clear()const
	{
		_t.clear();
	}
	iterator find(const K& key)
	{
		return _t.find(key, V());
	}

	// acess
	V& operator[](const K& key)
	{
		return (*(_t.insert(make_pair(key, V()))).first).second;
	}


private:
	RBT _t;
};

void testMap()
{
	map<string, string> m;
	m.insert(make_pair("8", "橘子"));
	m.insert(make_pair("2", "橘子"));
	m.insert(make_pair("3", "橘子"));
	m.insert(make_pair("4", "橘子"));
	m.insert(make_pair("6", "橘子"));
	m.insert(make_pair("5", "橘子"));
	m.insert(make_pair("7", "橘子"));
	m.insert(make_pair("1", "子"));

	cout << m.size() << endl;
	cout << m.empty() << endl;
	cout << m["1"] << endl;

	auto it_begin = m.begin();
	auto it_end = m.end();
	cout << it_begin->first << "->" << it_begin->second << endl;


	cout << "-------------------" << endl;
	while (it_begin != it_end)
	{
		cout << it_begin->first << "->" << it_begin->second << endl;
		it_begin++;
	}
}
