/*
프로그래머스 - 정수 삼각형 (DP2)
https://programmers.co.kr/learn/courses/30/lessons/43105
dp[n][m] += max(dp[n-1][m-1], dp[n-1][m])
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
	int h = triangle.size();
	for (int i = 1; i < h; i++) {
		for (int j = 0; j <= i; j++) {
			int a, b;
			a = b = -1;
			if (j > 0)
				a = triangle[i - 1][j - 1];
			if (j < i)
				b = triangle[i - 1][j];
			triangle[i][j] += max(a, b);
		}
	}
	sort(triangle.back().begin(), triangle.back().end());
	return triangle.back().back();
}