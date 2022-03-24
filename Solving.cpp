#include <iostream>
#include <queue>

using namespace std;

struct Node{
	int a, b, c;
	Node(int x, int y, int z){a=x,b=y,c=z;}
	bool operator<(const Node& n)const {
		return c > n.c;
	}
};

int main(){
	priority_queue<Node> pq;
	pq.push(Node(1,2,3));
	pq.push(Node(5,6,7));
	pq.push(Node(3,111,1122));

	while(!pq.empty()){
		cout << pq.top().c << endl;
		pq.pop();
	}

	cout << "he";
}