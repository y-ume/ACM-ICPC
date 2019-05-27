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
int n , a[N] , b[N];

int main() {
  int T;
  scanf("%d",&T);
  rep(i,0,T) {
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",a + i);
    set<pii> Sum , remain;
    map<int,int> times , remaintimes;
    rep(i,0,n) times[a[i]] += 2 , remaintimes[a[i]] ++;
    for(auto e : times) {
      Sum.insert(mp(e.se , e.fi));
      remain.insert(mp(e.fi , e.se / 2));
    }
    if(Sum.rbegin()->fi > n) {
      puts("Impossible");
      continue;
    }
    auto add = [&](int x,int d,int o) {
      Sum.erase(Sum.find(mp(times[x],x)));
      times[x] += d;
      Sum.insert(mp(times[x],x));
      if(o) {
        remain.erase(remain.find(mp(x , remaintimes[x])));
        remaintimes[x] += d;
        if(remaintimes[x] != 0)
          remain.insert(mp(x , remaintimes[x]));
      }
    };
    rep(i,0,n) {
      int del = N;
      int Max = Sum.rbegin()->se;
      if(a[i] != Max && times[Max] == n - i)
        del = Max;
      if(del == N) {
        int cnt = 0;
        for(auto e : remain) {
          if(++cnt >= 5) break;
          if(e.fi != a[i]) {
            del = e.fi;
            break;
          }
        }
      }
      b[i] = del;
      add(b[i] , -1 , 1);
      add(a[i] , -1 , 0);
    }
    rep(i,0,n) printf("%d%c",b[i]," \n"[i+1==n]);
  }
  return 0;
}
