/*
 * Main catch is that we can break so, pick the one with maximum value/weight first
 *
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;
struct Item
{
	int val;
	int weight;
};
class Solution
{
public:
	bool static comp(Item a, Item b)
	{
		double r1 = (double)a.val / (double)a.weight;
		double r2 = (double)b.val / (double)b.weight;
		return r1 > r2;
	}
	double fractionalKnapsack(int W, Item arr[], int n)
	{
		sort(arr, arr + n, comp);
		int curWeight = 0;
		double finalValue = 0.0;
		for (int i = 0; i < n; i++)
		{
			if (curWeight + arr[i].weight <= W)
			{
				curWeight += arr[i].weight;
				finalValue += arr[i].val;
			}
			else
			{
				int remain = W - curWeight;
				finalValue += (arr[i].val / (double)arr[i].weight) * (double)remain;
				break;
			}
		}
		return finalValue;
	}
};
int main()
{
	int n = 3, weight = 50;
	Item arr[n] = {{100, 20}, {60, 10}, {120, 30}};
	Solution sol;
	double ans = sol.fractionalKnapsack(weight, arr, n);
	cout << setprecision(2) << fixed << ans << endl;
}
