#include <vector>

int n, i, j;
vector<bool> isPrime(n, true);

for (i = 2; i * i <= n; i++) {
	if (isPrime[i])
		for (j = i * i; j <= n; j += i)
			isPrime[i] = false;
}
