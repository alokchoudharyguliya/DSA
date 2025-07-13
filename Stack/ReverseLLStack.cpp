#include <bits/stdc++.h>
#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
struct node
{
    int data;
    struct node *next;
};

void append(struct node **head, int new_data) // we don't change the head of the initial calling function rather we created a new one
{
    struct node *new_node = new node;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return;
    }
    // return new_node;
    struct node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}
void printLL(struct node *head)
{ // again new head node
    while (head)
    {
        /* code */
        cout << head->data << ",";
        head = head->next;
    }
}
void reverse(node *head)
{
    // stack<int> st;
    stack<node*>st;
    node *temp = head;
    while (temp != NULL)
    {
        // st.push(temp->data);
        st.push(temp);
        temp = temp->next;
    }
    while (!st.empty())
    {
        // int n = st.top();
        node* n = st.top();
        cout << n->data << ",";
        st.pop();
    }
}
using ll = long long;
using ld = long double;
const ll mod = 1e9 + 7;
const ll N = 2e5 + 10;
const ll inf = 1e9;
const ll linf = 1e18;
int main()
{
    fio;
    int t;
    cin >> t;
    while (t--)
    {
        struct node *head = NULL;
        append(&head, 5);
        append(&head, 4);
        append(&head, 3);
        append(&head, 2);
        append(&head, 1);
        printLL(head);
        cout<<endl;
        reverse(head);
    }
    return 0;
}