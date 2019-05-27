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
const int N = 5005 , P = 1e9 + 7;
int n , m , a[N] , nxt[N][N] , pre[N][N];
pii ans , best , f[N][N];
void pp(int &x,int d){
    x += d;(x >= P) && (x -= P);
}
void Update(pii&a,pii b){
    if(a.fi<b.fi) a = b;
    else if(a.fi==b.fi) pp(a.se,b.se);
}

int main(){
    while(~scanf("%d",&n)){
        vi v;
        rep(i,1,n+1) scanf("%d",a + i) , v.pb(a[i]);
        sort(all(v));v.erase(unique(all(v)),v.end());
        rep(i,1,n+1) a[i] = lower_bound(all(v),a[i]) - v.begin();
        m = sz(v);
        a[0] = a[n+1] = -1;
        rep(i,0,m) pre[0][i] = i , nxt[n+1][i] = n+1;
        rep(i,1,n+2) rep(j,0,m) pre[i][j] = a[i-1] == j ? i-1 : pre[i-1][j];
        for(int i=n;i>=0;--i) rep(j,0,m) nxt[i][j] = a[i+1] == j ? i+1 : nxt[i+1][j];
        for(int i=n;i>=1;--i){
            best = mp(0,1);
            rep(j,i,n+1){
                f[i][j] = a[i] == a[j] ? mp(best.fi+2-(i==j),best.se) : mp(0,0);
                if(a[j] <= a[i]){
                    pii tmp = f[nxt[i][a[j]]][pre[j][a[j]]];
                    if(tmp.fi == best.fi) pp(best.se,P-tmp.se);
                    tmp = f[nxt[i][a[j]]][j];
                    Update(best , tmp);
                }
            }
        }
        ans = mp(0,1);
        rep(i,0,m) Update(ans , f[nxt[0][i]][pre[n+1][i]]);
        printf("%d %d\n",ans.fi,ans.se);
    }
    return 0;
}
