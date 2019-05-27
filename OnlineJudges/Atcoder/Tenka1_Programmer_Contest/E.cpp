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

const int N = 40404;
const db inf = 1e20;
int n , a[N] , b[N] , c[N] , s[N] , t[N];
db Y[N];
template<class T>
struct Fenwick{
#define lb(x) ((x)&-(x))
    int n;T a[N];
    void ini(int _n){ fill_n(a+1,n=_n,0);}
    void add(int x,T d){ for(;x<=n;x+=lb(x)) a[x]+=d;}
    T sum(int x){ T r=0;for(;x>=1;x^=lb(x)) r+=a[x];return r;}
};
Fenwick<int> fen;

db solve() {
    rep(i,0,n) s[i] = t[i] = i;
    int need = (n * (n - 1) / 2 + 1) / 2;
    db l = -inf , r = inf;
    rep(i,0,n) Y[i] = (c[i] - a[i] * l) / b[i];
    sort(t , t + n , [&](int x,int y){return Y[x] < Y[y];});
    rep(i,0,n) s[t[i]] = i;
    rep(i,0,200) {
        db m = (l + r) / 2;
        rep(i,0,n) Y[i] = (c[i] - a[i] * m) / b[i];
        sort(t , t + n , [&](int x,int y){return Y[x] < Y[y];});
        int cnt = 0;
        fen.ini(n);
        rep(i,0,n) cnt+=i-fen.sum(s[t[i]]+1),fen.add(s[t[i]]+1,1);
        if(cnt >= need) r = m;
        else l = m;
    }
    return r;
}

int main(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%d%d%d",a+i,b+i,c+i);
    pair<db,db> ans;
    ans.fi = solve();
    rep(i,0,n) swap(a[i] , b[i]);
    ans.se = solve();
    printf("%.16f %.16f\n",ans.fi , ans.se);
    return 0;
}
