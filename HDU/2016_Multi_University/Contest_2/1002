#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <bitset>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 1<<8 , NN = N*N+10 ,mask = N-1 , P = 1e9 + 7;
typedef unsigned int ui;
int T,n,w[NN],who[N], val[N][N][3] , K , ans;
vi g[NN];
char s[20];
ui f[NN][N];
void pp(int &x,int d){x += d;if(x >= P)x -= P;}
void dfs(int c,int fa){
    int a = w[c]>>8&mask , b = w[c]&mask;
    ui F = 0;
    rep(left,0,N) if(who[left]) F = max(F , f[who[left]][b] + (val[left][a][K]<<8));
    pp(ans , (ll)(F+w[c])*c%P);
    int tp = who[a];who[a] = c;
    rep(right,0,N) f[c][right] = F + val[right][b][K];
    for(int t : g[c]) if(t != fa) dfs(t , c);
    who[a] = tp;
}
int main(){
    rep(i,0,N) rep(j,0,N) val[i][j][0] = i&j , val[i][j][1] = i|j , val[i][j][2] = i^j;
    scanf("%d",&T);
    rep(i,0,T){
        scanf("%d",&n);
        scanf("%s",s);
        if(s[0] == 'A') K = 0;
        else if(s[0] == 'O') K = 1;
        else K = 2;
        rep(i,1,n+1) scanf("%d",w + i) , g[i].clear();
        int x;rep(i,2,n+1) scanf("%d",&x) , g[x].pb(i);
        ans = 0;
        dfs(1,0);
        printf("%d\n",ans);
    }
    return 0;
}
