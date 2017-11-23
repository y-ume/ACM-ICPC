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

const int N = 20 , P = 1e9 + 7;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
int n , m , K , f[1 << N] , mask[N] , need[N];
int go[1 << N][N];

int main(){
    cin >> n >> m >> K;
    --n;
    rep(i,0,K){
        int a,b,c;
        cin >> a >> b >> c;
        --a;--b;
        mask[a] |= 1 << b;
        need[a] |= c << b;
    }
    rep(i,0,1<<n) {
        int top = -1;
        per(j,0,n) {
            if(i >> j & 1) top = j;
            else {
                if(top == -1) go[i][j] = i ^ (1 << j);
                else go[i][j] = i ^ (1 << j) ^ (1 << top);
            }
        }
    }
    f[0] = 1;
    rep(i,0,m) {
        rep(j,0,n) rep(k,0,1<<n) if(f[k] && (~k>>j&1)){
            pp(f[go[k][j]] , f[k]);
        }
        rep(k,0,1<<n) if(need[i] != (mask[i] & k))
            f[k] = 0;
    }
    int ans = 0;
    rep(i,0,1<<n) pp(ans , f[i]);
    printf("%d\n",ans);
    return 0;
}
