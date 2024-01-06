#include <iostream>
using namespace std;

class BST;

class TreeNode
{
	friend class BST;
    int data;
    TreeNode* left;
    TreeNode* right;
};

class BST
{
    TreeNode* root;

public:
	BST()
	{
        root = 0;
    }

    bool insert(TreeNode*& t, int val)
	{
        if(t == NULL)
		{
            t = new TreeNode;
            t->data = val;
            t->left = NULL;
            t->right = NULL;
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
            return false;
        }
    }

    void insert(int val)
	{
        insert(root, val);
    }

    void inorder(TreeNode* t)
	{
	    if(t != 0)
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

    int height(TreeNode* t)
	{
		if(t == NULL)
		{
			return 0 ;
		}

		else
		{
			int l = height(t->left);
			int r = height(t->right);

			if(l>r)
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

	void find_level(TreeNode* t)
	{
		int h=height(root);

		for(int i=0;i<h;i++)
		{
			levelorderPrint(t,i);
		}
	}

    void levelorderPrint(TreeNode* t,int lvl)
	{
	    if(t == 0)
		{
	  	    return;
		}
	    if(lvl == 0)
		{
		    cout << t->data << " ";
	    }

	    else
		{
		    levelorderPrint(t->left, lvl-1);
		    levelorderPrint(t->right, lvl-1);
	    }
    }

    void levelorderPrint()
	{
	    find_level(root);
    }
};

int main()
{
    int n;
	int val;
    BST t;
    cout << "Enter the amount of values you want to enter : ";
	cin >> n;

    for (int i=0; i<n; i++)
	{ 
		cout << "Enter the " << i+1 << " value : ";
        cin >> val;
        t.insert(val);
    }
	cout << "The binary tree in order is : ";
    t.inorder();
	cout << endl << "The keys using level order traversal are : ";
    t.levelorderPrint();
    cout << endl;
    
	system("pause");
	return 0;
}