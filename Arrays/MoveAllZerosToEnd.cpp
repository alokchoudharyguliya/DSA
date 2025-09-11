/* 1. 
 * For X non-zero elements copy them into a temp array
 * Now copy back these X non-zero elements to the original array and fill the remaining N-X places with zeros.
 */

/* 2.
	use two pointers and try to replace all the zero places with non-zero elements increment the pointer of zero position only when it has been replaced with a nonzero element
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> moveZeros(int n, vector<int> a)
{
	int j = -1;
	for (int i = 0; i < n; i++)
	{
		// find the point where there is a zero
		if (a[i] == 0)
		{
			j = i;
			break;
		}
	}
	// no zero found
	if (j == -1)
		return a;

	// after the position where zero is found
	for (int i = j + 1; i < n; i++)
	{
		if (a[i] != 0) // just like removing duplicacy, i pointing to a nonzero element, we store the nonzero element at the position of zero element
		{
			swap(a[i], a[j]);
			j++;
		}
	}

	return a;
}
int main()
{
	vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
	int n = 10;
	vector<int> ans = moveZeros(n, arr);
	for (auto &it : ans)
		cout << it << ",";
	cout << "\n";
	return 0;
}
