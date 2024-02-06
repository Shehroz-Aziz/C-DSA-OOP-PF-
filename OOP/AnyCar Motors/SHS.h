#pragma once
#pragma comment(lib,"winmm.lib")
//#include"Manager.h"
//#include<mmsystem.h>
#include<Windows.h>
#include <iostream>
#include <fstream>
#include <string>
#include "Vehicle.h"
#include"Car.h"
#include"Bike.h"
#include"van.h"
#include"truck.h"
#include<iomanip>
#include<ctime>
using namespace std;
class SHS
{
	Car** c;
	bike** b;
	van** v;
	truck** t;
	int total;
	long long int storage;
public:
	void addprice(long int price)
	{
		storage;
		int b;
		int a = 0;
		ifstream file;
		file.open("number.txt");
		file >> b >> a >> storage;
		if (storage < 0)
		{
			storage = 0;
		}
		if (b < 0)
		{
			b = 0;
		}
		file.close();
		storage = storage + price;
		b = b + 1;
		ofstream file2;
		file2.open("number.txt");
		file2 << b << " " << a << " " << storage;
		file2.close();
	}
	void cutprice(long int price)
	{
		storage ;
		int b;
		int a = 0;
		ifstream file;
		file.open("number.txt");
		file >> b >> a >> storage;
		if (storage < 0)
		{
			storage = 0;
		}
		if (b < 0)
		{
			b = 0;
		}
		file.close();
		storage = storage - price;
		b = b - 1;
		ofstream file2;
		file2.open("number.txt");
		file2 << b << " " << a << " " << storage;
		file2.close();
	}
	int return_count()
	{
		int b = 0;
		int a = 0;
		total = 0;
		ifstream file;
		file.open("number.txt");
		file >> total >> a >> b;
		file.close();
		return total;
	}
	long long int return_price()
	{
		int b = 0;
		int a = 0;
		storage = 0;
		ifstream file;
		file.open("number.txt");
		file >> b >> a >> storage;
		file.close();
		return storage;
	}
	SHS()
	{
		int a=0;
		int b = 0;
		ofstream file;
		file.open("sedan.txt", ios::app);
		file.close();
		file.open("Hatch_back.txt", ios::app);
		file.close();
		file.open("Jeep.txt", ios::app);
		file.close();
		file.open("SUV.txt", ios::app);
		file.close();
		file.open("Bike.txt", ios::app);
		file.close();
		file.open("Wagon.txt", ios::app);
		file.close();
		file.open("hiace.txt", ios::app);
		file.close();
		file.open("Loader.txt", ios::app);
		file.close();
		file.open("pickup.txt", ios::app);
		file.close();
		file.open("number.txt", ios::app);
		file.close();
	}
	void sedan1(Car* p)
	{
		string r = "Sedan";
		int a = p->get_storage_num();
		string b = p->get_colour();
		float c = p->get_power();
		string e = p->get_company();
		int f = p->get_model();
		long int g = p->get_price();
		string h = p->get_model_name();
		string i;
		if (p->get_fourwheel())
		{
			i = "Yes";
		}
		else
		{
			i = "No";
		}
		int j = p->get_seats();
		string k;
		if (p->get_automatic())
		{
			k = "Automatic";
		}
		else
		{
			k = "Manual";
		}
		string l;
		if (p->get_local_made())
		{
			l = "Local-Made";
		}
		else
		{
			l = "Impoted";
		}
		string m;
		if (p->get_petrol())
		{
			m = "Petrol";
		}
		else
		{
			m = "Diesel";
		}
		ofstream S1;
		S1.open("sedan.txt", ios::app);
		S1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << setw(13) << m << "\n";
		S1.close();
		addprice(g);

	}
	void hashback1(Car *p)
	{
		    string r="Hatch-back";
		    int a=p->get_storage_num();
			string b=p->get_colour();
			float c=p->get_power();
			string e=p->get_company();
			int f=p->get_model();
			long int g=p->get_price();
			string h=p->get_model_name();
			//bool i=p->get_fourwheel();
			string i;
			if (p->get_fourwheel())
			{
				i = "Yes";
			}
			else
			{
				i = "No";
			}
			//bool j=p->get_automatic();
			string j;
			if (p->get_automatic())
			{
				j = "Automatic";
			}
			else
			{
				j = "Manual";
			}
			//bool k=p->get_local_made();
			string k;
			if (p->get_local_made())
			{
				k = "Local-Made";
			}
			else
			{
				k = "Impoted";
			}
			//bool l=p->get_trunk();
			string l;
			if (p->get_trunk())
			{
				l = "Yes";
			}
			else
			{
				l = "No";
			}
			ofstream S1;
			S1.open("Hatch_back.txt",ios::app);

			S1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " <<  "\n";
			/*S1 << a << "\t" << b << "\t" << c << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\t" << k << "\t" << l <<  "\n"  ;*/
			S1.close();
			addprice(g);
	}
	void jeep1(Car*p)
	{
		    string r="Jeep";
		    int a=p->get_storage_num();
			string b=p->get_colour();
			float c=p->get_power();
			string e=p->get_company();
			int f=p->get_model();
			long int g=p->get_price();
			string h=p->get_model_name();
			//bool i=p->get_fourwheel();
			string i;
			if (p->get_fourwheel())
			{
				i = "Yes";
			}
			else
			{
				i = "No";
			}
			//bool j=p->get_roof();
			string j;
			if (p->get_roof())
			{
				j = "Yes";
			}
			else
			{
				j = "No";
			}
			//bool k=p->get_extrasuspension();
			string k;
			if (p->get_extrasuspension())
			{
				k = "Yes";
			}
			else
			{
				k = "No";
			}
			//bool l=p->get_petrol();
			string l;
			if (p->get_petrol())
			{
				l = "Petrol";
			}
			else
			{
				l = "Diesel";
			}
			ofstream S1;
			S1.open("Jeep.txt",ios::app);

			S1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " "  << "\n";
			//S1 << a << "\t" << b << "\t" << c << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\t" << k << "\t" << l  << "\n"  ;
			S1.close();
			addprice(g);
	}
	void SUV1(Car *p)
	{
		    string r="SUV"; 
		    int a=p->get_storage_num();
			string b=p->get_colour();
			float c=p->get_power();
			string e=p->get_company();
			int f=p->get_model();
			long int g=p->get_price();
			string h=p->get_model_name();
			//bool i=p->get_fourwheel();
			string i;
			if (p->get_fourwheel())
			{
				i = "Yes";
			}
			else
			{
				i = "No";
			}
			int j=p->get_seats();
			//bool k=p->get_automatic();
			string k;
			if (p->get_automatic())
			{
				k = "Automatic";
			}
			else
			{
				k = "Manual";
			}
			//bool l=p->get_electric();
			string l;
			if (p->get_electric())
			{
				l = "Yes";
			}
			else
			{
				l = "No";
			}
			ofstream S1;
			S1.open("SUV.txt",ios::app);
		    S1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " <<  "\n";
			//S1 << a << "\t" << b << "\t" << c << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\t" << k << "\t" << l  << "\n"  ;
			S1.close();
			addprice(g);
	}
	void Bike(bike* p)
	{
		int a = p->get_storage_num();
		string b = p->get_colour();
		float c = p->get_power();
		string e = p->get_company();
		int f = p->get_model();
		long int g = p->get_price();
		string h = p->get_model_name();
		int i = p->get_gears();
		//bool j = p->get_self_start();
		string j;
		if (p->get_self_start())
		{
			j = "Yes";
		}
		else
		{
			j = "No";
		}
		ofstream B1;
		B1.open("Bike.txt", ios::app);

		B1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << "\n";
		//B1 << a << "\t" << b << "\t" << c << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\n";
		B1.close();
		addprice(g);
	}
	void wagon(van* p)
	{
		int a = p->get_storage_num();
		string b = p->get_colour();
		float c = p->get_power();
		string e = p->get_company();
		int f = p->get_model();
		long int g = p->get_price();
		string h = p->get_model_name();
		int i = p->get_seats();
		//bool j = p->get_petrol();
		string j;
		if (p->get_petrol())
		{
			j = "Petrol";
		}
		else
		{
			j = "Diesel";
		}
		//bool k = p->get_local_made();
		string k;
		if (p->get_local_made())
		{
			k = "Local-Made";
		}
		else
		{
			k = "Impoted";
		}

		ofstream V1;
		V1.open("Wagon.txt", ios::app);
		V1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";
		//V1 << a << "\t" << b << "\t" << c << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\t" << k << "\n";
		V1.close();
		addprice(g);
	}
	void hiace(van* p)
	{

		int a = p->get_storage_num();
		string b = p->get_colour();
		float c = p->get_power();
		string e = p->get_company();
		int f = p->get_model();
		long int g = p->get_price();
		string h = p->get_model_name();
		int i = p->get_seats();
		//bool j = p->get_petrol();
		string j;
		if (p->get_petrol())
		{
			j = "Petrol";
		}
		else
		{
			j = "Diesel";
		}
		//bool k = p->get_broadrims();
		string k;
		if (p->get_broadrims())
		{
			k = "Yes";
		}
		else
		{
			k = "No";
		}
		ofstream h1;
		h1.open("hiace.txt", ios::app);
		h1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";
		//h1 << a << "\t" << b << "\t" << c << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\t" << k << "\n";
		h1.close();
		addprice(g);
	}
	void Loader(truck* p)
	{

		int a = p->get_storage_num();
		string b = p->get_colour();
		float c = p->get_power();
		string e = p->get_company();
		int f = p->get_model();
		long int g = p->get_price();
		string h = p->get_model_name();
		int i = p->get_loading_capacity();
		int j = p->get_tyres();
		ofstream l1;
		l1.open("Loader.txt", ios::app);
		l1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";
		//l1 << a << "\t" << b << "\t" << c << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\n";
		l1.close();
		addprice(g);
	}
	void pickup(truck* p)
	{
		int a = p->get_storage_num();
		string b = p->get_colour();
		float c = p->get_power();
		string e = p->get_company();
		int f = p->get_model();
		long int g = p->get_price();
		string h = p->get_model_name();
		int i = p->get_loading_capacity();
		//bool j = p->get_roofs();
		string j;
		if (p->get_roofs())
		{
			j = "Yes";
		}
		else
		{
			j = "No";
		}
		int k = p->get_tyres();
		ofstream p1;
		p1.open("pickup.txt", ios::app);
		p1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j <<  "\n";
		//p1 << a << "\t" << b << "\t" << c << "\t" << e << "\t" << f << "\t" << g << "\t" << h << "\t" << i << "\t" << j << "\n";
		p1.close();
		addprice(g);

	}
	void show_data()
	{
		int decision = -1;
		bool cont = true;
		while (cont != false)
		{
			cout << "Enter 1 to show all Vehicles" << endl;
			cout << "Enter 2 to show Cars" << endl;
			cout << "Enter 3 to show Bikes" << endl;
			cout << "Enter 4 to show Mini Trucks" << endl;
			cout << "Enter 5 to show Vans" << endl;
			cout << "Enter 0 to Exit" << endl;
			cin >> decision;
			while (decision < 0 || decision>5)
			{
				cout << "Wrong input ,Enter Again !!!" << endl;
				cin >> decision;
			}
			if (decision == 1)
			{
				string h;
				ifstream file;
				cout << "----Car-----" << endl;
				cout << "---Sedan-----" << endl;
				file.open("sedan.txt");
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  Product       Fuel_type    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
				cout << "---Jeep-----" << endl;
				file.open("jeep.txt");
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Roof          X_Suspension  Product       Fuel_type    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				
				//cout << "Storage_no.\tColour\tEngine\tCompany\tModel\tPrice (Rs.)\tName\tFour_Wheel_Drive\tRoof\tX_Suspension\tFuel_type" << endl << endl;
				//cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
				cout << "---Hatch-Back-----" << endl;
				file.open("Hatch_back.txt");
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Transmission  Product       Trunk        " << endl << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

				//cout << "Storage_no.\tColour\tEngine\tCompany\tModel\tPrice (Rs.)\tName\tFour_Wheel_Drive\tTransmission\tProduct\tTrunk" << endl << endl;
				//cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
				cout << "---SUV-----" << endl;
				file.open("SUV.txt");
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  E-Powered     " << endl << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

				//cout << "Storage_no.\tColour\tEngine\tCompany\tModel\tPrice (Rs.)\tName\tFour_Wheel_Drive\tSeats\tTransmission\tE-Powered" << endl << endl;
				//cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
				cout << "----Bike-----"<<endl;
				
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Gears        Self_Start    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				file.open("Bike.txt");
				//cout << "Storage_no.\tColour\tEngine\tCompany\tModel\tPrice (Rs.)\tName\tGears\tSelf_Start" << endl << endl;
				//cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
				cout << "---------Mini-Trucks---------"<<endl;
				cout << "----Loader----"<<endl;
				file.open("Loader.txt");
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Capacity(kgs) Tyres         " << endl << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

				//cout << "Storage_no.\tColour\tEngine\tCompany\tModel\tPrice (Rs.)\tName\tLoad-Capacity (kgs.)\tTyres" << endl << endl;
				//cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
				cout << "-----Pickup-----"<<endl;
				file.open("pickup.txt");
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Capacity(kgs)  Roof          Tyres         " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				//cout << "Storage_no.\tColour\tEngine\tCompany\tModel\tPrice (Rs.)\tName\tLoad-Capacity (kgs.)\tRoof\tTyres" << endl << endl;
				//cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
				cout << "----Vans-----"<<endl;
				cout << "---Wagon----" << endl;
				file.open("Wagon.txt");
				//cout << "Storage_no.\tColour\tEngine\tCompany\tModel\tPrice (Rs.)\tName\tSeats\tFuel_Type\tProduct" << endl << endl;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Product       " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

				//cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
				cout << "----HIACE-----"<<endl;
				file.open("hiace.txt");
				//cout << "Storage_no.\tColour\tEngine\tCompany\tModel\tPrice (Rs.)\tName\tSeats\tFuel_Type\tBroad_Rims" << endl << endl;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Broad_Rims    " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

				//cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				while (getline(file, h))
				{
					cout << h << endl;
				}
				file.close();
			}
			else if (decision == 2)
			{
				cout << "Enter 1 to Show all Cars" << endl;
				cout << "Enter 2 to Show all Sedans cars" << endl;
				cout << "Enter 3 to Show all Jeeps cars" << endl;
				cout << "Enter 4 to Show all Hatch-back cars" << endl;
				cout << "Enter 5 to Show all SUV cars" << endl;
				cout << "Enter 0 to Go Back" << endl;
				cin >> decision;
				while (decision < 0 || decision>5)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					string h;
					ifstream file;
					cout << "---Sedan-----" << endl;
					file.open("sedan.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  Product       Fuel_type    " << endl << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
					cout << "---Jeep-----" << endl;
					file.open("jeep.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Roof          X_Suspension  Product       Fuel_type    " << endl << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
					cout << "---Hatch-Back-----" << endl;
					file.open("Hatch_back.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Transmission  Product       Trunk        " << endl << endl;
					cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
					cout << "---SUV-----" << endl;
					file.open("SUV.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  E-Powered     " << endl << endl;
					cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
					

				}
				else if (decision == 2)
				{
					string h;
					ifstream file;
					file.open("sedan.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  Product       Fuel_type    " << endl << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 3)
				{
					string h;
					ifstream file;
					file.open("jeep.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Roof          X_Suspension  Product       Fuel_type    " << endl << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 4)
				{
					string h;
					ifstream file;
					file.open("Hatch_back.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Transmission  Product       Trunk        " << endl << endl;
					cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 5)
				{
					string h;
					ifstream file;
					file.open("SUV.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  E-Powered     " << endl << endl;
					cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 3)
			{
				cout << "Enter 1 to Show all Bike" << endl;
				cout << "Enter 0 to Go Back" << endl;
				cin >> decision;
				while (decision < 0 || decision>1)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					string h;
					ifstream file;
					file.open("Bike.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Gears        Self_Start    " << endl << endl;
					cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 4)
			{
				cout << "Enter 1 to Show all Mini Trucks" << endl;
				cout << "Enter 2 to Show Pick-Up trucks" << endl;
				cout << "Enter 3 to Show Loader trucks" << endl;
				cout << "Enter 0 to Go Back" << endl;
				cin >> decision;
				while (decision < 0 || decision>3)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					cout << "----Loader----"<<endl;
					string h;
					ifstream file;
					file.open("Loader.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Load-Capacity Tyres         " << endl << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
					cout << "-----Pickup-----"<<endl;
					file.open("pickup.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Load-Capacity Roof          Tyres         " << endl << endl;
					cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();

				}
				else if (decision == 2)
				{
					string h;
					ifstream file;
					file.open("pickup.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Load-Capacity Roof          Tyres         " << endl << endl;
					cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 3)
				{
					string h;
					ifstream file;
					file.open("Loader.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Load-Capacity Tyres         " << endl << endl;
					cout << "------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 5)
			{
				cout << "Enter 1 to Show all Vans" << endl;
				cout << "Enter 2 to Show Wagons" << endl;
				cout << "Enter 3 to Show HIACE vans" << endl;
				cout << "Enter 0 to Go Back" << endl;
				cin >> decision;
				while (decision < 0 || decision>3)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					string h;
					ifstream file;
					cout << "---Wagon----"<<endl;
					file.open("Wagon.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Product      " << endl << endl;
					cout << "-------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
					cout << "----HIACE-----" << endl;					
					file.open("hiace.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Broad_Rims    " << endl << endl;
					cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 2)
				{
					string h;
					ifstream file;
					file.open("Wagon.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Product       " << endl << endl;
					cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 3)
				{
					string h;
					ifstream file;
					file.open("hiace.txt");
					cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Broad_Rims    " << endl << endl;
					cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
					while (getline(file, h))
					{
						cout << h << endl;
					}
					file.close();
				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 0)
			{
				break;
			}
			cont = false;
		}
		
	}
	void addData()
	{
		c = new Car * [4];
		b = new bike * [1];
		v = new van * [2];
		t = new truck * [2];
		int decision = -1;
		int cont = 1;
		while (cont != 0)
		{
			cout << "Choose The Type of Vehicle that you want to enter" << endl;
			cout << "Enter 1 for Car" << endl;
			cout << "Enter 2 for Bike" << endl;
			cout << "Enter 3 for Van" << endl;
			cout << "Enter 4 for Mini Truck" << endl;
			cout << "Enter 0 for Exit" << endl;
			cin >> decision;
			while (decision < 0 || decision>4)
			{
				cout << "Wrong input ,Enter Again !!!" << endl;
				cin >> decision;
			}
			if (decision == 1)
			{
				cout << "Choose The Type of Car that you want to enter" << endl;
				cout << "Enter 1 for Sedan" << endl;
				cout << "Enter 2 for Hatch Back" << endl;
				cout << "Enter 3 for Jeep" << endl;
				cout << "Enter 4 for SUV" << endl;
				cout << "Enter 0 for Go back" << endl;
				cin >> decision;
				while (decision < 0 || decision>4)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					c[0] = new Sedan;
					c[0]->set();
					sedan1(c[0]);
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);

				}
				else if (decision == 2)
				{
					c[3] = new hashback;
					c[3]->set();
					hashback1(c[3]);
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);

				}
				else if (decision == 3)
				{
					c[1] = new jeep;
					c[1]->set();
					jeep1(c[1]);
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);

				}
				else if (decision == 4)
				{
					c[2] = new SUV;
					c[2]->set();
					
					SUV1(c[2]);
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);

				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 2)
			{
				cout << "Enter 1 to Enter data" << endl;
				cout << "Enter 0 to Go Back	" << endl;
				cin >> decision;
				while (decision < 0 || decision>1)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					b[0] = new bike;
					b[0]->set();
					Bike(b[0]);
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);

				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 3)
			{
				cout << "Choose The Type of Van that you want to enter" << endl;
				cout << "Enter 1 for Wagon" << endl;
				cout << "Enter 2 for HIACE" << endl;
				cout << "Enter 0 for Go back" << endl;
				cin >> decision;
				while (decision < 0 || decision>2)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					v[0] = new Wagon;
					v[0]->set();
					wagon(v[0]);
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);

				}
				else if (decision == 2)
				{
					v[1] = new HIACE;
					v[1]->set();
					hiace(v[1]);
					
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);

				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 4)
			{
				cout << "Choose The Type of Mini Truck that you want to enter" << endl;
				cout << "Enter 1 for Loader" << endl;
				cout << "Enter 2 for Pickup" << endl;
				cout << "Enter 0 for Go back" << endl;
				cin >> decision;
				while (decision < 0 || decision>2)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					t[0] = new loader;
					t[0]->set();
					
					Loader(t[0]);
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);

				}
				else if (decision == 2)
				{
					t[1] = new Pickup;
					t[1]->set();
					pickup(t[1]);
					PlaySound(TEXT("Add.wav"), NULL, SND_SYNC);
					
				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 0)
			{	
				break;
			}
			cout << "Do you want to Enter More!!!!!" << endl;
			cout << "Enter 1 for Yes, 0 for No		:";
			cin >> cont;
			while (cont < 0 || cont > 1)
			{
				cout << "Wrong input ,Enter Again !!!" << endl;
				cin >> cont;
			}
		}
	}
	void askpurchasing()
	{
		int cont2 = 1;
		cout << "Do you want to buy any Vehicle?" << endl;
		cout << "Enter 1 for Yes, 0 for No :";
		cin >> cont2;
		while (cont2 < 0 || cont2 > 1)
		{
			cout << "Wrong input ,Enter Again !!!" << endl;
			cin >> cont2;
		}
		if (cont2 == 1)
		{
			Purchasing();
			system("pause");
			system("cls");
		}
	}
	friend ostream &operator << (ostream &out, const SHS& obj)
	{
		SHS obj1;
		int cont=1;
		int decision = -1;
		while (cont)
		{
			cout << "Enter 1 to show with type of vehicles	" << endl;
			cout << "Enter 2 to show with Model Year and Price Range " << endl;
			cout << "Enter 0 to Exit " << endl;
			cin >> decision;
			while (decision < 0 || decision>2)
			{
				cout << "Wrong input ,Enter Again !!!" << endl;
				cin >> decision;
			}
			if (decision == 1)
			{
				obj1.show_data();
			}
			else if (decision == 2)
			{
				obj1.search();
			}
			else if (decision == 0)
			{
				break;
			}
			cout << "Do yo want to search more?"<<endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			while (cont < 0 || cont > 1)
			{
				cout << "Wrong input ,Enter Again !!!" << endl;
				cin >> cont;
			}
		}
		return out;
	}
	void search()
	{
		int upper = 0;
		int lower = 0;
		int model = 0;
		int decision = -1;
		bool cont = true;
		while (cont)
		{
			bool check = false;
			cout << "Enter 1 to search by Model Year" << endl;
			cout << "Enter 2 to search by Price Range" << endl;
			cout << "Enter 0 to Exit" << endl;
			cin >> decision;
			while (decision < 0 || decision>2)
			{
				cout << "Wrong input ,Enter Again !!!" << endl;
				cin >> decision;
			}
			if (decision == 1)
			{
				
				cout << "Enter 1 to search from Cars" << endl;
				cout << "Enter 2 to search from Bikes" << endl;
				cout << "Enter 3 to search from Vans" << endl;
				cout << "Enter 4 to search from Mini Trucks" << endl;
				cout << "Enter 0 to Go Back" << endl;
				cin >> decision;
				while (decision < 0 || decision>4)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				cout << "Enter the Model Year :";
				cin >> model;
				while (model<1990)
				{
					cout << "Existance Impossible " << endl;
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				if (decision == 1)
				{
					sedanbyyear(model,check);
					hatchbackbyyear(model, check);
					Jeepbyyear(model, check);
					//SUVbyyear(model, check);
					if (!check)
					{
						cout << "Sorry !! No car is available against this Model Year"<<endl;
					}
				}
				else if (decision == 2)
				{
					bikebyyear(model, check);
					if (!check)
					{
						cout << "Sorry !! No bike is available against this Model Year" << endl;
					}
				}
				else if (decision == 3)
				{
					HIACEbyyear(model, check);
					wagonbyyear(model, check);
					if (!check)
					{
						cout << "Sorry !! No van is available against this Model Year" << endl;
					}
				}
				else if (decision == 4)
				{
					loaderbyyear(model, check);
					pickupbyyear(model, check);
					if (!check)
					{
						cout << "Sorry !! No mini truck is available against this Model Year" << endl;
					}
				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 2)
			{
				
				cout << "Enter 1 to search from Cars" << endl;
				cout << "Enter 2 to search from Bikes" << endl;
				cout << "Enter 3 to search from Vans" << endl;
				cout << "Enter 4 to search from Mini Trucks" << endl;
				cout << "Enter 0 to Go Back" << endl;
				cin >> decision;
				while (decision < 0 || decision>4)
				{
					cout << "Wrong input ,Enter Again !!!" << endl;
					cin >> decision;
				}
				cout << "Enter the Lower Price Limit :";
				cin >> lower;
				cout << "Enter the Upper Price Limit :";
				cin >> upper;
				while (lower > upper)
				{
					cout << "Upper Price should >= Lower Price" << endl;
					cout << "Wrong input ,Enter Again !!!" << endl;
					cout << "Enter the Lower Price Limit :";
					cin >> lower;
					cout << "Enter the Upper Price Limit :";
					cin >> upper;
				}
				if (decision == 1)
				{
					sedanbyrange(upper, lower, check);
					hatchbackbyrange(upper, lower, check);
					Jeepbyrange(upper, lower, check);
					SUVbyrange(upper,lower, check);
					if (!check)
					{
						cout << "Sorry !! No car is available against this Price Range" << endl;
					}
				}
				else if (decision == 2)
				{
					bikebyrange(upper, lower, check);
					if (!check)
					{
						cout << "Sorry !! No bike is available against this Price Range" << endl;
					}
				}
				else if (decision == 3)
				{
					HIACEbyrange(upper, lower, check);
					wagonbyrange(upper, lower, check);
					if (!check)
					{
						cout << "Sorry !! No van is available against this Price Range" << endl;
					}
				}
				else if (decision == 4)
				{
					loaderbyrange(upper, lower, check);
					pickupbyrange(upper, lower, check);
					if (!check)
					{
						cout << "Sorry !! No mini truck is available against this Price Range" << endl;
					}
				}
				else if (decision == 0)
				{
					continue;
				}
			}
			else if (decision == 0)
			{
				break;
			}
			cont = false;
		}
	}
	void sedanbyno(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j = 0;
		string k;
		string l;
		string m;
		ifstream file;
		file.open("sedan.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		while (!file.eof())
		{
			
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  Product       Fuel_type    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << setw(13) << m << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k << l << m;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		}
		file.close();
	}
	void sedanbyyear(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j = 0;
		string k;
		string l;
		string m;
		ifstream file;
		file.open("sedan.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		while (!file.eof())
		{
			
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  Product       Fuel_type    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << setw(13) << m << "\n";
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		}
		file.close();
	}
	void sedanbyrange(int z, int y, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j = 0;
		string k;
		string l;
		string m;
		ifstream file;
		file.open("sedan.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		while (!file.eof())
		{
			
			if (g <=z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  Product       Fuel_type    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << setw(13) << m << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k << l << m;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		}
		file.close();
	}
	void hatchbackbyno(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		ifstream file1;
		file1.open("Hatch_back.txt");
		file1 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file1.eof())
		{
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Transmission  Product       Trunk        " << endl << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k << l;

			}
			file1 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file1.close();
	}
	void hatchbackbyyear(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		ifstream file1;
		file1.open("Hatch_back.txt");
		file1 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file1.eof())
		{
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Transmission  Product       Trunk        " << endl << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

			}
			file1 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file1.close();
	}
	void hatchbackbyrange(int z, int y, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		ifstream file1;
		file1.open("Hatch_back.txt");
		file1 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file1.eof())
		{
			if (g <= z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Transmission  Product       Trunk        " << endl << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k << l;

			}
			file1 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file1.close();
	}
	void Jeepbyno(int z, bool& check)
	{

		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		ifstream file2;
		file2.open("jeep.txt");
		file2 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file2.eof())
		{
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Roof          X_Suspension  Product       Fuel_type    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k << l;
			}
			file2 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file2.close();
	}
	void Jeepbyyear(int z, bool& check)
	{

		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		ifstream file2;
		file2.open("jeep.txt");
		file2 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file2.eof())
		{
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Roof          X_Suspension  Product       Fuel_type    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";
			}
			file2 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file2.close();
	}
	void Jeepbyrange(int z, int y, bool& check)
	{

		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		ifstream file2;
		file2.open("jeep.txt");
		file2 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file2.eof())
		{
			if (g <= z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Roof          X_Suspension  Product       Fuel_type    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k << l;
			}
			file2 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file2.close();
	}
	void SUVbyno(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j=0;
		string k;
		string l;
		ifstream file3;
		file3.open("SUV.txt");
		file3 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file3.eof())
		{
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  E-Powered     " << endl << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k << l;
			}
			file3 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file3.close();
	}
	void SUVbyyear(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j=0;
		string k;
		string l;
		ifstream file3;
		file3.open("SUV.txt");
		file3 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file3.eof())
		{
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  E-Powered     " << endl << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";
			}
			file3 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file3.close();
	}
	void SUVbyrange(int z, int y, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j=0;
		string k;
		string l;
		ifstream file3;
		file3.open("SUV.txt");
		file3 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file3.eof())
		{
			if (g <= z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          4Wheel_Drive  Seats         Transmission  E-Powered     " << endl << endl;
				cout << "----------------------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k << l;
			}
			file3 >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file3.close();
	}
	void bikebyno(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		ifstream file;
		file.open("Bike.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Gears        Self_Start    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << "\n";

				//cout << a << b << c << e << f << g << h << i << j;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		file.close();
	}
	void bikebyyear(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		ifstream file;
		file.open("Bike.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Gears        Self_Start    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << "\n";
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		file.close();
	}
	void bikebyrange(int z, int y, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		ifstream file;
		file.open("Bike.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (g <= z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Gears        Self_Start    " << endl << endl;
				cout << "-----------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << "\n";

				//cout << a << b << c << e << f << g << h << i << j;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		file.close();
	}
	void HIACEbyno(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		ifstream file;
		file.open("hiace.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Broad_Rims    " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();

	}
	void HIACEbyyear(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		ifstream file;
		file.open("hiace.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Broad_Rims    " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();

	}
	void HIACEbyrange(int z, int y, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		ifstream file;
		file.open("hiace.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (g <= z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Broad_Rims    " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();

	}
	void wagonbyno(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		ifstream file;
		file.open("Wagon.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Product       " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
	}
	void wagonbyyear(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		ifstream file;
		file.open("Wagon.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Product       " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
	}
	void wagonbyrange(int z, int y, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		ifstream file;
		file.open("Wagon.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (g <= z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Seats         Fuel_Type     Product       " << endl << endl;
				cout << "--------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
	}
	void loaderbyno(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		int j = 0;
		ifstream file;
		file.open("Loader.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Capacity(kgs) Tyres         " << endl << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";

				//cout << a << b << c << e << f << g << h << i << j;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		file.close();
	}
	void loaderbyyear(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		int j = 0;
		ifstream file;
		file.open("Loader.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Capacity(kgs) Tyres         " << endl << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		file.close();
	}
	void loaderbyrange(int z,  int y, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		int j = 0;
		ifstream file;
		file.open("Loader.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (g <= z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Capacity(kgs) Tyres         " << endl << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";

				//cout << a << b << c << e << f << g << h << i << j;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		file.close();
	}
	void pickupbyno(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		int k = 0;
		ifstream file;
		file.open("pickup.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (z == a)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Capacity(kgs)  Roof          Tyres         " << endl << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
	}
	void pickupbyyear(int z, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		int k = 0;
		ifstream file;
		file.open("pickup.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (z == f)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Capacity(kgs)  Roof          Tyres         " << endl << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
	}
	void pickupbyrange(int z,int y, bool& check)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		int k = 0;
		ifstream file;
		file.open("pickup.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (g <= z && g >= y)
			{
				check = true;
				cout << "Storage_no.   Colour        Engine        Company       Model         Price (Rs.)   Name          Capacity(kgs)  Roof          Tyres         " << endl << endl;
				cout << "---------------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
				cout << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";

				//cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
	}
	void SearchSedan()
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j = 0;
		string k;
		string l;
		string m;

		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find Sedan by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("sedan.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j << k << l << m;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		}
		if (Check == false)
		{
			cout << endl << "No such sedan " << endl;
		}
		file.close();
		cout << "\nEnter the Model year to find Sedan by storage no. \n";
		cin >> C;
		file.open("sedan.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j << k << l << m;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		}
		file.close();



	}
	void SearchHashback()
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;

		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find Hashback by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("Hatch_back.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j << k << l;

			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		if (Check == false)
		{
			cout << endl << "No such Hashback " << endl;
		}
		file.close();
		cout << "\nEnter the Model year to find hashback by storage no. \n";
		cin >> C;
		file.open("Hatch_back.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j << k << l;

			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		if (Check1 == false)
		{
			cout << endl << "No such Hashback " << endl;
		}
		file.close();
	}
	void SearchJeep()
	{

		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find Jeep by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("jeep.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j << k << l;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}

		file.close();
		cout << "\nEnter the Model year to find Jeep by storage no. \n";
		cin >> C;
		file.open("jeep.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j << k << l;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file.close();
		


	}
	void SearchSUV()
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j = 0;
		string k;
		string l;
		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find SUV by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("SUV.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j << k << l;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		if (Check == false)
		{
			cout << endl << "No such SUV " << endl;
		}
		file.close();
		cout << "\nEnter the Model year to find SUV by storage no. \n";
		cin >> C;
		file.open("SUV.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j << k << l;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		if (Check1 == false)
		{
			cout << endl << "No such SUV " << endl;
		}
		file.close();


	}
	void SearchBike()
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find Bike by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("Bike.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		if (Check == false)
		{
			cout << endl << "No such Bike " << endl;
		}
		file.close();
		cout << "\nEnter the Model year to find Bike by storage no. \n";
		cin >> C;
		file.open("Bike.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		if (Check1 == false)
		{
			cout << endl << "No such Bike " << endl;
		}
		file.close();


	}
	void SearchWagon()
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find Wagon by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("Wagon.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		if (Check == false)
		{
			cout << endl << "No such Wagon " << endl;
		}
		file.close();
		cout << "\nEnter the Model year to find Wagon by storage no. \n";
		cin >> C;
		file.open("Wagon.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		if (Check1 == false)
		{
			cout << endl << "No such Wagon " << endl;
		}
		file.close();
	}
	void SearchHiace()
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find Hiace by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("hiace.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		if (Check == false)
		{
			cout << endl << "No such Hiace " << endl;
		}
		file.close();
		cout << "\nEnter the Model year to find Hiace by storage no. \n";
		cin >> C;
		file.open("hiace.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		if (Check1 == false)
		{
			cout << endl << "No such Hiace " << endl;
		}
		file.close();
	}
	void SearchLoader()
	{

		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		int j = 0;
		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find Loader by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("Loader.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		if (Check == false)
		{
			cout << endl << "No such Loader " << endl;
		}
		file.close();
		cout << "\nEnter the Model year to find Loader by storage no. \n";
		cin >> C;
		file.open("Loader.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		if (Check1 == false)
		{
			cout << endl << "No such Loader " << endl;
		}
		file.close();
	}
	void SearchPickup()
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		int k = 0;
		bool Check = false;
		bool Check1 = false;
		int C;
		cout << "\nEnter the serial no. to find Pickup by storage no. \n";
		cin >> C;
		ifstream file;
		file.open("pickup.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C == a)
			{
				Check = true;
				cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		if (Check == false)
		{
			cout << endl << "No such Pickup " << endl;
		}
		file.close();
		cout << "\nEnter the Model yaer to find Pickup by storage no. \n";
		cin >> C;
		file.open("pickup.txt");
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C == f)
			{
				Check1 = true;
				cout << a << b << c << e << f << g << h << i << j << k;
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		if (Check1 == false)
		{
			cout << endl << "No such Pickup " << endl;
		}
		file.close();
	}
	void Purchasing()
	{
		int st;
		bool cont=false;
		bool c1 = false;
		bool c2 = false;
		bool c3 = false;
		bool c4 = false;
		bool c5 = false;
		bool c6 = false;
		bool c7 = false;
		bool c8 = false;
		bool c9 = false;

		cout << "Enter the Unique Storage Number of vehicle (that you want to buy) "<<endl;
		cin >> st;
		while (st <0)
		{
			cout << "Wrong input ,Enter Again !!!" << endl;
			cin >> st;
		}
		sedanbyno(st,c1);
		hatchbackbyno(st,c2);
		Jeepbyno(st,c3);
		SUVbyno(st,c4);
		bikebyno(st,c5);
		wagonbyno(st,c6);
		HIACEbyno(st,c7);
		loaderbyno(st,c8);
		pickupbyno(st,c9);
		if(c1)
		{
			cout << "Confirm Again that You Want to Buy This Sedan Car"<<endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if(cont)
			{
				RemoveSedan(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);

				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new Sedan Car" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations" << endl;

			}
			
		}
		else if(c2)
		{
			cout << "Confirm Again that You Want to Buy This Hatch Back Car"<<endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveHashback(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);

				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new Hatch Back Car" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations" << endl;

			}
			
		}
		else if(c3)
		{
			
			cout << "Confirm Again that You Want to Buy This Jeep Car"<<endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveJeep(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);

				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new Jeep" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations" << endl;

			}
			
		}
		else if(c4)
		{
			cout << "Confirm Again that You Want to Buy This SUV Car"<<endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveSUV(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);
				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new SUV" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations" << endl;

			}

		}
		else if(c5)
		{
			cout << "Confirm Again that You Want to Buy This Bike" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveBike(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);
				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new Bike" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations and always wear Helmet" << endl;

			}
		
		}
		else if(c6)
		{
			cout << "Confirm Again that You Want to Buy This Wagon Van" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{

				RemoveWagon(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);
				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new Wagon" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations" << endl;

			}

		}
		else if(c7)
		{
			cout << "Confirm Again that You Want to Buy This HIACE Van" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveHiace(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);
				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new HIACE Van" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations" << endl;

			}

		}
		else if(c8)
		{
			cout << "Confirm Again that You Want to Buy This Loader Truck" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveLoader(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);
				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new Loader" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations" << endl;

			}

		}
		else if(c9)
		{
			cout << "Confirm Again that You Want to Buy This Pickup Truck" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemovePickup(st);
				PlaySound(TEXT("Pay.wav"), NULL, SND_SYNC);
				cout << "Pay the above mentioned amount to our dealer" << endl;
				cout << "Congratulations!!!!!! for your new Pickup Truck" << endl;
				cout << "We Request you to follow all the driving Rules and Regulations" << endl;

			}

		}
		else
		{
			int pich;
			cout << "No Vehicle Exists Against this Storage Number "<<endl;
			cout << "Do you want to Enter Again correctly?" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> pich;
			while (pich < 0 || pich > 1)
			{
				cout << "Wrong input ,Enter Again !!!" << endl;
				cin >> pich;
			}
			if (pich)
			{
				Purchasing();
			}
			else
			{

			}
		}


	}
	void Deleting()
	{
		int st;
		bool cont = false;
		bool c1 = false;
		bool c2 = false;
		bool c3 = false;
		bool c4 = false;
		bool c5 = false;
		bool c6 = false;
		bool c7 = false;
		bool c8 = false;
		bool c9 = false;
		cout << "Enter the Unique Storage Number of vehicle (that you want to delete) " << endl;
		cin >> st;
		while (st < 0)
		{
			cout << "Wrong input ,Enter Again !!!" << endl;
			cin >> st;
		}
		sedanbyno(st, c1);
		hatchbackbyno(st, c2);
		Jeepbyno(st, c3);
		SUVbyno(st, c4);
		bikebyno(st, c5);
		wagonbyno(st, c6);
		HIACEbyno(st, c7);
		loaderbyno(st, c8);
		pickupbyno(st, c9);
		if (c1)
		{
			cout << "Confirm Again that You Want to Delete This Sedan Car" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveSedan(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "Sedan Deleted Successfully" << endl;
			}
		}
		else if (c2)
		{
			cout << "Confirm Again that You Want to Delete This Hatch Back Car" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveHashback(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "Hatch Back Deleted Successfully" << endl;
			}
		}
		else if (c3)
		{

			cout << "Confirm Again that You Want to Delete This Jeep Car" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveJeep(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "Jeep Deleted Successfully" << endl;

			}
		}
		else if (c4)
		{
			cout << "Confirm Again that You Want to Delete This SUV Car" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveSUV(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "SUV Deleted Successfully" << endl;

			}
		}
		else if (c5)
		{
			cout << "Confirm Again that You Want to Delete This Bike" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveBike(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "Bike Deleted Successfully" << endl;
			}
		}
		else if (c6)
		{
			cout << "Confirm Again that You Want to Delete This Wagon Van" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveWagon(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "Wagon Deleted Successfully" << endl;

			}
		}
		else if (c7)
		{
			cout << "Confirm Again that You Want to Delete This HIACE Van" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveHiace(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "HIACE Deleted Successfully" << endl;

			}
		}
		else if (c8)
		{
			cout << "Confirm Again that You Want to Delete This Loade Truck" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemoveLoader(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "Loader Deleted Successfully" << endl;

			}
		}
		else if (c9)
		{
			cout << "Confirm Again that You Want to Buy Delete Pickup Truck" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> cont;
			if (cont)
			{
				RemovePickup(st);
				PlaySound(TEXT("Delete.wav"), NULL, SND_SYNC);
				cout << "Pickup Deleted Successfully" << endl;

			}
		}
		else
		{
			int pich;
			cout << "No Vehicle Exists Against this Storage Number " << endl;
			cout << "Do you want to Enter Again correctly?" << endl;
			cout << "Enter 1 for Yes, 0 for No :";
			cin >> pich;
			while (pich < 0 || pich > 1)
			{
				cout << "Wrong input ,Enter Again !!!" << endl;
				cin >> pich;
			}
			if (pich)
			{
				Deleting();
			}
		}
	}
	void RemoveSedan(int C)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j = 0;
		string k;
		string l;
		string m;
		ifstream file;
		ofstream file1;
		file.open("sedan.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		while (!file.eof())
		{
			if (C != a)
			{

				//cout << a << b << c << e << f << g << h << i << j << k << l << m;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << setw(13) << m << "\n";
				//file1 << a << b << c << e << f << g << h << i << j << k << l << m << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l >> m;
		}
		file.close();
		file1.close();
		remove("sedan.txt");
		rename("temp.txt","sedan.txt");

	}
	void RemoveHashback(int C)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		ifstream file;
		ofstream file1;
		file.open("Hatch_back.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C != a)
			{
				//cout << a << b << c << e << f << h << i << j << k << l;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//file1 << a << b << c << e << f << h << i << j << k << l << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file.close();
		file1.close();
		remove("Hatch_back.txt");
		rename("temp.txt","Hatch_back.txt");

	}
	void RemoveJeep(int C)
	{

		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		string j;
		string k;
		string l;
		ifstream file;
		ofstream file1;
		file.open("jeep.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C != a)
			{
				//cout << a << b << c << e << f << h << i << j << k << l;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//file1 << a << b << c << e << f << h << i << j << k << l << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file.close();
		file1.close();
		remove("jeep.txt");
		rename("temp.txt","jeep.txt");

	}
	void RemoveSUV(int C)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		string i;
		int j = 0;
		string k;
		string l;
		ifstream file;
		ofstream file1;
		file.open("SUV.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		while (!file.eof())
		{
			if (C != a)
			{
				//cout << a << b << c << e << f << h << i << j << k << l;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << " " << setw(13) << l << " " << "\n";

				//file1 << a << b << c << e << f << h << i << j << k << l << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k >> l;
		}
		file.close();
		file1.close();
		remove("SUV.txt");
		rename("temp.txt","SUV.txt");

	}
	void RemoveBike(int C)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		ifstream file;
		ofstream file1;
		file.open("Bike.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (C != a)
			{
				//cout << a << b << c << e << f << h << i << j;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << "\n";

				//file1 << a << b << c << e << f << h << i << j << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		file.close();
		file1.close();
		remove("Bike.txt");
		rename("temp.txt","Bike.txt");

	}
	void RemoveWagon(int C)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		ifstream file;
		ofstream file1;
		file.open("Wagon.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C != a)
			{
				//cout << a << b << c << e << f << h << i << j << k;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";

				//file1 << a << b << c << e << f << h << i << j << k << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
		file1.close();
		remove("Wagon.txt");
		rename("temp.txt","Wagon.txt");

	}
	void RemoveHiace(int C)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		string k;
		ifstream file;
		ofstream file1;
		file.open("hiace.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C != a)
			{
				//cout << a << b << c << e << f << h << i << j << k;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << " " << setw(13) << k << "\n";

				//file1 << a << b << c << e << f << h << i << j << k << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
		file1.close();
		remove("hiace.txt");
		rename("temp.txt","hiace.txt");

	}
	void RemoveLoader(int C)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		int j = 0;
		ifstream file;
		ofstream file1;
		file.open("Loader.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		while (!file.eof())
		{
			if (C != a)
			{

				//cout << a << b << c << e << f << h << i << j;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";

				//file1 << a << b << c << e << f << h << i << j << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j;
		}
		file.close();
		file1.close();
		remove("Loader.txt");
		rename("temp.txt","Loader.txt");

	}
	void RemovePickup(int C)
	{
		int a = 0;
		string b;
		float c = 0;
		string e;
		int f = 0;
		long int g = 0;
		string h;
		int i = 0;
		string j;
		int k = 0;
		ifstream file;
		ofstream file1;
		file.open("pickup.txt");
		file1.open("temp.txt", ios::app);
		file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		while (!file.eof())
		{
			if (C != a)
			{
				//cout << a << b << c << e << f << h << i << j << k;
				file1 << left << setw(13) << a << " " << setw(13) << b << " " << setw(13) << c << " " << setw(13) << e << " " << setw(13) << f << " " << setw(13) << g << " " << setw(13) << h << " " << setw(13) << i << " " << setw(13) << j << "\n";

				//file1 << a << b << c << e << f << h << i << j << k << endl;
			}
			else
			{
				cutprice(g);
			}
			file >> a >> b >> c >> e >> f >> g >> h >> i >> j >> k;
		}
		file.close();
		file1.close();
		remove("pickup.txt");
		rename("temp.txt","pickup.txt");
	}
};