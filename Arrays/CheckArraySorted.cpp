// 1. Nested Loop
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        if (arr[i] > arr[j])
            return false;
    }
}

// 2. Single Traversal
for (int i = 1; i < n; i++)
{
    if (arr[i] < arr[i - 1])
        return false;
}