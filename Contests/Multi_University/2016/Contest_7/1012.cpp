#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 500005;
int n;

struct Point {
    int x, y, id;
    void read() {
        scanf("%d%d", &x, &y);
    }
} p[N], pp[N];

bool cmpx(Point a, Point b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool cmpy(Point a, Point b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

struct Rec {
    int x1, y1, x2, y2;
} rec[N];

void init() {
    for (int i = 1; i <= n; i++) pp[i].read();
    sort(pp + 1, pp + n + 1, cmpx);
    int pn = 0;
    p[++pn] = pp[1];
    for (int i = 2; i <= n; i++) {
        if (pp[i].x == pp[i - 1].x && pp[i].y == pp[i - 1].y) continue;
        p[++pn] = pp[i];
    }
    n = pn;
    for (int i = 1; i <= n; i++) p[i].id = i;
}

struct SB {
    int l, r, id;
    SB() {}
    SB(int l, int r, int id) : l(l), r(r), id(id){}
};
vector<SB> g[50005];
int bit[50005];

#define lowbit(x) (x&(-x))

void add(int x) {
    while (x <= 50000) {
        bit[x]++;
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

int get(int l, int r) {
    return get(r) - get(l - 1);
}

int ans[N];
int main() {
    while (~scanf("%d", &n) && n) {
        init();
        sort(p + 1, p + n + 1, cmpx);
        for (int i = 1; i <= n; i++) {
            int j;
            for (j = i + 1; j <= n; j++)
                if (p[j].x != p[i].x) break;
            for (int k = i; k < j; k++) {
                if (k == i) rec[p[k].id].y1 = 1;
                else rec[p[k].id].y1 = p[k - 1].y + 1;
                if (k == j - 1) rec[p[k].id].y2 = 50000;
                else rec[p[k].id].y2 = p[k + 1].y - 1;
            }
            i = j - 1;
        }
        sort(p + 1, p + 1 + n, cmpy);
        for (int i = 1; i <= n; i++) {
            int j;
            for (j = i + 1; j <= n; j++)
                if (p[j].y != p[i].y) break;
            for (int k = i; k < j; k++) {
                if (k == i) rec[p[k].id].x1 = 1;
                else rec[p[k].id].x1 = p[k - 1].x + 1;
                if (k == j - 1) rec[p[k].id].x2 = 50000;
                else rec[p[k].id].x2 = p[k + 1].x - 1;
            }
            i = j - 1;
        }
        //printf("%d\n", n);
        //for (int i = 1; i <= n; i++) printf("%d %d\n", p[i].x, p[i].y);
        //for (int i = 1; i <= n; i++) printf("%d %d %d %d\n", rec[i].x1, rec[i].y1, rec[i].x2, rec[i].y2);
        for (int i = 1; i <= 50000; i++) g[i].clear();
        for (int i = 1; i <= n; i++) g[p[i].x].push_back(SB(p[i].y, 0, 0));
        for (int i = 1; i <= n; i++) {
            g[rec[i].x1 - 1].push_back(SB(rec[i].y1, rec[i].y2, -i));
            g[rec[i].x2].push_back(SB(rec[i].y1, rec[i].y2, i));
        }
        memset(ans, 0, sizeof(ans));
        memset(bit, 0, sizeof(bit));
        for (int i = 1; i <= 50000; i++) {
            for (int j = 0; j < g[i].size(); j++) {
                SB tmp = g[i][j];
                if (tmp.id == 0) add(tmp.l);
                else {
                    int f = tmp.id < 0 ? -1 : 1;
                    ans[tmp.id * f] += f * get(tmp.l, tmp.r);
                }
            }
        }
        //for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
        int f = 1;
        for (int i = 1; i <= n; i++) if (ans[i] != 1) f = 0;
        printf("%s\n", f ? "YES" : "NO");
    }
    return 0;
}
