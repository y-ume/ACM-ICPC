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
const ll inf = 1ll<<60;
struct Seg{
    ll mn[N<<2] , add[N<<2];
    void Add(int c,int l,int r,int L,int R,ll d){
        if(L<=l&&r<=R) mn[c]+=d,add[c]+=d;
        else {
            int m=(l+r)>>1;
            if(L<=m) Add(c<<1,l,m,L,R,d);
            if(R>m) Add(c<<1|1,m+1,r,L,R,d);
            mn[c]=min(mn[c<<1],mn[c<<1|1])+add[c];
        }
    }
    ll query(int c,int l,int r,int L,int R){
        if(L<=l&&r<=R) return mn[c];
        else {
            int m=(l+r)>>1;
            ll res=inf<<2;
            if(L<=m) res=min(res,query(c<<1,l,m,L,R));
            if(R>m) res=min(res,query(c<<1|1,m+1,r,L,R));
            return res+add[c];
        }
    }
};
Seg f1 , f2;
int n,Q,A,B;

int main(){
    scanf("%d%d%d%d",&n,&Q,&A,&B);
    rep(i,1,n+1) {
        if(i == A) f1.Add(1,1,n,i,i,i);
        else f1.Add(1,1,n,i,i,inf+i);
        if(i == A) f2.Add(1,1,n,i,i,-i);
        else f2.Add(1,1,n,i,i,inf-i);
    }
    rep(i,0,Q){
        int x;
        scanf("%d",&x);
        ll bestr = f1.query(1,1,n,x,n)-x;
        ll bestl = f2.query(1,1,n,1,x)+x;
        ll best = min(bestl , bestr);
        int costB = abs(x - B);
        f1.Add(1,1,n,1,n,costB);
        f2.Add(1,1,n,1,n,costB);
        ll past = f1.query(1,1,n,B,B)-B;
        if(best < past) {
            f1.Add(1,1,n,B,B,-past+best);
            f2.Add(1,1,n,B,B,-past+best);
        }
        B = x;
    }
    ll ans = inf;
    rep(i,1,n+1) ans=min(ans,f1.query(1,1,n,i,i)-i);
    printf("%lld\n",ans);
    return 0;
}
