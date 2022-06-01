# map
<a href="https://www.cplusplus.com/reference/map/map/">Reference</a>

### `Bidirectional Iterator`

### 개요

    key-value 형 자료구조
    key를 기준으로 정렬됨 (red-black tree)
    key의 중복을 허용하지 않음

### 사용
```c++
#include <map>
std::map<int, int> m;
```

### 선언 및 초기화
```c++
std::map<KT, VT> m; //key type이 KT이고 value type이 VT인 map 선언

auto cmp = [](int a, int b){return a>b;};
std::map<KT, VT, decltype(cmp)> m(cmp); //C++11 내림차순
```
### Member Functions

* Modifiers
    ```c++
    //insert
    pair<iterator, bool> : m.insert(pair<KT, VT>(key_value, val_value)); //반환되는 pair값은 새로 들어간 곳의 iterator와 insert의 성공 여부. 중복된 key값이 있으면 insert가 실패한다.
    map<KT, VT>::iterator : m.insert(iterator pos, VT val);
    void : m.insert(InputIterator first, InputIterator last); //[first,last) 범위 삽입

    //emplace
    pair<iterator, bool> : m.emplace(...args); //자동으로 key와 value 형식에 맞게 넣어줌

    //erase
    void : m.erase(iterator pos); //pos 위치의 element 삭제
    size_t : m.erase(KT key); //키가 key인 element 삭제
    void : m.erase(iterator first, iterator last); //[first,last) 범위 삭제

    //swap
    void : m.swap(m2); //map 교체

    //clear
    void : m.clear(); //모든 elements 삭제
    ```

* Element Access
    ```c++
    VT : arr[key_value]; 
    VT : arr.at(key_value'); //두 코드 모두 val_value 반환. bidirectional 컨테이너지만 [] 연산자를 사용할 수 있는 게 특징
    ```

* Iterators

    ```c++
    map<KT, VT>::iterator : m.begin();
    map<KT, VT>::iterator : m.end();
    
    map<KT, VT>::iterator : m.rbegin();
    map<KT, VT>::iterator : m.rend();

    const map<KT, VT>::iterator : m.cbegin();
    const map<KT, VT>::iterator : m.cend();
    const map<KT, VT>::iterator : m.crbegin();
    const map<KT, VT>::iterator : m.crend();
    ```

* Capacity

    ```c++
    bool : m.empty();
    size_t : m.size(); //elements의 개수
    size_t : m.max_size(); //m에 넣을 수 있는 elements의 최댓값
    ```

* Operations

    ```c++
    map<Kt, VT>::iterator : m.find(KT key_value); //키값이 key_value인 element의 iterator 반환. 해당 키를 가진 엘리먼트가 없으면 m.end() 반환
    
    size_t : m.count(KT key_value); //키값이 key_value인 elements의 수 반환. 그런데 map은 특성상 key가 unique하기 때문에 항상 0 or 1을 반환

    map<Kt, VT>::iterator : m.lower_bound(KT key_value);
    map<Kt, VT>::iterator : m.upper_bound(KT key_value);
    ```

<br><br>
# multimap
<a href="https://www.cplusplus.com/reference/map/multimap/">Reference</a>

### `Bidirectional Iterator`

### 개요

    key값의 중복이 가능한 map

### map과 차이점

* key의 중복 가능
* operator [] 사용 불가