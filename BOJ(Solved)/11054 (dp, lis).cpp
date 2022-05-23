/*
LIS (by DP) 응용
is[x] : x가 마지막에 포함된 LIS 길이
ds[x] : x가 처음에 포함된 역 LIS 길이
ans : max(is[k]+ds[k]) k : [0, n)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, i, j;
    cin >> n;
    vector<int> arr, is(n, 0), ds(n, 0);
    for (i = 0; i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    is[0] = 1;
    for (i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && is[j] > is[i])
                is[i] = is[j];
        }
        is[i]++;
    }

    ds[n - 1] = 1;
    for (i = n - 2; i >= 0; i--)
    {
        for (j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && ds[j] > ds[i])
                ds[i] = ds[j];
        }
        ds[i]++;
    }

    int ans = 0;
    for (i = 0; i < n; i++)
    {
        int now = is[i] + ds[i] - 1;
        if (now > ans)
            ans = now;
    }
    cout << ans;
}