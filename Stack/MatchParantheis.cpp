/* Analyzing the logic
        Having a string {}{} where 
                        .
                        add into stack
                        {}{}
                         .
                         Now the last guy into the stack must match this closing one because who soever was in between we already popped those from the stack
                         
*/
#include <bits/stdc++.h>
#define fio                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define debug(_) cout << #_ << " is " << _ << '\n';
using namespace std;
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
        // char brackType[]={'{',}
        string inp = "[[]{()}]()";
        stack<char> st;
        for (int i = 0; i < inp.length(); i++)
        {
            if (inp[i] == '{' || inp[i] == '[' || inp[i] == '(')
            {
                st.push(inp[i]);
                // continue;
            }
            if (st.empty())
            {
                cout << "Invalid";
                return 1;
            }
            else if (inp[i] == '}' || inp[i] == ']' || inp[i] == ')')
            {
                char top = st.top();
                st.pop();
                switch (inp[i])
                {
                case '}':
                    if (top == '{')
                        /* code */
                        break;
                    else
                    {
                        cout << "Invalid";
                        return 1;
                        // break;
                    }
                case ']':
                    if (top == '[')
                        break;

                    else
                    {
                        cout << "Invalid";
                        return 1;
                        break;
                    }
                case ')':
                    if (top == '(')
                        break;

                    else
                    {
                        cout << "Invalid";
                        return 1;
                        break;
                    }
                }
            }
        }
        st.empty()?cout<<"OK":cout<<"Invalid";
    }
    return 0;
}
