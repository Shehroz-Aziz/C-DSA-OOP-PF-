#pragma once
#include "Vehicle.h"
class Car :public Vehicle
{
	int fourwheel;
public:
	virtual void set()
	{
		Vehicle::set();
		cout << "The car is four wheel drive?"<<endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No" << ":";
		cin >> fourwheel;
		while (fourwheel < 0 || fourwheel > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> fourwheel;
		}
	}
	virtual void abstraction()
	{

	}
	virtual bool get_fourwheel()
	{
		return fourwheel;
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
	/*	virtual bool get_automtic()
	{
		return 1;
	}*/
	virtual bool get_local_made()
	{
		return 0;
	}
	virtual bool get_trunk()
	{
		return 0;
	}
	virtual bool get_roof()
	{
		return 1;
	}
	virtual bool get_extrasuspension()
	{
		return 1;
	}
	/*virtual bool get_petrol()
	{
		return 0;
	}*/
	/*virtual int get_seats()
	{
		return 0;
	}*/
	virtual bool get_automatic()
	{
		return 1;
	}
	/*virtual bool get_local_made()
	{
		return 1;
	}*/
	virtual bool get_petrol()
	{
		return 1;
	}
	virtual int get_seats()
	{
		return 0;
	}
	/*virtual bool get_automatic()
	{
		return 1;
	}*/
	virtual bool get_electric()
	{
		return 1;
	}

	~Car()
	{
		//Destructor
	}
};
class hashback :public Car
{
	int automatic;
	int local_made;
	int trunk;
public:
	virtual void set()
	{
		Car::set();
		cout << "The Hatch Back is automatic transmission?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No" << ":";
		cin >> automatic;
		while (automatic < 0 || automatic > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> automatic;
		}
		cout << "The hatch back is locally made?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No" << ":";
		cin >> local_made;
		while (local_made < 0 || local_made > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> local_made;
		}
		cout << "The hatch back has trunk?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No" << ":";
		cin >> trunk;
		while (trunk < 0 || trunk > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> trunk;
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
	virtual bool get_fourwheel()
	{
		return Car::get_fourwheel();
	}
	virtual bool get_automtic()
	{
		return automatic;
	}
	virtual bool get_local_made()
	{
		return local_made;
	}
	virtual bool get_trunk()
	{
		return trunk;
	}
};
class jeep :public Car
{
	int roof;
	int extrasuspension;
	int petrol;
public:
	virtual void set()
	{
		Car::set();
		cout << "The jeep has roof?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes , 0 or No" << ":";
		cin >> roof;
		while (roof < 0 || roof > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> roof;
		}
		cout << "The jeep has extra suspension?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes , 0 or No" << ":";
		cin >> extrasuspension;
		while (extrasuspension < 0 || extrasuspension > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> extrasuspension;
		}
		cout << "The Jeep has petrol type engine?" << endl;
		cout << left << setw(50) << "Enter 1 for Petrol ,0 for Diesel" << ":";
		cin >> petrol;
		while (petrol < 0 || petrol > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> petrol;
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
	virtual bool get_fourwheel()
	{
		return Car::get_fourwheel();
	}
	virtual bool get_roof()
	{
		return roof;
	}
	virtual bool get_extrasuspension()
	{
		return extrasuspension;
	}
	virtual bool get_petrol()
	{
		return petrol;
	}
};
class Sedan :public Car
{
	int seat_number;
	bool automatic;
	bool local_made;
	bool petrol;
public:
	virtual void set()
	{
		Car::set();
		cout << left << setw(50) << "Enter Number of seats in Sedan" << ":";
		cin >> seat_number;
		while (seat_number < 2)
		{
			cout << left << setw(50) << "Seats of Sedan Impossible (<2)" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> seat_number;
		}
		cout << "The sedan is automatic transmission?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No" << ":";
		cin >> automatic;
		while (automatic < 0 || automatic > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> automatic;
		}
		cout << "The sedan is locally manufactured?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No" << ":";
		cin >> local_made;
		while (local_made < 0 || local_made > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> local_made;
		}
		cout << "The sedan has petrol type engine?" << endl;
		cout << left << setw(50) << "Enter 1 for Petrol ,0 for Diesel" << ":";
		cin >> petrol;
		while (petrol < 0 || petrol > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> petrol;
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
	virtual bool get_fourwheel()
	{
		return Car::get_fourwheel();
	}
	virtual int get_seats()
	{
		return seat_number;
	}
	virtual bool get_automatic()
	{
		return automatic;
	}
	virtual bool get_local_made()
	{
		return local_made;
	}
	virtual bool get_petrol()
	{
		return petrol;
	}
	~Sedan()
	{
		//Destructor
	}
};
class SUV :public Car
{
	int seats;
	bool automatic;
	bool electric;
public:
	virtual void set()
	{
		Car::set();
		cout << left << setw(50) << "Enter Number of seats in SUV" << ":";
		cin >> seats;
		while (seats < 4)
		{
			cout << left << setw(50) << "Seats of SUV Impossible (<4)" << endl;
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :";
			cin >> seats;
		}
		cout << "The SUV is automatic transmission?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No"<<":";
		cin >> automatic;
		while (automatic < 0 || automatic > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> automatic;
		}
		cout << "The SUV is Electrically powered?" << endl;
		cout << left << setw(50) << "Enter 1 for Yes ,0 for No"<<":";
		cin >> electric;
		while (electric < 0 || electric > 1)
		{
			cout << left << setw(50) << "Wrong input ,Enter Again !!! :"; 
			cin >> electric;
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
	virtual bool get_fourwheel()
	{
		return Car::get_fourwheel();
	}
	virtual int get_seats()
	{
		return seats;
	}
	virtual bool get_automatic()
	{
		return automatic;
	}
	virtual bool get_electric()
	{
		return electric;
	}
};
