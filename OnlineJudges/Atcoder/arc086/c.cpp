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

int n , K , a;

int main(){
  scanf("%d%d",&n,&K);
  map<int,int> times;
  rep(i,0,n) {
    scanf("%d",&a);
    times[a]++;
  }
  vi v;
  for(auto e : times) v.pb(e.se);
  sort(all(v));
  int del = max(0 , sz(v) - K);
  int ans = 0;
  rep(i,0,del) ans += v[i];
  printf("%d\n",ans);
  return 0;
}
