/// Factory.cpp : Defines the entry point for the console application.
///
/// \file Factory.cpp

#include "stdafx.h"
#include <vector>
using namespace std; 
enum Classes {ID_B=0, ID_D, ID_C};
Classes id;
/// Class A
class A
{
public:
	virtual int print()=0; ///Virtual funciya
	static A* getistance(Classes id);
};

/// Class B - potomok 1
class B: public A
{
	public:
	int print()
	{
		cout<<"This is B "<<endl; /// pereopredelenie Virtualnoj funcii for B
		return 0;
	}
};

/// Class C - potomok 2
class C: public A
{
	public:
	int print()
	{
		cout<<"This is C "<<endl;/// pereopredelenie Virtualnoj funcii for C
		return 0;
	}
};

/// Class D - potomok 3
class D: public A
{
	public:
	int print()
	{
		cout<<"This is D "<<endl; /// pereopredelenie Virtualnoj funcii for D
		return 0;
	}
};

///Perechislenie

A* getistance(Classes id)
{
	A* p;
	switch(id)
	{
	case ID_B:
		p=new B();
		break;
	case ID_D:
		p=new D();
        break;
	case ID_C:
		p=new C();
		break;
	default:
		return NULL;
	}
	return p;
};

/// \fn Glavnaya funciya
int _tmain(int argc, _TCHAR* argv[])
{
	vector<A*> arr;
	char n;
	B b;
	C c;
	D d;
	arr.push_back(&b);
	arr.push_back(&c);
	arr.push_back(&d);
	/*for (int i=0; i<5; i++)
	{cout<<"Enter data (B C or D)"<<endl;
	cin>>n;
	arr.push_back(A::getistance(id));
	}*/
	for (int i=0; i<3; i++)
		arr[i]->print();
	getch();
	return 0;
}

