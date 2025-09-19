#include <bits/stdc++.h>
using namespace std;
class Parent
{
protected:
    int id_prot;
};
enum color
{
    red,
    green,
    blue
};
class Child : public Parent
{
public:
    void setId(int id)
    {
        id_prot = id;
    }
    void displayId()
    {
        cout << id_prot << endl;
    }
};
int main()
{
    Child ob1;
    ob1.setId(12);
    ob1.displayId();
    return 0;
}