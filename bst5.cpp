#include<iostream>
using namespace std;

class BST;

class Treenode
{
	friend class BST;
	Treenode* left;
	Treenode* right;
	int data;
};

class BST
{
	Treenode* root;

public:
	BST()
	{
		root = NULL;
	}

	bool insert(Treenode*& t, int val)
	{
		if(t == NULL)
		{
			t = new Treenode;
			t->left = NULL;
			t->right = NULL;
			t->data = val;
			return true;
		}

		else if(val < t->data)
		{
			insert(t->left, val);
		}

		else if(val > t->data)
		{
			insert(t->right, val);
		}

		else
		{
			cout << "val exists already" << endl;
			return false;
		}
	}

	void insert(int val)
	{
		insert(root, val);
	}
	
	int height(Treenode* t)
	{
		if(t == NULL)
		{
			return 0 ;
		}

		else
		{
			int l = height(t->left);
			int r = height(t->right);

			if(l > r)
			{
				return l+1;
			}
			else 
			{
				return r+1;
			}
		}
	}

	int height()
	{
		return height(root);
	}
	
	void inorder(Treenode* t)
	{
	    if(t!=0)
		{
		    inorder(t->left);
		    cout << t->data << " ";
		    inorder(t->right);
	    }
    }

    void inorder()
	{
	    inorder(root);
    }
};

int main()
{
    int n;
	int val;
    BST t;
    cout << "Enter the amount of values you want to enter : ";
	cin >> n;

    for (int i = 0; i<n; i++)
	{
		cout << "Enter the " << i+1 << " value : ";
        cin >> val;
        t.insert(val);
    }

	cout << "The binary tree in order is : ";
    t.inorder();
    cout << endl << "Height of the binary tree is : " << t.height() << endl;

    system("pause");
	return 0;
}