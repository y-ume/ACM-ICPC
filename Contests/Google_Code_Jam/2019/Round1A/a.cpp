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

#define imp cout << "IMPOSSIBLE" << endl;return;
#define wa cout << "wa " << R << " " << C << endl;return;

void check(vector<pii> ans,int R,int C) {
  int a[20][20];
  memset(a,0,sizeof(a));
  if(sz(ans) != R * C) {
    wa;
  }
  for(auto e: ans) {
    if(a[e.fi][e.se]) {
      wa;
    }
    a[e.fi][e.se] = 1;
  }

  rep(i,0,sz(ans)-1) {
    int a=ans[i].fi,b=ans[i].se;
    int c=ans[i+1].fi,d=ans[i+1].se;
    if(a==c||b==d||a+b==c+d||a-b==c-d) {
      de(a);de(b);de(c);de(d);
      wa;
    }
  }
  puts("yes");
}

void solve(int R,int C) {
  int swp = false;
  if(R > C) swap(R , C) , swp = true;
  if(C <= 3) {
    imp;
  } else if(R == 2 && C <= 4) {
    imp;
  } else {
    cout << "POSSIBLE" << endl;
    vector<pii> ans;
    if(R == 4 && C == 6) {
      rep(i,0,C-2) {
        int y=i;
        rep(j,0,R) {
          ans.pb(mp(j,y));
          if(j & 1) y-=2;
          else y+=2;
        }
      }
      vi s;
      s.pb(C-2);s.pb(C-1);
      for(auto e : s) {
        int y=e;
        rep(j,0,R) {
          ans.pb(mp(j,y));
          if(j & 1) y+=C-2;
          else y-=C-2;
        }
      }
    } else if(R == 4) {
      int y=0;
      rep(j,0,R) {
        ans.pb(mp(j,y));
        if(j & 1) y-=2;
        else y+=2;
      }
      vi s;
      s.pb(C-1);s.pb(C-2);
      int xx=0,yy=C-1;
      int x=ans.back().fi;
      y=ans.back().se;
      if(xx==x||yy==y||xx+y==x+y||xx-yy==x-y)
        swap(s[0],s[1]);
      for(auto e : s) {
        int y=e;
        rep(j,0,R) {
          ans.pb(mp(j,y));
          if(j & 1) y+=C-2;
          else y-=C-2;
        }
      }
      rep(i,1,C-2) {
        int y=i;
        rep(j,0,R) {
          ans.pb(mp(j,y));
          if(j & 1) y-=2;
          else y+=2;
        }
      }
    } else {
      rep(i,2,C) {
        int y=i;
        rep(j,0,R) {
          ans.pb(mp(j,y));
          if(j & 1) y+=2;
          else y-=2;
        }
      }
      vi s;
      s.pb(1);s.pb(0);
      int xx=0,yy=1;
      int x=ans.back().fi,y=ans.back().se;
      if(xx==x||yy==y||xx+yy==x+y||xx-yy==x-y)
        swap(s[0],s[1]);
      if(s[0]==1&&R==C&&(R%2==0)) swap(s[0],s[1]);
      for(auto e : s) {
        int y=e;
        rep(j,0,R) {
          ans.pb(mp(j,y));
          if(j & 1) y-=C-2;
          else y+=C-2;
        }
      }
    }
    //check(ans,R,C);
    if(swp) rep(i,0,sz(ans)) swap(ans[i].fi,ans[i].se);
    for(auto e : ans) cout << e.fi + 1 << " " << e.se + 1 << endl;
  }
}
/*
   int X = 4 , Y = 4;
   int vis[100][100];
   vector<pii> ans;
   void dfs(int x,int y) {
   vis[x][y] = true;
   ans.pb(mp(x,y));
   if(sz(ans) == X * Y) {
   throw 1;
   }
   rep(i,0,X) rep(j,0,Y) if(!vis[i][j]) {
   if(i == x || j == y || i - j == x - y || i + j == x + y)
   continue;
   dfs(i , j);
   }
   vis[x][y] = false;
   ans.pop_back();
   }
   */

int main() {
  /*
     rep(i,0,X) rep(j,0,Y) {
     memset(vis,0,sizeof(vis));
     try {
     dfs(i,j);
     } catch(...){
     for(auto e: ans) {
     cout << e.fi << " " << e.se << endl;
     }
     return 0;
     }
     }
     */
  //rep(i,2,21) rep(j,2,21) solve(i,j);
  int T;
  cin >> T;
  rep(i,0,T){
    int R , C;
    cin >> R >> C;
    cout << "Case #" << i+1 << ": ";
    solve(R , C);
  }
  return 0;
}
