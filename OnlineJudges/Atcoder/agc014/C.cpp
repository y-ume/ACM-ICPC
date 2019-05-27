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

const int N = 808;
char s[N][N];
int n , m , K , _ , dis[N][N];
pii q[N*N];

int main(){
    scanf("%d%d%d",&n,&m,&K);
    rep(i,1,n+1) scanf("%s",s[i] + 1);
    rep(i,1,n+1) rep(j,1,m+1) dis[i][j] = N * N;
    rep(i,1,n+1) rep(j,1,m+1) if(s[i][j] == 'S')
        q[_++]=mp(i,j),dis[i][j]=0;
    int ans=N*N;
    rep(i,0,_){
        int x=q[i].fi,y=q[i].se;
        ans=min(ans,1+(min(min(x-1,n-x),min(y-1,m-y))+K-1)/K);
        if(dis[x][y]==K) continue;
        rep(d,0,4) {
            int nx=x+(d==2)-(d==0);
            int ny=y+(d==3)-(d==1);
            if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&s[nx][ny]=='.')
                if(dis[nx][ny]>dis[x][y]+1)
                    dis[nx][ny]=dis[x][y]+1,q[_++]=mp(nx,ny);
        }
    }
    printf("%d\n",ans);
    return 0;
}
