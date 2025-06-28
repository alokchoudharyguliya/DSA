#include <bits/stdc++.h>
using namespace std;

void leftViewUtil(node *root)
{
    queue<node *> q;
    if (root == NULL)
        return;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        if (temp)
        {
            cout << temp->data;
            while (q.front() != NULL)
            {
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
                q.pop();
                temp = q.front();
            }
            q.push(NULL);
        }
        q.pop();
    }
}
