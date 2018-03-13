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
  int n , K;
  cin >> n >> K;
  ll ans = 0;
  if(K == 0)
    ans += n;
  rep(b,2,n+1) if(b - 1 >= K) {
    ans += n / b * (b - K);
    // 1 2 3 4 5 0
    int remain = n % b;
    if(K == 0)
      ans += remain;
    else
      ans += max(0 , min(b - 1 , remain) - K + 1);
  }
  cout << ans << endl;
  return 0;
}
