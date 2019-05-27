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

const int N = 400 , P = 1e9 + 7;
int f[N][N] , cnt[N][N];
pii nxt[N][N];
int a[N] , posa[N] , b[N] , posb[N] , n , cof;
inline void pp(int &x,int d){
    if((x+=d)>=P)x-=P;
}

int main(){
    cin >> n;
    rep(i,0,n) cin >> a[i] , posa[a[i]] = i;
    rep(i,0,n) cin >> b[i] , posb[b[i]] = i;
    per(i,0,n+1) per(j,0,n+1){
        if(i >= n || j >= n) nxt[i][j] = mp(n , n);
        else if(posb[a[i]] < j) nxt[i][j] = nxt[i+1][j];
        else if(posa[b[j]] < i) nxt[i][j] = nxt[i][j+1];
        else nxt[i][j] = mp(i , j);
    }
    rep(i,0,n+1) rep(j,0,n+1) {
        if(i) cnt[i][j]=cnt[i-1][j]+(posb[a[i-1]]>=j);
        else if(j) cnt[i][j]=cnt[i][j-1]+(posa[b[j-1]]>=i);
        else cnt[i][j]=0;
    }
    int m = n / 3;
    f[0][0] = 1;
    rep(t,1,m+1) {
        per(i,0,n) per(j,0,n) if(f[i][j]) {
            if(a[i]!=b[j]) pp(f[nxt[i+1][j+1].fi][nxt[i+1][j+1].se],f[i][j]);
            f[i][j]=0;
        }
        int full=t*3;
        rep(i,0,n) rep(j,0,n) if(f[i][j]&&cnt[i][j]<full){
            pp(f[nxt[i+1][j].fi][nxt[i+1][j].se],1ll*f[i][j]*(full-cnt[i][j])%P);
        }
        rep(i,0,n) rep(j,0,n) if(f[i][j]&&cnt[i][j]<full){
            if(nxt[i][j+1].fi==i)
                pp(f[nxt[i][j+1].fi][nxt[i][j+1].se],1ll*f[i][j]*(full-cnt[i][j])%P);
        }
    }
    cof=1;
    rep(i,0,m) cof=1ll*cof*(i*3+1)%P*(i*3+2)%P;
    cof=1ll*cof*f[n][n]%P;
    printf("%d\n",cof);
    return 0;
}
