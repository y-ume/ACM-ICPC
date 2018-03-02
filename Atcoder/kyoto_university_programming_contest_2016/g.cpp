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

namespace Doubling{
  static const int N = 101010;
  int t[N] , wa[N] , wb[N] , sa[N] , h[N];
  void sort(int *x,int *y,int n,int m){
    rep(i,0,m) t[i] = 0;
    rep(i,0,n) t[x[y[i]]]++;
    rep(i,1,m) t[i] += t[i-1];
    per(i,0,n) sa[--t[x[y[i]]]] = y[i];
  }
  bool cmp(int *x,int a,int b,int d){
    return x[a] == x[b] && x[a+d] == x[b+d];
  }
  void da(int *s,int n,int m){
    int *x=wa,*y=wb;
    rep(i,0,n) x[i] = s[i] , y[i] = i;
    sort(x , y , n , m);
    for(int j=1,p=1;p<n;m=p,j<<=1){
      p = 0;rep(i,n-j,n) y[p++] = i;
      rep(i,0,n) if(sa[i] >= j) y[p++] = sa[i] - j;
      sort(x , y , n , m);
      swap(x , y);p = 1;x[sa[0]] = 0;
      rep(i,1,n) x[sa[i]] = cmp(y,sa[i],sa[i-1],j)?p-1:p++;
    }
  }
  void cal_h(int *s,int n,int *rk){
    int j,k=0;
    for(int i=1;i<=n;++i) rk[sa[i]] = i;
    for(int i=0;i<n;h[rk[i++]] = k)
      for(k&&--k,j=sa[rk[i]-1];s[i+k]==s[j+k];++k);
  }
}
static const int N = 101010;
int rk[N] , in[N] , Log[N] , n;

int main(){
  string s;
  cin >> s;
  n = sz(s);
  rep(i,0,n) in[i] = s[i];
  in[n] = 0;
  Doubling::da(in,n+1,300);
  Doubling::cal_h(in,n,rk);
  vi height;
  rep(i,1,n+1) height.pb(Doubling::h[i]);
  sort(all(height));
  int ans = 0 , cur = 0 , sum = 0;
  rep(i,0,n) {
    while(cur < sz(height) && height[cur] == i)
      ++cur , sum++;
    ans = max(ans , sum);
    sum--;
  }
  cout << ans << endl;
  return 0;
}
