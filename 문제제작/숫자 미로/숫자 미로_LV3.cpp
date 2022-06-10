/*
숫자 미로_LV3.cpp
알고리즘 : DFS
시작지점부터 DFS를 돌려 출구에 도착할 때마다 계산값이 목표값과 같은지 비교하고, 같다면 답을 +1합니다.
*/

#include <iostream>
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

void dfs(vector<string> maze, vector<int> nowloc, vector<int> eloc, long long sum, char oprt, long long target) {
    if (nowloc == eloc) {
        if (sum == target) {
            ans++;
        }
        return;
    }
    for (int dir = 0; dir < 4; dir++) {
        if (nowloc[0] + dy[dir] >= row || nowloc[0] + dy[dir] < 0 ||
            nowloc[1] + dx[dir] >= col || nowloc[1] + dx[dir] < 0)
            continue;
        vector<int> nextloc = {nowloc[0] + dy[dir], nowloc[1] + dx[dir]};
        if (check[nextloc[0]][nextloc[1]])
            continue;

        char now = maze[nowloc[0]][nowloc[1]];
        char next = maze[nextloc[0]][nextloc[1]];
        long long tmp = sum;

        if (next >= '0') {
            if (now < '0') {
                if (oprt == -1 || (oprt == '/' && next == '0'))
                    continue;
                tmp = calc(sum, next - '0', oprt);
            } else {
                tmp = sum * 10 + (next - '0');
            }
        }

        check[nextloc[0]][nextloc[1]] = true;
        dfs(maze, nextloc, eloc, tmp, (next < '0' ? next : oprt), target);
        check[nextloc[0]][nextloc[1]] = false;
    }
    return;
}

int solution(vector<string> maze, vector<int> sloc, vector<int> eloc, long long target) {
    row = maze.size();
    col = maze[0].length();
    check[sloc[0]][sloc[1]] = true;
    dfs(maze, sloc, eloc, maze[sloc[0]][sloc[1]] - '0', -1, target);
    return ans;
}

int main() {
    solution({"50/4-", "*8/35", "12*++", "+537-", "0*/+9"}, {0, 0}, {4, 4}, 126);
    // solution({"50/4-", "*8/35", "12*++", "+537-", "0*/+9"}, {0, 0}, {4, 4}, 120);
    // solution({ "50/4-", "*8/35", "12*++", "+537-", "0*/+9" }, { 3, 2 }, { 2, 0 }, 3521);
    // solution({ "1+","+2" }, { 0,0 }, { 1,1 }, 2);
}