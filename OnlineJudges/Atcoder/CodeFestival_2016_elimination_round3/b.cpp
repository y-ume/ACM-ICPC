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
int n , a[N] , c[N];
char s[N];

bool check(int x) {
  rep(i,0,n) c[i] = a[i] >= x;
  set<pii> seg;
  priority_queue<pair<int,pii> > q[2];
  int cnt[2] = {0 , 0};
  for(int i=0,j=0;i<n;i=j) {
    for(j=i;j<n&&c[j]==c[i];++j);
    seg.insert(mp(i , j - 1));
    q[c[i]].push(mp(-(j - i) , mp(i , j - 1)));
  }
  rep(i,0,n-1) {
    cnt[s[i] == 'M']++;
    int p = s[i] == 'M' ? 0 : 1;
    while(sz(q[p])) {
      int x = -q[p].top().fi;
      pii s = q[p].top().se;
      if(!seg.count(s)) {
        q[p].pop();
        continue;
      }
      if(x + cnt[p] > cnt[p^1]) break;
      q[p].pop();
      seg.erase(s);
      int l = s.fi , r = s.se;
      //cout << i << " " << l << " " << r << endl;
      auto it = seg.upper_bound(s);
      if(it != seg.end()) {
        r = it->se;
        seg.erase(it);
      }
      it = seg.upper_bound(s);
      if(it != seg.begin()) {
        --it;
        l = it->fi;
        seg.erase(it);
      }
      c[l] = c[r] = p ^ 1;
      seg.insert(mp(l , r));
      q[c[l]].push(mp(-(r - l + 1) , mp(l , r)));
    }
  }
  for(auto e : seg) {
    int l = e.fi , r = e.se;
    int p = c[l];
    if(p) l -= cnt[1] , r -= cnt[0];
    else r -= cnt[1] , l -= cnt[0];
    if(l <= 0 && 0 <= r)
      return p;
  }
  return true;
}

int main(){
  scanf("%d",&n);
  rep(i,0,n) scanf("%d",a + i);
  scanf("%s",s);
  int l = 1 , r = n + 1;
  while(l + 1 < r) {
    int mid = (l + r) >> 1;
    (check(mid) ? l : r) = mid;
  }
  printf("%d\n",l);
  return 0;
}
