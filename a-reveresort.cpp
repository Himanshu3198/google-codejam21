#include <bits/stdc++.h>
using namespace std;

int findMin(int i, vector<int> &nums, int n)
{
    int minval = nums[i];
    int index = i;

    for (int j = i; j < n; j++)
    {

        if (nums[j] < minval)
        {
            minval = nums[j];
            index = j;
        }
    }
    return index;
}

void reverse(vector<int> &nums, int start, int end)
{

    while (start < end)
    {

        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

int main()
{

    int t;
    cin >> t;
    for (int tt = 1; tt <= t; tt++)
    {

        int n;
        cin >> n;
        vector<int> v, ans;

        int val;

        for (int i = 0; i < n; i++)
        {
            cin >> val;
            v.push_back(val);
        }

        int cost, minIndex;
        for (int i = 0; i < n - 1; i++)
        {

            minIndex = findMin(i, v, n);

            reverse(v, i, minIndex);
            if (i == minIndex)
            {
                cost = 1;
            }
            else
            {
                cost = minIndex - i + 1;
            }
            ans.push_back(cost);
        }
        int finalCost = 0;

        for (int i = 0; i < ans.size(); i++)
        {

            finalCost += ans[i];
        }

        cout << "Case #" << tt << ": "<<finalCost << "\n";
    }

    return 0;
}
