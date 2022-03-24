vector<int> get_pi(string& s) {
	int i, j = 0,len = s.size();
	vector<int> pi(s.size(), 0);
	for (i = 1; i < len; i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> kmp(string& t, string& p) {
	vector<int> ans, pi = get_pi(p);
	int n, m, i, j=0;
	n = t.size();
	m = p.size();
	for (i = 0; i < n; i++) {
		while (j > 0 && t[i] != p[j])
			j = pi[j - 1];
		if (t[i] == p[j]) {
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
	return ans;
}

int main() {
	string t, p;
	getline(cin, t);
	getline(cin, p);
	auto ans = kmp(t, p);
}