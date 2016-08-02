#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 100005;
#define fi first
#define se second
#define mp(a,b) make_pair(a,b)
typedef pair<int, int> pii;
int n, q;
int ch[N][26], sz;
char str[N];
vector<int> g[N];

struct Node {
    int ls, rs, sum, lazy;
} node[N * 30];
int rt[N], idx;

void pushup(int x, int sz) {
    int ls = node[x].ls, rs = node[x].rs;
    node[x].sum = node[ls].sum + node[rs].sum + node[x].lazy * sz;
}

void pushdown(int x, int sz, int f) {
    node[x].lazy += f; node[x].sum += sz * f;
}

void build(int L, int R, int &x) {
    x = ++idx;
    node[x].lazy = 0;
    if (L == R) {
        node[x].sum = 0;
        return;
    }
    int mid = (L + R)>>1;
    build(L, mid, node[x].ls);
    build(mid + 1, R, node[x].rs);
    pushup(x, R - L + 1);
}

void modify(int l, int r, int w, int L, int R, int &x) {
    node[++idx] = node[x]; x = idx;
    if (L >= l && R <= r) {
        pushdown(x, R - L + 1, w);
        return;
    }
    int mid = (L + R)>>1;
    if (l <= mid) modify(l, r, w, L, mid, node[x].ls);
    if (r > mid) modify(l, r, w, mid + 1, R, node[x].rs);
    pushup(x, R - L + 1);
}

int ans;

void Q1(int l, int r, int L, int R, int x) {
    if (l > r) return;
    if (L >= l && R <= r) {
        ans += node[x].sum;
        return;
    }
    ans += node[x].lazy * (r - l + 1);
    int mid = (L + R)>>1;
    if (r <= mid) Q1(l, r, L, mid, node[x].ls);
    else if (l > mid) Q1(l, r, mid + 1, R, node[x].rs);
    else {
        Q1(l, mid, L, mid, node[x].ls);
        Q1(mid + 1, r, mid + 1, R, node[x].rs);
    }
}

int pre[N];

void ins(int id) {
    int len = strlen(str + 1);
    int u = 0;
    for (int i = 1; i <= len; i++) {
        int c = str[i] - 'a';
        if (!ch[u][c]) {
            ch[u][c] = ++sz;
            memset(ch[sz], 0, sizeof(ch[sz]));
        }
        u = ch[u][c];
        g[id].push_back(pre[u]);
        pre[u] = id;
    }
}

struct Seg {
    int l, r, v;
    Seg() {}
    Seg(int l, int r, int v) : l(l), r(r), v(v) {}
};

vector<Seg> s[N];

int main() {
    //freopen("1010.in", "r", stdin);
    //freopen("out", "w", stdout);
    while (~scanf("%d", &n)) {
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; i++) g[i].clear();
        sz = 0;
        memset(ch[sz], 0, sizeof(ch[sz]));
        for (int i = 1; i <= n; i++) {
            scanf("%s", str + 1);
            ins(i);
        }
        idx = 0;
        build(1, n, rt[0]);
        for (int i = 1; i <= n; i++) {
            rt[i] = rt[i - 1];
            for (int j = 0; j < g[i].size(); j++)
                modify(g[i][j] + 1, i, 1, 1, n, rt[i]);
        }
        int qn;
        scanf("%d", &qn);
        int u, v;
        ans = 0;
        while (qn--) {
            scanf("%d%d", &u, &v);
            int tmp = min((ans + u) % n, (ans + v) % n) + 1;
            v = max((ans + u) % n, (ans + v) % n) + 1;
            u = tmp;
            ans = 0;
            Q1(u, u, 1, n, rt[v]);
            printf("%d\n", ans);
        }
    }
    return 0;
}
