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
string s;

void solve(int first,int second) {
  vi v;
  v.pb(first);v.pb(second);
  rep(i,1,n-1) v.pb(v[i]^(s[i]=='x')^v[i-1]);
  rep(i,0,n) if((v[i]^(s[i]=='x'))!=(v[(i-1+n)%n]^v[(i+1)%n]))
    return;
  rep(i,0,n) putchar("SW"[v[i]]);
  exit(0);
}

int main(){
  cin >> n >> s;
  rep(i,0,2) rep(j,0,2)
    solve(i , j);
  puts("-1");
  return 0;
}
