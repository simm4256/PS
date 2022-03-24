/*
프로그래머스 - 파괴되지 않은 건물
https://programmers.co.kr/learn/courses/30/lessons/92344
누적합 개념 이용
1차원에서 [0,3]에 2를 더한다면
0에 2 4에 -2를 기입
최종으로 행단위 누적합 시행
하지만 이 문제는 2차원 배열이므로 2차원 누적합 이용
[0,0]~[2,2]에 2를 더한다면
0,0 3,3에 2
0,3 3,0에 -2를 대입
최종적으로 행단위로 먼저 누적합 시행, 이후 열단위로 누적합 시행
*/
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n, m;
    n = board.size();
    m = board[0].size();
    vector<vector<int>> sum(n+1, vector<int>(m+1, 0));
    for (auto i : skill) {
        int num = i[5] * (i[0] == 1 ? -1 : 1);
        sum[i[1]][i[2]] += num;
        sum[i[1]][i[4] + 1] -= num;
        sum[i[3] + 1][i[2]] -= num;
        sum[i[3] + 1][i[4] + 1] += num;
    }
    for (int i = 0; i < n; i++) {
        int now = sum[i][0];
        for (int j = 1; j < m; j++) {
            sum[i][j] += now;
            now = sum[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        int now = sum[0][i];
        for (int j = 1; j < n; j++) {
            sum[j][i] += now;
            now = sum[j][i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (sum[i][j] + board[i][j] > 0)
                ans++;
        }
    }
    return ans;
}