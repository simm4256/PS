/*
프로그래머스 - 주차 요금 계산
https://programmers.co.kr/learn/courses/30/lessons/92341
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, pair<int, int> > m; //차량번호, sum, 입차된시간
    for (auto order : records) {
        bool in = (order.back() == 'N' ? true : false);
        int time = stoi(order.substr(0, 2)) * 60 + stoi(order.substr(3, 2));
        string num = order.substr(6, 4);
        if (in) {
            if (m.find(num) == m.end()) {
                m[num] = make_pair(0, time);
            }
            else {
                m[num].second = time;
            }
        }
        else {
            m[num].first += time - m[num].second;
            m[num].second = -1;
        }
    }
    vector<int> ans;
    for (auto i : m) {
        int res = 0;
        res += i.second.first;
        if (i.second.second != -1)
            res += (23 * 60 + 59) - i.second.second;
        res -= fees[0];
        if (res < 0)
            res = 0;
        ans.push_back(fees[1] + (res)/fees[2]*fees[3] + ((res)%fees[2] == 0 ? 0 : fees[3]) );
    }
    return ans;
}

int main() {
    solution({ 180,5000,10,600 }, { "05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT" });
}