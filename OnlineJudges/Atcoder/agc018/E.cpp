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

const int N = 2e6 + 10 , P = 1e9 + 7;
int x[6] , y[6] , fac[N] = {1} , ifac[N];
int inv(int x){return x==1?1:P-ll(P/x)*inv(P%x)%P;}
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
inline int way(int x,int y){
    if(x<0||y<0) return 0;
    return ll(fac[x+y])*ifac[x]%P*ifac[y]%P;
}
inline int way(int sx,int sy,int tx,int ty){
    return way(tx-sx,ty-sy);
}

int solve(int sx,int sy,int tx,int ty){
    int res=0;
    int x0=x[2],x1=x[3],y0=y[2],y1=y[3];
    for(int i=x0;i<=x1;++i) {
        pp(res,P-ll(way(sx,sy,i,y0-1))*way(i,y0,tx,ty)%P*(i+y0)%P);
        pp(res,ll(way(sx,sy,i,y1))*way(i,y1+1,tx,ty)%P*(i+y1+1)%P);
    }
    for(int j=y0;j<=y1;++j) {
        pp(res,P-ll(way(sx,sy,x0-1,j))*way(x0,j,tx,ty)%P*(x0+j)%P);
        pp(res,ll(way(sx,sy,x1,j))*way(x1+1,j,tx,ty)%P*(x1+1+j)%P);
    }
    //cout << sx << " " << sy << " " << tx << " " << ty << " " << res << endl;
    return res;
}

int main(){
    rep(i,1,N) fac[i]=ll(fac[i-1])*i%P;
    ifac[N-1]=inv(fac[N-1]);
    per(i,1,N) ifac[i-1]=ll(ifac[i])*i%P;
    rep(i,0,6) scanf("%d",x+i);
    rep(i,0,6) scanf("%d",y+i);
    x[0]--,y[0]--,x[5]++,y[5]++;
    int ans=0;
    rep(ai,0,2) rep(aj,0,2) rep(bi,0,2) rep(bj,0,2) {
        int t=solve(x[ai],y[aj],x[4+bi],y[4+bj]);
        if(ai^aj^bi^bj) pp(ans,P-t);
        else pp(ans,t);
    }
    printf("%d\n",ans);
    return 0;
}
