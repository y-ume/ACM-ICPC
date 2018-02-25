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

const int N = 1e5 + 10 , NODE = 4e5 + 10 , M = 26;
int sz[NODE] , ed[NODE] , ne[NODE][M] , _ , rt;
int n , Q , cnt[N][M][M] , big[N];
string s[N] , order;

void ins(int c,string&s,int p) {
  sz[c] ++;
  if(p == sz(s)) {
    ed[c] ++;
    return;
  }
  int t=s[p]-'a';
  if(ne[c][t]==0)
    ne[c][t]=++_;
  ins(ne[c][t],s,p+1);
}

void ask(int c,string&s,int p,int id) {
  big[id] += ed[c];
  if(p == sz(s)) {
    return;
  }
  int t=s[p]-'a';
  rep(i,0,M) if(i!=t) cnt[id][t][i]+=sz[ne[c][i]];
  ask(ne[c][t],s,p+1,id);
}

int main() {
  cin >> n;
  rt = ++_;
  rep(i,0,n) {
    cin >> s[i];
    ins(rt , s[i] , 0);
  }
  rep(i,0,n) ask(rt , s[i] , 0 , i);
  cin >> Q;
  rep(i,0,Q) {
    int K;
    cin >> K >> order;
    --K;
    int ans = big[K];
    rep(i,0,M) rep(j,0,i) ans += cnt[K][order[i]-'a'][order[j]-'a'];
    cout << ans << endl;
  }
  return 0;
}

