#pragma once
#include <iostream>
#include <string>
#include<iomanip>
#include<fstream>
using namespace std;
class Vehicle
{
	int stoarge_number;
	string colour;
	float power;
	string company;
	int model;
	long int price;
	string model_name;
public:
	Vehicle()
	{
		stoarge_number = 0;
		colour = " ";
		power = 0;
		company = " ";
		model = 0;
		price = 0;
		model_name = " ";
	}
	virtual void set()
	{
		cout << left << setw(50) << "Enter the manufacturing company of vehicle"<<":";
		cin >> company;
		cout << left << setw(50) <<"Enter the Model Name of vehicle" << ":";
		cin >> model_name;
		cout << left << setw(50) << "Enter the colour of vehicle" << ":";
		cin >> colour;
		cout << left << setw(50) << "Enter the Engine size of vehicle in cc" << ":";
		cin >> power;
		while (power < 50 )
		{
			cout << left << setw(50) << "Power of Vehicle Impossible" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> power;
		}
		cout << left << setw(50) << "Enter the model year of vehicle" << ":";
		cin >> model;
		while (model < 1990)
		{
			cout << left << setw(50) << "Exsistance of Vehicle Impossible"<<endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> model;
		}
		cout << left << setw(50) << "Enter the Price of vehicle in PKR" << ":";
		cin >> price;
		while (price < 10000)
		{
			cout << left << setw(50) << "Price of Vehicle Impossible" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> price;
		}
		stoarge_number=storage_sender();
	}
	int storage_sender()
	{
		int b;
		int a=0;
		int c;
		ifstream file;
		file.open("number.txt");
		file >> b >> a >> c;
		file.close();
		a=a+1;
		ofstream file2;
		file2.open("number.txt");
		file2 << b << " " << a << " " << c;
		file2.close();
		return a;
	}
	virtual void abstraction() = 0;
	virtual int get_storage_num()
	{
		return stoarge_number;
	}
	virtual string get_colour()
	{
		return colour;
	}
	virtual float get_power()
	{
		return power;
	}
	virtual string get_company()
	{
		return company;
	}
	virtual int get_model()
	{
		return model;
	}
	virtual int get_price()
	{
		return price;
	}
	virtual string get_model_name()
	{
		return model_name;
	}
	~Vehicle()
	{

	}
};