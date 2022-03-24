/*
프로그래머스 - 등굣길(DP3)
https://programmers.co.kr/learn/courses/30/lessons/42898
dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD
단, (m,n)이 주어질 때 순서가 반대인 함정에 유의
*/

#include <string>
#include <vector>

using namespace std;
const int MOD = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(int(n), vector<int>(int(m), 0));
    dp[0][0] = 1;
    for (auto i : puddles) {
        dp[i[1] - 1][i[0] - 1] = -1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] != 0)
                continue;
            int a, b;
            a = b = 0;
            if (i > 0 && dp[i - 1][j] != -1)
                a = dp[i - 1][j];
            if (j > 0 && dp[i][j - 1] != -1)
                b = dp[i][j - 1];
            dp[i][j] = (a + b) % MOD;
        }
    }
    return dp[n - 1][m - 1];
}

int main() {
    int x = solution(4, 3, { {2,2} });
}