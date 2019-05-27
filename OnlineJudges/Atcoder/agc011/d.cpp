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

int n , K;
string s;
deque<int> v;

int main(){
  cin >> n >> K >> s;
  for(auto ch : s) v.pb(ch=='A'?0:1);
  bool rev=false;
  int times=0;
  if(K<=2*n) times=K;
  else times=2*n+(K&1);
  rep(i,0,times) {
    int c=rev^v.front();
    v.pop_front();
    if(c==0) v.push_front(rev^1);
    else rev^=1,v.push_back(rev);
  }
  while(sz(v)) {
    putchar("AB"[rev^v.front()]);
    v.pop_front();
  }
  return 0;
}
