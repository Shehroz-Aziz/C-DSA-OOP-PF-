#include<iostream>
#include<string>
using namespace std;
struct Data
{
	int batch;
	float cgpa;
	string fname, lname, dept;
	friend ostream& operator<<(ostream &out, Data &obj)
	{
		out << "Batch:" << obj.batch << endl;
		out << "CGPA:" << obj.cgpa << endl;
		out << "Name:" << obj.fname << " " << obj.lname << endl;
		out << "Department:" << obj.dept << endl;
		return out;
	}
	void change(int year, float gpa, string fisrt, string last, string deptart)
	{
		batch = year;
		cgpa = gpa;
		fname = fisrt;
		lname = last;
		dept = deptart;
	}
};
template<typename K, typename V>
struct Node
{
	K key;
	V value;
	Node<K, V>* left;
	Node<K, V>* right;
	Node<K, V>()
	{
		left = NULL;
		right = NULL;
	}
};
template<typename K, typename V>
class specialBST
{
private:
	Node<K, V>* root;
public:
	specialBST()
	{
		root = NULL;
	}
	bool insert(K key, V value)
	{
		bool found1 = true;
		bool found2;
		if (root == NULL)
		{
			Node<K, V>* newNode = new Node<K, V>;
			newNode->key = key;
			newNode->value = value;
			root = newNode;
			return true;
		}
		else
		{
			insertion(root, key, value, found1);
			root = makeroot(root, key, found2);
			return found1;
		}
	}
	bool insertion(Node<K, V>*& current, K key, V value, bool& inseted)
	{
		if (current == NULL)
		{
			Node<K, V>* newNode = new Node<K, V>;
			newNode->key = key;
			newNode->value = value;
			current = newNode;
		}
		else if (key > current->key)
		{
			insertion(current->right, key, value, inseted);
		}
		else if (key < current->key)
		{
			insertion(current->left, key, value, inseted);
		}
		else if (key == current->key)
		{
			inseted = false;
		}
		return inseted;
	}
	void InOrder()
	{
		InOrder(root);
	}
	void InOrder(Node<K, V>* tempNode)
	{
		if (tempNode != NULL)
		{
			
			InOrder(tempNode->left);
			cout << tempNode->key << endl;
			cout << tempNode->value << endl;
			InOrder(tempNode->right);
		}
	}
	void LevelOrder(int level)
	{
		int templevel = -1;
		LevelOrder(root, level, templevel);
	}
	void LevelOrder(Node<K, V>* tempNode, int level, int templevel)
	{
		templevel++;
		if (tempNode != NULL)
		{
			if (templevel == level)
			cout << tempNode->value << endl;
			LevelOrder(tempNode->left, level, templevel);
			LevelOrder(tempNode->right, level, templevel);
		}
	}
	bool Search(int key)
	{

		bool find = false;
		root = makeroot(root, key, find);
		return find;
	}
	Node<K, V>* rightRotate(Node<K, V>*& newright)
	{
		Node<K, V>* temp = newright->left;
		newright->left = temp->right;
		temp->right = newright;
		return temp;
	}
	Node<K, V>* leftRotate(Node<K, V>*& newleft)
	{
		Node<K, V>* temp = newleft->right;
		newleft->right = temp->left;
		temp->left = newleft;
		return temp;
	}
	Node<K, V>* makeroot(Node<K, V>* temproot, K key, bool& found)
	{
		Node<K, V>* returnnode = NULL;
		if (temproot == NULL)
		{
			return temproot;
		}
		else if (temproot->key == key)
		{
			found = true;
			return temproot;
		}
		if (temproot->key < key)
		{
			if (temproot->right == NULL)
				return temproot;

			if (temproot->right->key < key)
			{
				temproot->right->right = makeroot(temproot->right->right, key, found);
				temproot = leftRotate(temproot);
			}
			else if (temproot->right->key > key)
			{
				temproot->right->left = makeroot(temproot->right->left, key, found);
				if (temproot->right->left)
					temproot->right = rightRotate(temproot->right);
			}
			else
			{
				found = true;
			}
			if (temproot->right)
			{
				temproot = leftRotate(temproot);
			}
			return temproot;
		}
		else
		{
			if (temproot->left == NULL)
				return temproot;
			if (temproot->left->key > key)
			{
				temproot->left->left = makeroot(temproot->left->left, key, found);
				temproot = rightRotate(temproot);  //No need to worry in Zig Zig case as if its NULL in the last it simple becomes left at NULL
			}
			else if (temproot->left->key < key)
			{
				temproot->left->right = makeroot(temproot->left->right, key, found);
				if (temproot->left->right) //if there is NULL then there is no need to rotate as it will break the link between left and parent
					temproot->left = leftRotate(temproot->left);
			}
			else
			{
				found = true;
			}
			if (temproot->left)
			{
				temproot = rightRotate(temproot);
			}
			return temproot;
		}
	}
	bool deleteR(int d)
	{
		bool exists = false;
		root = makeroot(root, d, exists);
		if (exists)
		{
			deleteR(d, root);
			return exists;
		}
		else
		{
			return exists;
		}
	}
	void deleteR(K d, Node<K, V>*& node)
	{
		if (d > node->key)
			deleteR(d, node->right);
		else if (d < node->key)
			deleteR(d, node->left);
		else
			deleteNode(node);
	}
	void deleteNode(Node<K, V>*& node)
	{

		K d;
		Node<K, V>* temp;
		temp = node;
		if (node->left == NULL) {
			node = node->right;
			delete temp;
		}
		else if (node->right == NULL) {
			node = node->left;
			delete temp;
		}
		else
		{
			getPredecessor(node->left, d);
			node->key = d;
			deleteR(d, node->left);
		}
	}
	void getPredecessor(Node<K, V>* node, int& key)
	{
		while (node->right != NULL)
			node = node->right;
		key = node->key;
	}
	void deletion(Node<K, V>* tempNode)
	{
		if (tempNode)
		{
			deletion(tempNode->left);
			deletion(tempNode->right);
			delete tempNode;
		}
	}
	~specialBST()
	{
		deletion(root);
	}
};
class studentlist
{
private:
	specialBST<int, Data> tree;
public:
	bool InsertNewStudent(int rollNumber, string firstName, string lastName, int batch, string department, float cgpa)
	{
		Data obj;
		obj.batch = batch;
		obj.fname = firstName;
		obj.lname = lastName;
		obj.dept = department;
		obj.cgpa = cgpa;
		return tree.insert(rollNumber, obj);
	}
	bool deleteStudent(int rollNumber)
	{
		if (tree.deleteR(rollNumber))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void updateStudent(int oldRollNumber, int newRollNumber, string newFirstName, string newLastName, int newBatch, string newDepartment, float newCgpa)
	{
		if (tree.Search(oldRollNumber))
		{
			if (!tree.Search(newRollNumber))
			{
				tree.deleteR(oldRollNumber);
				InsertNewStudent(newRollNumber, newFirstName, newLastName, newBatch, newDepartment, newCgpa);
			}
			else
			{
				tree.deleteR(oldRollNumber);
				InsertNewStudent(newRollNumber, newFirstName, newLastName, newBatch, newDepartment, newCgpa);
				cout << "Number Already Exists: Changing Other Parameters:" << endl;
			}
		}
		else
		{
			cout << "Number Not Exists" << endl;
		}
	}
	void printAllStudents()
	{
		tree.InOrder();
	}
	bool searching(int roll)
	{
		return tree.Search(roll);
	}
};
int main()
{
	studentlist obj;
	char input;
	int batch, rollno, old;
	string f, l, d;
	float cgpa;
	while (true)
	{
		cout << "Press I to insert a new student" << endl;
		cout << "Press D to delete a student" << endl;
		cout << "Press S to search a student by roll number" << endl;
		cout << "Press U to update the data of a student" << endl;
		cout << "Press P to print all students sorted by roll number" << endl;
		cout << "Press E to exit" << endl;
		cin >> input;
		if (input == 'I' || input == 'i')
		{
			cout << "Enter the Roll no:";
			cin >> rollno;
			while (rollno < 0)
			{
				cout << "Wrong Roll no: Enter Again:";
				cin >> rollno;
			}
			cout << "Enter the Batch no:";
			cin >> batch;
			while (rollno < 1990)
			{
				cout << "Wrong Batch no: Enter Again:";
				cin >> batch;
			}
			cout << "Enter the Department:";
			cin >> d;
			cout << "Enter the First Name:";
			cin >> f;
			cout << "Enter the Last Name:";
			cin >> l;
			cout << "Enter the CGPA:";
			cin >> cgpa;
			if (!obj.InsertNewStudent(rollno, f, l, batch, d, cgpa))
			{
				cout << "Data Against Same Roll no Already Exists so Insertion failed" << endl;
			}
		}
		else if (input == 'D' || input == 'd')
		{
			cout << "Enter Roll No of Student to delete:";
			cin >> rollno;
			if (!obj.deleteStudent(rollno))
			{
				cout << "Not Exists" << endl;
			}
		}
		else if (input == 'S' || input == 's')
		{
			cout << "Enter Roll No of Student to Search:";
			cin >> rollno;
			if(!obj.searching(rollno))
			{
				cout << "Not Found" << endl;
			}
			else
			{
				cout << "Found" << endl;
			}
		}
		else if (input == 'U' || input == 'u')
		{
			cout << "Enter Credentials to update if you want to change parameters against same roll no then Enter same old and new roll no:" << endl;
			cout << "Enter the Old Roll no:";
			cin >> old;
			cout << "Enter the New Roll no:";
			cin >> rollno;
			while (rollno < 0)
			{
				cout << "Wrong Roll no: Enter Again:";
				cin >> rollno;
			}
			cout << "Enter the New Batch no:";
			cin >> batch;
			while (rollno < 1990)
			{
				cout << "Wrong Batch no: Enter Again:";
				cin >> batch;
			}
			cout << "Enter the New Department:";
			cin >> d;
			cout << "Enter the New First Name:";
			cin >> f;
			cout << "Enter the New Last Name:";
			cin >> l;
			cout << "Enter the New CGPA:";
			cin >> cgpa;
			obj.updateStudent(old, rollno, f, l, batch, d, cgpa);
		}
		else if (input == 'P' || input == 'p')
		{
			obj.printAllStudents();
		}
		else if (input == 'E' || input == 'e')
		{
			break;
		}
	}
	system("pause");
}