# algorithm
<a href="https://www.cplusplus.com/reference/algorithm/">Reference</a>

### 사용

```c++
#include <algorithm>
```

### Functions

* lower_bound, upper_bound
    
    Binary Search

    ```c++
    vector<int> v = {1,3,5,7,9};
    vector<int>::iterator low, up;
    low = lower_bound(v.begin(), v.end(), 7); //*low = 7
    up = upper_bound(v.begin(), v.end(), 7); //*up = 9

    lower_bound(v.begin(), v.end(), val, cmp); //cmp 지정 가능
    ```