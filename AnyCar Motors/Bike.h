#pragma once
#include"Vehicle.h"
class bike :public Vehicle
{
	int gears;
	int self_start;
public:
	bike()
	{
		gears = 0;
		self_start=0;
	}
	virtual void set()
	{
		Vehicle::set();
		cout << left << setw(50) << "Enter the gears of bike"<<":";
		cin >> gears;
		while (gears < 4 || gears >6)
		{
			cout << left << setw(50) << "Gears of bike Impossible (<4 || >6)" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> gears;
		}
		cout << "The bike is self start?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No"<<":";
		cin >> self_start;
		while (self_start < 0 || self_start > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> self_start;
		}
	}
	virtual void abstraction()
	{

	}
	virtual int get_gears()
	{
		return gears;
	}
	virtual bool get_self_start()
	{
		return self_start;
	}
	virtual int get_storage_num()
	{
		return Vehicle::get_storage_num();
	}
	virtual string get_colour()
	{
		return Vehicle::get_colour();
	}
	virtual float get_power()
	{
		return Vehicle::get_power();
	}
	virtual string get_company()
	{
		return Vehicle::get_company();
	}
	virtual int get_model()
	{
		return Vehicle::get_model();
	}
	virtual int get_price()
	{
		return Vehicle::get_price();
	}
	virtual string get_model_name()
	{
		return Vehicle::get_model_name();
	}
};