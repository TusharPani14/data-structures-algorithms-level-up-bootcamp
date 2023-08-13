#include <bits/stdc++.h>
using namespace std;
void recursiveSol(int idx, vector<int> &nums, vector<vector<int>> &ans, vector<int> ds, bool prev)
{
    if (idx == nums.size())
    {
        ans.push_back(ds);
    }
    else
    {
        recursiveSol(idx + 1, nums, ans, ds, false);
        if (idx > 0 && nums[idx] == nums[idx - 1] && !(prev))
            return;
        ds.push_back(nums[idx]);
        recursiveSol(idx + 1, nums, ans, ds, true);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    vector<int> ds;
    recursiveSol(0, nums, ans, ds, false);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> subsetsResult = subsetsWithDup(nums);
    // Print the subsets using a for loop
    for (const auto &subset : subsetsResult)
    {
        cout << "{ ";
        for (const int num : subset)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}