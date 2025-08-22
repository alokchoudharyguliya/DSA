<<<<<<< HEAD
#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int>arr={2,3,4,7,9};
	int diff=0;
	int k=4;
	int low=0;
	int high=arr.size()-1;
	while(low<=high)
	{	
		int mid=(low+high)/2;
		diff=arr[mid]-mid-1;
		if(diff<k){
			low=mid+1;
		}else
			high=mid-1;
	}

	cout<<k+high+1;


}
=======
// arr[]={2,3,4,7,11} k=5
// 1,5,6,8,9,10 missing 
// 5th number is 9

// for the present numbers, the number that is present results ki humara missing number ek aage shift ho jayega
// for the current number, the current number will take one place
#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={2,3,4,7,11};
    int k=5;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if(arr[i]<k)
            k++;
        else
        break;
    }
    cout<<k;
}

// What about its optimization?
// Current time - O(N) space - O(1)
// Optimized version lesser than O(N) will be O(logN) also given array is sorted so binary search not nomral but modified

// Why we cannot use typical binary search ?

// because we are looking for the number it is not present in the array
// What about binary search on answers
//
>>>>>>> 927909678b4f424954c1b4f4d7cd8d11081b3eae
