long long sum(vector<long long>& tree, int ind, int s, int e, int qa, int qb) {
	if (s >= qa && e <= qb)
		return tree[ind];
	if (s > qb || e < qa || s>e)
		return 0;
	return sum(tree, ind * 2, s, (s + e) / 2, qa, qb) + sum(tree, ind * 2 + 1, (s + e) / 2 + 1, e, qa, qb);
}

void update(vector<long long>& tree, int ind, long long diff) {
	while (ind > 0) {
		tree[ind] += diff;
		ind /= 2;
	}
}

int main(){
    int sn;
	for (sn = 1; sn < n; sn *= 2);
	vector<long long> tree(sn * 2, 0);
}