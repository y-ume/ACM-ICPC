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

int n;
vector<pair<int,ll> > A , B;

int main(){
    scanf("%d",&n);
    A.pb(mp(0 , 1));
    rep(i,0,3) {
        rep(i,1,sz(A)) A[i].se += A[i-1].se;
        B.assign(n,mp(0,0));
        rep(i,0,n) scanf("%d",&B[i].fi);
        sort(all(B));
        rep(i,0,n) {
            auto e = lower_bound(all(A),mp(B[i].fi,0ll));
            if(e!=A.begin()){
                --e;
                B[i].se=e->se;
            }
        }
        swap(A , B);
    }
    ll ans=0;
    rep(i,0,n) ans+=A[i].se;
    printf("%lld\n",ans);
    return 0;
}
