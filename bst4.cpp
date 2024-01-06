#include <iostream>
using namespace std;

class BST;

class TreeNode
{
	friend class BST;
	TreeNode* left;
	TreeNode* right;
	int data;
};

class BST
{
	TreeNode* root;
	int count;

public:
	BST()
	{
		root =NULL;
		count=0;
	}

	bool insert(TreeNode*& t, int val)
	{
		if(t == 0)
		{
			t = new TreeNode;
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
			insert(t->right,val);
		}

		else
		{
			cout << "The value already exist in the tree" << endl;
			return false;
		}
	}

	void insert(int val)
	{
		insert(root,val);
	}

	int length(TreeNode*t)
	{
	    if(t == 0)
		{
		    return false;
		}
	    else
		{
		    return 1 + length(t->left) + length(t->right);
	    }
}
	int length()
	{
	    return length(root);
    }

	TreeNode* kthsmallval(TreeNode* t, int val)
	{
		if(t==0)
		{
			return 0;
		}

		TreeNode*l = kthsmallval(t->left,val);

		if(l != NULL)
		{
			return l;
		}
		else
		{
			count++;
			if(val == count)
				return t;
			else
				return kthsmallval(t->right,val);
		}
	}

	int kthsmallval(int val)
	{
		return kthsmallval(root,val)->data;
	}

	TreeNode* kthlargeval(TreeNode*t,int val)
	{
		if(t==0)
		{
			return 0;
		}
		TreeNode*l = kthlargeval(t->left,val);

		if(l != NULL)
		{
			return l;
		}
		else
		{
			count++;
			if(val == count)
				return t;
			else
				return kthlargeval(t->right,val);
		}
	}

	int kthlargeval(int val)
	{
		return kthlargeval(root,val)->data;
	}

	void inorder(TreeNode* t)
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
    int k_small;
    int k_large;
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
    cout<<endl;
    int l = t.length();
    cout << "The length of the tree is : " << l << endl;

    cout << "Enter kth smallest value you want to determine : ";
    cin >> k_small;
    cout << k_small << "th smallest value is : " << t.kthsmallval(k_small) << endl;

    cout << "Enter the kth largest value you want to determine : ";
    cin >> k_large;
    cout << k_large << "th largest value is : " << t.kthlargeval((l+1)-k_large) << endl;

    system("pause");
	return 0;
}