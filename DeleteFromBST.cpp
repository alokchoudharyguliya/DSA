#include<bits/stdc++.h>
using namespace std;
// Find where the node to deleted appears ? 
// Deleting can be done in two ways for a non-leaf node:
// 1.	Accept the left subtree as the new root which will take place of the node deleted. Join the right subtree to the right most node of the current subtree.
// 2.	Accept the right subtree as new root which will take place of the node deleted. Join the left subtree to the left most node of the current subtree.

// Edge case can be when either right subtree or left subtree is absent.

struct Node{
	int data;
	Node*left;
	Node*right;
	Node(int val):data(val),left(nullptr),right(nullptr){}

};
int main(){


}
