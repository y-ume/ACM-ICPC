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

const int N = 2020;
int n , a[N] , vis[N];
vi g[N];

vi merge(vi a,vi b) {
  vi r(sz(a)+sz(b),0);
  for(int i=0,j=0,x=0;i<sz(a)||j<sz(b);)
    r[x++]=(j==sz(b)||(i!=sz(a)&&a[i]>b[j]))?a[i++]:b[j++];
  return r;
}

vi dfs(int c) {
  vis[c]=true;
  sort(all(g[c]),[&](int x,int y){return a[x]<a[y];});
  vi res;
  for(auto t : g[c]) if(!vis[t]) {
    res = merge(res , dfs(t));
  }
  res.insert(res.begin(),a[c]);
  return res;
}

int main(){
  cin >> n;
  rep(i,1,n+1) cin >> a[i];
  rep(i,1,n+1) g[0].pb(i);
  rep(i,1,n+1) rep(j,i+1,n+1) if(__gcd(a[i],a[j])!=1)
    g[i].pb(j),g[j].pb(i);
  vi v = dfs(0);
  rep(i,1,n+1) cout << v[i] << " \n"[i==n];
  return 0;
}
