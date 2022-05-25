Spanning Tree (신장 트리)

    주어진 그래프의 간선 중 사이클 없이 (n-1)개의 간선을 선택해 만든 sub 그래프이자 트리

Minimum Spanning Tree

    여러 Spanning Tree 중 간선의 가중치의 합이 가장 작은 Spanning Tree

종류

Kruskal

    알고리즘 : Greedy

    1. 간선을 오름차순 정렬한다.
    2. 사이클이 형성되지 않는 간선을 n-1회 선택한다.

Prim

    알고리즘

    1. 시작 정점을 하나 정해 MST 집합에 포함시킨다.
    2. 현재 MST 집합에 연결된 간선 중 사이클이 없는 최소 간선을 선택하여 확장한다.
    3. 2번을 n-1개의 간선을 가질 때까지 반복한다.