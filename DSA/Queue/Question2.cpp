#include <iostream>
#include <string>
#include <cstring>
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
template <typename T>
void StrRadixSort(queue<T>obj,int m,int k)  //k and m designated to number of digits and max digit
{
	int n = obj.sizee();
	queue <string> temp;
	queue <string> *radix=new queue<string>[m];   //0 to m Digits of Queues
	int ASCII;
	int tempsize;
	string tempstr;
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < n; j++)
		{
			tempstr = obj.fronte();
			ASCII = tempstr[i];
			radix[ASCII].push(obj.fronte());     //storing ASCII at desired queue 
			obj.pop();
		}
		for (int j = 0; j < m; j++)
		{
			tempsize = radix[j].sizee();	
			for (int l = 0; l < tempsize; l++)	//pushing in order into our temporary queue
			{
				temp.push(radix[j].fronte());
				radix[j].pop();
			}
		}
		for (int i = 0; i < n; i++)
		{
			obj.push(temp.fronte());           //Moving temporary queue into main queue
			temp.pop();
		}
	}
	cout << "After Sort" << endl;
	obj.display();
}
template <typename T>
void RadixSort(queue<T>obj, int m, int k)  //k and m designated to number of digits and max digit
{
	int n = obj.sizee();
	queue <int> temp;
	queue <int>* radix = new queue<int>[m];   //0 to m Digits of Queues
	int tempsize;
	int dividor = 10;
	int digit;
	for (int i = 0; i < k; i++)
	{
		dividor = pow(10, i);                 //Divisor to extrect digit
		for (int j = 0; j < n; j++)
		{
			digit = (obj.fronte() / dividor) % 10;		//Extracting digit
			radix[digit].push(obj.fronte());	//Digit at desired queue
			obj.pop();
		}
		for (int j = 0; j < m; j++)
		{
			tempsize = radix[j].sizee();
			for (int l = 0; l < tempsize; l++)
			{
				temp.push(radix[j].fronte());		//pushing in order in our temporary queue
				radix[j].pop();
			}
		}
		for (int i = 0; i < n; i++)
		{
			obj.push(temp.fronte());				//moving temporary sorted data into permanent queue
			temp.pop();
		}
	}
	cout << "After Sort" << endl;
	obj.display();
}
int main()
{
	queue<int>obj;
	obj.push(103);
	obj.push(365);
	obj.push(140);
	obj.push(707);
	obj.push(371);
	obj.push(710);
	cout << "Before Sort" << endl;
	obj.display();
	RadixSort(obj,8,3);  //8 is the highest integer and 3 is number of digit
	queue<string>obj2;
	obj2.push("ab");
	obj2.push("ac");
	obj2.push("ae");
	obj2.push("ad");
	obj2.push("ah");
	StrRadixSort(obj2, 120, 2);  //120 is maximum acsii of character and 2 is the lenght of it

}