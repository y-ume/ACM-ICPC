#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define de(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
typedef vector<int> vi;
const int mod = 1e9 + 7;
int T;
const int N = 501 ,K = 251;
int f[2][N][K];
int g[N][K][2];

void pp(int &a,int b){
    a += b;
    if(a >= mod)
        a -= mod;
}

void Dp1(){
    g[0][0][0] = 1;
    rep(i,1,N) rep(j,0,K){
        g[i][j][0] = g[i-1][j][0];
        pp(g[i][j][0] , g[i-1][j][1]);
        g[i][j][1] = g[i-1][j][1];
        if(j) pp(g[i][j][1] , g[i-1][j-1][0]);
    }
    rep(i,1,N) rep(j,0,K){
        f[0][i][j] = g[i][j][0] + g[i][j][1];
        pp(f[0][i][j] , 0);
        if(j) pp(f[0][i][j] , f[0][i][j-1]);
    }
}
typedef vector<pair<int,int> > vii;
vector<vii> States;
map<vii,int> Mp;

int id(vii x){
    if(Mp.find(x) == Mp.end()){
        Mp[x] = sz(States);
        States.pb(x);
    }
    return Mp[x];
}

int cnt1[] = {0 , 1 , 1 , 2 , 1 , 2 , 2 , 3};
int cover[8] , gr[3] = {1 , 2 , 3};
int go[100][4] , cost[100][4];
void bfs(vii a){
    int u = id(a);
    rep(mask,0,4){
        vii b;
        int Mincost = 2;
        int dis[8];
        fill(dis , dis + 8 , 10);
        rep(i,0,sz(a)){
            int x = a[i].first , del = a[i].second;
            rep(j,0,8) if(cnt1[j] <= 1 && ((j&x) == 0)){
                int y = j | x;
                for(int z=y;;z=(z-1)&y){
                    if(mask == cover[z]){
                        Mincost = min(Mincost , del + cnt1[j]);
                        dis[z] = min(dis[z] , del + cnt1[j]);
                    }
                    if(z == 0) break;
                }
            }
        }
        rep(i,0,8) if(dis[i] <= cnt1[i] + Mincost)
            b.pb(mp(i , dis[i] - Mincost));
        sort(all(b));
        b.erase(unique(all(b)) , b.end());
        int v = id(b);
        go[u][mask] = v , cost[u][mask] = Mincost;
    }
}

void Pre(){
    rep(i,0,8) rep(j,0,3) if(i>>j&1) cover[i] ^= gr[j];
    id(vii(1,mp(0,0)));
    rep(i,0,sz(States)){
        bfs(States[i]);
    }
    /*
    de(sz(States));
    rep(i,0,sz(States)){
        for(auto e: States[i])
            cout << e.first << " " << e.second << "   ";
        cout << endl;
    }
    */
}
int ff[N + 10][K + 10][12];

void Dp2(){
    Pre();
    ff[0][0][0] = 1;
    rep(i,0,N) rep(j,0,K) rep(k,0,sz(States)) if(ff[i][j][k]) rep(mask,0,4){
        pp(ff[i+1][j + cost[k][mask]][go[k][mask]] , ff[i][j][k]);
    }
    rep(i,1,N) rep(j,0,K){
        rep(k,0,sz(States)) pp(f[1][i][j] , ff[i][j][k]);
        if(j) pp(f[1][i][j] , f[1][i][j-1]);
    }
}

int main(){
    Dp1();
    Dp2();
    scanf("%d",&T);
    rep(i,0,T){
        int n , m , k;
        scanf("%d%d%d",&n,&m,&k);
        printf("%d\n",f[m-1][n][k]);
    }
    return 0;
}
