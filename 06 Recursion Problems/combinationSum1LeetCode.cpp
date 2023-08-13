
#include <bits/stdc++.h>
using namespace std;
void recursiveFun(int idx, vector<vector<int>> &ans, int target, vector<int> &ds, vector<int> &candidates)
{
    if (idx == candidates.size())
    {
        if (target == 0)
            ans.push_back(ds);
        return;
    }
    if (candidates[idx] <= target)
    {
        ds.push_back(candidates[idx]);
        recursiveFun(idx, ans, target - candidates[idx], ds, candidates);
        ds.pop_back();
    }
    recursiveFun(idx + 1, ans, target, ds, candidates);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    recursiveFun(0, ans, target, ds, candidates);
    return ans;
}

int main()
{
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> subsetsResult = combinationSum(candidates, target);
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