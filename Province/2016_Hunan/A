#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = (1<<8);
int n, m;
int x[N];
int cnt[8] = {2, 2, 2, 2, 2, 3, 3, 7};

int a[N], b[N];

int main() {
	for (int i = 0; i < (1<<8); i++) {
		x[i] = 1;
		for (int j = 0; j < 8; j++)
			if (i>>j&1) x[i] *= cnt[j];
	}
	sort(x, x + (1<<8));
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < (1<<8); i++) {
			a[i] = n / x[i];
			b[i] = m / x[i];
		}
		for (int i = (1<<8) - 1; i >= 0; i--) {
			for (int j = (1<<8) - 1; j > i; j--) {
				if (x[j] % x[i] == 0) {
					a[i] -= a[j];
					b[i] -= b[j];
				}
			}
		}
		long long ans = 0;
		for (int i = 0; i < (1<<8); i++) {
			for (int j = 0; j < (1<<8); j++) {
				if (x[i] * x[j] % 2016 == 0)
					ans += 1LL * a[i] * b[j];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
