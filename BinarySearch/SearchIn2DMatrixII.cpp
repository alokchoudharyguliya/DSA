// performing 1D binary search for each row
int BS(vector<int> row, int tar)
{
    int low = 0, high = row.size();
    while (low < high)
    {
        int mid = (low + high) >> 1;

        if (row[mid] < tar)
        {
            low = mid + 1;
        }
        else if (row[mid] > tar)
        {
            high = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
for (int i = 0; i < n - 1; i++)
{
    ind = BS(mat[i], target);
    if (ind != -1)
    {
        return {i, ind};
    }
    return {-1, -1};
}