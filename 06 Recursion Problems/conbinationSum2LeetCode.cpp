#include <bits/stdc++.h>
using namespace std;
void recursiveFun(int idx, vector<vector<int>> &ans, int target, vector<int> &ds, vector<int> &candidates, bool prev)
{
    if (idx == candidates.size())
    {
        if (target == 0)
            ans.push_back(ds);
        return;
    }
    else
    {
        recursiveFun(idx + 1, ans, target, ds, candidates, false);
        if (candidates[idx] <= target)
        {
            if (idx > 0 && candidates[idx] == candidates[idx - 1] && !(prev))
                return;
            ds.push_back(candidates[idx]);
            recursiveFun(idx + 1, ans, target - candidates[idx], ds, candidates, true);
            ds.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> ds;
    recursiveFun(0, ans, target, ds, candidates, false);
    return ans;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> subsetsResult = combinationSum2(candidates, target);
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