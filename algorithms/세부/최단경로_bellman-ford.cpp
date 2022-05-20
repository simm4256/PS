
/*
음수 간선 허용, 음수 사이클 존재 여부 판별가능
O(VE) E=V^2이면 O(V^3)
*/

struct node{
	int val, x, y;
}
vector<node> edge;
vector<long long> dist(n, INT_MAX);

bool bellman_ford() {
	bool isChanged = false;
	for (auto i : edge) {
		if (dist[i.x] == INF)
			continue;
		if (dist[i.x] + i.val < dist[i.y]) {
			dist[i.y] = dist[i.x] + i.val;
			isChanged = true;
		}
	}
	return isChanged;
}

int main() {
	for(i=0;i<n;i++){
		if(!bellman_ford())
			break;
	}
	if (bellman_ford())
		isCycling = true;
}
