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
	void uniadd(T data)
	{
		node<T>* temp = new node<T>;
		temp->data = data;
		if (head == NULL)
		{
			temp->next = NULL;
			this->head = temp;
			tail = head;
			head->next = NULL;
		}
		else if (head->next == NULL)
		{
			tail->next = temp;
			temp->next = NULL;
			tail = temp;
			head->next = tail;
		}
		else
		{
			tail->next = temp;
			temp->next = NULL;
			this->tail = temp;
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
	void del(int index)
	{
		node <T>* current, * previous;
		current = head;
		previous = current;
		int count = 0;
		while (current != NULL && count!=index)
		{
			previous = current;
			current = current->next;
			count++;
		}
		if (current != NULL && count == index)
		{
			if (current == head)
			{
				head = head->next;
			}
			else if (current == tail)
			{
				tail = previous;
			}
			else
			{
				previous->next = current->next;
			}
			delete current;
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
	void uni(sortedset<T>const& otherSet)
	{
		sortedset<T> temp;
		node <T>* current1, * current2;
		current1 = head;
		current2 = otherSet.head;
		while (current1 != NULL && current2 != NULL)
		{
			if (current1->data < current2->data)
			{
				temp.uniadd(current1->data);  //uniadd() is special function just to add data
				current1 = current1->next;	  //insert() function is avoided to maintain time complexity O(n)
			}
			else if (current1->data > current2->data)
			{
				temp.uniadd(current2->data);
				current2 = current2->next;
			}
			else
			{
				temp.uniadd(current1->data);
				current2 = current2->next;
				current1 = current1->next;
			}
		}
		if (current1 == NULL)
		{
			while (current2 != NULL)
			{
				temp.uniadd(current2->data);
				current2 = current2->next;
				
			}
		}
		else 
		{
			while (current1 != NULL)
			{
				temp.uniadd(current1->data);
				current1 = current1->next;
			}
		}
		cout << head->data << " " << tail->data << endl;
		*this = temp;
	}
	~sortedset()
	{
		head = nullptr;
		tail = nullptr;
	}
};
int main()
{
	int key;
	sortedset<int> obj1;
	sortedset<int> obj2;
	obj1.insert(10);
	obj1.insert(5);
	obj1.insert(20);
	obj1.insert(40);
	obj1.insert(30);
	obj1.insert(60);
	obj1.insert(50);
	obj1.insert(70);
	obj1.insert(10); //adding 10 again to check whether it stops to insert or not 
	cout << "Set1: ";
	obj1.print();
	cout << endl;
	obj2.insert(10);
	obj2.insert(15);
	obj2.insert(20);
	obj2.insert(25);
	obj2.insert(30);
	obj2.insert(35);
	obj2.insert(40);
	obj2.insert(10); //adding 10 again to check whether it stops to insert or not 
	cout << "Set2: ";
	obj2.print();
	cout << endl;
	obj1.uni(obj2);
	cout << "Union set is: ";
	obj1.print();
	cout << endl;
	cout << "Enter index from union set to delete: ";
	cin >> key;
	obj1.del(key);
	obj1.print();
	cout << endl;
	system("pause");
}