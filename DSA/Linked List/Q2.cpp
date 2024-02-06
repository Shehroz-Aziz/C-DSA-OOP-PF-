#include<iostream>
using namespace std;
template <typename T>
struct node
{
	T data;
	node* next;
};
template<class T>
class sortedset
{
private:
	node<T>* head;
	node<T>* tail;
public:
	sortedset()
	{
		head = NULL;
		tail = NULL;
	}
	void indexrotate(int k)
	{
		node<T>* newtail = head;
		k--;
		while (k > 0 && newtail != NULL)
		{
			newtail = newtail->next;
			k--;
		}
		if (newtail != NULL && newtail != head)
		{
			tail->next = head;
			head = newtail->next;
			newtail->next = NULL;
		}

	}
	void insert(T data)
	{
		node<T>* temp = new node<T>;
		node<T>* current, * previous;
		temp->data = data;
		if (head == NULL)
		{
			temp->next = NULL;
			head = temp;
			tail = head;
		}
		else if (head->next == NULL)
		{
			if (data == head->data)
			{
				cout << "Not Possible! Already Exists" << endl;
			}
			if (data > head->data)
			{
				temp->next = NULL;
				tail = temp;
				head->next = tail;
			}
			else
			{
				tail = head;
				tail->next = NULL;
				temp->next = tail;
				head = temp;
			}
		}
		else
		{
			current = head;
			previous = NULL;
			while (current != NULL && current->data < data)
			{
				previous = current;
				current = current->next;
			}
			if (current == NULL)
			{
				temp->next = NULL;
				previous->next = temp;
				tail = temp;
			}
			else if (current != NULL && current->data != data)
			{
				temp->next = current;
				previous->next = temp;
			}
			else
			{
				cout << "Not Possible! Already Exists" << endl;
			}
		}
	}
	void print()
	{
		node<T>* current = head;
		while (current != NULL)
		{
			cout << current->data << " ";
			current = current->next;
		}
	}
	~sortedset()
	{
		head = nullptr;
		tail = nullptr;
	}
};
int main()
{
	int k=0;
	sortedset<int> obj1;
	obj1.insert(10);
	obj1.insert(20);
	obj1.insert(30);
	obj1.insert(40);
	obj1.insert(50);
	obj1.insert(60);
	obj1.insert(70);
	obj1.insert(10); //adding 10 again to check whether it stops to insert or not 
	obj1.print();
	cout << endl;
	cout << "Enter index to rotate: ";
	cin >> k;
	obj1.indexrotate(k);
	obj1.print();
	cout << endl;
	system("pause");
}