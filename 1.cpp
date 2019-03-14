#include<iostream>
using namespace std;

class Node
	{
		public:
		int data;
		// Children
		Node * left;
		Node * right;
	
		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
	};

class BiST
	{
		public:
		Node * root;
	
		BiST() 
 		{ root = NULL; }
		//insert
		void insert(int value)
		{ insertHelper(root, value);}

		void insertHelper(Node *curr, int value)
		{
			if (root == NULL)
			{
				root = new Node(value);
			}
			// Else compare the current data with the value
			else if (value < curr->data)
			{
				// else move to left and call insertHelper
				if (curr->left == NULL)
					curr->left = new Node(value);
				else
					insertHelper(curr->left, value);
			}
			else
			{
				// Else move to right and call insertHelper
				if (curr->right == NULL)
					curr->right = new Node(value);
				else
					insertHelper(curr->right, value);
			}
  		}
		//display
  		void display()
		{displayHelper(root);}
	
  		void displayHelper(Node *curr)
		{
			// Base condition
			if (curr == NULL)
				return;
			// Display left part
			displayHelper(curr->left);
			// Display current part
			cout << curr->data << ",";
			// Display right part
			displayHelper(curr->right);
		}
	
		
		//search
		Node * search(Node * cur,int value)
		{
			if(cur==NULL)
			{
				return NULL;
			}
			if(cur->data==value)
			{
				return cur;
			}
			if(cur->data<value)
			{
				return search(cur->right,value);
			}
			else
			{
				return search(cur->left,value);
			}
		}
	};	
	
int main()
{
		BiST b1;
		b1.insert(2);
		b1.insert(4);
		b1.insert(1);
		b1.insert(3);
		b1.insert(8);
		b1.insert(62);
		b1.insert(5);
		b1.insert(53);
		b1.insert(6);
		b1.display();
}
