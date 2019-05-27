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

const int N = 210;
int link[N] , vis[N] , n;
vi g[N];
int dfs(int c) {
    for(auto t : g[c]) if(!vis[t]) {
        vis[t] = true;
        if(link[t]==-1||dfs(link[t]))
            return link[t]=c,1;
    }
    return 0;
}
int bipart(int n,int m){
    fill_n(link,m,-1);
    int res=0;
    rep(i,0,n){
        memset(vis,0,m*sizeof(int));
        res += dfs(i);
    }
    return res;
}
bool isoddprim(int x){
    if(x <= 2) return false;
    for(int i=2;i*i<=x;++i) if(x%i==0)
        return false;
    return true;
}

int main(){
    cin >> n;
    map<int,int> vis;
    rep(i,0,n){
        int x;
        cin>>x;
        vis[x]^=1;
        vis[x+1]^=1;
    }
    vi odd , even;
    for(auto e : vis) if(e.se == 1) {
        (e.fi & 1 ? odd : even).pb(e.fi);
    }
    int n = sz(odd) , m = sz(even);
    rep(i,0,n) rep(j,0,m) if(isoddprim(abs(odd[i] - even[j])))
        g[i].pb(j);
    int maxmatch = bipart(n , m);
    cout << maxmatch + ((n - maxmatch) / 2 + (m - maxmatch) / 2) * 2 + ((n - maxmatch) & 1) * 3 << endl;;
    return 0;
}
