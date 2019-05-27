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

const int N = 15 , P = 1e9 + 7;
int n , m , g[N] , f[1 << N] , can[1 << N] , cnt[N][1 << N];
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
inline int mul(int a,int b){return ll(a)*b%P;}

int main(){
    cin >> n >> m;
    rep(i,0,m) {
        int x , y;
        cin >> x >> y;
        --x;--y;
        g[x] |= 1 << y;
    }
    rep(i,0,n) rep(j,0,n) rep(k,0,1<<j)
        cnt[i][k|1<<j]=cnt[i][k]+(g[i]>>j&1);
    rep(i,0,1<<n) can[i] = (i & 1) == (i >> 1 & 1);
    f[0] = 1;
    rep(i,1,1<<n) if(can[i]) {
        f[i] = 1;
        for(int s=i;s;s=(s-1)&i){
            if(s==i || !can[s]) continue;
            int t=s^i;
            int tmp=f[s];
            rep(j,0,n) if(s>>j&1) tmp=mul(tmp,(1<<cnt[j][t])-1);
            rep(j,0,n) if(t>>j&1) tmp=mul(tmp,1<<cnt[j][s]);
            pp(f[i],tmp);
        }
    }
    int ans=1;
    rep(i,0,m) ans=ans*2%P;
    pp(ans,P-f[(1<<n)-1]);
    cout << ans << endl;
    return 0;
}
