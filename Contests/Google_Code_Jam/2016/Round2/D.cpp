#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<b;++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 50 , M = 1e7;
int n , vis[N];
char s[N][N];
vi g[N];
int dp[M] , a[N] , b[N] , cnt[N] , _ , d[N];

void gt(int c,int id,int left,int right,int &ans){
    if(c == _){
        if(left == right) ans = min(ans , dp[id] + left * right);
        return ;
    }
    rep(i,0,d[c] + 1)
        gt(c + 1 , id * (cnt[c] + 1) + i , left + (d[c] - i) * a[c] , right + (d[c] - i) * b[c] , ans);
}

void dfs(int c,int id){
    if(c == _){
        if(id == 0) dp[id] = 0;
        else{
            dp[id] = ~0U>>1;
            gt(0 , 0 , 0 , 0, dp[id]);
        }
        return ;
    }
    rep(i,0,cnt[c] + 1)
        d[c] = i , dfs(c + 1 , id * (cnt[c] + 1) + i);
}

int wk(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%s",s[i]);
    rep(i,0,n+n) g[i].clear();
    fill(vis , vis + n + n , false);
    int all = 0;
    rep(i,0,n) rep(j,0,n) if(s[i][j] == '1') all++ , g[i].pb(j+n) , g[j+n].pb(i);
    map<pii,int> Mp;
    rep(i,0,n+n) if(!vis[i]){
        vis[i] = true;vi v;v.pb(i);
        rep(j,0,sz(v)){
            int c = v[j];
            for(int t : g[c]) if(!vis[t]) vis[t] = true , v.pb(t);
        }
        int cnt[2] = {0};
        for(int t : v) cnt[t>=n]++;
        Mp[mp(cnt[0] , cnt[1])]++;
    }
    _ = 0;int states = 1;for(auto e : Mp) a[_] = e.fi.fi , b[_] = e.fi.se , cnt[_] = e.se , states *= (cnt[_] + 1) , ++_;
    cerr << states << endl;
    dfs(0 , 0);
    return dp[states - 1] - all;
}

int T;
int main(){
    scanf("%d",&T);
    rep(i,1,T+1) cerr << i << endl , printf("Case #%d: %d\n",i , wk());
    return 0;
}
