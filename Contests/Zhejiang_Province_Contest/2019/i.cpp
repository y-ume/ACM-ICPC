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

const int N = 1e5 + 10;
string S;

int get() {
  cin >> S;
  int x = 0;
  rep(i,0,sz(S)) {
    x = x * 10 + S[i] - '0';
    x %= 3;
  }
  return x;
}

int main() {
  // 1 , 1 , 0 , 1 , 1 , 0
  // 1 , 0 , 0 , 1 , 0 , 0
  int T;
  cin >> T;
  rep(i,0,T) {
    int l = (get() + 2) % 3;
    int r = get() % 3;
    int ans = (l == 1) ^ (r == 1);
    cout << ans << endl;
  }
  return 0;
}
