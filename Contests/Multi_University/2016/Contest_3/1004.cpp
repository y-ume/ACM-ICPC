#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

const int N = 905;
int T, n, m;
bitset<905> b[3], maxs;

struct R {
    bitset<905> s[3];
    R() {
        for (int i = 0; i < 3; i++)
            s[i].reset();
        s[0] = maxs;
        //for (int i = 0; i <= n * m; i++)
          //  s[0][i] = 1;
    }

    R operator ^ (const R& c) const {
        R ans;
        //ans.s[0].reset();
        for (int i = 1; i < 3; i++) {
            ans.s[i] |= (c.s[0]&s[i]);
            ans.s[i] |= (s[0]&c.s[i]);
            for (int j = 1; j < 3; j++) {
                int tmp = (i + j) % 3;
                if (tmp == 0) continue;
                ans.s[tmp] |= (s[i]&c.s[j]);
            }
        }
        ans.s[0] = maxs^ans.s[1]^ans.s[2];
        return ans;
    }

    void out() {
        for (int j = 0; j <= n * m; j++) {
            if (s[0][j]) printf("0");
            else if (s[1][j]) printf("1");
            else if (s[2][j]) printf("2");
        }
        printf("\n");
    }
};

R A[N];

void Gauss(int n, int m) {
    int i = 0, x = 0;
    int tot = 0;
    while (i < n && x < m) {
        int r = i;
        for (int j = i + 1; j < n; j++) {
            if (A[j].s[1][x] || A[j].s[2][x]) {
                r = j;
                break;
            }
        }
        if (A[r].s[1][x] == 0 && A[r].s[2][x] == 0) {
            x++;
            continue;
        }
        if (r != i) swap(A[r], A[i]);
        int s1 = 0, s2 = 0;
        if (A[i].s[1][x]) s1 = 1;
        if (A[i].s[2][x]) s1 = 2;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            s2 = 0;
            if (A[j].s[1][x]) s2 = 1;
            if (A[j].s[2][x]) s2 = 2;
            if (s2 == 0) continue;
            tot++;
            if (s1 == 1) {
                if (s2 == 1) {
                    A[j] = A[j]^A[i];
                    A[j] = A[j]^A[i];
                } else {
                    A[j] = A[j]^A[i];
                }
            } else {
                if (s2 == 1) {
                    A[j] = A[j]^A[i];
                }
                else {
                    A[j] = A[j]^A[i];
                    A[j] = A[j]^A[i];
                }
            }
        }
     //   for (int l = 0; l < n; l++) A[l].out();printf("\n");
        i++; x++;
    }
   // printf("%d\n", tot);
}

const int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
R ss;
#define mp(a, b) make_pair(a, b)

vector<pair<int, int> > ans;
int main() {
    scanf("%d", &T);
    while (T--) {
        maxs.reset();
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n * m; i++) maxs[i] = 1;
        int w;
        for (int i = 0; i < n * m; i++) A[i] = R();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &w);
               // w = 0;
                ss = R();
                if (w == 2) w = 1;
                else if (w == 1) w = 2;
                ss.s[0][n * m] = 0;
                ss.s[w][n * m] = 1;
               // ss.out();
                A[i * m + j] = A[i * m + j]^ss;
                for (int k = 0; k < 4; k++) {
                    int xx = i + dir[k][0];
                    int yy = j + dir[k][1];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                    ss = R();
                    ss.s[0][xx * m + yy] = 0;
                    ss.s[1][xx * m + yy] = 1;
                    A[i * m + j] = (A[i * m + j]^ss);
                }
                ss = R();
                ss.s[0][i * m + j] = 0;
                ss.s[2][i * m + j] = 1;
                A[i * m + j] = (A[i * m + j]^ss);
            }
        }
    //    for (int i = 0; i < n * m; i++) A[i].out();
        Gauss(n * m, n * m);
     //   for (int i = 0; i < n * m; i++) A[i].out();
        ans.clear();
        for (int i = 0; i < n * m; i++) {
            int ss = 0, bb = 0;
            if (A[i].s[1][i]) ss = 1;
            if (A[i].s[2][i]) ss = 2;
            if (A[i].s[1][n * m]) bb = 1;
            if (A[i].s[2][n * m]) bb = 2;
            if (ss == 0) continue;
            if (bb == 1) {
                if (ss == 1) {
                    ans.push_back(mp(i / m + 1, i % m + 1));
                } else {
                    ans.push_back(mp(i / m + 1, i % m + 1));
                    ans.push_back(mp(i / m + 1, i % m + 1));
                }
            } else if (bb == 2) {
                if (ss == 1) {
                    ans.push_back(mp(i / m + 1, i % m + 1));
                    ans.push_back(mp(i / m + 1, i % m + 1));
                } else {
                    ans.push_back(mp(i / m + 1, i % m + 1));
                }
            }
        }
        printf("%d\n", (int)ans.size());
        for (int i = 0; i < ans.size(); i++)
            printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}
