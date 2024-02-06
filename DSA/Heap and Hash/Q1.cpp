//#include<iostream>
//#include<iomanip>
//#include<cmath>
//using namespace std;
//class Heap
//{
//private:
//	int **heap;
//	int capacity;
//	int totalitems;
//public:
//	Heap()
//	{
//		heap = NULL;
//		capacity = 0;
//		totalitems = 0;
//	}
//	Heap(int lenght)
//	{
//		heap = new int* [2];
//		heap[0] = new int[lenght];
//		heap[1] = new int[lenght];
//		capacity = lenght;
//		totalitems = 0;
//	}
//	void MinReheapUp(int root, int bottom)
//	{
//		int parent;
//		if (bottom > root)
//		{
//			parent = (bottom - 1) / 2;
//			if (heap[0][parent] > heap[0][bottom])
//			{
//				swap(heap[0][parent], heap[0][bottom]);
//				MinReheapUp(root, parent);
//			}
//		}
//	}
//	void MaxReheapUp(int root, int bottom)
//	{
//		int parent;
//		if (bottom > root)
//		{
//			parent = (bottom - 1) / 2;
//			if (heap[1][parent] <= heap[1][bottom])
//			{
//				swap(heap[1][parent], heap[1][bottom]);
//				MaxReheapUp(root, parent);
//			}
//		}
//	}
//	void MaxReheapDown(int root, int bottom)
//	{
//		int maxChild, rightChild, leftChild;
//		leftChild = 2 * root + 1;
//		rightChild = 2 * root + 2;
//		if (leftChild <= bottom)
//		{
//			if (leftChild == bottom)
//				maxChild = leftChild;
//
//			else
//			{
//				if (heap[1][leftChild] < heap[1][rightChild])
//					maxChild = rightChild;
//				else
//					maxChild = leftChild;
//			}
//			if (heap[1][root] <= heap[1][maxChild])
//			{
//				swap(heap[1][root], heap[1][maxChild]);
//				MaxReheapDown(maxChild, bottom);
//			}
//		}
//	}
//	void MinReheapDown(int root, int bottom)
//	{
//		int minChild, rightChild, leftChild;
//		leftChild = 2 * root + 1;
//		rightChild = 2 * root + 2;
//		if (leftChild <= bottom)
//		{
//			if (leftChild == bottom)
//				minChild = leftChild;
//
//			else 
//			{
//
//				if (heap[0][leftChild] >= heap[0][rightChild])
//					minChild = rightChild;
//				else
//					minChild = leftChild;
//			}
//			if (heap[0][root] > heap[0][minChild]) 
//			{
//				swap(heap[0][root], heap[0][minChild]);
//				MinReheapDown(minChild, bottom);
//			}
//		}
//	}
//	void insert(int value)
//	{
//		if (totalitems >= capacity)
//		{
//			cout << "Not Inserted! Heap Overflow!" << endl;
//			return;
//		}
//		if (totalitems % 2 == 0)
//		{
//			heap[0][(totalitems/2)] = value;
//			int parent = ((totalitems/2) - 1) / 2;
//			if (totalitems > 0)
//			{
//				if (heap[1][parent] < value)
//				{
//					swap(heap[1][parent], heap[0][totalitems / 2]);
//					MaxReheapUp(0, parent);
//				}
//			}
//			MinReheapUp(0, totalitems / 2);
//			totalitems++;
//		}
//		else
//		{
//			if (value >= heap[0][totalitems/2])
//			{
//				heap[1][totalitems/2] = value;
//				MaxReheapUp(0, totalitems/2);
//			}
//			else
//			{
//				heap[1][totalitems/2] = heap[0][totalitems/2];
//				heap[0][totalitems/2] = value;
//				MinReheapUp(0, totalitems / 2);
//				MaxReheapUp(0, totalitems / 2);
//			}
//			totalitems++;
//		}
//	}
//	void returnmin(int &key) { key = heap[0][0]; }
//	void search(int key,bool& found,int& index,int &heapno)
//	{
//		if (totalitems % 2 != 0)
//		{
//			if (heap[0][totalitems / 2] == key)
//			{
//				found = true;
//				index = totalitems / 2;
//				heapno = 0;
//			}
//		}
//		for (int i = 0; i < totalitems / 2 && !found; i++)
//		{
//			if (key == heap[0][i] || key == heap[1][i])
//			{
//				found = true;
//				if (key == heap[0][i])
//					heapno = 0;
//				if (key == heap[1][i])
//					heapno = 1;
//				index = i;
//			}
//		}
//	}
//	int getmin() { return heap[0][0]; }
//	int getmax() { return heap[1][0]; }
//	void balancer()
//	{
//		if (totalitems % 2 == 0)
//		{
//			for (int i = 0; i < totalitems / 2; i++)
//			{
//				if (heap[0][i] > heap[1][i])
//				{
//					swap(heap[0][i], heap[1][i]);
//				}
//			}
//			MaxReheapDown(0, totalitems / 2 - 1);
//			MinReheapDown(0, totalitems / 2 - 1);
//		}
//		else
//		{
//			for (int i = 0; i < totalitems / 2; i++)
//			{
//				if (heap[0][i] > heap[1][i])
//				{
//					swap(heap[0][i], heap[1][i]);
//				}
//			}
//			MaxReheapDown(0, totalitems / 2 - 1);
//			MinReheapDown(0, totalitems / 2);
//		}
//	}
//	void deletemax()
//	{
//		if (totalitems % 2 == 0)
//		{
//			swap(heap[1][0], heap[1][(totalitems / 2) - 1] );
//			totalitems--;
//			MaxReheapDown(0, totalitems / 2);
//			balancer();
//		}
//		else
//		{
//			swap(heap[1][0], heap[1][(totalitems / 2) - 1]);
//			swap(heap[0][totalitems / 2], heap[1][totalitems / 2 - 1]);
//			MaxReheapDown(0, totalitems / 2 - 1);
//			totalitems--;
//			balancer();
//		}
//	}
//	void update(int oldvalue, int newvalue)
//	{
//		int index = -1;
//		int heapno = -1;
//		bool found=false;
//		search(oldvalue, found, index, heapno);
//		if (index != -1)
//		{
//			swap(heap[heapno][index], newvalue);
//			if (totalitems % 2 == 0)
//			{
//				MaxReheapUp(0, totalitems / 2 - 1);
//				MinReheapUp(0, totalitems / 2 - 1);
//			}
//			else
//			{
//				MaxReheapUp(0, totalitems / 2 - 1);
//				MinReheapUp(0, totalitems / 2);
//			}
//			balancer();
//		}
//		else
//		{
//			cout << "Not Found!!!" << endl;
//		}
//	}
//	void deletemin()
//	{
//		
//		if (totalitems % 2 == 0)
//		{
//			swap(heap[0][0], heap[0][(totalitems / 2) - 1]);
//			totalitems--;
//			swap(heap[1][totalitems / 2], heap[0][totalitems/2]);
//			MinReheapDown(0, totalitems / 2);
//		}
//		else
//		{
//			swap(heap[0][0], heap[0][(totalitems / 2)]);
//			totalitems--;
//			MinReheapDown(0, totalitems / 2 - 1 );
//		}
//		balancer();
//	}
//	void display()
//	{
//		if (totalitems % 2 == 0)
//		{
//			for (int i = 0; i < totalitems / 2; i++)
//			{
//				cout << setw(4) << heap[0][i]  << " ";
//			}
//			cout << endl;
//			for (int i = 0; i < totalitems / 2; i++)
//			{
//				cout << setw(4) << heap[1][i] << " ";
//			}
//			cout << endl;
//		}
//		else
//		{
//			for (int i = 0; i < totalitems / 2; i++)
//			{
//				cout << setw(4) << heap[0][i] << " ";
//			}
//			cout << setw(4) << heap[0][(totalitems / 2)] << endl;
//			for (int i = 0; i < totalitems / 2; i++)
//			{
//				cout << setw(4) << heap[1][i] << " ";
//			}
//			cout << endl;
//			
//		}
//	}
//	bool isempty() { return (totalitems == 0); }
//	~Heap()
//	{
//		delete[] heap;
//	}
//};
//int main()
//{
//	Heap obj(100);
//	obj.insert(5);
//	obj.insert(4);
//	obj.insert(9);
//	obj.insert(11);
//	obj.insert(14);
//	obj.insert(6);
//	obj.insert(15);
//	obj.insert(22);
//	obj.insert(40);
//	obj.insert(31);
//	obj.insert(17);
//	obj.insert(10);
//	obj.display();
//	obj.deletemin();
//	obj.display();
//	obj.deletemin();
//	obj.display();
//	obj.insert(25);
//	obj.insert(4);
//	obj.deletemax();
//	obj.display();
//	obj.deletemax();
//	obj.display();
//	obj.update(25,19);
//	obj.display();
//	system("pause");
//}