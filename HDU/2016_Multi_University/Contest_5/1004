#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int N = 2005;
int n;
struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y) : x(x), y(y) {}
    void read() {
        scanf("%lld%lld", &x, &y);
    }
    Point operator - (const Point& c) const {
        return Point(x - c.x, y - c.y);
    }
    ll operator ^ (const Point& c) const {
        return x * c.y - y * c.x;
    }
    ll operator * (const Point& c) const {
        return x * c.x + y * c.y;
    }
} p[N], tmp[N * 2];
int tn;

int A(Point &a){
    return (a.x >= 0) ^((a.y < 0) + 1);
}
bool cmp(Point a, Point b) {
    int x = A(a), y = A(b);
    if (x != y) return x < y;
    return (a^b) > 0LL;
}

ll f[N];

bool ck(Point a, Point b) {
    if ((a * b) < 0) return false;
    return (a ^ b) == 0LL;
}

bool ck2(Point a, Point b) {
    if ((b ^ a) >= 0 && (b * a) > 0) return true;
    return false;
}

bool ck3(Point a, Point b) {
    if ((b ^ a) == 0 && (b * a) < 0) return false;
    if ((b ^ a) >= 0) return true;
    return false;
}

int main() {
    for (int i = 1; i < N; i++) f[i] = f[i - 1] + i;
    while (~scanf("%d", &n)) {
        ll tot = 0;
        ll ans = 1LL * n * (n - 1) * (n - 2) / 6;
        for (int i = 1; i <= n; i++) p[i].read();
        for (int i = 1; i <= n; i++) {
            tn = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j) continue;
                tmp[++tn] = p[j] - p[i];
            }
            sort(tmp + 1, tmp + tn + 1, cmp);
            reverse(tmp + 1, tmp + tn + 1);
            int cnt = 1;
            for (int i = 2; i <= tn; i++) {
                if (!ck(tmp[i - 1], tmp[i])) {
                    tot += f[cnt - 1];
                    cnt = 1;
                } else cnt++;
            }
            tot += f[cnt - 1];
            for (int i = 1; i <= tn; i++) tmp[i + tn] = tmp[i];
            int r1 = 1, r2 = 1;
            for (int i = 1; i <= tn; i++) {
                while (r1 < i + tn && ck2(tmp[i], tmp[r1])) r1++;
                while (r2 < i + tn && ck3(tmp[i], tmp[r2])) r2++;
               // printf("%d %d\n", r2, r1);
                ans -= r2 - r1;
            }
        }
        //printf("%lld\n", tot);
        printf("%lld\n", ans - tot / 2);
    }
    return 0;
}
