#include<bits/stdc++.h>
using namespace std;

// Transpose the matrix(changing the columns to rows and rows to columns)
// Reverse each row of the matrix

void rotateTranspose(vector<vector<int>>&matrix){
	int n=matrix.size();
	for(int i=0;i<n;i++)	
	{
		for(int j=0;j<i;j++){
		swap(matrix[i][j],matrix[j][i]);
		}
	}
	for(int i=0;i<n;i++){
		reverse(matrix[i].begin(),matrix[i].end());
	}
}


vector<vector<int>>rotate(vector<vector<int>>&matrix){
	int n=matrix.size();
	vector<vector<int>>rotated(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			//All the SAAR of the question is in this line
			rotated[j][n-i-1]=matrix[i][j];
		}
	}
	return rotated;
}
int main(){
	vector<vector<int>>arr;
	arr={{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int>>rotated=rotate(arr);
	rotateTranspose(arr);
	for(int i=0;i<rotated.size();i++)
	{
		for(int j=0;j<rotated[0].size();j++){
			cout<<rotated[i][j]<<",";
		}
		cout<<endl;
	}
	cout<<endl;
	cout<<endl;
	for(int i=0;i<arr.size();i++)
	{
		for(int j=0;j<arr[0].size();j++)
			cout<<arr[i][j]<<",";
		cout<<endl;
	}
	return 0;
}
