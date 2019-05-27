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

const int N = 2e5 + 10 , P = 1e9 + 7;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
int n,Mx[N],Mn[N];
pii a[N];
vi V;

int main(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%d%d",&a[i].fi,&a[i].se),V.pb(a[i].se);
    sort(all(V));
    sort(a,a+n);
    rep(i,0,n) a[i].se=lower_bound(all(V),a[i].se)-V.begin();
    Mx[0]=a[0].se;
    rep(i,1,n) Mx[i]=max(Mx[i-1],a[i].se);
    Mn[n-1]=a[n-1].se;
    per(i,0,n-1) Mn[i]=min(Mn[i+1],a[i].se);
    vector<pii> f;
    f.pb(mp(0,1));
    int s=1,c=0,ans=0;
    rep(i,0,n) {
        // [Mn[i] , Mx[i]]
        while(c<sz(f)&&f[c].fi<Mn[i])
            pp(s,P-f[c++].se);
        if(Mx[i]+1==n) pp(ans,s);
        f.pb(mp(Mx[i]+1,s)); pp(s,s);
    }
    printf("%d\n",ans);
    return 0;
}
