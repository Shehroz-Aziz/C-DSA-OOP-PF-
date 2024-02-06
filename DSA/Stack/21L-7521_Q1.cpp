#include <iostream>
#include <fstream>
#include <string>
using namespace std;
template<class T>
class Node
{
public:
	T data;
	Node<T>* next;

};
template<class T>
class Stack {
private:
	Node<T>* top;
	int size;
public:
	Stack()
	{
		top = NULL;
		size = 0;
	}
	~Stack()
	{
		Node<T>* current = top;
		while (current != NULL)
		{
			Node<T>* temp = current;
			current = current->next;
			delete temp;
		}
	}
	bool IsEmpty()
	{
		return(top == NULL);
	}
	void push(T data)
	{
		Node<T>* temp = new Node<T>;
		temp->data = data;
		if (top == NULL)
		{
			temp->next = NULL;
			top = temp;
		}
		else
		{
			temp->next = top;
			top = temp;
		}
		size++;
	}
	T pop()
	{

		if (top == NULL)
		{
			return NULL;
		}
		else
		{
			Node<T>* temp = top;
			top = temp->next;
			return temp->data;
			delete temp;
		}
		size--;
	}
	int getsize()
	{
		return size;
	}
	void display()
	{
		if (top != NULL)
		{ 
			Node<T>* temp = top;
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		cout << endl;
	}
};
template<class T>
class XMLdata :private Stack<T>
{
private:
	ifstream file;
	string array;
	Stack<char> s1;
	Stack<char> s2;
	int line;
public:
	XMLdata()
	{
		file.open("data.xml");
		line = 0;
	}
	void header()
	{
		getline(file, array);
		int i = 0;
		while (array[i]!='>')
		{
			s1.push(array[i]);
			i++;
		}
		while (!file.eof())
		{
			while (!s2.IsEmpty())
			{
				s2.pop();
			}
			getline(file, array);
			int i = 0;
			while(array[i] != '<')
			{
				i++;
			}
			while (array[i] != '>' || array[i] != '\n')
			{
				s2.push(array[i]);
			}
			line++;
		}
		if (s2.getsize() + 1 == s1.getsize())
		{
			bool equal = true;
			int i = 0;
			while(i<=s1.getsize())
			{ 
				int i = 1;
				char left, right;
				right = s2.pop();
				if (i == 2 && right == '/')
				{
					continue;
				}
				left = s1.pop();
				if (left != right)
				{
					equal = false;
				}
			}
			if (!equal)
			{
				cout << "Head not closed correctly, line no: " << line << endl;
			}
		}
		else
		{
			cout << "Head not closed correctly, line no: " << line << endl;
		}
	}
	void linetag()
	{
		line = 0;
		while (!file.eof())
		{
			getline(file, array);
			int i = 0;
			while (array[i] != '>')
			{
				s1.push(array[i]);
				i++;
			}
			i = 0;
			while (array[i] != '<')
			{
				i++;
			}
			while (array[i] != '>' || array[i] != '\n')
			{
				s2.push(array[i]);
			}
			line++;
			if (array[i] != '\n')
			{
				cout << "Tag not closed correctly, line no: " << line << endl;
			}
			if (s2.getsize() + 1 == s1.getsize())
			{
				bool equal = true;
				int i = 0;
				while (i <= s1.getsize())
				{
					int i = 1;
					char left, right;
					right = s2.pop();
					if (i == 2 && right == '/')
					{
						continue;
					}
					left = s1.pop();
					if (left != right)
					{
						equal = false;
					}
				}
				if (!equal)
				{
					cout << "Tag not closed correctly, line no: " << line << endl;
				}
			}
			else
			{
				cout << "Tag not closed correctly, line no: " << line << endl;
			}
		}
	}
	void comments()
	{
		bool closed = false;
		line = 0;
		while (!file.eof())
		{
			line++;
			getline(file, array);
			int i = 0;
			while (array[i] != '\n')
			{
				i++;
			}
			if (array[0] == '<' && array[i] == '>')
			{
				if (array[1] == '!' && array[i - 1] == '-')
				{
					if (array[2] == '-' && array[i - 2] == '-')
					{
						if (array[3] == '-')
						{
							closed = true;
						}
					}
				}
			}
			if (!closed)
			{
				cout << "Comment no closed correctly, line no:" << line << endl;
			}
		}
	}
	~XMLdata()
	{
		file.close();
	}
};
int main()
{
	XMLdata<string> d;
	d.header();
	d.comments();
	d.linetag();
	system("pause");
	return 0;
}