/*
프로그래머스 - 양과 늑대
https://programmers.co.kr/learn/courses/30/lessons/92343
root 노드부터 출발, 현재까지 지나온 노드 passed + 갈 수 있는 노드 can을 큐에 넣으면서 BFS
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct node {
    vector<int> passed, can;
    int sum, sheep;
};

vector<int> sum_vector(vector<int> a, vector<int> b) {
    vector<int> res = a;
    res.insert(res.end(), b.begin(), b.end());
    return res;
}

vector<int> del_vector(vector<int> a, int b) {
    vector<int> res = a;
    auto it = find(res.begin(), res.end(), b);
    res.erase(it);
    return res;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int n = info.size();
    queue<node> q;
    vector<vector<int>> v(n);
    for (auto i : edges) {
        v[i[0]].push_back(i[1]);
    }
    q.push(node{ {0},v[0], 1, 1 });
    int ans = 1;
    while (!q.empty()) {
        node now = q.front();
        q.pop();
        for (auto i : now.can) {
            if (info[i] == 1 && now.sum < 2)
                continue;
            node tmp;
            tmp.passed = sum_vector(now.passed, { i });
            tmp.can = sum_vector(del_vector(now.can, i), v[i]);
            tmp.sum = (now.sum + (info[i] == 1 ? -1 : 1));
            tmp.sheep = now.sheep + (info[i] == 1 ? 0 : 1);
            q.push(tmp);

            if (tmp.sheep > ans)
                ans = tmp.sheep;
        }
    }
    return ans;
}