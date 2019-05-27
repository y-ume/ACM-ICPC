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
using namespace std;
typedef long long ll;
typedef long double db;
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
const int N = 17 , P = 1e9 + 7;
int f[N][N] , g[N][N];
int dp[2][1<<N];

void pp(int &x,int d){x+=d;if(x>=P)x-=P;}
void F(int m){
    int c = 0;fill(dp[c] , dp[c] + (1<<m) , 0);
    dp[c][(1<<m)-1] = 1;
    rep(i,1,N){
        rep(j,0,m){
            c ^= 1;fill(dp[c] , dp[c] + (1<<m) , 0);
            rep(mask,0,1<<m){
                pp(dp[c][mask^(1<<j)] , dp[c^1][mask]);
                if(j && (mask>>(j-1)&3)==2) pp(dp[c][mask|(3<<(j-1))] , dp[c^1][mask]);
            }
        }
        f[i][m] = dp[c][(1<<m)-1];
    }
}
#define lb(x) (x&-(x))
int who[1<<N] , cnt[1<<N] , a[N] , b[N];
void G(int m){
    rep(mask,0,1<<(m-1)){
        rep(n,1,N) {
            a[n] = 1;int s = mask | (1<<(m-1)) , past = -1;
            for(;s;s^=lb(s)) a[n] = (ll)a[n] * f[n][who[lb(s)]-past] % P,past=who[lb(s)];
        }
        rep(n,1,N) {
            b[n] = a[n];rep(i,1,n) pp(b[n] , P - (ll)a[i]*b[n-i]%P);
            if(cnt[mask]&1) pp(g[n][m] , P - b[n]);
            else pp(g[n][m] , b[n]);
        }
    }
}

int main(){
    rep(i,0,N) who[1<<i] = i;
    rep(i,1,1<<N) cnt[i] = cnt[i^lb(i)] + 1;
    rep(m,1,N) F(m);
    rep(m,1,N) G(m);
    int n , m;
    while(~scanf("%d%d",&n,&m)) printf("%d\n",g[n][m]);
    return 0;
}
