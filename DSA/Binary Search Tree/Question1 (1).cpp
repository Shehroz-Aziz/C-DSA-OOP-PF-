#include<iostream>
using namespace std;
template<typename K,typename V>
struct Node
{
	K key;
	V value;
	Node<K,V>* left;
	Node<K,V>* right;
	Node<K,V>()
	{
		left = NULL;
		right = NULL;
	}
};
template<typename K, typename V>
class specialBST
{
private:
	Node<K,V>* root;
public:
	specialBST()
	{
		root = NULL;
	}
	bool insert(K key,V value)
	{
		bool found1=true;
		bool found2;
		if (root == NULL)
		{
			Node<K,V>* newNode = new Node<K,V>;
			newNode->key = key;
			newNode->value = value;
			root = newNode;
			return true;
		}
		else
		{
			insertion(root, key ,value, found1);
			root=makeroot(root, value, found2);
			return found1;
		}
	}
	bool insertion(Node<K,V>*& current,K key,V value , bool &inseted)
	{
		if (current == NULL)
		{
			Node<K,V>* newNode = new Node<K,V>;
			newNode->key = key;
			newNode->value = value;
			current = newNode;
		}
		else if (key > current->key)
		{
			insertion(current->right, key ,value, inseted);
		}
		else if (key < current->key)
		{
			insertion(current->left, key ,value, inseted);
		}
		else if(key == current->key)
		{
			inseted = false;
		}
		return inseted;
	}
	void InOrder()
	{
		InOrder(root);
	}
	void InOrder(Node<K,V>* tempNode)
	{
		if (tempNode != NULL)
		{
			cout << tempNode->value << " ";
			InOrder(tempNode->left);
			InOrder(tempNode->right);
		}
	}
	void LevelOrder(int level)
	{
		int templevel=-1;
		LevelOrder(root,level,templevel);
	}
	void LevelOrder(Node<K,V>* tempNode,int level, int templevel)
	{
		templevel++;
		if (tempNode != NULL)
		{
			if(templevel==level)
			LevelOrder(tempNode->left,level,templevel);
			cout << tempNode->value << " ";
			LevelOrder(tempNode->right,level,templevel);
		}
	}
	bool Search(int key)
	{

		bool find=false;
		root=makeroot(root, key, find);
		return find;
	}
	Node<K,V>* rightRotate(Node<K,V>*& newright)
	{
		Node<K,V>* temp = newright->left;
		newright->left = temp->right;
		temp->right = newright;
		return temp;
	}
	Node<K,V>* leftRotate(Node<K,V>*& newleft)
	{
		Node<K,V>* temp = newleft->right;
		newleft->right = temp->left;
		temp->left = newleft;
		return temp;
	}
	Node<K, V>* makeroot(Node<K,V>* temproot, K key, bool& found)
	{ 
		Node<K, V>* returnnode=NULL;
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
	void deleteR(int d)
	{
		bool exists=false;
		root=makeroot(root, d, exists);
		if (exists)
		{
			deleteR(d, root);
		}
		else
		{
			cout << "Not Exists"<<endl;
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
	void deleteNode(Node<K,V>*& node) 
	{

		K d;
		Node<K,V>* temp;
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
	void getPredecessor(Node<K,V>*node, int & key) 
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
int main()
{
	specialBST <int,int>obj;
	obj.insert(1,25);
	obj.insert(2,20);
	obj.insert(3,36);
	obj.insert(4,10);
	obj.insert(5,22);
	obj.insert(6,30);
	obj.insert(7,40);
	obj.insert(8,5);
	obj.insert(9,8);
	obj.insert(10,28);
	obj.insert(11,45);
	obj.insert(12,50);
	obj.insert(13,89);
	cout << obj.insert(13,37) <<endl;
	obj.InOrder();
	cout << endl;
	obj.LevelOrder(2);
	cout << endl;
	cout << obj.Search(12) << endl;
	obj.InOrder();
	cout << endl;
	obj.deleteR(13);
	obj.InOrder();
	system("pause");
}