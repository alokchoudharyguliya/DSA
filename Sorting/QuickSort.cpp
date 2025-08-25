// a divide and conquer algorithm like Merge Sort
// unlike merge sort does not use any extra array for sorting
// uses an auxiliary space .: slightly better than merge sort

// Algo is basically a repetition of two simple steps:
// 1. Pick a pivot and place it in its correct place in the sorted array
// 2. Shift smaller elements (i.e. smaller than pivot) on the left of the pivot and larger ones to the right.


// Choosing the pivot
// It can be any element of our choice
    // first element of the array
    // last element of the array
    // median of the array
    // any random element of the array
// place it in its correct position (i.e. The place it should be after the array gets sorted) in the array. 
// {4.6.2.5.7.9.1.3} correct position of 4 will be 4th position


// let's choose first element as our pivot
// shift the smaller elements(smaller than pivot) to the left of the pivot and larger ones to the right of the pivot.
// if we choose 4 as pivot, after performing step 3 the array will be {3,2,1,4,6,5,7,9}

// we can see that after completing the steps, pivot 4 is in its corect position with the right and left subarray unsorted.
// Now we will apply these two steps on the left subarray and right subarray recursively.
// And we continue this process until the size of the unsorted part becomes 1.

// low=first index
// high=last index
// partition() function 
// partition index, creates a parition between left and right unsorted subarrays.
// After placing the pivot in the partition inde, call the function quickSort(left subarray) quickSort(right subarray) 
// range of the left subarray will be [low to (parition index -1) ] and the range of the right subarray be [(parition index +1) to high]
// continue until the ranges becomes 1

#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int>&arr){
    int n=arr.size();
    for(int i=0;i<n;i++)
    cout<<arr<<",";
}
int partition(vector<int>&arr,int low, int high){
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j){
        while(arr[i]<=pivot&&i<=high-1)i++;
        while(arr[j]>pivot&&j>=low+1)j--;
        if(i<j)swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}
void qs(vector<int>&arr,int low,int high)
{
    if(low<high){
        int pIndex=partition(arr,low,high);
        qs(arr,low,pIndex-1);
        qs(arr,pIndex+1,high);
    }
}
vector<int>quickSort(vector<int>&arr){
    qs(arr,0,arr.size()-1);
    return arr;
}

int main(){
    vector<int>arr={4,6,2,5,7,9,1,3};
    arr=quickSort(arr);
    printArr(arr);
}