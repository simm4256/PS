/*
프로그래머스 - k진수에서 소수 개수 구하기
https://programmers.co.kr/learn/courses/30/lessons/92335
주어진 수를 k진수로 변환 후 소수판별
소수판별에 에라토스테네스의 체를 사용 시 메모리초과, 따라서 수 마다 판별 반복
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int k) {
	string a;
	while (n >= k) {
		a.insert(a.begin(),(n % k) + '0');
		n /= k;
	}
	a.insert(a.begin(),n + '0');
	vector<long long> v;
	string s;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '0') {
			if (!s.empty()) {
				v.push_back(stoll(s));
				s.clear();
			}
		}
		else {
			s.push_back(a[i]);
		}
	}
	if (!s.empty())
		v.push_back(stoll(s));
	sort(v.begin(), v.end());
	long long i, j;
	int ans = 0;
	for (auto ll : v) {
		if (ll<2)
			continue;
		bool isPrime = true;
		for(i=3;i*i<=ll;i++)
			if (ll % i == 0) {
				isPrime = false;
				break;
			}
		if (isPrime)
			ans++;
	}
	return ans;
}