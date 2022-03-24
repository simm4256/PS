/*
프로그래머스 - 도둑질(DP4)
https://programmers.co.kr/learn/courses/30/lessons/42897
dp[i][0] = money[i]를 선택했을 때 최댓값 = dp[i-1][1] + money[i]
dp[i][1] = money[i]를 선택하지 않았을 때 최댓값 = max(dp[i-1][0], dp[i-1][1])
단, money 배열이 원형이므로, 0번째를 선택했을 때와 선택하지 않았을 때로 나누어 계산, max값 return

주의점 : 2차원 벡터의 크기를 [100005][2] 와 같이 선언 시 동적할당을 n번 하게 되어 시간초과
따라서 크기를 바꾸던가 vector<pair<int, int>> 로 선언하던가 아예 처음부터 array로 하던가 해야함
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int n = money.size(), a, b;
    vector<vector<int>> dp(2, vector<int>(n));
    dp[0][0] = money[0]; dp[1][0] = 0;
    dp[0][1] = money[0]; dp[1][1] = money[0];
    for (int i = 2; i < n; i++) {
        dp[0][i] = (dp[1][i - 1] + money[i]);
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }
    a = dp[1][n - 1];

    dp[0][0] = 0; dp[1][0] = 0;
    for (int i = 1; i < n; i++) {
        dp[0][i] = dp[1][i - 1] + money[i];
        dp[1][i] = max(dp[0][i - 1], dp[1][i - 1]);
    }
    b = max(dp[0][n - 1], dp[1][n - 1]);
    return max(a, b);
}


int main() {
    int x = solution({ 0,0,0 });
}