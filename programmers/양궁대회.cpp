/*
프로그래머스 - 양궁대회
https://programmers.co.kr/learn/courses/30/lessons/92342
10점부터 모든 경우의 수 다 탐색
단, 점수가 같은 경우 낮은 점수에 많이 맞힌쪽으로 갱신
*/

#include <string>
#include <vector>

using namespace std;

vector<int> ans = { -1 };
int sum_max = -1;

void brute_force(vector<int> now, int arrows, vector<int> info, int ind, int sum, int goal) {
    if (ind == 10) {
        if (sum > goal && sum - goal >= sum_max) {
            now.push_back(arrows);
            if (sum - goal == sum_max) {
                for (int i = 10; i >= 0; i--) {
                    if (now[i] == ans[i])
                        continue;
                    if (now[i] > ans[i])
                        ans = now;
                    break;
                }
            }
            else {
                ans = now;
                sum_max = sum - goal;
            }
        }
        return;
    }
    vector<int> a, b;
    a = now; b = now;
    if (arrows >= info[ind] + 1) {
        a.push_back(info[ind] + 1);
        brute_force(a, arrows - info[ind] - 1, info, ind + 1, sum + 10 - ind, (info[ind] == 0 ? goal : goal - 10 + ind));
    }
    b.push_back(0);
    brute_force(b, arrows, info, ind + 1, sum, goal);
}

vector<int> solution(int n, vector<int> info) {
    int goal = 0;
    for (int i = 0; i < 11; i++)
        goal += (info[i] == 0 ? 0 : 10 - i);
    brute_force({}, n, info, 0, 0, goal);
    return ans;
}

int main() {
    solution(5, { 2,1,1,1,0,0,0,0,0,0,0 });
}