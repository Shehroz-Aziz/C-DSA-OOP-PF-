#include<iostream>
using namespace std;
template <class T>
class stack
{
private:
	int size, top, capacity, first; //A new first named data member used for traversal of our array
	T* arr;
	bool flipped;
public:
	stack(int lenght)
	{
		arr = new T[lenght];
		first = 0;
		top = -1;
		capacity = lenght;
		size = 0;
		flipped = false;
	}
	bool push(const T& data)
	{
		if (!isfull())
		{
			if (flipped) //Pushing opposite as top and first exchanged positions
			{
				if (top == 0)
					top = capacity;
				arr[--top] = data;
				size++;				
				return true;
			}
			else
			{
				if (top == capacity-1)
					top = -1;
				arr[++top] = data;
				size++;
				return true;
			}
		}
		else
		{
			cout << "Stack Overflow !! Doubling Size" << endl;   // if its circular then we have 4 different scenaios while increasing its size
			int i, j;
			T* temp = new T[capacity * 2];
			if (flipped)
			{
				if (top > first)
				{
					i = capacity - 1;
					j = (capacity * 2) - 1;
					do
					{
						temp[j] = arr[i];
						i--;
						j--;
					} while (i > first);
					top = j;
					i = 0;
					j = 0;
					do
					{
						temp[i] = arr[i];
						i++;
						j++;
					} while (i <= first);
				}
				else
				{
					i = capacity - 1;
					j = (capacity * 2) - 1;
					do
					{
						if (i == first)
							first = j;
						temp[j] = arr[i];
						i--;
						j--;
					}while (i>=top);
					top = j + 1;
				}
			}
			else if(!flipped)
			{
				if (first > top)
				{
					i = capacity - 1;
					j = (capacity * 2) - 1;
					do
					{
						temp[j] = arr[i];
						i--;
						j--;
					} while (i > top);
					first = j;
					i = 0;
					j = 0;
					do
					{
						temp[i] = arr[i];
						i++;
						j++;
					} while (i <= top);
				}
				else
				{
					i = 0;
					j = 0;
					do
					{
						if (i == first)
							first = j;
						temp[j] = arr[i];
						i++;
						j++;
					} while (i <= top);
					top = j - 1;
				}
			}
			arr = temp;
			capacity = capacity * 2;
			push(data);
		}
	}
	void display()
	{
		if (!flipped)
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
		else
		{
			int i = first;
			if (!isempty())
			{
				do
				{
					if (i == -1)	//it can be possible as our top is flexible so if it reaches at top then can return to zero index
						i = capacity-1;
					cout << arr[i] << " ";
					i--;
				} while (i != top - 1 );
				cout << endl;
			}
		}
		
	}
	void pop()
	{
		if (size > capacity / 2)
		{
			if (flipped)  //Poping opposite if flipped as first and top changes position
			{
				top++;
				if (top == capacity)
				{
					top = 0;
				}
				size--;
			}
			else
			{
				top--;
				if (top == -1)
				{
					top = capacity - 1;
				}
				size--;
			}
		}
		else
		{
			cout << "Half of stack is empty !! cutting Size" << endl;    // if its circular then we have 4 different scenaios while decreasing its size
			int i, j;
			T* temp = new T[capacity / 2];
			if (flipped)
			{
				if (top > first)
				{
					i = capacity - 1;
					j = (capacity / 2) - 1;
					do
					{
						temp[j] = arr[i];
						i--;
						j--;
					} while (i >= top);
					top = j + 1;
					i = 0;
					j = 0;
					do
					{
						temp[i] = arr[i];
						i++;
						j++;
					} while (i <= first);
				}
				else
				{
					i = capacity - 1;
					j = (capacity / 2) - 1;
					do
					{
						if (i == first)
							first = j;
						temp[j] = arr[i];
						i--;
						j--;
					} while (i >= top);
					top = j + 1;
				}
			}
			else if (!flipped)
			{
				if (first > top)
				{
					i = capacity - 1;
					j = (capacity / 2) - 1;
					do
					{
						temp[j] = arr[i];
						i--;
						j--;
					} while (i >= first);
					first = j + 1 ;
					i = 0;
					j = 0;
					do
					{
						temp[i] = arr[i];
						i++;
						j++;
					} while (i <= top);
				}
				else
				{
					i = 0;
					j = 0;
					do
					{
						if (i == first)
							first = j;
						temp[j] = arr[i];
						i++;
						j++;
					} while (i <= top);
					top = j - 1;
				}
			}
			arr = temp;
			capacity = capacity / 2;
			pop();
		}
		

	}
	void flip()
	{
		swap(top, first);
		flipped = true;
	}
	void unflip()
	{
		swap(first, top);
		flipped = false;
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
	~stack()
	{
		delete[] arr;
	}
};
int main()
{
	stack<int> obj(3);
	for (int i = 0; i < 3; i++)
	{
		obj.push(i);
	}
	obj.display();
	obj.flip();
	obj.display();
	for (int i = 3; i < 6; i++)
	{
		obj.push(i);
	}
	obj.display();
	obj.unflip();
	obj.push(19);
	obj.display();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.pop();
	obj.display();
}