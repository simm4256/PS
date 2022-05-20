# 개요

### 정렬 알고리즘
* stable : 정렬 대상이 같은 2개 이상의 값의 순서가 정렬 후에도 유지되는 특성
* `O(n^2)`
    <details>
    <summary>삽입 정렬 (Insertion sort) : stable</summary>
    알고리즘

      1. k번째 숫자를 선택
      2. 1~(k-1)번째까지 고정된 숫자를 탐색하며 선택한 숫자의 자리 고정
      3. 1~2를 반복
   </details>
	
	<details>
    <summary>선택 정렬 (Selection sort) : unstable</summary>
	알고리즘

	  1. 남은 배열 중 우선순위 가장 높은 수(오름차순의 경우 가장 낮은 수) 선택 
	  2. 정렬된 배열의 마지막에 삽입
	  3. 1~2를 반복
	</details>

	<details>
	<summary>버블 정렬 (Bubble sort) : stable</summary>
	알고리즘

	  1. k번째 원소와 k+1번째 원소를 비교하여 정렬
	  2. 1을 반복

	</details>

* `O(n log n)`

	<details>
	<summary>병합 정렬 (Merge sort) : stable</summary>

	알고리즘 : 분할정복

	  1. 분할 : 배열을 절반씩 계속해서 나눈다. (divide)
	  2. 정복 : 끝까지 나눈 배열을 하나씩 합친다. (merge)

	```c++
	#include <algorithm>
	#include <vector>
	#include <iostream>
	using namespace std;

	vector<int> merge(vector<int> a, vector<int> b) {
		vector<int> res;
		auto a_it = a.begin(), b_it = b.begin();
		while (a_it != a.end() || b_it != b.end()) {
			int select;
			if (a_it == a.end())
				select = *b_it++;
			else if (b_it == b.end())
				select = *a_it++;
			else {
				if (*a_it <= *b_it)
					select = *a_it++;
				else
					select = *b_it++;
			}
			res.push_back(select);
		}
		return res;
	}

	vector<int> merge_sort(vector<int> v) {
		int size = v.size();
		if (size <= 1)
			return v;

		//divide
		vector<int> a = merge_sort(vector<int>{v.begin(), v.begin() + size / 2});
		vector<int> b = merge_sort(vector<int>{v.begin() + size / 2, v.end()});

		//merge
		return merge(a, b);
	}

	vector<int> merge_sort(vector<int> v) {
		int size = v.size();

	}

	int main() {
		vector<int> v = { 5,2,4,3,1 };
		vector<int> sorted_v = merge_sort(v);
	}
	```
	
	</details>

	<details>
	<summary>힙 정렬 (Heap sort) : unstable</summary>

	알고리즘

	  1. 힙을 구현한다.
	  2. 배열의 모든 데이터를 힙에 넣는다.
	  3. 하나씩 pop하며 결과 배열에 채운다.

	```c++
	#include <algorithm>
	#include <vector>
	#include <queue>
	using namespace std;

	vector<int> heap_sort(vector<int> v) {
		int size = v.size();
		priority_queue<int, vector<int>, greater<int> > pq;
		for (auto it = v.begin(); it != v.end(); it++) {
			pq.push(*it);
		}
		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top());
			pq.pop();
		}
		return res;
	}

	int main() {
		vector<int> v = { 5,2,4,3,1 };
		vector<int> sorted_v = heap_sort(v);
	}
	```

	</details>

	<details>
	<summary>퀵 정렬 (Quick sort) : unstable</summary>

	알고리즘

	  1. 배열 내에 한 요소를 선택한다. 이 요소를 pivot이라 부른다.
	  2. pivot보다 작은 값은 pivot의 왼쪽으로, 큰 값은 오른쪽으로 옮긴다.
	  3. 왼쪽과 오른쪽 배열에 대해 1~2를 반복한다.

	</details>


# using library

```c++
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

struct Node {
	int index;
	string name;
	
	Node(int _index, string _name) :
		index(_index), name(_name) {}
};
bool cmp_less(Node a, Node b) {
	return a.index < b.index;
}

bool cmp_greater(Node a, Node b) {
	return a.index > b.index;
}

bool operator<(Node a, Node b) {
	return a.index < b.index;
}

int main() {
	int arr[] = { 4,2,5,1,3 };
	vector<int> vi = { 4,2,5,1,3 };
	vector<Node> vn = { Node(3, "Kim"), Node(1, "Sim"), Node(2, "Lee")};

	sort(arr, arr + 5); //1,2,3,4,5
	sort(arr, arr + 5, greater<int>());
	
	sort(vi.begin(), vi.end()); // 1,2,3,4,5
	sort(vi.begin(), vi.end(), greater<int>()); //5,4,3,2,1
	
	//cmp 함수 만들어 사용
	sort(vn.begin(), vn.end(), cmp_less); //1,2,3
	sort(vn.begin(), vn.end(), cmp_greater); //3,2,1

	//비교연산자 오버라이딩
	sort(vn.begin(), vn.end()); //1,2,3
}
```