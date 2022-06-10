/*
수학 미로_LV2.cpp
알고리즘 : DFS
시작지점부터 DFS를 돌려 출구에 도착할 때마다 계산값이 목표값과 같은지 비교하고,
같다면 답을 +1합니다.
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

bool check[5][5];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int row, col, ans;

long long calc(long long a, long long b, char oprt) {
    switch (oprt) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return a / b;
    }
}

int cnt;
void dfs(vector<string> maze, stack<vector<int>> passed, vector<int> nowloc,
         vector<int> eloc, long long sum, char oprt, long long goal) {
    passed.push({nowloc[0], nowloc[1], (int)sum, (int)oprt});
    cnt++;
    if (nowloc == eloc) {
        if (sum == goal) {
            vector<vector<int>> t;
            stack<vector<int>> s = passed;
            while (!s.empty()) {
                t.push_back(s.top());
                s.pop();
            }
            reverse(t.begin(), t.end());
            for (auto it = t.begin(); it != t.end(); it++) {
                cout << '(' << it->at(0) << ',' << it->at(1)
                     << ") : " << it->at(2) << " | " << (char)it->at(3) << '\n';
            }
            cout << "-------------------------------------------\n";
            ans++;
        }
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        if (nowloc[0] + dy[dir] >= row || nowloc[0] + dy[dir] < 0 ||
            nowloc[1] + dx[dir] >= col || nowloc[1] + dx[dir] < 0)
            continue;
        vector<int> nextloc = {nowloc[0] + dy[dir], nowloc[1] + dx[dir]};
        if (check[nextloc[0]][nextloc[1]]) continue;

        char now = maze[nowloc[0]][nowloc[1]];
        char next = maze[nowloc[0] + dy[dir]][nowloc[1] + dx[dir]];
        long long tmp = sum;

        if (next >= '0') {
            if (now < '0') {
                if (oprt == -1 || (oprt == '/' && next == '0')) continue;
                tmp = calc(sum, next - '0', oprt);
            } else {
                tmp = sum * 10 + (next - '0');
            }
        }

        check[nextloc[0]][nextloc[1]] = true;
        dfs(maze, passed, nextloc, eloc, tmp, (next < '0' ? next : oprt), goal);
        check[nextloc[0]][nextloc[1]] = false;
    }
    passed.pop();
    return;
}

int solution(vector<string> maze, vector<int> sloc, vector<int> eloc,
             long long goal) {
    row = maze.size();
    col = maze[0].length();
    check[sloc[0]][sloc[1]] = true;
    dfs(maze, stack<vector<int>>(), sloc, eloc, maze[sloc[0]][sloc[1]] - '0',
        -1, goal);
    return ans;
}

int main() {
    // solution({ "50/4-", "*8/35", "12*++", "+537-", "0*/+9" }, { 3, 2 }, { 2,
    // 0 }, 3521);
    solution({"1+", "+2"}, {0, 0}, {1, 1}, 2);
}