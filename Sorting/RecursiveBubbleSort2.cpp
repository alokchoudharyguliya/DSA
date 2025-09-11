if (n == 1)
    return;

for (int i = 0; i < n - 1; i++)
{
    if (arr[i] < arr[i + 1])
        swap(arr[i], arr[i + 1]);
}
bubble(arr, n - 1);