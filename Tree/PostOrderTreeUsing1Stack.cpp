#include<bits/stdc++.h>
using namespace std;
class Node{
    int data;
    Node*left;
    Node*right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};
void postorder(Node*root,vector<int>&arr){
    
}
void printVector(vector<int>vec){
    for(int i=0;i<vec.size();i++)
    cout<<vec[i]<<" ";
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    vector<int>result=postOrder(root);
    printVector(result);
}