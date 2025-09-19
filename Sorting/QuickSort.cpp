#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;
    
    while (i < j) {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)  // Fixed: changed arr[i] to arr[j]
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);  // Place pivot in correct position
    return j;  // Return pivot index
}

void qS(vector<int>& arr, int low, int high) {  // Added reference &
    if (low < high) {
        int pIndex = partition(arr, low, high);
        qS(arr, low, pIndex - 1);
        qS(arr, pIndex + 1, high);
    }
}

vector<int> quickSort(vector<int> &arr) {
    qS(arr, 0, arr.size() - 1);
    return arr;
}