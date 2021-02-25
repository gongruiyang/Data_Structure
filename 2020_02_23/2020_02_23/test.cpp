#include <iostream>
#include <mutex>
using namespace std;

class Singleton1
{
private:
	Singleton1(){}
	static Singleton1* instance;
public:
	static Singleton1*& Insance()
	{
		return instance;
	}
};
Singleton1* Singleton1::instance = new Singleton1();

#if 0
class Singleton1
{
private:
	Singleton1(){}
	static Singleton1* instance;
public:
	static Singleton1*& Insance()
	{
		if (instance == nullptr)
			instance = new Singleton1();
		return instance;
	}
};
Singleton1* Singleton1::instance = nullptr;
#endif
#if 0
mutex g_lock;
class Singleton
{
private:
	Singleton(){}
	static Singleton* instance;
public:
	static Singleton*& Insance()
	{
		g_lock.lock();
		if (instance == nullptr)
			instance = new Singleton();
		g_lock.unlock();

		return instance;
	}
};
Singleton* Singleton::instance = nullptr;
#endif
#if 0
mutex g_lock;
class Singleton
{
private:
	Singleton(){}
	static Singleton* instance;
public:
	static Singleton*& Insance()
	{
		if (instance == nullptr)
		{
			g_lock.lock();

			if (instance == nullptr)
				instance = new Singleton();

			g_lock.unlock();
		}

		return instance;
	}
};
Singleton* Singleton::instance = nullptr;
#endif

int main()
{
	Singleton* instance = Singleton::Insance();
	cout << instance << endl;
	instance = Singleton::Insance();
	cout << instance << endl;
	system("pause");
	return 0;
}