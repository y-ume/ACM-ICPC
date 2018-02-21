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

int n , K , ban[10];

int main(){
  cin >> n >> K;
  rep(i,0,K) {
    int x;
    cin >> x;
    ban[x] = true;
  }
  for(int i=n;;++i) {
    int t=i,ok=1;
    while(t) {
      if(ban[t%10])
        ok=0;
      t/=10;
    }
    if(ok) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
