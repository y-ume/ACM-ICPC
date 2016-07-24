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
#define pb emplace_back
#define fi first
#define se second
const int N = 2020;
int T , n , m , K , id[N] , permu[4];
struct P{
    int x,y;
}p[N];
int go[N][2] , rk[N] , sum[N][N];
void link(int l,int r){
    go[l][1] = r , go[r][0] = l;
}
void del(int x){
    rep(i,0,2) go[go[x][i^1]][i] = go[x][i];
}
int Sum(int a,int b,int c,int d){
    return sum[c][d] + sum[a-1][b-1] - sum[a-1][d] - sum[c][b-1];
}

void main2(){
    scanf("%d%d%d",&n,&m,&K);
    rep(i,0,4) scanf("%d",permu + i);
    rep(i,1,n+1) rep(j,1,m+1) sum[i][j] = 0;
    rep(i,1,K+1){
        int x,y;scanf("%d%d",&x,&y);
        p[i]=P{x,y};id[i] = i;
        sum[x][y] = 1;
    }
    rep(i,1,n+1) rep(j,1,m+1) sum[i][j] += sum[i-1][j];
    rep(i,1,n+1) rep(j,1,m+1) sum[i][j] += sum[i][j-1];
    sort(p+1,p+K+1,[](P a,P b){if(a.x!=b.x)return a.x<b.x;return a.y<b.y;});
    sort(id+1,id+K+1,[](int a,int b){if(p[a].y!=p[b].y)return p[a].y<p[b].y;return p[a].x<p[b].x;});
    rep(i,1,K+1) rk[id[i]] = i;
    int up = 0 , down = 0;
    rep(i,0,4) up += permu[i] > max(permu[0],permu[3]) , down += permu[i] < min(permu[0],permu[3]);
    int mid = 2-up-down;
    int ans = 0;
    rep(i,1,K+1){
        int last = 0;
        rep(j,1,K+1) if(p[id[j]].x >= p[i].x) link(last , id[j]) , last = id[j];
        link(last,0);
        for(int j=K;p[j].x>p[i].x;del(j--)){
            if((permu[0] - permu[3])*(p[i].y - p[j].y) > 0){
                vector<P> v;v.pb(p[i]);v.pb(p[j]);
                int l = i , r = j;if(rk[i] > rk[j]) swap(l , r);
                for(int i=0,c=go[r][1];c&&i<up;++i,c=go[c][1]) v.pb(p[c]);
                for(int i=0,c=go[l][0];c&&i<down;++i,c=go[c][0]) v.pb(p[c]);
                for(int i=0,c=go[l][1];c&&i<mid;++i,c=go[c][1]) v.pb(p[c]);
                if(sz(v) == 4){
                    int ly = p[i].y , ry = p[i].y;
                    rep(i,0,4) ly = min(ly,v[i].y) , ry = max(ry,v[i].y);
                    if(Sum(p[i].x,ly,p[j].x,ry) == 4){
                        sort(all(v),[](P a,P b){if(a.x!=b.x)return a.x<b.x;return a.y<b.y;});
                        bool ok = true;
                        for(int i=0;i<3&&ok;++i) ok &= v[i].x < v[i+1].x;
                        for(int i=0;i<4&&ok;++i)
                            for(int j=i+1;j<4&&ok;++j)
                                ok &= (permu[i] - permu[j]) * (v[i].y - v[j].y) > 0;
                        ans += ok;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}

int main(){
    scanf("%d",&T);
    rep(i,0,T) main2();
    return 0;
}
