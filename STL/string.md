# String
<a href="https://www.cplusplus.com/reference/string/string/">Reference</a>

### `Bidirectional Iterator`

### 개요

    문자열 컨테이너

### 사용

```c++
#include <string>
std::string s = "Hello World!";
```

### 선언 및 초기화

```c++
string s; //빈 문자열 반환
string s = "Hello world!"; //큰따옴표(")로 감싸 문자열 표시
```

### Member Functions

* Modifiers
    ```c++
    s.push_back(char val); //s의 맨 뒤에 char형 val 추가
    s += str2; //s의 맨 뒤에 str2 추가
    s.pop_back(); //s의 맨 뒤 요소 삭제

    s.insert(size_t pos, string str2); // pos 위치에 str2 삽입
    s.insert(size_t pos, string str2, size_t subpos, size_t sublen); 
    s.insert(size_t pos, char* str3);
    s.insert(iterator p, char c); //iterator 위치에 char형 c 삽입. string은 삽입 불가

    s.replace(size_t pos, size_t len, string str2); //pos위치부터 len길이만큼 str2로 교체
    s.replace(size_t pos, size_t len, string str2, size_t subpos, size_t sublen); //str2의 substtr

    s.erase(size_t pos = 0, size_t len = npos); //pos위치부터 len길이만큼 삭제
    s.erase(iterator it); //it가 가리키는 곳만 삭제
    s.erase(iterator first, iterator last); //[first, last) 범위 삭제

    s.swap(str2); //s와 str2를 바꿈
    ```

* String Operations
    ```c++
    size_t : s.find(string str2, size_t pos = 0); //s의 pos부터 str2를 검색, 첫 위치 반환. str2가 없으면 string::npos(size_t의 maximum) 반환
    size_t : s.find(char c, size_t pos = 0);

    string : s.substr(size_t pos = 0, size_t len = npos); //pos부터 len길이의 string 반환

    int : s.compare(string str2); //같으면 0, s가 사전순 앞이면 음수, 아니면 양수 반환
    int : s.compare(size_t pos, size_t len, string str2); //s의 substr과 str2 비교
    int : s.compare(size_t pos, size_t len, string str2, size_t subpos, size_t sublen);
    ```

* Element access
    ```c++
    s.at(1);
    s[1]; //두 코드 모두 string의 1번 문자(char) 반환. (0번부터 시작하므로 순서는 2번째 요소)
    
    s.front();
    s.back();
    ```

* Iterators
    ```c++
    s.begin();
    s.end();

    s.rbegin();
    s.rend();
    ```

* Size
    ```c++
    size_t : s.size();
    size_t : s.length(); //size, length 둘 다 글자수 반환
    size_t : s.capacity(); //메모리 용량 반환
    s.clear(); //s를 빈 string으로 만들고 size를 0으로 초기화

    bool : s.empty(); //s.size()가 0이면 true, 아니면 false
    ```

* ETC
    ```c++
    string : std::to_string(int num); //숫자->문자열 변환
    double, float, long long 등 여러 타입 가능

    int : std::stoi(string s); //문자열->숫자 변환
    stof(float), stol(long), stod(double) 등 등 여러 타입 가능
    ```