# 개요

### 용어

* 유량 (Flow)

    그래프에서 source->sink로 흘려보내는 것 또는 그 양

* 최대 유량 (MF : Maximum Flow)

    유량의 최대량

* MCMF (Min-cost Max-Flow)

    여러 MF중 최소비용인 MF

### 종류

* MF를 찾는 알고리즘
  * Edmonds-Karp
  * Dinic
  * Bipartite Matching(이분매칭)
* MCMF (Min-Cost Max-Flow)

### 문제

* Maximum Flow (allow Edmonds-Karp)

	http://boj.kr/6086

<br><br>
# Edmonds-Karp

### O(VE^2)

### 특징
* source에서 sink까지의 경로를 찾는 방법이 명시되지 않은 것이 Ford-Fulkerson 알고리즘인데, 여기서 경로 탐색을 BFS로 한정지은것이 Edmonds-Karp 알고리즘이다.
* 증가 경로를 BFS로 찾으면 VE번 이상 찾지 않는다는 것이 증명되었다. 따라서 BFS를 사용

### 알고리즘
    1. BFS로 플로우 경로를 찾는다. 이 때 노드를 지날 때마다 해당 노드의 parent를 저장한다.
    2. sink부터 souce까지 역방향으로 가면서(1에서 저장한 parent 이용) 정방향 간선에 +flow, 역방향 간선에 -flow
    3. 플로우 경로를 더 이상 찾을 수 없을 때까지 1~2를 반복한다.

<details>
<summary>code</summary>

```c++
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define INF ((1<<31)-1)

int n, flow[MAX][MAX], capacity[MAX][MAX], ans = 0;

void edmond_karp() {
	while (true) {
		vector<int> parent(MAX);
		vector<bool> check(MAX, false);
		queue<int> q;
		q.push(0);
		check[0] = true;
		int max_flow = INF, i, j, now;
		while (!q.empty()) {
			now = q.front();
			q.pop();
			if (now == 'Z' - 'A')
				break;
			for (i = 0; i < MAX; i++) {
				if (!check[i] && capacity[now][i] > flow[now][i]) {
					q.push(i);
					parent[i] = now;
					max_flow = min(max_flow, capacity[now][i] - flow[now][i]);
					check[i] = true;
				}
			}
		}
		if (now != 'Z'-'A')
			return;

		while (now != 0) {
			int p = parent[now];
			flow[p][now] += max_flow;
			flow[now][p] -= max_flow;
			now = p;
		}

		ans += max_flow;
	}
}
```

</details>


<br><br>
# Dinic

### O(V^2E)

### 특징
* 일반적으로 Edmonds-Karp보다 빠르다. (E > V인 경우가 일반적이기 때문)
* capacity가 0 또는 1인 unit capacity에서는 min(V^(2/3)E, E^3/2)  이 된다. <a href="https://koosaga.com/18">출처</a>

### 알고리즘
    1. BFS로 level graph를 만든다.
    	* level graph : source=0, source와 연결된 정점은 1, ... 식으로 레벨을 매긴 그래프
    2. DFS로 blocking flow를 흘려보낸다.
    	* blocking flow : level이 x->(x+1)이 아닌 모든 edge를 제외한 그래프에서의 flow
    3. 1번에서 sink의 level을 지정할 수 없을 때까지 1~2를 반복한다.

<details>
<summary>code</summary>

```c++
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

#define INF ((1<<31)-1)
#define MAX 60

int n, flux[MAX][MAX], capacity[MAX][MAX], ans = 0;
int source = 0, sink = 'Z' - 'A';

vector<int> leveling() {
	vector<int> res(MAX, -1);
	res[0] = 0;
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int next = 0; next < MAX; next++) {
			if (capacity[now][next] > flux[now][next] && res[next] == -1) {
				res[next] = res[now] + 1;
				if (next == 'Z' - 'A')
					return res;
				q.push(next);
			}
		}
	}
	return vector<int>();
}

int flow(vector<int> level, int now, int max_flow) {
	if (now == sink) {
		ans += max_flow;
		return max_flow;
	}
	int next;
	for (next = 0; next < MAX; next++) {
		int res;
		if (level[next] == level[now] + 1 && capacity[now][next] > flux[now][next]) {
			res = flow(level, next, min(max_flow, capacity[now][next] - flux[now][next]));
			if (res != INF) {
				flux[now][next] += res;
				flux[next][now] -= res;
				return res;
			}
		}
	}
	return INF;
}

int main() {
	...// 그래프 생성
	while (true) {
		vector<int> level = leveling();
		if (level.empty())
			break;
		while (true) {
			if (flow(level, 0, INF) == INF)
				break;
		}
	}
	cout << ans;
}
```

</details>