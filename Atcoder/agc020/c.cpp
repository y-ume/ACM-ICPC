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
  vi a(n , 0);
  rep(i,0,n) cin >> a[i];
  int sum = 0;
  rep(i,0,n) sum += a[i];
  int half = (sum + 1) / 2;
  bitset<2000*2000+1> B;
  B[0] = 1;
  rep(i,0,n) B |= B << a[i];
  rep(i,half,sum+1) if(B.test(i)) {
    cout << i << endl;
    return 0;
  }
  return 0;
}
