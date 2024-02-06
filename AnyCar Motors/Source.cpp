//#pragma once
#pragma comment(lib, "winmm.lib")
#include <iostream>
#include <string>
#include<ctime>
#include<time.h>
#include"Vehicle.h"
#include"Car.h"
#include"SHS.h"
#include"Manager.h"
#include<iomanip>
#include<chrono>
#include"Customer.h"
#include<mmsystem.h>
using namespace std;
void clk()
{
	/*char timeline[50];
	time_t tmNow = time(0);
	char* dt = ctime(&tmNow);
	cout << "Current Date/Time: " << dt;*/
	cout << endl;
}
void display()
{
	clk();
	cout << "Please Maximize the console screen " << endl;
	cout << endl<<endl;
	
	PlaySound(TEXT("Welcome.wav"), NULL, SND_SYNC);
	PlaySound(TEXT("Slogan.wav"), NULL, SND_ASYNC);
	cout  << endl << endl << endl << endl << endl ;
	cout << setw(120);
	cout << "!!!!!!! Welcome to Anycar Motors !!!!!"<<endl<<endl<<endl;
	cout << setw(120);
	cout << "!!!!!!! Imagine the Unimaginable !!!!!" << endl << endl << endl;
	cout << setw(122) << "  Enter 1 for Manager Managment System    " << right << setw(53)  <<  "Owners:" << endl;
	cout << setw(122) << "  Enter 2 for Customer Managment System   " << right << setw(58)  <<  "Shehroz Aziz  " << endl;
	cout << setw(122) << "  Enter 0 for Exit                        " << right << setw(58) <<   "Muhammad Saib " << endl;
	cout << right << setw(180) << "Hamza Iftikhar" << endl;
}
int main()
{
	display();
	
	
	int choice = 0;
	int count = 0;
	bool check=false;
	int cont = 1;
	int cont2 = 1;
	cout << "Make Your Choice" << endl;
	/*cout << "Enter 1 for Manager" << endl;
	cout << "Enter 2 for Customer" << endl;*/
	//cout << setw(122) << "Enter 0 for Exit" << endl;
	cout << "Enter :";
	cin >> choice;
	while (choice < 0 || choice >2)
	{
		cout << "Wrong Input, Enter Again :";
		cin >> choice;
	}
	system("pause");
	system("cls");
	management man;
	customer cus;
	if (choice == 1)
	{
		check = man.ologin();
		while (!check)
		{
			cout << "--------------Try Again--------------" << endl;
			check = man.ologin();
		}
		cout << "Hello Mr. Manager !!" << endl;
		while (cont)
		{
			cout << "Enter 1 to add data to database" << endl;
			cout << "Enter 2 to get data to delete  " << endl;
			cout << "Enter 3 to view database		" << endl;
			cout << "Enter 4 to show Total Count with Total Price" << endl;
			cout << "Enter 0 to Exit" << endl;
			cout << "Make Your Choice :				";
			cin >> choice;
			while (choice < 0 || choice > 4)
			{
				cout << "Wrong Input, Enter Again :";
				cin >> choice;
			}
			if (choice == 1)
			{
				man.data_add();
				cout << "Vehicle Added Successfully" << endl;
				system("pause");
				system("cls");
			}
			else if (choice == 2)
			{
				man.delete_dat();
				system("pause");
				system("cls");
			}
			else if (choice == 3)
			{
				man.show();
				system("pause");
				system("cls");
			}
			else if (choice == 4)
			{
				cout << "We Have " << man.get_count() << " vehicles of worth " << man.get_price() << "\\- Rs." << endl;
				system("pause");
				system("cls");
			}
			else
			{
				cout << setw(120);
				cout << "-------- Bye!!!! Mr. Manager --------" << endl;
				system("pause");
				system("cls");
				cont = false;
			}
		}
	}
	else if (choice == 2)
	{
		while (cont2)
		{
			cout << "Enter 1 to Show Database" << endl;
			cout << "Enter 0 to Exit" << endl;
			cout << "Make Your Choice :				";
			cin >> choice;
			while (choice < 0 || choice > 1)
			{
				cout << "Wrong Input, Enter Again :";
				cin >> choice;
			}
			if (choice==1)
			{
				cout << setw(120);
				cout << "--------Thank You for visiting here------" << endl;
				cout << setw(120);
				cout << "---Press any key to visit our Showroom---" << endl;
				system("pause");
				system("cls");
				cus.show();
				system("pause");
				system("cls");
			}
			else if (choice==0)
			{
				cout << "Have a nice day!!! GOODBYE :)" << endl;
				cont2 = false;
				system("pause");
			}
		}
	}
	else
	{
		system("pause");
	}
	system("cls");
	PlaySound(TEXT("Thank.wav"), NULL, SND_SYNC);
	cout << setw(120) << "\n\n----Anycar Motors Signing off :(-----\n\n\n\n\n\n\n";
	return 0;
}