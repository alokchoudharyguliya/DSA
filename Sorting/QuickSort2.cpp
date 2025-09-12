int partition(vector<int> arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[i] > pivot && i >= low + 1)
            j--;
        if (i < j)
            swap(arr[i], arr[j]);
    }
}

void qS(vector<int> arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qS(arr, low, pIndex - 1);
        qS(arr, pIndex + 1, high);
    }
}
vector<int> quickSort(vector<int> &arr)
{
    qS(arr, 0, arr.size() - 1);
    return arr;
}

int partition(vector<int> arr, int low, int high)
{
    int i = low;
    int high = j;
    int pivot = arr[low];
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[i] > pivot && i >= low + 1)
            j++;
        if (i < j)
            swap(arr[i], arr[j]);
    }
}
void qS(vector<int> arr, int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        qS(arr, low, pIndex - 1);
        qS(arr, pIndex + 1, high;)
    }
}

vector<int> quickSort(vector<int> &arr)
{
    qs(arr, 0, arr.size() - 1);
    return arr;
}