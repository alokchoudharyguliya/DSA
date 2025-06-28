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
    // Add your DSA solution methods here
    void showstack(stack<int> s)
    {
        while (!s.empty())
        {
            // Pass by value a stack
            cout << "\t" << s.top();
            s.pop();
            cout << "\n";
        }
    }
};

// Test runner to automatically execute your solutions
class TestRunner
{
public:
    void runTests()
    {
        Solution solution;

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
    stack<int> s;
    s.push(10);
    s.push(30);
    s.push(20);
    s.push(5);
    s.push(1);
    showStack(s);
    cout << s.size();
    cout << s.top();
    s.pop();
    showStack(s);
    return 0;
}