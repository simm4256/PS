#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int> > pq;
    int len = scoville.size(), i, ans = 0;
    for(i=0;i<len;i++)
        pq.push(scoville[i]);
    while(pq.size() > 1 && pq.top() < K){
        int x = pq.top(); pq.pop();
        int y = pq.top(); pq.pop();
        pq.push(x + y*2);
        ans++;
    }
    if(pq.size() == 1 && pq.top() < K)
        ans = -1;
    return ans;
}