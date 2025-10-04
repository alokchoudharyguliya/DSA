#include <bits/stdc++.h>
using namespace std;

// optimizing the counting of 1s in a row
// as the row is sorted so we know that as we face the first occurrence of 1 we will get 1s ahead
// using the formula Number_of_ones=m(number of columns)-first occurrence of 1(0-based index)

int lowerBound(vector<int>row,int m,int val){
    int low=0,high=m-1;
    int ans=m;
    while(low<=high){
        int mid=(low+high)/2;
        if(row[mid]>=val){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> mat, int n, int m)
{
    int cnt_max=0;
    int in=-1;
    for(int i=0;i<n;i++){
        int cnt_ones=m-lowerBound(mat[i],m,1);
        if(cnt_ones>cnt_max){
            cnt_max=cnt_ones;
            in=i;
        }

    }
    return in;
}

int main()
{
    vector<vector<int>> matrix = {{0, 1, 1}, {1, 1, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << rowWithMax1s(matrix, n, m);
}