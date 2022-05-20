# vector

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

### method

* 삽입

    ```c++
    v.push_back(val); //v의 맨 뒤에 val라는 요소를 추가함. val의 데이터 타입은 v의 데이터 타입과 같아야 함.
    v.emplace_back(...args); //push_back과 동작은 같지만, 매개변수로 v의 데이터 타입 변수를 넣는 것이 아닌 해당 데이터 타입의 인수를 풀어서 넣음.
    v.emplace(iterator Where, datatype val); //iterator 위치에 val 요소 삽입. 기존 위치에 있던 값은 뒤로 밀려남
    ```