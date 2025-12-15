#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node*links[26];
    bool flag=false;
    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }
    void put(char ch, Node*node){
        links[ch-'a']=node;
    }
    Node*get(char ch){
       return links[ch-'a'];
    }
    bool setEnd(){
        flag=true;
    }
};
class Trie{
    private:
    Node*root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(string word){
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            // moves to the reference trie
            node->get(word[i]);
        }
        node->setEnd();
    }
    // Returns if the word is in the trie
    bool search(string word){
        Node*node=root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnd()==true;
    }
    // Returns if there is any word in the trie that starts with the given prefix string
    bool startsWith(string prefix){
        Node*node=root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i]))return false;
            node=node->get(prefix[i]);
        }
        return true;
    }
};