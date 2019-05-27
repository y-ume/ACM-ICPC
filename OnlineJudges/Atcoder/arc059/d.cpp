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

string s;

int main(){
  cin >> s;
  rep(i,1,sz(s)) if(s[i] == s[i - 1]) {
    cout << i << " " << i + 1 << endl;
    return 0;
  }
  rep(i,2,sz(s)) if(s[i] == s[i - 2]) {
    cout << i - 1 << " " << i + 1 << endl;
    return 0;
  }
  cout << -1 << " " << -1 << endl;
  return 0;
}
