#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool cmp1(vector<int> a, vector<int> b) {
    if (a[0] == b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

struct Node {
    vector<int> job;
    int start;
};

bool operator<(Node a, Node b) {
    if (a.job[1] == b.job[1])
        return a.job[0] > b.job[0];
    return a.job[1] > b.job[1];
}

int solution(vector<vector<int>> jobs) {
    int count = 0, answer = 0, size = jobs.size();
    sort(jobs.begin(), jobs.end(), cmp1);
    priority_queue<Node> pq;
    pq.push(Node{ jobs[0], jobs[0][0] });
    Node now = { {0,0},0 };
    auto it = ++jobs.begin();
    while (!pq.empty()) {
        if (pq.top().start == -1)
            answer += now.start + now.job[1] + pq.top().job[1] - pq.top().job[0];
        else
            answer += pq.top().start + pq.top().job[1] - pq.top().job[0];
        int pre = now.job[1] + now.start;
        now = pq.top();
        if (now.start == -1)
            now.start = pre;
        pq.pop();
        count++;
        while (it != jobs.end() && now.job[1] + now.start >= (*it)[0]) {
            pq.push(Node{ *it, -1 });
            it++;
        }
        if (pq.empty() && count < size) {
            pq.push(Node{ *it, (*it)[0] });
            it++;
        }
    }
    return answer / count;
}