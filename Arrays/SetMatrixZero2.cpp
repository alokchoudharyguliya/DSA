//==========BRUTE FORCE================
#include <bits/stdc++.h>
using namespace std;
// void markRow(vector<vector<int>> &arr, int row)
// {
//     for (int i = 0; i < arr[0].size(); i++)
//     { // to fill all the values for zeros in the row // traverse for all the column values
//         if (arr[row][i] !=0)
//         {
//             arr[row][i] = -1;
//         }
//     }
// }
// void markCol(vector<vector<int>> &arr, int col)
// {
//     for (int i = 0; i < arr.size(); i++)
//     { // to fill all the values for zeros in the col // traverse for all the row values
//         if (arr[i][col] !=0)
//         {
//             arr[i][col] = -1;
//         }
//     }
// }
// vector<vector<int>> zeroMatrix(vector<vector<int>> &arr, int row, int col)
// {
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (!arr[i][j])
//             {
//                 markRow(arr, i);
//                 markCol(arr, j);
//             }
//         }
//     }
//     for (int i = 0; i < row; i++)
//     {
//         for (int j = 0; j < col; j++)
//         {
//             if (arr[i][j] == -1)
//                 arr[i][j] = 0;
//         }
//     }
//     return arr;
// }
// int main()
// {
//     vector<vector<int>> arr = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
//     int n = arr.size();    // row indices
//     int m = arr[0].size(); // column indices
//     vector<vector<int>> ans = zeroMatrix(arr, n, m);
//     for (auto it : ans)
//     {
//         for (auto ele : it)
//             cout << ele << ",";
//         cout << "\n";
//     }
// }

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix[0].size();
        int m=matrix.size();
        // int col[n] = {0};
        // int row[m] = {0};
        vector<int>col(n,0);
        vector<int>row(m,0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (matrix[i][j] == 0) ? (row[i] = 1, col[j] = 1) : (int)0;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

