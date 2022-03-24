#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int cnt[10] = {0,}, len = priorities.size(), i, max_p = -1, ans = 1, ch[104]={-1,};
    for(i=0;i<len;i++){
        cnt[priorities[i]]++;
        if(max_p < priorities[i]) max_p = priorities[i];
    }
    for(i=0;i<len;){
        if(max_p == priorities[i]){
            if(--(cnt[max_p]) == 0){
                do{
                    max_p--;
                }while(cnt[max_p]==0 && max_p>0);
            }
            if(i == location)
                break;
            ch[i] = ans++;
        }
        if(++i == len) i=0;
    }
    return ans;
}

int main(){
    vector<int> a = {1,2,3,4,5,6};
    solution(a,0);
}