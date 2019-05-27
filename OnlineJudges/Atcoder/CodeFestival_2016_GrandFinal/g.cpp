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

const int N = 600;
ll n;
ll comb(int a,int b) {
  ll r = 1;
  rep(i,0,b) r=r*(a-i)/(i+1);
  return r;
}
ll cof[N + 1] , c[N + 1];

int main(){
  cin >> n;
  rep(i,1,N+1) cof[i] = comb(i + 7 - 1 , 7);
  per(i,1,N+1) {
    if(cof[i] <= n) {
      c[i] = n / cof[i];
      n -= c[i] * cof[i];
    }
  }
  int end = N;
  while(!c[end]) --end;
  string ans = "";
  rep(i,1,end+1) {
    ans += "FESTIVA";
    ans += string(c[i],'L');
  }
  cout << ans << endl;
  return 0;
}
