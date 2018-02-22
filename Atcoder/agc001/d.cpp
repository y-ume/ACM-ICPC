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
int n , m , a[N];

int main(){
  cin >> n >> m;
  vi odd , even;
  rep(i,0,m) {
    cin >> a[i];
    (a[i] & 1 ? odd : even).pb(a[i]);
  }
  if(sz(odd) > 2) cout << "Impossible" << endl;
  else {
    vi A , B;
    if(sz(odd)>=1) A.pb(odd[0]);
    for(auto e : even) A.pb(e);
    if(sz(odd)==2) A.pb(odd[1]);
    B = A;
    if(sz(B) == 1) B[0]--,B.pb(1);
    else {
      B[0]--;
      B[sz(B)-1]++;
    }
    vi C;
    for(auto e : B) if(e) C.pb(e);
    B = C;
    rep(i,0,sz(A)) cout << A[i] << " \n"[i+1==sz(A)];
    cout << sz(B) << endl;
    rep(i,0,sz(B)) cout << B[i] << " \n"[i+1==sz(B)];
  }
  return 0;
}
