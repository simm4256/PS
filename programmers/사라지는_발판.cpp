/*
프로그래머스 - 사라지는 발판
https://programmers.co.kr/learn/courses/30/lessons/92345
게임이론
서로 움직일 수 있는 말의 위치가 다르고, 패자는 가장 늦게 지는 방법을 찾기 때문에 DFS로 해결
가장 빨리 이기는 방법을 찾는 것이기 때문에, 가능한 행동 집합의 모든 행동의 결과의 level을 저장하고
이길 수 있다면 이긴 결과 중 가장 작은 것을
이길 수 없다면 진 결과 중 가장 높은 것을 return
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dx = { 1,0,-1,0 },
            dy = { 0,1,0,-1 };
int n, m;

bool cmp1(pair<bool, int> a, pair<bool, int> b) {
    return a.second < b.second;
}
bool cmp2(pair<bool, int> a, pair<bool, int> b) {
    return a.second > b.second;
}

pair<bool, int> dfs(vector<vector<int>> board, bool player, vector<int> aloc, vector<int> bloc, int level) {
    vector<int> now = (player ? aloc : bloc);
    int a = now[0], b = now[1];
    
    if (!board[a][b]) {
        return make_pair(false, level);
    }
    vector<pair<bool, int>> win, lose;
    bool can_win = false;
    for (int i = 0; i < 4; i++) {
        if (a + dy[i] == n || a + dy[i] == -1 || b + dx[i] == m || b + dx[i] == -1 || board[a + dy[i]][b + dx[i]] == 0)
            continue;
        vector<vector<int>> tmp = board;
        tmp[a][b] = 0;
        pair<bool, int> res = dfs(tmp, !player, (player ? vector<int>{a + dy[i], b + dx[i]} : aloc), (player ? bloc : vector<int>{ a + dy[i], b + dx[i] }), level + 1);
        if (!res.first) {
            can_win = true;
            win.push_back(make_pair(!res.first, res.second));
        }
        else
            lose.push_back(make_pair(!res.first, res.second));
    }
    if (win.empty() && lose.empty()) {
        return make_pair(false, level);
    }
    else if(can_win){
        sort(win.begin(), win.end(), cmp1);
        return win[0];
    }
    else {
        sort(lose.begin(), lose.end(), cmp2);
        return lose[0];
    }
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    n = board.size();
    m = board[0].size();
    return dfs(board, true, aloc, bloc, 0).second;
}

int main() {
    int x = solution({ {1,1,1},{1,1,1,},{1,1,1} }, { 1,0 }, { 1,2 });
}