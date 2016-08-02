#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 50005;
int n, a[N], h[N], hn;

#define lowbit(x) (x&(-x))

int bit[N];

void add(int x, int w) {
    while (x <= hn) {
        bit[x] += w;
        x += lowbit(x);
    }
}

int get(int x) {
    int ans = 0;
    while (x) {
        ans += bit[x];
        x -= lowbit(x);
    }
    return ans;
}

int lm[N], rm[N], lb[N], rb[N];

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            h[i] = a[i];
        }
        sort(h + 1, h + 1 + n);
        hn = unique(h + 1, h + 1 + n) - h - 1;
        for (int i = 1; i <= n; i++)
            a[i] = lower_bound(h + 1, h + 1 + hn, a[i]) - h;
        memset(bit, 0, sizeof(bit));
        long long sa = 0, sb = 0;
        for (int i = 1; i <= n; i++) {
            lm[i] = get(a[i] - 1);
           // printf("%d %d\n", a[i], lm[i]);
            add(a[i], 1);
            sa += lm[i];
        }
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= n; i++) {
            lb[i] = get(hn) - get(a[i]);
            add(a[i], 1);
        }
        memset(bit, 0, sizeof(bit));
        for (int i = n; i >= 1; i--) {
            rm[i] = get(a[i] - 1);
            add(a[i], 1);
            sb += rm[i];
        }
        //printf("%lld %lld\n", sa, sb);
        memset(bit, 0, sizeof(bit));
        for (int i = n; i >= 1; i--) {
            rb[i] = get(hn) - get(a[i]);
            add(a[i], 1);
        }
      //  for (int i = 1; i <= n; i++) printf("%d %d\n", lm[i], lb[i]);
      //  for (int i = 1; i <= n; i++) printf("%d %d\n", rm[i], rb[i]);
        long long ans = sa * sb;
        for (int i = 1; i <= n; i++) {
            ans -= 1LL * rb[i] * rm[i];
            ans -= 1LL * lb[i] * lm[i];
            ans -= 1LL * rb[i] * lb[i];
            ans -= 1LL * lm[i] * rm[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}
