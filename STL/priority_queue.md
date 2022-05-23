# Priority_queue
<a href="https://www.cplusplus.com/reference/queue/priority_queue/">Reference</a>

### 사용

```c++
#include <queue>
std::priority_queue<int> pq;
```

### 선언 및 초기화

```c++
std::priority_queue<int> pq;
std::priority_queue<int, vector<int>, greater<int> > pq;
std::priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
```

### 우선순위 정하기

```c++
// default : 최대 우선순위 큐
std::priority_queue<int> pq;
std::priority_queue<pair<int, int>>;

// operator< 오버라이드 
bool operator<(Node a, Node b){
    return a.value > b.value; //최소 우선순위
    return a.value < b.value; //최대 우선순위
}

// cmp 만들어 사용하기 : 구버전
struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return *(--a.end()) > *(--b.end());
    }
};
priority_queue<vector<int>, vector<vector<int> >, cmp> pq; // 벡터 마지막원소 작은것이 우선

// cmp 만들어 사용하기 : Modern C++ 11
auto cmp = [](int a, int b) { return ... };
std::set<int, decltype(cmp)> s(cmp);

// cmp 만들어 사용하기 : Modern C++ 20
auto cmp = [](int a, int b) { return ... };
std::set<int, decltype(cmp)> s;
```

### Member Functions

```c++
void : pq.push(T val); // 클래스 템플릿 T형태의 변수 삽입
void : pq.emplace(...args); // 클래스 템플릿 T의 arguments를 나열하여 삽입

T : pq.top(); //우선순위가 가장 높은 요소 반환 (pop은 되지 않음)
void : pq.pop(); //우선순위가 가장 높은 요소 삭제 (반환은 되지 않음)

bool : pq.empty(); //비어있으면 true, 아니면 false
size_t : pq.size(); //요소의 개수
```

