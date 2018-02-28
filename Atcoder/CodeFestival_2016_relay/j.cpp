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

const int N = 170000;
int x[N] , y[N] , _ , vis[N];
void add(int a,int b) {
  x[_] = a , y[_++] = b;
  if(b == 0) vis[a] = true;
}

int main(){
  int n;
  scanf("%d",&n);
  for(int i=1;i<n;i+=3) {
    rep(j,0,n) if((i + j) & 1)
      add(i , j);
  }
  if(n % 3 == 1) {
    rep(j,0,n) if((n - 1 + j) & 1)
      add(n - 1 , j);
  }
  rep(i,0,n) if(i & 1 && !vis[i])
    add(i , 0);
  printf("%d\n",_);
  rep(i,0,_) printf("%d %d\n",x[i],y[i]);
  return 0;
}
