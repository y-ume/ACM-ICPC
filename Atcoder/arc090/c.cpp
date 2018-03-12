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

int main(){
  int n;
  cin >> n;
  vector<vi> a(2 , vi(n));
  rep(i,0,2) rep(j,0,n) cin >> a[i][j];
  int best = 0;
  rep(i,0,n) {
    int sum = 0;
    rep(j,0,i+1) sum += a[0][j];
    rep(j,i,n) sum += a[1][j];
    best = max(best , sum);
  }
  cout << best << endl;
  return 0;
}
