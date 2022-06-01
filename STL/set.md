# set
<a href="https://www.cplusplus.com/reference/set/set/">Reference</a>]

### `Bidirectional Iterator`

### 개요

    중복을 허용하지 않는 자동 정렬 자료구조 (red-black tree)

### 사용
```c++
#include <set>
std::set<int> s;
```

### 선언 및 초기화
```c++
std::set<T> s;

auto cmp = [](int a, int b){return a>b;};
std::set<T, decltype(cmp)> s(cmp); // C++11 내림차순
```

### Member Functions

* Modifiers
    ```c++
    //insert
    pair<iterator, bool> : s.insert(T val); //iterator는 성공 시 새로 넣은 element의 위치, 이미 있으면 있는 element의 위치 반환
    set<T>::iterator : s.insert(iterator pos, T val);
    void : s.insert(InputIterator first, InputIterator last); //[first,last) 범위 삽입
    ```