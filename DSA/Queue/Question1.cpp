#pragma comment(lib, "winmm.lib")
#include<iostream>
#include"graphics.h"
using namespace std;
template<typename T>
struct node
{
	T data;
	node* nxt;
};
template<typename T>
class queue
{
private:
	node<T>* front;
	node<T>* rare;
	int size;
public:
	queue()
	{
		front = NULL;
		rare = NULL;
		size = 0;
	}
	bool isempty()
	{
		return(size == 0);
	}
	void push(T value)
	{
		node<T>* temp = new node<T>;
		temp->data = value;
		temp->nxt = NULL;
		if (isempty())
		{
			front = temp;
			rare = temp;
			size++;
		}
		else
		{
			rare->nxt = temp;
			rare = temp;
			size++;
		}
	}
	void pop()
	{
		node<T>* temp = new node<T>;
		temp = front;
		if (!isempty())
		{
			front = front->nxt;
			size--;
			delete temp;
		}
	}
	int sizee()
	{
		return size;
	}
	T fronte()
	{
		return front->data;
	}
	void display()
	{
		node<T>* temp = front;
		if (!isempty())
		{
			do
			{
				cout << temp->data << " ";
				temp = temp->nxt;
			} while (temp != NULL);
		}
		cout << endl;
	}
};
void makered(int value)
{
	int y = 27 + value / 20 * 50;
	int x = 27 + (value % 20) * 55;  //Find point of circle to make it red
	setfillstyle(SOLID_FILL, RED);
	floodfill(x, y, BLUE);
}
void printcircles(int total, bool* flags)
{
	int x, y;
	int line = 0;
	setcolor(BLUE);					//blue circle

	y = 27;
	int countinline = 0;
	for (int i = 0; i < total; i++)
	{
		if (countinline >= 20)		//if circle count exceeds 20 then jmp to next line 
		{
			y = y + 52;
			line++;
			countinline = 0;
		}
		x = 27 + (i - 20 * line) * 55;
		circle(x, y, 25);
		countinline++;
		if(flags[i]==true)			//if bool exceuted in true then make it red
			makered(i);

	}
	setfillstyle(SOLID_FILL, WHITE);
	floodfill(0, 0, BLUE);
}
int main()
{
	queue<string>obj;
	int gd = DETECT, gm;
	int soliders;
	int value = 3;
	string str;
	cout << "Enter the number of soliders" << endl;
	cin >> soliders;
	for (int i = 0; i < soliders; i++)
	{
		cout << "Enter the name :";
		cin >> str;
		obj.push(str);
	}
	obj.display();
	cout << "Enter the number of jump to kill: ";
	cin >> value;
	int count = 0;
	bool* executed = new bool[soliders];
	for (int l = 0; l < soliders; l++)
	{
		executed[l] = false;			//making all alive !executed
	}
	int i = 0;
	while (obj.sizee() > 1)
	{
		if (i == soliders)
			i = 0;
		if (count == value - 1)								//Pop then push untill got the required jump 
		{
			cout << obj.fronte() << " is executed" << endl;
			count = 0;
			executed[i] = true;
			i++;
			PlaySound(TEXT("guncock.wav"), NULL, SND_SYNC);  //Voice of gun
			initgraph(&gd, &gm, "");
			initwindow(1112, 404);
			printcircles(soliders, executed);				//making circles 
			PlaySound(TEXT("gunshot.wav"), NULL, SND_ASYNC);
			getch();
			closegraph();
		}
		else
		{
			obj.push(obj.fronte());
			count++;
			i++;
		}
		obj.pop();
	}
	cout << obj.fronte() << " is freed" << endl;
	system("pause");
}
