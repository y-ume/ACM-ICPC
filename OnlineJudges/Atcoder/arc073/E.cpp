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

const int N = 2e5 + 10;
int n , x[N] , y[N];

int main(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%d%d",x+i,y+i);
    int mn=min(*min_element(x,x+n),*min_element(y,y+n));
    int mx=max(*max_element(x,x+n),*max_element(y,y+n));
    ll ans = 2e18;
    vector<pii> v;
    rep(i,0,n) v.pb(x[i]<y[i]?mp(x[i],y[i]):mp(y[i],x[i]));
    sort(all(v));
    multiset<int> S;
    rep(i,0,n) S.insert(v[i].fi);
    rep(i,0,n+1) {
        ans = min(ans,ll(mx-mn)*(*S.rbegin()-*S.begin()));
        if(i!=n) {
            S.erase(S.find(v[i].fi));
            S.insert(v[i].se);
        }
    }
    int mn2=2e9,mx2=-2e9;
    rep(i,0,n) {
        int a=x[i],b=y[i];
        if(a>b) swap(a,b);
        mx2=max(mx2,a);
        mn2=min(mn2,b);
    }
    ans=min(ans,ll(mx2-mn)*(mx-mn2));
    printf("%lld\n",ans);
    return 0;
}

