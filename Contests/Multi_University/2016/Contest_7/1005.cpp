#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1005;
int T, n;

struct SB {
    int v, id;
    void read(int id) {
        scanf("%d", &v);
        this->id = id;
    }
    bool operator < (const SB& c) const {
        return v < c.v;
    }
} sb[N];

vector<pair<int, int> > ans;

bool judge() {
    for (int i = 1; i <= n; i++) {
        if (sb[i].v > i - 1) return false;
        for (int j = 1; j <= sb[i].v; j++)
            ans.push_back(make_pair(sb[i].id, sb[j].id));
    }
    return true;
}

int main() {
    int cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) sb[i].read(i);
        sort(sb + 1, sb + 1 + n);
        printf("Case #%d: " , ++cas);
        ans.clear();
        if (judge()) {
            printf("Yes\n");
            printf("%d\n", (int)ans.size());
            for (int i = 0; i < ans.size(); i++) {
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        } else printf("No\n");
    }
    return 0;
}
