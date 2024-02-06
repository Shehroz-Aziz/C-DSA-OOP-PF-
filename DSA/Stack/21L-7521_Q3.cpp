#include<iostream>
using namespace std;
template <class T>
class stack
{
private:
	int size,top,capacity,first; //A new first data member used for traversal of our array
	T* arr;
	bool overwriting;
public:
	stack(int lenght)
	{
		arr = new T[lenght];
		first = 0;
		top = -1;
		capacity = lenght;
		size = 0;
		overwriting = false;
	}
	bool push(const T &data)
	{	
		if (!istopindex())
		{
			arr[++top] = data;
			size++;
			if (overwriting)  //we are pushing our first locations by this logic to if our starting index pushed till last index then it can be circular and shifed at the zero index
			{
				if (first == capacity - 1)
					first = -1;
				first++;
			}
			return true;
		}
		else
		{
			overwriting = true;		//this check differentiates that stack is working normal aur it can be circular which is forgetting its least known data
			top = -1;
			arr[++top] = data;
			first++;
			return true;
		}
	}
	void display()
	{
		int i = first;
		if (!isempty())
		{
			do
			{
				if (i == capacity)	//it can be possible as our top is flexible so if it reaches at top then can return to zero index
					i = 0;
				cout << arr[i] << " ";
				i++;
			} while (i != top+1);
			cout << endl;
		}
	}
	T pop()
	{
		T temp;
		if (!isempty())
		{
			temp= arr[top];
			arr[top] = NULL;
			top--;
			size--;
			if (overwriting)		//if overwriting then our can reach at zero index so sending it to the upper level
			{
				if (top == -1)
				{
					top = capacity-1;
				}
			}
		}
		return temp;
	}
	bool isfull()
	{
		return(size == capacity);
	}
	bool istopindex()
	{
		return(top == capacity - 1);
	}
	bool isempty()
	{
		return(size == 0);
	}
	bool isstartingindex()
	{
		return(top == first);
	}
	~stack()
	{
		delete[] arr;
	}
};
int main()
{
	stack<int> obj(5);
	for (int i = 0; i < 6; i++)
	{
		obj.push(i);
	}
	obj.display();
	obj.pop();
	obj.pop();
	obj.display();
}