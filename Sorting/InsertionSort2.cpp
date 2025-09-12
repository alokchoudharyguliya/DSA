for (int i = 1; i < n; i++)
{
    int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = key;
}
// Time -> Worst - O(n)
//    Average - O(n^2)
//    Worst - O(n^2)
// Space O(1)


for(int i=1;i<n;i++){
    int key=arr[i]
    int j=i-1;
    while(j>=0&&arr[j]<key){
        arr[j+1]=arr[j--];
    }
    arr[j+1]=key
}