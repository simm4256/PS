#include <string>
#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> ans;
    int i, len = progresses.size(), maxx=(((100-progresses[i])+speeds[0]-1)/speeds[0]), sum=1;
    for(i=1;i<len;i++){
        int x = (((100-progresses[i])+speeds[i]-1)/speeds[i]);
        if(x>maxx){
            maxx = x;
            ans.push_back(sum);
            sum=0;
        }
        sum++;
    }
    ans.push_back(sum);
    return ans;
}

int main(){
    solution(vector<int>{93,30,55}, vector<int>{1,30,5});
}