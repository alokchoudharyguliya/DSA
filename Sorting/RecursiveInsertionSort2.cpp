void insertion(vector<int> &arr, int n, int i)
{
    int temp = i;
    int var = arr[i];
    while (i > 0 && arr[i] < arr[i - 1])
    {
        swap(arr[i], arr[i - 1]);
        i--;
    }

    arr[i] = var
        insertion(arr, n, temp + 1);
    return
}