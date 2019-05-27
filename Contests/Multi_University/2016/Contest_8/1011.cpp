#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;
int T, n;
char str[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", str + 1);
        int cnt = 0;
        int h = 1, r = 1;
        int ff = 1;
        for (int i = 1; i <= n; i++) {
            cnt += str[i] == '(' ? 1 : -1;
            if (cnt < 0) {
                ff = 0;
                h = i;
                break;
            }
        }
        if (cnt) ff = 0;
        cnt = 0;
        for (int i = n; i >= 1; i--) {
            if (str[i] == '(') {
                r = i;
                break;
            }
        }
        int f = 1;
        if (ff) {
            if (n == 2 && str[1] == '(' && str[2] == ')')
                f = 0;
        } else {
            swap(str[h], str[r]);
            cnt = 0;
            for (int i = 1; i <= n; i++) {
                cnt += str[i] == '(' ? 1 : -1;
                if (cnt < 0) {
                    f = 0;
                    break;
                }
            }
            if (cnt) f = 0;
        }
        printf("%s\n", f ? "Yes" : "No");
    }
    return 0;
}
