#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    int len = phone_book.size(), i;
    sort(phone_book.begin(), phone_book.end());
    string a, b;
    for(i=1;i<len;i++){
        a = phone_book[i-1], b = phone_book[i];
        if(a.compare(b.substr(0, a.size())) == 0) 
            return false;
    }
    return true;
}

int main(){
    int n;
    string s;
    vector<string> v;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        v.push_back(s);
    }
    cout << solution(v);
}