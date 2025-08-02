#include <bits/stdc++.h>
using namespace std;
// Basically we storing the coordinates and those having same horizontal coordinate will lie in a single line, to give the coordinate we simply use the root as origin and as we go left -1, and right +1.
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
	public:
	vector<vector<int>>findVertical(Node*root){
	    // map to store nodes based on vertical and level information
	    map<int,map<int,multiset<int>>>nodes;

	    // queue for BFS traversal, each element is a pair containing node and its vertical and level information
	    queue<pair<Node*,pair<int,int>>>todo;
	    todo.push({root,{0,0}});
	    while(!todo.empty()){

		    auto p=todo.front();
		    todo.pop();
		    Node*temp=p.first;
		    int x=p.second.first;
		    int y=p.second.second;
		    nodes[x][y].insert(temp->data);
		    
		    if(temp->left)
			    todo.push({temp->left,{x-1,y+1}});
			if(temp->right)
				todo.push({temp->right,{x+1,y+1}});
	    }
		vector<vector<int>>ans;
		for(auto p:nodes){
			vector<int>col;
			for(auto q:p.second){

				col.insert(col.end(),q.second.begin(),q.second.end());
			}
			ans.push_back(col);
		}
			return ans;
    
	}
};

void printResult(const vector<vector<int>>&res){
	for(auto level:res){
		for(auto node:level){
			cout<<node<<" ";

		}
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->right = new Node(9);
    root->left->left->left=new Node(8);
    root->left->right->left = new Node(10);
    root->left->right->right=new Node(11);

    root->right = new Node(3);
    root->right->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right->left=new Node(14);
    root->right->right->right=new Node(15);
    root->right->left->left= new Node(12);
    root->right->left->right=new Node(13);
    Solution sol;
    vector<vector<int>> verticalTraversal = sol.findVertical(root);
    printResult(verticalTraversal);
}
