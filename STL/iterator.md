### Iterator(반복자)란?

    STL 컨테이너를 순회할 수 있는 객체
    Iterator는 그 기능에 따라 5가지로 구분된다.

### Iterator의 종류

* Input Iterator

    1. 증가 연산자(++)로 순방향 이동할 수 있음
    2. 참조 연산자(*)로 element의 값을 `읽을` 수 있음
    3. 비교 연산자(==, !=)로 iterator간의 비교를 수행할 수 있음

* Output Iterator

    1. 증가 연산자(++)로 순방향 이동할 수 있음
    2. 참조 연산자(*)로 element의 값을 `변경`할 수 있음

* Forward Iterator

    0. Input + Output
   
* Bidirectional Iterator

    0. Forward Iterator
    1. 감소 연산자(--)로 역방향 이동할 수 있음

* Random Access Iterator

    0. Bidirectional Iterator
    1. 첨자 연산자([])로 임의의 요소에 접근할 수 있음
    2. 산술 연산자(+, -) 로 iterator의 위치를 지정할 수 있음
    3. 산술 대입 연산자(+=, -=)로 iterator의 위치를 변경할 수 있음
    4. 관계 연산자(<, <=, >, >=)로 iterator간의 관계를 알 수 있음

<br>

### STL 컨테이너와 반복자

* Forward Iterator
  
    `unordered_set, unordered_map`

* Bidirectional Iterator
  
    `list, set, multiset, map, multimap`

* Random Access Iterator

    `array, vector`