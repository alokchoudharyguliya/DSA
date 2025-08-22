/*
 * Given a matrix if an element in the matrix is 0 then we will have to set its entire column and row to 0 and return the matrix
 *
 *
 */
#include<bits/stdc++.h>
using namespace std;
/*
void markRow(vector<vector<int>>&matrix,int n, int m, int row){

	for(int i=0;i<m;i++)
	{
		if(matrix[row][i]!=0)
			matrix[row][i]=-1;
	}
}

void markCol(vector<vector<int>>&matrix, int n, int m, int col){
	for(int i=0;i<n;i++)
	{
		if(matrix[i][col]!=0){
			matrix[i][col]=-1;
		}
	}
}

vector<vector<int>>zeroMatrix(vector<vector<int>>&matrix, int n,int m){
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0)
			{
				markRow(matrix,n,m,i);
				markCol(matrix,n,m,j);
			}

		}
	}
	for(int i=0;i<n;i++)
	{

	for(int j=0;j<m;j++){
		if(matrix[i][j]==-1)
			matrix[i][j]=0;
	}
	}
	return matrix;
}
*/

// Using two extra arrays
// Two loops to traverse
// if found a zero in matrix then mark the respective column and row as 1 in the row and column array
// Traverse the entire matrix again and we will put 0 into all the cells for which either row or col is marked 1
//
/*
vector<vector<int>>zeroMatrix(vector<vector<int>>&matrix,int n, int m){
	int row[n]={0};
	int col[m]={0};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		if(matrix[i][j]==0){

			row[i]=1;
			col[j]=1;
		}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
		if(row[i]||col[j]){
			matrix[i][j]=0;
		}
		}
	}
	return matrix;
}
*/
vector<vector<int>>zeroMatrix(vector<vector<int>>&matrix, int n, int m){
		int col0=1;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(matrix[i][j]==0){
					matrix[i][0]=0;
					if(j!=0)
						matrix[0][j]=0;
					else
						col0=0;
				}	
			}
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<m;j++){
				if(matrix[i][j]!=0){
					if(matrix[i][0]==0||matrix[0][j]==0){
						matrix[i][j]=0;
					}
				}
			}
		}
		if(matrix[0][0]==0){
			for(int i=0;i<m;i++)
				matrix[0][i]=0;
		}
		if(col0==0){
			for(int i=0;i<n;i++){
				matrix[i][0]=0;
			}
		}
		return matrix;
}
int main(){
	vector<vector<int>>matrix={{1,1,1},{1,0,1},{1,1,1}};
	int n=matrix.size();
	int m=matrix[0].size();
	vector<vector<int>>ans=zeroMatrix(matrix,n,m);
	for(auto it:ans){
		for(auto ele:it){
			cout<<ele<<",";
		}
		cout<<endl;
	}
	return 0;
}

