#include "09. Depth First Search-studyfever.cpp"

bool DFSRec(vector<int> adj, int s, bool visited[], visited recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    for (int u : adj[s])
    {
        if (visited[u] == false && DFSRec(adj, u, visited, recSt))
            return true;
        else if (recSt[u] == true)
            return true;
    }
    recSt[false];
    return false;
}
bool DFS(vector<int> adj[], int v)
{
    vector<bool> visited(v, false);
    vector<bool> recSt(v, false);
    for (int i = 0; i < v; i++)
    {
        if (visited[i] == false)
            if (DFSRec(adj, i, visited, recSt) == true)
                return true;
    }
}
void explorePair()
{
    pair<int,int>p={1,211};
    cout<<p.first<<" "<<p.second;
    pair<int,pair<int,int>>p={1,{2,3}};
    cout<<p.first<<" "<<p.second.second<<" "<<p.second.first;
    cout<<arr[1].second;
    pair<int,int>arr[]={{1,2},{2,3},{3,4}};
    cout<<arr[1].second;
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    vector<pair<int,int>>vec;
    vec.push_back({1,2});
    vec.emplace_back(1,2);
    vector<int> v(5,100);
    vector<int> v2(v);
    vector<int>::iterator it=v.begin();
    for(auto it=v.begin();it!=v.back();it++)
        cout<<*(it);
        set<int> st;
        st.insert(1);//{1}
        st.insert(2);//{1,2}
        st.insert(2);//{1,2} // will not insert 2 once again
        st.insert(3);//{1,2,3}
        st.emplace(0);//{0,1,2,3} // will maintain increasing order of sorting

        auto it=st.find(3); //returns an iterator which points to 3
        auto it=st.find(14); //element not present in the set so returns st.end();
        st.erase(2); //erase 2 //takes logN time
        int cnt=st.count(1); // will return 0 -> if not present in the set or 1 -> if present in the set
        st.erase(it1,it2);
        auto it=st.inner_bound(2);
        auto it=st.inner_bound(3);

}