int parent[n];

int find(int x){
    if(parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void uni(int x, int y){
    int px = find(x), py = find(y);
    parent[y] = px;
}