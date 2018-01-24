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

const int N = 1e5 + 10;
int n , K , a[N] , b[N] , lft[N] , rgt[N];
ll s[N] , dpL[N] , dpR[N];
vi V;

struct SegmentTree{
  int n , a[N << 4];
  int Min(int c,int l,int r,int pos) {
    if(l==r) return a[c];
    else {
      int mid=(l+r)>>1;
      return min(a[c],pos<=mid?
          Min(c<<1,l,mid,pos):Min(c<<1|1,mid+1,r,pos));
    }
  }
  void modify(int c,int l,int r,int L,int R,int x) {
    if(L<=l&&r<=R) a[c]=x;
    else {
      int mid=(l+r)>>1;
      if(L<=mid) modify(c<<1,l,mid,L,R,x);
      if(R>mid) modify(c<<1|1,mid+1,r,L,R,x);
    }
  }
  int Min(int pos) {
    return Min(1,0,n-1,pos);
  }
  void modify(int L,int R,int x) {
    modify(1,0,n-1,L,R,x);
  }
  void init(int _n) {
    n = _n;
    memset(a,0x37,sizeof(a));
  }
}sgt;

int main(){
  scanf("%d%d",&n,&K);
  ll ans = 0;
  rep(i,1,n+1) {
    scanf("%d%d",a+i,b+i);
    ans += a[i] * 2;
    s[i] = s[i-1] + a[i];
    if(b[i] == 1) {
      if(a[i] * 2 > K)
        return puts("-1") , 0;
      lft[i] = (-2 * s[i] % K + K) % K;
      rgt[i] = (-2 * s[i-1] % K + K) % K;
      V.pb(lft[i]);
      V.pb(rgt[i]);
      V.pb((lft[i] + 1) % K);
      V.pb((rgt[i] - 1 + K) % K);
    }
  }
  sort(all(V));
  V.erase(unique(all(V)),V.end());
  rep(i,1,n+1) if(b[i] == 1){
    lft[i] = lower_bound(all(V),lft[i])-V.begin();
    rgt[i] = lower_bound(all(V),rgt[i])-V.begin();
  }
  sgt.init(sz(V));
  per(i,1,n+1) if(b[i] == 1){
    int x = sgt.Min(lft[i]);
    if(x > n) dpL[i] = 0;
    else dpL[i] = dpR[x] + (V[rgt[x]] - V[lft[i]] + K) % K;
    x = sgt.Min(rgt[i]);
    if(x > n) dpR[i] = 0;
    else dpR[i] = dpR[x] + (V[rgt[x]] - V[rgt[i]] + K) % K;
    int l = (lft[i] + 1) % sz(V);
    int r = (rgt[i] - 1 + sz(V)) % sz(V);
    if(l <= r) sgt.modify(l , r , i);
    else sgt.modify(0 , r , i) , sgt.modify(l , sz(V) - 1 , i);
  }
  ll ans2 = *min_element(b+1,b+1+n)==2?0:1ll<<62;
  sgt.init(sz(V));
  rep(i,1,n+1) if(b[i] == 1){
    int x = sgt.Min(lft[i]);
    if(x > n) ans2 = min(ans2 , dpL[i]);
    x = sgt.Min(rgt[i]);
    if(x > n) ans2 = min(ans2 , dpR[i]);
    int l = (lft[i] + 1) % sz(V);
    int r = (rgt[i] - 1 + sz(V)) % sz(V);
    if(l <= r) sgt.modify(l , r , 0);
    else sgt.modify(0 , r , 0) , sgt.modify(l , sz(V) - 1 , 0);
  }
  printf("%lld\n",ans + ans2);
  return 0;
}

