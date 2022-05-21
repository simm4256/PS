# vector
<a href="http://www.cplusplus.com/reference/vector/vector/">Reference</a>

### 사용
```c++
#include <vector>

std::vector<int> v;
```

### 선언 및 초기화

```c++
std::vector<int> v; //빈 벡터
std::vector<int> v(3); //크기가 3이고 값이 0으로 초기화된 벡터
std::vector<string> v(3,"hi"); //크기가 3이고 값이 "hi"로 초기화된 벡터
std::vector<int> v = {1,3,5,2,4}; //직접 값을 지정해 초기화 가능

vector<vector<int>> v; //2차원 벡터
vector<vector<int>> v(10, vector<int>(3, 2)); //값이 2로 초기화된 10*3 크기의 2차원 벡터. !!!사용 지양!!!
vector<pair<int, int>> v; //2차원이지만 두 번쨰 차원의 크기가 2로 고정된 벡터
```

### Member Functions

* Modifiers
    ```c++
    v.push_back(T val); //v의 맨 뒤에 요소 val 추가
    v.emplace_back(...args); //push_back과 동작은 같지만, 매개변수로 v의 데이터 타입 변수를 넣는 것이 아닌 해당 데이터 타입의 인수를 풀어서 넣음.
    
    v.emplace(iterator it, datatype val); //it에 val 요소 삽입. 기존 위치에 있던 값은 뒤로 밀려남
    
    v.insert(iterator it, T v); //it에 list 삽입. 이렇게 사용한 insert는 삽입된 곳의 iterator를 반환하므로 it = v.insert(it, val); 로 선언하면 it가 뒤로 밀리지 않고 추가한 것을 가리키게 할 수 있음
    v.insert(iterator it, iterator input_first, iterator input_last); //it에 [input_first,input_last) 범위의 벡터 삽입. 다른 벡터일 수 있음

    v.erase(iterator it); //it의 공간 제거. 제거 후 it는 제거하기 전의 오른쪽 요소를 가리킴
    v.erase(iterator first, iterator last); //[first, last) 범위 제거
    ```

* Element access
    ```c++
    vector<T> v;

    T : v.at(1);
    T : v[1]; // 두 코드 모두 벡터의 1번 요소 반환 (0번부터 시작하므로 순서는 2번째 요소) 

    T : v.front(); //첫번째 요소, 즉 *(v.begin()) 반환
    T : v.back(); //마지막 요소, 즉 *(--v.end()) 반환
    ```

* Iterators
    <image src="https://upload.cppreference.com/mwiki/images/3/39/range-rbegin-rend.svg"/>
    ```c++
    vector<T>::iterator : v.begin(); //첫 요소의 iterator 반환
    vector<T>::iterator : v.end(); //마지막 요소 다음 공간의 iterator 반환. 마지막 요소가 아님에 주의

    vector<T>::iterator : v.rbegin(); //마지막 요소의 iterator 반환
    vector<T>::iterator : v.rend(); //첫 요소의 이전 공간의 iteraotr반환. 첫 요소가 아님에 주의
    ```

* Size
    ```c++
    size_t : v.size(); //요소의 개수 반환 (데이터 사이즈와 관계 없음에 주의)
    size_t : v.capacity(); //벡터가 차지하고있는 메모리 용량 반환
    v.clear(); //v를 빈 벡터로 만들고 size를 0으로 초기화. 단 capacity는 변하지 않음
    
    bool : v.empty(); //v.size()가 0이면 true, 아니면 false
    ```


###  Tips

* 2차원 이상의 벡터는 가급적 사용 지양
  
    ```c++
    vector<vector<int>> v(10000, vector<int>(100));
    ```
    위와 같은 2차원 배열은 초기화할 때 그만큼의 동적 할당을 하기 때문에 성능상 좋지 않음

    굳이 사용해야 한다면 배열의 첫 번째 차원을 낮은 숫자로 사용하거나
    2차원 벡터가 아닌 pair나 custom struct의 1차원 벡터를 사용

* `v.clear();` 는 size만 0으로 초기화함
  
    capacity는 그대로 남음
    ```c++
    v.clear();
    vector<int>().swap(v);
    ``` 
    위와 같이 swap 트릭으로 capcity까지 0으로 초기화 가능

    단, 위의 작업 이후 v를 다시 사용하려면 대할당 필요

* sub vector 추출
  
    ```c++
    vector<int> v = {1,2,3,4,5};
    vector<int> v2 = {v.begin(), v.begin()+2}; ///{1,2}
    ```

* iterator가 몇 번째?
    ```c++
    vector<int>::iterator it = v.begin()+3;
    int dist = distance(v.begin(), it); //3
    ```