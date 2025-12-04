#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node*left;
    Node*right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

class Solution{
    public:
    void traverse(Node*root, vector<int>&element){
        if(!root)return;
        traverse(root->left, element);
        element.push_back(root->data);
        traverse(root->right, element);
    }
    vector<int>mergeBSTs(Node*root1,Node*root2){
        vector<int>element;
        traverse(root1,element);
        traverse(root2,element);
        sort(element.begin(),element.end());
        return element;
    }
};

int main(){
    Node*root1=new Node(2);
    root1->left=new Node(1);
    root1->right=new Node(4);
    Node*root2=new Node(3);
    root2->left=new Node(0);
    root2->right=new Node(5);

    Solution sol;
    vector<int>res=sol.mergeBSTs(root1,root2);
    for(int val:res){
        cout<<val<<",";
    }
}