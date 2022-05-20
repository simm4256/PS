long long sum(vector<long long>& tree, int i) {
	long long res = 0;
	while (i > 0) {
		res += tree[i];
		i -= (i & -i);
	}
	return res;
}

void update(vector<long long>& tree, int i, long long val) {
	while (i < tree.size()) {
		tree[i] += val;
		i += (i & -i);
	}
}

int main(){
    vector<long long> a(n + 1);
	vector<long long> tree(n + 1, 0);
}