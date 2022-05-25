# array
<a href="https://www.cplusplus.com/reference/array/array/">Reference</a>

### `Random Access Iterator`

### 개요

    vector가 동적 배열이라면 array는 고정 배열
    c++에 내장된 배열의 업그레이드 버전

### 사용

```c++
#include <array>
std::array<int, 5> arr = {1,2,3,4,5};
```

### 선언 및 초기화

```c++
std::array<int, 5> arr = {1,2,3,4,5};
std::array<int, 5> arr{1,2,3,4,5};

std::array<int, > arr = {1,2,3,4,5}; //ERROR! array는 반드시 크기를 지정해줘야 함
```

### Member Functions

* Modifiers
    ```c++
    void : arr.fill(T val); //arr 내의 모든 element를 val로 채움
    void : arr.swap(arr2); //arr과 arr2를 교체
    ```

* Element Access
    ```c++
    T : arr.at(1);
    T : arr[1]; // 두 코드 모두 arr의 1번 요소 반환
    T : arr.front(); //첫번째 요소 반환
    T : arr.back(); //마지막 요소 반환

    T* : arr.data(); //첫번째 요소의 포인터 반환
    ```

### Tips

* VS에서 디버깅할 때 elements 바로 보기
    ```c++
    arr._Elems
    ```