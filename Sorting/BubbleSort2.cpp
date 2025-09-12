// bool swapped; for optimizing
for (int i = 0; i < n - 1; i++)
{
    swapped = false;
    for (j = i + 1; j < n + 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
            swapped = true;
        }
    }
    if (!swapped)
        break;
}

for (int i = 0; i < n - 1; i++)
{
    swapped = false;
    for (int j = 0; j < n - j - 1; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1])
                swapped = true
        }
    }
}