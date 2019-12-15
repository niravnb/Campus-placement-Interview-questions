// Bottom View of a Binary Tree


#include <iostream>
#include <map>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = this->right = nullptr;
    }
};

// Recursive function to do a pre-order traversal of the tree and fill the map
// Here node has 'dist' horizontal distance from the root of the
// tree and level represent level of the node

void printBottom(Node *node, int dist, int level, auto &map)
{
	// base case: empty tree
	if (node == nullptr)
		return;

	// if current level is more than or equal to maximum level seen so far
	// for the same horizontal distance or horizontal distance is seen for 
	// the first time, update the map

	if (level >= map[dist].second)
	{
		// update value and level for current distance
		map[dist] = { node->key, level };
	}

	// recur for left subtree by decreasing horizontal distance and
	// increasing level by 1
	printBottom(node->left, dist - 1, level + 1, map);

	// recur for right subtree by increasing both level and
	// horizontal distance by 1
	printBottom(node->right, dist + 1, level + 1, map);
}

// Function to print the bottom view of given binary tree
void printBottom(Node *root)
{
	// create an empty map where
	// key -> relative horizontal distance of the node from root node and
	// value -> pair containing node's value and its level

	map<int, pair<int, int>> map;

	// do pre-order traversal of the tree and fill the map
	printBottom(root, 0, 0, map);

	// traverse the map and print bottom view
	for (auto it: map)
		cout << it.second.first << " ";
}

// main function
int main()
{
    Node* root = nullptr;

    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

	printBottom(root);

	return 0;
}













// C++ Program to print Bottom View of Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 

// Tree node class 
struct Node 
{ 
	int data; //data of the node 
	int hd; //horizontal distance of the node 
	Node *left, *right; //left and right references 

	// Constructor of tree node 
	Node(int key) 
	{ 
		data = key; 
		hd = INT_MAX; 
		left = right = NULL; 
	} 
}; 

// Method that prints the bottom view. 
void bottomView(Node *root) 
{ 
	if (root == NULL) 
		return; 

	// Initialize a variable 'hd' with 0 
	// for the root element. 
	int hd = 0; 

	// TreeMap which stores key value pair 
	// sorted on key value 
	map<int, int> m; 

	// Queue to store tree nodes in level 
	// order traversal 
	queue<Node *> q; 

	// Assign initialized horizontal distance 
	// value to root node and add it to the queue. 
	root->hd = hd; 
	q.push(root); // In STL, push() is used enqueue an item 

	// Loop until the queue is empty (standard 
	// level order loop) 
	while (!q.empty()) 
	{ 
		Node *temp = q.front(); 
		q.pop(); // In STL, pop() is used dequeue an item 

		// Extract the horizontal distance value 
		// from the dequeued tree node. 
		hd = temp->hd; 

		// Put the dequeued tree node to TreeMap 
		// having key as horizontal distance. Every 
		// time we find a node having same horizontal 
		// distance we need to replace the data in 
		// the map. 
		m[hd] = temp->data; 

		// If the dequeued node has a left child, add 
		// it to the queue with a horizontal distance hd-1. 
		if (temp->left != NULL) 
		{ 
			temp->left->hd = hd-1; 
			q.push(temp->left); 
		} 

		// If the dequeued node has a right child, add 
		// it to the queue with a horizontal distance 
		// hd+1. 
		if (temp->right != NULL) 
		{ 
			temp->right->hd = hd+1; 
			q.push(temp->right); 
		} 
	} 

	// Traverse the map elements using the iterator. 
	for (auto i = m.begin(); i != m.end(); ++i) 
		cout << i->second << " "; 
} 

// Driver Code 
int main() 
{ 
	Node *root = new Node(20); 
	root->left = new Node(8); 
	root->right = new Node(22); 
	root->left->left = new Node(5); 
	root->left->right = new Node(3); 
	root->right->left = new Node(4); 
	root->right->right = new Node(25); 
	root->left->right->left = new Node(10); 
	root->left->right->right = new Node(14); 
	cout << "Bottom view of the given binary tree :\n"
	bottomView(root); 
	return 0; 
} 



// C++ Program to print Bottom View of Binary Tree 
#include < bits / stdc++.h > 
#include < map > 
using namespace std; 

// Tree node class 
struct Node 
{ 
	// data of the node 
	int data; 
	
	// horizontal distance of the node 
	int hd; 
	
	//left and right references 
	Node * left, * right; 
	
	// Constructor of tree node 
	Node(int key) 
	{ 
		data = key; 
		hd = INT_MAX; 
		left = right = NULL; 
	} 
}; 

void printBottomViewUtil(Node * root, int curr, int hd, map <int, pair <int, int>> & m) 
{ 
	// Base case 
	if (root == NULL) 
		return; 
	
	// If node for a particular 
	// horizontal distance is not 
	// present, add to the map. 
	if (m.find(hd) == m.end()) 
	{ 
		m[hd] = make_pair(root -> data, curr); 
	} 
	// Compare height for already 
	// present node at similar horizontal 
	// distance 
	else
	{ 
		pair < int, int > p = m[hd]; 
		if (p.second <= curr) 
		{ 
			m[hd].second = curr; 
			m[hd].first = root -> data; 
		} 
	} 
	
	// Recur for left subtree 
	printBottomViewUtil(root -> left, curr + 1, hd - 1, m); 
	
	// Recur for right subtree 
	printBottomViewUtil(root -> right, curr + 1, hd + 1, m); 
} 

void printBottomView(Node * root) 
{ 
	
	// Map to store Horizontal Distance, 
	// Height and Data. 
	map < int, pair < int, int > > m; 
	
	printBottomViewUtil(root, 0, 0, m); 
	
	// Prints the values stored by printBottomViewUtil() 
	map < int, pair < int, int > > ::iterator it; 
	for (it = m.begin(); it != m.end(); ++it) 
	{ 
		pair < int, int > p = it -> second; 
		cout << p.first << " "; 
	} 
} 

int main() 
{ 
	Node * root = new Node(20); 
	root -> left = new Node(8); 
	root -> right = new Node(22); 
	root -> left -> left = new Node(5); 
	root -> left -> right = new Node(3); 
	root -> right -> left = new Node(4); 
	root -> right -> right = new Node(25); 
	root -> left -> right -> left = new Node(10); 
	root -> left -> right -> right = new Node(14); 
	cout << "Bottom view of the given binary tree :\n"; 
	printBottomView(root); 
	return 0; 
} 
