#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    vector<string> v;
    int i, j, len = clothes.size(), arr[40]={0,}, ans=1;
    bool is;
    for(i=0;i<len;i++){
        int vl = v.size();
        is = false;
        for(j=0;j<vl;j++){
            if(clothes[i][1].compare(v[j]) == 0){
                is = true;
                arr[j]++;
                break;
            }
        }
        if(!is){
            v.push_back(clothes[i][1]);
            arr[v.size()-1]++;
        }
    }
    for(i=0;i<v.size();i++){
        ans *= arr[i]+1;
    }
    return ans-1;
}

int main(){
    vector<vector<string>> s;
    s.push_back(vector<string>{"a","1"});
    s.push_back(vector<string>{"d","2"});
    s.push_back(vector<string>{"b","1"});

    cout << solution(s);
}