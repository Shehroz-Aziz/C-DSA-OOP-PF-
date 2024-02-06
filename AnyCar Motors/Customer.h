#pragma once
#include<iostream>
#include"SHS.h"
using namespace std;
class customer
{
private:
	SHS obj;
public:
	void show()
	{
		cout << "\n\n\n\nWe have Total " << obj.return_count() << " vehicles" << endl;
		cout << obj;
		obj.askpurchasing();
	}

};
