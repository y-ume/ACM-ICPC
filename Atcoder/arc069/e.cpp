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
int n , a[N];
ll ans[N];

int main(){
  cin >> n;
  rep(i,1,n+1) cin >> a[i];
  vi pos;pos.pb(0);
  rep(i,1,n+1) if(a[i]>a[pos.back()])
    pos.pb(i);
  int cnt = 0 , cur = n;
  priority_queue<int> Q;
  per(i,1,sz(pos)) {
    while(cur >= pos[i-1]) Q.push(a[cur--]);
    ll del = ll(cnt) * (a[pos[i]] - a[pos[i-1]]);
    while(sz(Q) && Q.top() >= a[pos[i-1]]) {
      del += Q.top() - a[pos[i-1]] , cnt++;
      Q.pop();
    }
    ans[pos[i]] = del;
  }
  rep(i,1,n+1) cout << ans[i] << endl;
  return 0;
}
