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
int n , a[N] , b[N] , c[N] , has[N];
int s[N] , del[N] , maxup[N];

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%d%d",a+i,b+i);
  rep(i,0,n+1) scanf("%d",c+i);
  vi v(c,c+n+1);
  sort(all(v));
  v.erase(unique(all(v)),v.end());
#define rk(x) lower_bound(all(v),x)-v.begin()
  vi seg;
  rep(i,0,n) {
    a[i]=rk(a[i]);b[i]=rk(b[i]);
    s[a[i]]++;
    if(b[i]<a[i]) {
      has[i] = true;
      seg.pb(i);
    }
  }
  rep(i,0,n+1) {
    c[i]=rk(c[i]);
    s[c[i]]--;
  }
  int need = 0 , err = 0 , cur = 0 , dif = 0;
  sort(all(seg),[&](int x,int y){return a[x]>a[y];});
  rep(i,1,sz(v)) s[i]+=s[i-1];
  priority_queue<pii> Q;
  vi used;
  per(i,0,sz(v)) {
    dif += del[i];
    int t = s[i] + dif;
    while(cur<sz(seg)&&a[seg[cur]]>i) {
      Q.push(mp(-b[seg[cur]],seg[cur]));
      cur++;
    }
    while(t<-1&&sz(Q)) {
      int x = Q.top().se;Q.pop();
      if(b[x]>i) continue;
      used.pb(x);
      has[x] = false;
      need ++;
      dif ++;
      t ++;
      if(b[x]) del[b[x]-1] --;
    }
    if(t<-1) {
      err=1;
      break;
    }
  }
  if(!err) {
    memset(del , 0 , sizeof(del));
    for(auto e : used) del[b[e]]++ , del[a[e]]--;
    rep(i,1,sz(v)) del[i]+=del[i-1];
    rep(i,0,sz(v)) s[i]+=del[i];
    memset(maxup , -1 , sizeof(maxup));
    maxup[0] = n - need;
    vi seg;
    rep(i,0,n) if(has[i]) {
      seg.pb(i);
    }
    sort(all(seg),[&](int x,int y){return b[x]<b[y];});
    priority_queue<pii> Q;
    memset(del , 0 , sizeof(del));
    int cur = 0 , dif = 0;
    rep(i,0,sz(v)) {
      dif += del[i];
      int t = s[i] + dif;
      while(cur<sz(seg)&&b[seg[cur]]<=i){
        Q.push(mp(a[seg[cur]],seg[cur]));
        cur++;
      }
      while(t<0&&sz(Q)) {
        int x = Q.top().se;Q.pop();
        if(a[x]<=i) continue;
        need ++;
        dif ++;
        t ++;
        del[a[x]]--;
      }
      if(t<0) break;
      else maxup[i+1] = n - need;
    }
  } else memset(maxup , -1 , sizeof(maxup));
  int q;
  scanf("%d",&q);
  rep(i,0,q) {
    int d,e;
    scanf("%d%d",&d,&e);
    d=rk(d);e=rk(e);
    int ans=-1;
    if(maxup[d]!=-1) ans=max(ans,maxup[d]+1);
    if(maxup[e]!=-1) ans=max(ans,maxup[e]);
    printf("%d\n",ans);
  }
  return 0;
}
