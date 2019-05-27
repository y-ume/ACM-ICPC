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

int n , K , cnt[26];

int main(){
  cin >> n >> K;
  rep(i,0,n) {
    string s;
    cin >> s;
    cnt[s[0] - 'A']++;
  }
  int ans = 0;
  while(true) {
    sort(cnt , cnt + 26);
    reverse(cnt , cnt + 26);
    int c = 0;
    rep(i,0,26) if(cnt[i]) {
      cnt[i]--;c++;
      if(c == K) break;
    }
    if(c == K) ans++;
    else break;
  }
  cout << ans << endl;
  return 0;
}
