#include <bits/stdc++.h>
using namespace std;
void recursiveSol(vector<int> nums, vector<int> output, vector<vector<int>> &result)
{
    if (nums.size() == 0)
    {
        result.push_back(output);
        return;
    }
    int last_elem = nums[nums.size() - 1];
    nums.pop_back();
    recursiveSol(nums, output, result);
    output.push_back(last_elem);
    recursiveSol(nums, output, result);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<int> output;
    vector<vector<int>> result;
    recursiveSol(nums, output, result);
    return result;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<vector<int>> subsetsResult = subsets(nums);
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
