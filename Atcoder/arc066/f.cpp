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

const int N = 3e5 + 10;
int n , a[N];
#define left Left
#define right Right
ll left[N] , right[N] , sum[N];
#define cost(j,i) (i-j+1)*(i-j)/2-(sum[i]-sum[j])+f[j]
#define K(j) (-j)
#define B(j) (ll(j-1)*j/2+sum[j]+f[j])
#define R(i) (ll(i+1)*i/2-sum[i])
typedef pair<ll,ll> pll;
pll p[N];
inline ll get(pll t,ll x) {return t.fi*x+t.se;}
inline ll cross(pll a,pll b,pll c) {
  return (b.fi-a.fi)*(c.se-a.se)-(c.fi-a.fi)*(b.se-a.se);
}

void Dp(ll *f) {
  rep(i,1,n+1) sum[i]=sum[i-1]+a[i];
  int _ = 0;
  p[_++]=mp(K(0),B(0));
  rep(i,1,n+1) {
    while(_>1&&get(p[_-2],i)>=get(p[_-1],i)) --_;
    f[i]=max(f[i-1],get(p[_-1],i)+R(i));
    pair<ll,ll> pts=mp(K(i),B(i));
    while(_>1&&cross(p[_-2],p[_-1],pts)<=0) --_;
    p[_++]=pts;
  }
  //rep(i,1,n+1) printf("%lld%c",f[i]," \n"[i==n]);
}
ll tmp[N] , best[N];

void solve(int l,int r) {
  if(l==r) return;
  int m=(l+r)>>1;
  int _=0;ll *f=left;
  rep(i,l,m+1) {
    pair<ll,ll> pts=mp(K(i),B(i));
    while(_>1&&cross(p[_-2],p[_-1],pts)<=0) --_;
    p[_++]=pts;
  }
  rep(i,m+1,r+1) {
    while(_>1&&get(p[_-2],i)>=get(p[_-1],i)) --_;
    tmp[i]=get(p[_-1],i)+R(i)+right[i+1];
  }
  per(i,m+1,r+1) {
    if(i!=r) tmp[i]=max(tmp[i],tmp[i+1]);
    best[i]=max(best[i],tmp[i]);
  }
  solve(l,m);
  solve(m+1,r);
}

int main(){
  scanf("%d",&n);
  rep(i,1,n+1) scanf("%d",a+i);
#define rev(a) reverse(a+1,a+1+n)
  Dp(left);rev(a);
  Dp(right);rev(a);rev(right);
  rep(i,1,n+1) best[i]=-8e18;
  rep(i,0,2) {
    rep(i,1,n+1) sum[i]=sum[i-1]+a[i];
    solve(0 , n);
    rev(best);rev(a);rev(left);rev(right);
    rep(i,1,n+1) swap(left[i],right[i]);
  }
  int m;
  scanf("%d",&m);
  rep(i,0,m) {
    int x,k;
    scanf("%d%d",&x,&k);
    printf("%lld\n",max(left[x-1]+right[x+1],best[x]+a[x]-k));
  }
  return 0;
}
