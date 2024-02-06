#include<iostream>
#include<list>
#include<string>
#include<fstream>
#include<iomanip>
#include<set>
using namespace std;
struct node
{
	int no;
	int weight;
	string vertex;
	node()
	{
		no=0;
		weight=0;
		vertex="/0";	
	}	
	friend ostream& operator<<(ostream&out, node& obj)
    {
		out << "(" << obj.no << "(" << obj.vertex << ")" << ","  << obj.weight << ")" << endl;
		return out;	
    }
	void returnvalues(int& number, int& weigh, string& vertexname)
	{
		number = this->no;
		weigh = this->weight;
		vertexname = this->vertex;
		return;
	}
	int returndest()
	{
		return this->no;
	}
};
struct heapnode
{
	int first;
	int last;
	int weight;
	heapnode()
	{
		first = -1;
		last = -1;
		weight = -1;
	}
};
class heap
{
private:
	int total;
	int capacity;
	heapnode* arr;
public:
	heap()
	{
		total = 0;
		capacity = 20;
		arr = new heapnode[capacity];
	}
	heap(int val)
	{
		total = 0;
		capacity =val;
		arr = new heapnode[val];
	}
	void ReheapUp(int root, int bottom)
	{
		int parent;
		if (bottom > root)
		{
			parent = (bottom - 1) / 2;
			if (arr[parent].weight > arr[bottom].weight)
			{
				swap(arr[parent], arr[bottom]);
				ReheapUp(root, parent);
			}
		}
	}
	void ReheapDown(int root, int bottom)
	{
		int minChild, rightChild, leftChild;
		leftChild = 2 * root + 1;
		rightChild = 2 * root + 2;
		if (leftChild <= bottom)
		{
			if (leftChild == bottom)
				minChild = leftChild;
			else {

				if (arr[leftChild].weight >= arr[rightChild].weight)
					minChild = rightChild;
				else
					minChild = leftChild;

			}
			if (arr[root].weight > arr[minChild].weight)
			{
				swap(arr[root], arr[minChild]);
				ReheapDown(minChild, bottom);
			}
		}
	}
	void insert(heapnode obj)
	{
		if (capacity > total)
		{
			arr[total] = obj;
			ReheapUp(0, total);
			total++;
		}
		else
		{
			heapnode* temp = new heapnode[capacity * 2];
			for (int i = 0; i < capacity * 2; i++)
			{
				temp[i] = arr[i];
			}
			arr = temp;
			capacity = capacity * 2;
			insert(obj);
		}
	}
	heapnode deletemin()
	{
		if (total > 0)
		{
			swap(arr[0], arr[total - 1]);
			total--;
			ReheapDown(0, total - 1);
			return arr[total];
		}
		else
		{
			cout << "Heap is empty" << endl;
		}
	}
	heapnode returnmin() { return arr[0]; }
	bool isempty() { return (total == 0); }
	~heap()
	{
		delete[] arr;
	}
};
class graph
{
private:
		int vertices;
		int edges;
		list <node> *mainarr;
		bool *visited;
		string* names;
public:
	graph()
	{
		vertices = 0;
		mainarr = NULL;
		visited = NULL;
		names = NULL;
		edges = 0;
	}
	graph(int value)	
	{
		edges = 0;
		vertices = value;
		mainarr = new list <node> [value];
		names = new string[value];
		visited = new bool [value];
		for(int i=0; i < vertices ; i++)
		{
			visited[i]=false;	
		}
	}	
	void connect(node one, node two)
	{
		mainarr[one.no].push_back(two);
		mainarr[two.no].push_back(one);
	}
	void printlist()
	{
		for (int i = 0; i < vertices; i++)
		{
			for (list<node>::iterator it=mainarr[i].begin();it!=mainarr[i].end();++it)
			{
				if (!visited[it->no])
				{
					cout << i << "(" << names[i] << ")" << "->" << *it << endl;
				}
			}
			visited[i] = true;
		}
		khalikrdeinge();
	}
	void notrequiredprint()
	{
		for (int i = 0; i < vertices; i++)
		{
			cout << i << " " << setw(8) << names[i] << " is adjacent to: ";
			for (node iterator : mainarr[i])
			{
					cout << "|" << iterator.no << ":" << setw(8) << iterator.vertex << "(" << setw(2) << iterator.weight << ")";
			}
			cout << endl;
		}
	}
	void gettingname()
	{
		ifstream file;
		file.open("file.txt");
		int waste;
		int vertex;
		file >> waste;
		for (int i = 0; i < waste; i++)
		{
			file >> vertex;
			file >> names[vertex];
		}
		file.close();
	}
	void populategraph()
	{
		ifstream file;
		file.open("file.txt");
		int waste;
		int vertex;
		file >> waste;
		for (int i = 0; i < waste; i++)
		{
			file >> vertex;
			file >> names[vertex];
		}
		int edgess;
		file >> edgess;
		int start;
		int end;
		int weight;
		for (int a = 0; a < edgess; a++)
		{
			file >> start >> end >> weight;
			this->addedge(start, end, weight);
		}
		file.close();
	}
	void storeinfile()
	{
		fstream file;
		file.open("file.txt");
		file << vertices << endl;
		for (int i = 0; i < vertices; i++)
		{
			file << i << " " << names[i] << endl;
		}
		int temp1, temp2;
		string temp3;
		file << edges << endl;
		for (int i = 0; i < vertices; i++)
		{
			for (node iterator : mainarr[i])
			{
				iterator.returnvalues(temp1, temp2, temp3);
				if (!visited[temp1])
				{
					file << i << " " << temp1 << " " << temp2 << endl;
				}
				visited[i] = true;
			}
		}
		khalikrdeinge();
		file.close();
	}
	void khalikrdeinge()
	{
		for (int i = 0; i < vertices; i++)
		{
			visited[i] = false;
		}
	}
	int getvertice() { return vertices; }
	void addedge(int start,int end,int weight)
	{
		node starting;
		node ending;
		bool check = true;
		for (node iterator : mainarr[start])
		{
			if (iterator.returndest() == end)
			{
				check = false;
				break;
			}
		}
		if (check)
		{
			starting.no = start;
			ending.no = end;
			starting.weight = weight;
			ending.weight = weight;
			starting.vertex = names[start];
			ending.vertex = names[end];
			this->connect(starting, ending);
			edges++;
		}
		else
		{
			cout << "There's already a link here so no connection made!"<<endl;
		}
	}
	bool isthere(string name)
	{
		for (int i = 0; i < vertices; i++)
		{
			if (names[i] == name)
				return true;
		}
		return false;
	}
	void addnewname(string name)
	{
		int i = 0;
		string* namest = new string[vertices];
		while (i < vertices - 1)
		{
			namest[i] = names[i];
			i++;
		}
		namest[i] = name;
		names = namest;
	}
	void prims(graph &temp)
	{
		//graph temp(vertices);
		temp.gettingname();
		heapnode one;
		heapnode two;
		int temp1, temp2;
		string temp3;
		int a = 0;
		bool indserted = false;
		for (int i = 0; i < vertices; i++)
		{
			indserted = false;
			if (!visited[a])
			{
				heap obj;
				for (node iterator : mainarr[a])
				{
					iterator.returnvalues(temp1, temp2, temp3);
					one.first = a;
					one.last = temp1;
					one.weight = temp2;
					if (!visited[one.last])
					{
						obj.insert(one);
						indserted = true;
					}
				}
				visited[a] = true;
				if (indserted)
				{
					two = obj.deletemin();
					a = two.last;
					temp.addedge(two.first, two.last, two.weight);
				}
			}
		}
		for (int i = 0; i < vertices; i++)
		{
			indserted = false;
			if (!visited[i])
			{
				heap obj;
				for (node iterator : mainarr[i])
				{
					iterator.returnvalues(temp1, temp2, temp3);
					one.first = i;
					one.last = temp1;
					one.weight = temp2;
					obj.insert(one);
					indserted = true;
				}
				visited[a] = true;
				if (indserted)
				{
					two = obj.deletemin();
					a = two.last;
					temp.addedge(two.first, two.last, two.weight);
				}
			}
		}
		khalikrdeinge();
	}
	void addvertex()
	{
		string name;
		cout << "Enter the name of new Vertex :";
		cin >> name;
		if (isthere(name))
		{
			while (isthere(name))
			{
				cout << "Wrong input Vertex Aleady Exists :";
				cin >> name;
			}
		}
		list <node>* secondary = new list <node>[vertices + 1];
		this->vertices++;
		addnewname(name);
		for (int i = 0; i < vertices - 1; i++)
		{
			secondary[i] = this->mainarr[i];
		}
		this->mainarr = secondary;
	}
	~graph()
	{
		for (int i = 0; i < vertices; i++)
		{
			mainarr[i].clear();
		}
		delete[] mainarr;
		delete[] names;
	}
};
int vertexno()
{
	ifstream fin;
	fin.open("file.txt");
	int vertices;
	fin >> vertices;
	fin.close();
	return vertices;
}
int main()
{
	graph obj(vertexno());
	
	int value;
	while (true)
	{
		cout << "Enter 1 to Input Graph from file" << endl;
		cout << "Enter 2 to Save Graph in file" << endl;
		cout << "Enter 3 to Add Vertex in Graph" << endl;
		cout << "Enter 4 to Add Edge in Graph" << endl;
		cout << "Enter 5 to Print" << endl;
		cout << "Enter 0 to Exit" << endl;
		cin >> value;
		while (value < 0 && value > 5)
		{
			cout << "Wrong Input! Enter Again :";
			cin >> value;
		}
		if (value == 1)
		{
			obj.populategraph();
			cout << "Done!" << endl;
		}
		else if (value == 2)
		{
			obj.storeinfile();
			cout << "Done!" << endl;
		}
		else if (value == 3)
		{
			obj.addvertex();
		}
		else if (value == 4)
		{
			int start;
			int end;
			int weight;
			cout << "Enter Starting Vertex :";
			cin >> start;
			while (start >= obj.getvertice())
			{
				cout << "Vertex not exists, Enter again:";
				cin >> start;
			}
			cout << "Enter Ending Vertex   :";
			cin >> end;
			while (end >= obj.getvertice())
			{
				cout << "Vertex not exists, Enter again:";
				cin >> end;
			}
			cout << "Enter Weight Between them :";
			cin >> weight;
			obj.addedge(start,end,weight);
		}
		else if(value == 5)
		{
			graph temp(vertexno());
			obj.prims(temp);
			temp.printlist();
		}
		else
		{
			break;
		}
	}
}