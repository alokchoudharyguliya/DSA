/*
 * Given row number and column number. Print the element at position(r,c) in Pascal's Triangle
 *
 * Given the row number n, Print the nth row of Pascal's Triangle
 *
 * Given the number of rows n, Print the first n rows of Pascal's Trianlge
 *
 *
 */

#include<bits/stdc++.h>
using namespace std;
int nCr(int n,int r){
	long long res=1;
	for(int i=0;i<r;i++){
	res=res*(n-i);
	res=res/(i+1);

	}
	return res;
}
int pascalTriangle(int r,int c)
{
	int element=nCr(r-1,c-1);
	return element;
}
int main(){
	int r=5,c=3;
	int element=pascalTriangle(r,c);
	cout<<element<<endl;
	return 0;
}
