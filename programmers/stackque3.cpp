#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int> > q;
    int truck_num = 0, i=0, bridge_weight = 0, passed = 0, truck_size =  truck_weights.size();
    while(passed < truck_size){
        i++;
        if(!q.empty() && i - q.front().second == bridge_length){
            bridge_weight -= q.front().first;
            q.pop();
            passed++;
        }
        if(bridge_weight + truck_weights[truck_num] <= weight){
            q.push(make_pair(truck_weights[truck_num], i));
            bridge_weight += truck_weights[truck_num++];
        }
    }
    return i;
}