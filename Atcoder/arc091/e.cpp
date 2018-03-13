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

int n , A , B;

int main(){
  scanf("%d%d%d",&n,&A,&B);
  if(A + B - 1 <= n && n <= 1ll * A * B) {
    int s = 1 , remain = n - A - B + 1;
    vi v;
    auto add = [&](int from,int to) {
      per(i,from,to) v.pb(i);
    };
    add(s , s + B);
    s += B;
    rep(i,1,A) {
      int inc = min(remain , B - 1);
      remain -= inc;
      add(s , s + 1 + inc);
      s += 1 + inc;
    }
    rep(i,0,sz(v)) printf("%d%c",v[i]," \n"[i+1==sz(v)]);
  } else
    puts("-1");
  return 0;
}
