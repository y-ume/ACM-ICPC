#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

struct Node {
    int ti, id;
    Node() {}
    Node(int ti, int id) : ti(ti), id(id) {};
    bool operator < (const Node& c) const {
        return ti >  c.ti;
    }
};

set<Node> A[2];
int id[2];

int n;
char op[15], a[15], b[15];
int x;

int main() {
    int cas = 0;
    while (~scanf("%d", &n) && n) {
        id[0] = 0; id[1] = 1;
        A[0].clear(); A[1].clear();
        printf("Case #%d:\n", ++cas);
        for (int i = 0; i < n; i++) {
            scanf("%s", op);
            if (op[1] == 'u') {
                scanf("%s%d", a, &x);
                int f = a[0] == 'B';
                A[id[f]].insert(Node(i, x));
            } else if (op[1] == 'o') {
                scanf("%s", a);
                int f = a[0] == 'B';
                set<Node>::iterator it = A[id[f]].begin();
                printf("%d\n", it->id);
                A[id[f]].erase(it);
            } else {
                scanf("%s%s", a, b);
                int f0 = a[0] == 'B';
                int f1 = b[0] == 'B';
                int f = 0;
                if (A[id[f0]].size() < A[id[f1]].size()) {
                    swap(f0, f1);
                    f ^= 1;
                }
                for (set<Node>::iterator it = A[id[f1]].begin(); it != A[id[f1]].end(); it++)
                    A[id[f0]].insert(*it);
                A[id[f1]].clear();
                if (f) swap(id[f0], id[f1]);
            }
        }
    }
    return 0;
}
