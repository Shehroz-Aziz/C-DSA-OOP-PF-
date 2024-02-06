#pragma once
#include"Vehicle.h"
class truck :public Vehicle
{
    int petrol;
	int loading_capacity;
public:
	truck()
	{
		petrol = false;
	}
	virtual void abstraction()
	{

	}
	virtual void set()
	{
		Vehicle::set();
		cout << "The Jeep has petrol type engine?" << endl;
		cout << left << setw(50) << "Enter 1 for Petrol ,0 for Diesel" << ":";
		cin >> petrol;
		while (petrol < 0 || petrol > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :" ;
			cin >> petrol;
		}
		cout << left << setw(50) << "Enter the loading capacity of truck in kgs"<<":";
		cin >> loading_capacity;
		while (loading_capacity < 1000)
		{
			cout << left << setw(50) << "Load Capacity of Truck Impossible (<1000 kg)" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> loading_capacity;
		}
	}
	virtual int get_loading_capacity()
	{
		return loading_capacity;
	}
		virtual int get_storage_num()
	{
		return 0;
	}
	virtual string get_colour()
	{
		return "hello";
	}
	virtual float get_power()
	{
		return 0.0;
	}
	virtual string get_company()
	{
		return "hello";
	}
	virtual int get_model()
	{
		return 0;
	}
	virtual int get_price()
	{
		return 0;
	}
	virtual string get_model_name()
	{
		return "hello";
	}
	virtual bool get_roofs()
	{
		return 1;
	}
	virtual int get_tyres()
	{
		return 0;
	}
	//virtual int get_tyres()
	//{
	//	return 0;
	//}
};
class Pickup :public truck
{
	int roof;
	int tyres;
public:
	virtual void set()
	{
		truck::set();
		cout << "The Pickup has roof?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes, 0 for No"<<":";
		cin >> roof;
		while (roof < 0 || roof > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> roof;
		}
		cout << left << setw(50) << "Enter number of tyres of Pick up"<<":";
		cin >> tyres;
		while (tyres < 4)
		{
			cout << left << setw(50) << "Tyres of Pickup Impossible (<4)" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> tyres;
		}
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
	virtual int get_loading_capacity()
	{
		return truck::get_loading_capacity();
	}
	virtual bool get_roofs()
	{
		return roof;
	}
	virtual int get_tyres()
	{
		return tyres;
	}
};
class loader :public truck
{
	int tyres;
public:
	virtual void set()
	{
		truck::set();
		cout << left << setw(50) << "Enter the number of tyres of loader"<<":";
		cin >> tyres;
		while (tyres < 4)
		{
			cout << left << setw(50) << "Tyres of Loader Impossible (<4)" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> tyres;
		}
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
	virtual int get_loading_capacity()
	{
		return truck::get_loading_capacity();
	}
	virtual int get_tyres()
	{
		return tyres;
	}
};