void maxHeapify(int arr[], int n, int i)
{
    int largest=i, left=2*i+1, right=2*(i+1);
    if(left<n && arr[left]>arr[largest] )largest=left;

    if(right<n && arr[right]>arr[largest]) largest=right;

    if(largest!=i)
    {
        swap(arr[largest],arr[i]);
        maxHeapify(arr,n, largest);
    }
}
void buildHeap(int arr[], int n)
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        maxHeapify(arr,n,i);
    }
}