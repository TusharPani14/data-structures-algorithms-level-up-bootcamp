#include <bits/stdc++.h>
using namespace std;
bool divideAmongK(vector<int> books, int n, int k, int limit)
{

    int cnt = 1;
    int current_sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (current_sum + books[i] <= limit)
        {
            current_sum += books[i];
        }
        else
        {
            cnt += 1;
            if (books[i] > limit || cnt > k)
            {
                return false;
            }
            else
            {
                current_sum = books[i];
            }
        }
    }
    return true;
}

int minPages(vector<int> books, int m)
{
    int s = 0, e = 0;
    int n = books.size();
    for (int i = 0; i < n; i++)
    {
        e += books[i];
    }
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        bool isPossible = divideAmongK(books, n, m, mid);
        if (isPossible)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> books = {10, 20, 30, 15};
    int students = 2;
    cout << minPages(books, students);
}