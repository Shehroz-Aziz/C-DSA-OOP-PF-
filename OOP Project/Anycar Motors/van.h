#pragma once
#include"Vehicle.h"
class van :public Vehicle
{
	int seats;
	int petrol;
public:
	virtual void set()
	{
		Vehicle::set();
		cout << left << setw(50) << "Enter number seats in van"<<":";
		cin >> seats;
		while (seats < 6)
		{
			cout << left << setw(50) << "Seats of van Impossible (<6)" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> seats;
		}
		cout << "The Van has petrol type engine?" << endl;
		cout << left << setw(50) << "Enter 1 for Petrol ,0 for Diesel"<<":";
		cin >> petrol;
		while (petrol < 0 || petrol > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> petrol;
		}
	}
	virtual void abstraction()
	{

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
	virtual int get_seats()
	{
		return seats;
	}
	virtual bool get_petrol()
	{
		return petrol;
	}
	virtual bool get_local_made()
	{
		return 1;
	}
	virtual bool get_broadrims()
	{
		return 1;
	}
};
class Wagon :public van
{
	int local_made;
	
public:
	virtual void set()
	{
		van::set();
	    cout << "The wagon is locally made?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for NO"<<":";
		cin >> local_made;
		while (local_made < 0 || local_made > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> local_made;
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
	virtual int get_seats()
	{
		return van::get_seats();
	}
	virtual bool get_petrol()
	{
		return van::get_petrol();
	}
	virtual bool get_local_made()
	{
		return local_made;
	}
};
class HIACE :public van
{
	int broadrims;
public:
	virtual void set()
	{
		van::set();
		cout << "The HIACE has broad rims?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes, 0 for No"<<":";
		cin >> broadrims;
		while (broadrims < 0 || broadrims > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> broadrims;
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
		virtual int get_seats()
	{
		return van::get_seats();
	}
	virtual bool get_petrol()
	{
		return van::get_petrol();
	}
	virtual bool get_broadrims()
	{
		return broadrims;
	}
};

