#pragma once
#pragma comment(lib, "winmm.lib")
#include"SHS.h"
#include<iostream>
#include<Windows.h>
using namespace std;
class management
{
private:
	SHS obj;
	unsigned long long int opassword;
	int count;
public:
	management()
	{
		count = 0;
		ifstream f;
		f.open("passwords.txt");
		f >> opassword;
		if(opassword<0 || opassword>9999)
		{
			ofstream faf;
			opassword=0;
			faf.open("passwords.txt");
			faf << opassword;
			faf.close();
		}
		f.close();
	}
	void data_add()
	{
		obj.addData();
		
	}
	void delete_dat()
	{
		obj.show_data();
		obj.Deleting();
		
	}
	void show()
	{
		cout << obj;
	}
	int get_count()
	{
		return obj.return_count();
	}
	long long int get_price()
	{
		return obj.return_price();
	}
	bool setpassword()
	{
		if (opassword == 0)
		{
			cout << "Set Your 4-Digit Pin" << endl;
			cin >> opassword;
			while(opassword<=1000 || opassword>=9999)
			{
				cout << "Wrong Input, Enter Again :";
				cin >> opassword;
			}
			ofstream f;
			f.open("passwords.txt");
			f << opassword;
			f.close();
			return true;
		}
		return false;
	}
	bool ologin()
	{
		unsigned long long int pass = 0;
		bool check=setpassword();
		if (!check)
		{
			cout << "Enter Your Login Pin, Beware You only have 3 attempts" << endl;
			cout << "Enter Your Pin	:";
			cin >> pass;
			if (pass == opassword)
			{
				return true;
			}
		}
		else
		{
			cout << "Enter Your Recent Set Pin , Beware You only have 3 attempts" << endl;
			cout << "Enter Your Pin	:";
			cin >> pass;
			if (pass == opassword)
			{
				return true;
			}
		}
		count++;
		if (count > 2)
		{
			cout << "!!!!!!!!!!!!!!!!!!!!!!!Security Breach!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
			cout << " Close Console Screen immidiately " << endl;
			system("color 74");
			while (1)
			{
				PlaySound(TEXT("Siren.wav"), NULL, SND_SYNC);
			}
			
			return false;
			
		}
		
		else
			return false;

	}
	
};