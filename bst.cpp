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
    TreeNode*root;

public:
	BST()
	{
        root = 0;
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

    int length(TreeNode* t)
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
};

int main()
{
    int n;
	int val;
    BST t;
    cout << "Enter the total amount of values you want to enter in binary tree : ";
	cin >> n;

    for (int i=0; i<n; i++)
	{
		cout << "Enter the " << i+1 << " value : ";
        cin >> val;
        t.insert(val);
    }
	cout << "The binary tree in order is : ";
    t.inorder();
    cout << endl;
    cout << "length of the binary tree is : " << t.length() << endl;
	cout << endl;

    system("pause");
	return 0;
}



#include <iostream>
#include <queue>

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function to insert a new value into the tree.
    bool insert(Node*& current, int value) {
        if (current == nullptr) {
            current = new Node(value);
            return true;
        }
        if (value < current->data) {
            return insert(current->left, value);
        }
        else if (value > current->data) {
            return insert(current->right, value);
        }
        return false; // Value already exists in the tree.
    }

    // Helper function for the copy constructor.
    Node* copyTree(const Node* other) {
        if (other == nullptr) {
            return nullptr;
        }
        Node* newNode = new Node(other->data);
        newNode->left = copyTree(other->left);
        newNode->right = copyTree(other->right);
        return newNode;
    }

    // Helper function for inorderPrint.
    void inorderPrint(const Node* current) const {
        if (current == nullptr) {
            return;
        }
        inorderPrint(current->left);
        std::cout << current->data << " ";
        inorderPrint(current->right);
    }

    // Helper function for levelorderPrint.
    void levelorderPrint() const {
        if (root == nullptr) {
            return;
        }
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            std::cout << current->data << " ";

            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
    }

    // Helper function for search.
    Node* search(Node* current, int key) {
        if (current == nullptr || current->data == key) {
            return current;
        }
        if (key < current->data) {
            return search(current->left, key);
        }
        return search(current->right, key);
    }

    // Helper function for countNodes.
    int countNodes(const Node* current) const {
        if (current == nullptr) {
            return 0;
        }
        return 1 + countNodes(current->left) + countNodes(current->right);
    }

    // Helper function for leafCount.
    int leafCount(const Node* current) const {
        if (current == nullptr) {
            return 0;
        }
        if (current->left == nullptr && current->right == nullptr) {
            return 1;
        }
        return leafCount(current->left) + leafCount(current->right);
    }

    // Helper function for the Destructor.
    void destroyTree(Node* current) {
        if (current == nullptr) {
            return;
        }
        destroyTree(current->left);
        destroyTree(current->right);
        delete current;
    }

public:
    // Default Constructor
    BST() : root(nullptr) {}

    // Destructor
    ~BST() {
        destroyTree(root);
    }

    // Public insert function
    bool insert(int value) {
        return insert(root, value);
    }

    // Copy constructor
    BST(const BST& other) {
        root = copyTree(other.root);
    }

    // Public inorderPrint function
    void inorderPrint() const {
        inorderPrint(root);
        std::cout << std::endl;
    }

    // Public levelorderPrint function
    void levelorderPrint() const {
        levelorderPrint();
        std::cout << std::endl;
    }

    // Public search function
    Node* search(int key) {
        return search(root, key);
    }

    // Public countNodes function
    int countNodes() const {
        return countNodes(root);
    }

    // Public leafCount function
    int leafCount() const {
        return leafCount(root);
    }
};

int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    std::cout << "Inorder Traversal: ";
    tree.inorderPrint();

    std::cout << "Levelorder Traversal: ";
    tree.levelorderPrint();

    int key = 30;
    BST::Node* found = tree.search(key);
    if (found) {
        std::cout << "Node with key " << key << " found." << std::endl;
    }
    else {
        std::cout << "Node with key " << key << " not found." << std::endl;
    }

    int nodeCount = tree.countNodes();
    std::cout << "Total nodes in the BST: " << nodeCount << std::endl;

    int leafCount = tree.leafCount();
    std::cout << "Leaf nodes in the BST: " << leafCount << std::endl;

    return 0;
}
