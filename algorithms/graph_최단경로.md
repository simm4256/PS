# 개요

### 최단경로
    그래프에서 두 정점간의 최단 경로를 찾아내는 알고리즘

### 종류

* Floyd-Warshall
* Dijkstra
* Bellman-Ford
* SPFA(Shortest Path Faster Algorithm)

<br><br>
# Floyd-Warshall

### O(V^3)

### 특징
* 아래 알고리즘들이 특정 시작점에서의 최단 경로를 구하는 알고리즘이라면, 플로이드-워셜은 모든 정점간의 최단경로를 구하는 알고리즘임
* 음의 간선 허용
* 음의 사이클 존재 불가 (사이클만 불가능하고 간선은 가능)

### 알고리즘
1. 2차원의 dist 배열을 생성하고, (i, i)는 0으로 초기화하고, 직접 간선이 연결되어있는 (a, b)는 해당 간선의 가중치로 초기화
2. 거쳐가는 노드 k를 선택하고 dist[i][j]를 min(dist[i][j], dist[i][k]+dist[k][j])로 업데이트
3. 2의 k를 1~n까지 반복
    * 이 때 k를 먼저 선택하고 i,j를 나중에 선택해야 함

<details>
<summary>code</summary>

```c++
#define INF ((1<<31)-1)

int n, m;

int main() {
	cin >> n >> m;
	int i, j, k;
	vector<vector<pair<int, int> > > edge(n+1);
	int dist[105][105];

    //1. 초기화
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			dist[i][j] = INF;
	for (i = 1; i <= n; i++)
		dist[i][i] = 0;
	for (i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].emplace_back(b, c);
		if (dist[a][b] > c)
			dist[a][b] = c;
	}

    //2~3. 업데이트
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				//i:시작노드 j:도착노드 k:중간노드
				if (dist[i][k] == INF || dist[k][j] == INF)
					continue;
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

    //출력
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++)
			cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
		cout << '\n';
	}
}
```

</details>

<br><br>
# dijkstra

### O(ElogV)

### 특징
* 음의 간선 불가
* 음의 사이클 존재 불가

### 알고리즘
1. 출발 노드의 거리를 0, 나머지 노드의 거리를 INF로 초기화
2. 거리가 가장 낮은 노드를 확정시킴
3. 확정된 노드로부터 연결된 간선으로 거리 업데이트
4. 2~3번을 도착 노드가 확정될때까지 반복

<details>
<summary>code</summary>

```c++
int n, v;
vector<vector<pair<int, int> > > edge;

int dijkstra(int start, int end) {
	vector<int> dist(n, -1);
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.emplace(0, start);
	int cnt = 0;
	while (!pq.empty() && cnt < n) {
		int x = pq.top().second, val = pq.top().first;
		pq.pop();
		if (dist[x] != -1)
			continue;
		dist[x] = val;
		if (++cnt == n || x == end)
			break;
		for (auto i : edge[x]) {
			if (dist[i.second] != -1)
				continue;
			pq.emplace(i.first + val, i.second);
		}
	}
	return dist[end];
}
```

</details>

<br><br>
# bellman-ford

### O(VE)

### 특징
* 음의 간선 허용
* 음의 사이클 여부 판별 가능
* But, 속도는 dijkstra보다 느림

### 알고리즘
1. 출발 노드의 거리를 0, 나머지 노드의 거리를 INF로 초기화
2. 모든 간선을 순회하며 거리 업데이트
3. 2번을 V-1번 반복 (도중에 업데이트가 되지 않으면 바로 종료)
4. 2번을 한 번 더 했는데 업데이트가 됐다면 음의 사이클이 존재하는 것

<details>
<summary>code</summary>

```c++
struct Node {
	int s, e, val;
};

int n, m;
vector<Node> edge;
vector<long long> dist(505, INT_MAX);

bool belman_ford() {
	bool isChanged = false;
	for (auto it : edge) {
		if (dist[it.s] == INT_MAX)
			continue;
		if (dist[it.e] > dist[it.s] + it.val) {
			dist[it.e] = dist[it.s] + it.val;
			isChanged = true;
		}
	}
	return isChanged;
}

int main() {
	cin >> n >> m;
	int i;
	for (i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge.emplace_back(Node{ a,b,c });
	}
	dist[1] = 0;
	for (i = 0; i < n-1; i++) {
		if (!belman_ford())
			break;
	}
	if (belman_ford())
		cout << -1;
	else {
		for (i = 2; i <= n; i++)
			cout << (dist[i] == INT_MAX ? -1 : dist[i]) << '\n';
	}
}
```

</details>


<br><br>
# SPFA

### O(VE)이지만 실제론 O(V+E) 혹은 O(E)로 봐도 무방

### 특징
* bellman-ford 알고리즘의 개량판
* 음의 간선 허용
* 음의 사이클 여부 판별 가능

### 알고리즘
1. 출발 노드의 거리를 0, 나머지 노드의 거리를 INF로 초기화
2. 큐에 방문할 정점을 저장하고, isInQ 배열로 큐에 정점이 들어가있는지를 관리
    * 이 때 해당 노드의 방문횟수가 전체 노드의 개수보다 많아지면 음의 사이클이 존재하는 것
3. 큐에서 정점을 꺼낸 후 해당 정점에 연결된 간선으로 거리 업데이트
4. 큐가 비거나 음의 사이클이 발견될 때까지 2~3을 반복

<details>
<summary>code</summary>

```c++
bool spfa() {
	int s = startNumber;
	bool isInQ[510]; memset(isInQ, 0, sizeof(isInQ));
	fill(dist, dist + 509, INF);
	dist[s] = 0;
	queue<int> q;
	q.push(s);
	isInQ[s] = true;
	cnt[s] = 1;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		isInQ[x] = false;
		for (auto i : edge[x]) {
			if (dist[x] + i.v >= dist[i.to])
				continue;
			dist[i.to] = dist[x] + i.v;
			if (!isInQ[i.to]) {
				if (++cnt[i.to] > n)
					return false;
				q.push(i.to);
				isInQ[i.to] = true;
			}
		}
	}
	return true;
}

```

</details>