// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = 1e5 + 10;
int X , K , r[N];
int Q , t , a;

int main(){
    cin >> X >> K;
    rep(i,1,K+1) cin >> r[i];
    cin >> Q;
    int a = 0 , b = X , c = 0;
    int cur = 0;
    rep(i,0,Q) {
        int t , W;
        cin >> t >> W;
        while(cur < K && r[cur + 1] <= t) {
            int duration = r[cur + 1] - r[cur];
            if(cur & 1) {
                if(a + c + duration >= X) a = b = X , c = 0;
                else if(b + c + duration < X) c += duration;
                else b = X - duration - c , c = X - b;
            } else {
                if(b + c - duration <= 0) a = b = X , c = -X;
                else if(a + c - duration > 0) c -= duration;
                else a = duration - c , c = -a;
            }
            ++cur;
        }
        int fx = 0;
        if(W <= a) fx = a + c;
        else if(a < W && W < b) fx = W + c;
        else fx = b + c;
        if(cur & 1) printf("%d\n",min(X , fx + t - r[cur]));
        else printf("%d\n",max(0 , fx - t + r[cur]));
    }
    return 0;
}
