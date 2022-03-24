#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct node{
    int index, play;
    string genre;
};

bool compare(pair<int, int> a, pair<int,int> b){
    if(a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int i, j, k, len = genres.size();
    vector<pair<int, int>> sum;
    vector<vector<node>> v;
    for(i=0;i<len;i++){
        int vl = v.size();
        node itemNode = {i, plays[i], genres[i]};
        for(j=0;j<vl;j++){
            if(v[j][0].genre.compare(genres[i]) == 0){
                int vvl = v[j].size();
                for(k=0;k<vvl;k++){
                    if(v[j][k].play < plays[i]){
                        v[j].insert(v[j].begin()+k, itemNode);
                        break;
                    }
                }
                if(k==vvl)
                    v[j].push_back(itemNode);
                sum[j].second += plays[i];
                break;
            }
        }
        if(j==vl){
            v.push_back(vector<node>{itemNode});
            sum.push_back(pair<int,int>(v.size()-1, plays[i]));
        }
    }
    sort(sum.begin(), sum.end(), compare);

    for(auto it=sum.begin();it!=sum.end();it++){
        int len = v[it->first].size();
        for(i=0;i<2 && i<len;i++){
            answer.push_back(v[it->first][i].index);
        }
    }

    return answer;
}


int main(){
    vector<string> g = {"classic", "pop", "classic", "classic", "pop"};
    vector<int> p = {500, 600, 150, 800, 2500};
    solution(g, p);
}