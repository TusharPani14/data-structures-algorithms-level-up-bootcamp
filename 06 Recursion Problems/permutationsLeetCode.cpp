#include <bits/stdc++.h>
using namespace std;
void recursiveSol(vector<vector<int>> &ans, vector<int> &nums, int l)
{
    if (l == nums.size())
        ans.push_back(nums);
    else
    {
        // Permutations made
        for (int i = l; i < nums.size(); i++)
        {

            // Swapping done
            swap(nums[l], nums[i]);

            // Recursion called
            recursiveSol(ans, nums, l + 1);

            // backtrack
            swap(nums[l], nums[i]);
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    recursiveSol(ans, nums, 0);
    return ans;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permuteResult = permute(nums);
    // Print the permutes using a for loop
    for (const auto &permute : permuteResult)
    {
        cout << "{ ";
        for (const int num : permute)
        {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}