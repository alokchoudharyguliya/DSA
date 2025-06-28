// Approach:
// Scan the infix expression from left to right
// If the scanned character is an operand, output it
// Else
// If the precendence of the scanned operator is greater than the precedence than the precedence of the operator in the stack(or the stack is empty or the stack contaoines a '('), push it.
// Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator. After doing that Push the scanned operator to the stack.
// (If you encounter parenthesis while popping then stop there and push the scanned operator in the stack)
// If the scanned character is an '(', push it to the stack.
// If the scanned character is an ')', pop the stack and output it until a '(' is encountered, and discard both the parenthesis.
// Repeat steps 2-6 until infix expression is scanned.
// Print the output
// Pop and output from the stack until it is not empty.

#include <bits/stdc++.h>
using namespace std;

// ListNode structure for linked list problems
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// TreeNode structure for binary tree problems
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// GraphNode structure for graph problems (adjacency list)
struct GraphNode
{
    int val;
    vector<GraphNode *> neighbors;
    GraphNode() : val(0), neighbors({}) {}
    GraphNode(int x) : val(x), neighbors({}) {}
    GraphNode(int x, vector<GraphNode *> _neighbors) : val(x), neighbors(_neighbors) {}
};

// Utility functions to create data structures
class DataGenerator
{
public:
    // Create a linked list from vector
    static ListNode *createLinkedList(vector<int> values)
    {
        if (values.empty())
            return nullptr;

        ListNode *head = new ListNode(values[0]);
        ListNode *current = head;

        for (int i = 1; i < values.size(); i++)
        {
            current->next = new ListNode(values[i]);
            current = current->next;
        }

        return head;
    }

    // Convert linked list to vector
    static vector<int> linkedListToVector(ListNode *head)
    {
        vector<int> result;
        while (head)
        {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }

    // Create a binary tree from vector (level order)
    static TreeNode *createBinaryTree(vector<int> values)
    {
        if (values.empty())
            return nullptr;

        TreeNode *root = new TreeNode(values[0]);
        queue<TreeNode *> q;
        q.push(root);

        int i = 1;
        while (!q.empty() && i < values.size())
        {
            TreeNode *current = q.front();
            q.pop();

            if (i < values.size() && values[i] != INT_MIN)
            {
                current->left = new TreeNode(values[i]);
                q.push(current->left);
            }
            i++;

            if (i < values.size() && values[i] != INT_MIN)
            {
                current->right = new TreeNode(values[i]);
                q.push(current->right);
            }
            i++;
        }

        return root;
    }

    // Create a graph from adjacency list (index-based)
    static GraphNode *createGraph(vector<vector<int>> adjList)
    {
        if (adjList.empty())
            return nullptr;

        vector<GraphNode *> nodes(adjList.size());
        for (int i = 0; i < nodes.size(); i++)
        {
            nodes[i] = new GraphNode(i + 1); // Using 1-based values
        }

        for (int i = 0; i < adjList.size(); i++)
        {
            for (int neighborIdx : adjList[i])
            {
                nodes[i]->neighbors.push_back(nodes[neighborIdx]);
            }
        }

        return nodes[0];
    }
};

// Solution class where you'll implement your functions
class Solution
{
public:
    static int prec(char c)
    {
        if (c == '^')
            return 3;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    // Add your DSA solution methods here
    static void infixToPostfix(string s)
    {
        stack<char> st;
        st.push('N');
        int l = s.length();
        string ns;
        for (int i = 0; i < l; i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                ns += s[i];
            else if (s[i] == '(')
            {
                st.push('(');
            }
            else if (s[i] == ')')
            {

                while (st.top() != 'N' && st.top() != '(')
                {
                    char c = st.top();
                    st.pop();
                    ns += c;
                }
                if (st.top() == '(')
                {
                    char c = st.top();
                    st.pop();
                }
            }
            else
            {
                while (st.top() != 'N' && Solution::prec(s[i]) <= Solution::prec(st.top()))
                {
                    char c = st.top();
                    st.pop();
                    ns += c;
                }
                st.push(s[i]);
            }
        }
        while (st.top() != 'N')
        {
            char c = st.top();
            st.pop();
            ns += c;
        }
        cout << ns << endl;
    }
};

// Test runner to automatically execute your solutions
class TestRunner
{
public:
    void runTests()
    {
        Solution solution;
        string exp = "a+b*(c^d-e)^(f+g*h)-i";

        Solution::infixToPostfix(exp);
        // Add your test cases here
    }

    void printVector(const vector<int> &vec)
    {
        cout << "[";
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
            if (i != vec.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }
};

int main()
{
    TestRunner runner;
    runner.runTests();
    return 0;
}

