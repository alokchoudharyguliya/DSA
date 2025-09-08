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



#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

class Solution {
private:
    /**
     * @brief Generates a full binary palindrome from its first half.
     * @param first_half The number representing the left half of the palindrome.
     * @param total_len The total desired bit length of the palindrome.
     * @return The generated palindromic number.
     */
    long long makePalindromeFromHalf(long long first_half, int total_len) {
        long long result = first_half;
        
        // Determine the part to be reversed and appended
        long long second_half_base = (total_len % 2 == 1) ? (first_half >> 1) : first_half;

        // Append the reversed bits
        while (second_half_base > 0) {
            result = (result << 1) | (second_half_base & 1);
            second_half_base >>= 1;
        }
        return result;
    }

public:
    int countBinaryPalindromic(int n) {
        // Convert n to its binary string representation to get its length.
        std::string s = "";
        int temp_n = n;
        while(temp_n > 0){
            s += (temp_n % 2 == 0 ? "0" : "1");
            temp_n /= 2;
        }
        std::reverse(s.begin(), s.end());
        
        int L = s.length();
        int count = 1; // Start with 1 to account for 0.

        for (int len = 1; len < L; ++len) {

            count += (1 << ((len - 1) / 2));
        }

        int first_half_len = (L + 1) / 2;
        long long prefix_n = stoll(s.substr(0, first_half_len), nullptr, 2);
        
        long long first_possible_prefix = 1LL << (first_half_len - 1);
        
        count += (prefix_n - first_possible_prefix);
        
        long long pal_from_prefix = makePalindromeFromHalf(prefix_n, L);
        if (pal_from_prefix <= n) {
            count++;
        }        
        return count;
    }
};