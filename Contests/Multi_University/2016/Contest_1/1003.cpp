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
const int N = 1010;
int T , n , m , cntx[N] , cnty[N] , a[N];
char s[N][N];
vector<pii> V;
db ans;
void solve(){
    fill(a , a + n , -1);
    rep(i,0,sz(V)) a[V[i].fi] = V[i].se;
    rep(i,0,n) if(~a[i]){
        ans += a[i] * (m - 1 - a[i]) * 2;
        int c = a[i];
        rep(j,i+1,n){
            if(a[j] == -1 || a[j] < c) break;
            c = a[j];
            ans += a[i] * (m - 1 - a[j]) * 2;
        }
        c = a[i];
        rep(j,i+1,n){
            if(a[j] == -1 || a[j] > c) break;
            c = a[j];
            ans += (m - 1 - a[i]) * a[j] * 2;
        }
    }
}


int main(){
    scanf("%d",&T);
    rep(i,0,T){
        scanf("%d%d",&n,&m);
        rep(i,0,n) scanf("%s",s[i]);
        V.clear();
        fill(cntx , cntx + n , 0);
        fill(cnty , cnty + m , 0);
        rep(i,0,n) rep(j,0,m)
            if(s[i][j] == 'G') V.pb(mp(i,j));
            else cntx[i]++ , cnty[j]++;
        ans = 0;
        rep(i,0,n) rep(j,i+1,n) ans += (db)cntx[i] * cntx[j] * (j-i);
        rep(i,0,m) rep(j,i+1,m) ans += (db)cnty[i] * cnty[j] * (j-i);
        solve();
        rep(i,0,sz(V)) swap(V[i].fi,V[i].se);
        swap(n,m);
        solve();
        printf("%.4lf\n",ans * 2 / ((db)(n*m-sz(V)) * (n*m-sz(V))) + 1e-8);
    }
    return 0;
}
