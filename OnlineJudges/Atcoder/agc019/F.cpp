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

const int N = 1e6 + 10 , P = 998244353;
int Pow(int x,int t){int r=1;for(;t;t>>=1,x=ll(x)*x%P)if(t&1)r=ll(r)*x%P;return r;}
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
int inv[N] = {1} , fac[N] = {1} , ifac[N];
int n , m;
int comb(int a,int b){
    return ll(fac[a])*ifac[b]%P*ifac[a-b]%P;
}
int f(int n,int m,int a,int b){
    if(n>=0&&m>=0&&a>=0&&a<=n&&b>=0&&b<=m)
        return ll(comb(n+m-a-b,n-a))*comb(a+b,b)%P;
    return 0;
}

int main(){
    cin >> n >> m;
    if(n < m) swap(n , m);
    int tot = n + m + 1;
    rep(i,1,tot) fac[i]=ll(fac[i-1])*i%P;
    ifac[tot-1]=Pow(fac[tot-1],P-2);
    per(i,1,tot) ifac[i-1]=ll(ifac[i])*i%P;
    rep(i,1,tot) inv[i]=ll(fac[i-1])*ifac[i]%P;
    int ans = 0 , ver = 0 , hor = 0 , s = 0;
    int vx = 0 , vy = 0 , hx = 0 , hy = 0;
    rep(i,1,tot) {
        {
            int nx = vx + (~i & 1);
            int ny = vy + (i & 1);
            if(i == 1) nx = 1 , ny = 0 , ver = f(n-1,m,nx-1,ny);
            else if(nx == vx) pp(ver , f(n-2,m,nx-2,ny));
            else pp(ver , P-f(n-1,m-1,nx-2,ny));
            vx = nx , vy = ny;
        }
        {
            int nx = hx + (i & 1);
            int ny = hy + (~i & 1);
            if(i == 1) nx = 0 , ny = 1 , hor = f(n,m-1,nx,ny-1);
            else if(nx == hx) pp(hor , P-f(n-1,m-1,nx,ny-2));
            else pp(hor , f(n,m-2,nx,ny-2));
            hx = nx , hy = ny;
        }
        pp(s , hor);
        pp(s , ver);
        pp(ans , (ll)s*inv[i]%P);
    }
    ans = ll(ans)*Pow(comb(n+m,n),P-2)%P;
    printf("%d\n",ans);
    return 0;
}
