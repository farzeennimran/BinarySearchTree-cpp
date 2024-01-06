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
        root = NULL;
    }

    bool insert(TreeNode*& t, int val)
	{
        if (t == NULL)
		{
            t = new TreeNode;
            t->data = val;
            t->left = NULL;
            t->right = NULL;
            return true;
        }

        else if (val < t->data)
		{
            insert(t->left, val);
        }

        else if (val > t->data)
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

    bool del(int val)
	{
        TreeNode* cur = root;
		TreeNode* parent = NULL;

        while(cur != NULL && cur->data != val)
        {
            parent = cur;

            if (val < cur->data)
			{
                cur = cur->left;
			}
            else
			{
                cur = cur->right;
			}
        }

        if (cur == 0)
		{
            cout << "The tree is empty or the value you entered is not present" << endl;
            return false;
        }

        else
        {
            if(cur->left != 0 && cur->right != 0)
			{
                TreeNode*l = cur->left, *pl = cur;

                while (l->right != 0)
                {
                    pl = l;
                    l = l->right;
                }
                cur->data = l->data;
                cur = l;
                parent = pl;
            }
            TreeNode* child;

            if(cur->left != 0)
			{
                child = cur->left;
            }

            else
			{
                child = cur->right;
            }

            if(cur == root)
			{
                root = child;
            }

            else
			{
                if (cur == parent->right)
				{
                    parent->right = child;
				}
                else
				{
                    parent->left = child;
				}
            }
            delete cur;
            cur = 0;
            cout << "The value deleted" << endl;
            return true;
        }
    } 

    void inorder(TreeNode*t)
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
};

int main()
{
	int n;
    int val;
    int del;
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
    cout << endl << "Enter the value you want to delete from binary tree : " ;
    cin >> del;
    t.del(del);
	cout << endl;

    system("pause");
	return 0;
}