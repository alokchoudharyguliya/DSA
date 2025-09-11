// 1. Using Hashset that is set in CPP
int removeDuplicates(int arr[], int n)
{
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        set.insert(arr[i]);
    }
    int k = st.size();
    int j = 0;
    for (auto x : st)
    {
        arr[j++] = x;
    }
    return k;
}

// 2. Two Pointers
int removeDuplicates(int arr[], int n)
{
    int i = 0;
    for (int j = 1; j < n; j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return i + 1;
}