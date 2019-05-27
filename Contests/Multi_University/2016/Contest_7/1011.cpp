#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int P = 1e9 + 7 , N = 1010;
int Pow(int x,int t){int r=1;for(;t;t>>=1,x=1ll*x*x%P)if(t&1)r=1ll*r*x%P;return r;}
int T,n,a[N],f[N][N],F[N];

inline void pp(int &x,int d){
    x += d;
    if(x >= P) x -= P;
}
void main2(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i) scanf("%d",a + i);
    if(n == 1){
        printf("%d\n",1);
        return;
    }
    for(int i=1;i<=n-1;++i) for(int j=1;j<=i;++j) f[i][j] = 0;
    f[1][1] = 1;
    memset(F,0,sizeof(F));
    for(int i=1;i<=n-1;++i){
        int t = 0;
        for(int j=i;j>=1;--j){
            pp(t , F[j]);
            pp(f[i][j] , t);
        }
        for(int j=1;j<=i;++j) F[j] = 0;
        if(i!=n-1)
        for(int j=1;j<=i;++j) if(f[i][j]){
            if(a[i+1] == 0){
                pp(F[j] , f[i][j]);
                pp(f[i+1][1] , f[i][j]);
            } else {
                pp(f[i+1][j+1] , f[i][j]);
            }
        }
    }
    int ans = 0;
    for(int i=1;i<=n-1;++i) pp(ans , f[n-1][i]);
    ans = 1ll * ans *Pow(Pow(2,n-1),P-2) % P;
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&T);
    int re=0;
    rep(i,0,T) printf("Case #%d: ",++re) , main2();
    return 0;
}
