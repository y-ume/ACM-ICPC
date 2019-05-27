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

vi A[20] , B[20];
int ans[N] , _ , n;

// 0 : /2 (0) , 1 : /2 (1) , 2 : *2 , 3 : *2+1 , 4 : -1
void pre() {
  rep(i,1,20) if((1 << i) <= 1e5){
    A[i] = B[i - 1];
    A[i].pb(1);
    A[i].pb(2);
    per(j,0,sz(B[i - 1])) {
      int t = B[i - 1][j];
      if(t == 0) A[i].pb(3);
      if(t == 1) A[i].pb(2);
      if(t == 2) A[i].pb(1);
      if(t == 3) A[i].pb(0);
      if(t == 4) A[i].pb(4);
    }
    B[i] = A[i - 1];
    B[i].pb(4);
    rep(j,0,sz(B[i - 1])) B[i].pb(B[i - 1][j]);
    B[i].pb(0);
  }
  //rep(i,0,20) de(sz(A[i]));
  //rep(i,0,20) de(sz(B[i]));
}

void add(int x) {ans[_++]=x;}
void go(int root) {
  int S = root , dep = 0;
  while(S * 2 + 1 <= n) S = S * 2 + 1 , dep++;
  add(S);
  rep(i,0,sz(A[dep])) {
    if(A[dep][i] <= 1) S /= 2;
    else if(A[dep][i] == 2) S = S * 2;
    else if(A[dep][i] == 3) S = S * 2 + 1;
    else S = S - 1;
    add(S);
  }
}

int main() {
  pre();
  int T;
  scanf("%d",&T);
  rep(i,0,T) {
    scanf("%d",&n);
    _ = 0;
    vi path;
    int t = n;path.pb(t);
    if(t != 1) {
      do {
        t /= 2;
        path.pb(t);
      } while(t != 1);
    }
    reverse(all(path));
    vi left , right;
    rep(i,0,sz(path) - 1) {
      if(path[i + 1] == path[i] * 2) {
        if(path[i] * 2 + 1 <= n) right.pb(path[i] * 2 + 1);
      } else {
        left.pb(path[i] * 2);
      }
    }
    rep(i,0,sz(path)) add(path[i]);
    per(i,0,sz(left)) {
      go(left[i]);
    }
    rep(i,0,sz(right)) {
      go(right[i]);
    }
    rep(i,0,_) printf("%d%c",ans[i]," \n"[i+1==_]);
  }
  return 0;
}
