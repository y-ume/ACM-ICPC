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

int K , n , len;
string s;

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
struct DA{ // [0,n] , in[n] = 0 , n load
  static const int N = 101010;
  int p[18][N] , rk[N] , in[N] , Log[N] , n;
  void Build(){
    Doubling::da(in,n+1,300);
    Doubling::cal_h(in,n,rk);
    Log[0] = -1;for(int i=1;i<=n;++i) Log[i] = Log[i-1] + (i==(i&(-i)));
    for(int i=1;i<=n;++i) p[0][i] = Doubling::h[i];
    for(int j=1;1<<j<=n;++j){
      int lim = n+1-(1<<j);
      for(int i=1;i<=lim;++i)
        p[j][i] = min(p[j-1][i] , p[j-1][i+(1<<j>>1)]);
    }
  }
  int lcp(int a,int b){
    a = rk[a] , b = rk[b];
    if(a > b) swap(a , b);++a;
    int t = Log[b-a+1];
    return min(p[t][a] , p[t][b-(1<<t)+1]);
  }
}da;

int main(){
  cin >> K >> s;
  n = sz(s);
  ++K;
  len = (n + K - 1) / K;
  da.n = n;
  rep(i,0,n) da.in[i] = s[i];
  da.in[n] = 0;
  da.Build();
  vector<pii> order;
  rep(i,0,n-len+1) order.pb(mp(da.rk[i],i));
  sort(all(order));
  int l = -1 , r = sz(order) - 1;
  while(l + 1 < r) {
    int mid = (l + r) >> 1;
    int i = order[mid].se;
    int times = 0;
    for(int j=0;j<n;++times) {
      int lcp = i != j ? da.lcp(i , j) : n - i;
      if(lcp >= len || j + lcp >= n) j += len;
      else if(s[i + lcp] > s[j + lcp]) j += len;
      else if(len != 1) j += len - 1;
      else {times = K + 1;break;}
    }
    if(times <= K) r = mid;
    else l = mid;
  }
  cout << s.substr(order[r].se , len) << endl;
  return 0;
}
