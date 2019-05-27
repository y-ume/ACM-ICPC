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

const int N = 505;
int x[N] , a[N * N] , n , l[N] , r[N];

int main(){
  scanf("%d",&n);
  rep(i,1,n+1) scanf("%d",x + i) , a[x[i]] = i;
  priority_queue<pii> L;
  rep(i,1,n+1) l[i] = i - 1;
  rep(i,2,n+1) L.push(mp(-x[i] , i));
  int tot = n * n;
  vi R;
  rep(i,1,tot+1) {
    if(a[i]) {
      if(l[a[i]]) return puts("No") , 0;
      rep(j,0,n-a[i]) R.pb(a[i]);
    } else {
      if(sz(L)) {
        int t = L.top().se;L.pop();
        a[i] = t;
        if(--l[t]) L.push(mp(-x[t] , t));
      } else {
        if(!sz(R)) return puts("No") , 0;
        a[i] = R.back();
        R.pop_back();
      }
    }
  }
  puts("Yes");
  rep(i,1,tot+1) printf("%d%c",a[i]," \n"[i==tot]);
  return 0;
}
