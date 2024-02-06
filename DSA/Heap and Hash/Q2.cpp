#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include <assert.h>
using namespace std;
template <class v>
struct HashItem
{
	int key;
	v value;
	short status;
	HashItem()
	{
		key = 0;
		status = 0;
	}
	void operator =(const HashItem& obj)
	{
		key = obj.key;
		value = obj.value;
		status = obj.status;
	}
};
template <class v>
class hasher
{
protected:
	HashItem<v>* Harr;
	int capacity;
	int currentElements;
	void doubleCapacity()
	{
		HashItem<v>* temp = new HashItem<v>[capacity];
		for (int i = 0; i < capacity; i++)
		{
			if (Harr[i].status == 2)
			{
				temp[i] = Harr[i];
			}
		}
		//free(Harr);
		Harr = new HashItem<v>[capacity * 2];
		capacity *= 2;
		int h = 0;
		for (int i = 0; i < capacity/2; i++)
		{
			if (temp[i].status == 2)
			{
				int index = temp[i].key % (capacity);
				while (Harr[index].status == 2)
				{
					index = getNextCandidateIndex(temp[i].key, h);
					h++;
				}
				Harr[index] = temp[i];
			}
		}
	}
	virtual int getNextCandidateIndex(int key, int index)
	{
		int temp_index = (key + index) % this->capacity;
		return temp_index;
	}
public:
	hasher()
	{
		capacity = 10;
		currentElements = 0;
		Harr = new HashItem<v>[capacity];
	}
	hasher(int const cap)
	{
		capacity = cap;
		currentElements = 0;
		Harr = new HashItem<v>[capacity]();
	}
	void insert(int const key, v const value) {
		float factor = currentElements;
		factor /= capacity;
		if (factor >= 0.75)
		{
			doubleCapacity();
		}
		int i = key % capacity;
		int h = 0;
		while (Harr[i].status == 2)
		{
			i = getNextCandidateIndex(key, h);
			h++;
		}
		Harr[i].key = key;
		Harr[i].value = value;
		Harr[i].status = 2;
		currentElements++;
	}
	bool deleteKey(int const key)
	{
		int index = key % capacity;
		int i = 0;
		while (Harr[index].key != key)
		{
			index = getNextCandidateIndex(key, i);
			i++;
		}
		if (Harr[index].key == key && Harr[index].status != 1)
		{
			Harr[index].status = 1;
			currentElements--;
			return true;
		}
		return false;
	}
	v* get(int k)
	{
		v* h;
		int index = k % capacity;
		int i = 0;
		int a = 0;
		while ((Harr[index].key != k))
		{
			index = getNextCandidateIndex(k, i);
			i++;
		}
		if ((Harr[index].key == k) && (Harr[index].status != 1))
		{
			h = &Harr[index].value;
			return h;
		}
		return NULL;
	}
	~hasher()
	{
		delete Harr;
	}
};
template<class v>
class Qhasher : public hasher<v>
{
private:
	int getNextCandidateIndex(int key, int index)
	{
		int temp_index = (key + (index * index)) % this->capacity;
		return temp_index;
	}
};
template<class v>
class Dhasher : public hasher<v>
{
private:
	int getNextCandidateIndex(int key, int index)
	{
		int first = key % this->capacity;
		int second = 3 - (key % 3);
		int candidate = (first + (index * second)) % this->capacity;
		return candidate;
	}
};

void populateHash(string filename, hasher<string>* hash)
{
	ifstream file;
	file.open(filename);
	int size;
	file >> size;
	file.ignore();
	int roll;
	string name;
	while (size > 0)
	{
		file >> roll >> name;
		hash->insert(roll, name);
		size--;
	}
	file.close();
}
int main()
{
	hasher<string>* map = new hasher<string>;
	populateHash("students.txt", map);
	cout << *map->get(9) << endl << endl;
	cout << map->deleteKey(9); cout << endl;
	assert((map->get(9)==nullptr));
	free(map);

	map = new Qhasher<string>;
	populateHash("students.txt", map);
	cout << *map->get(98) << endl << endl;
	cout << map->deleteKey(98); cout << endl;
	assert(map->get(98)==nullptr);
	free(map);  //Delete not working

	map = new Dhasher<string>;
	populateHash("students.txt", map);
	cout << *map->get(101) << endl << endl;
	cout << map->deleteKey(101); cout << endl;
	assert(map->get(101)==nullptr);
	free(map); //Delete not working
	system("pause");
	return 0;
}