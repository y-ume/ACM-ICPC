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
int n , dis[2][N];
vi g[N];

void bfs(int s,int *dis){
    rep(i,1,n+1) dis[i] = n + 1;
    dis[s] = 0;
    vi q;q.pb(s);
    rep(i,0,sz(q)) {
        int c = q[i];
        for(auto t : g[c]) if(dis[t] == n + 1)
            dis[t] = dis[c] + 1 , q.pb(t);
    }
}

int main(){
    scanf("%d",&n);
    rep(i,1,n){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].pb(v);
        g[v].pb(u);
    }
    bfs(1 , dis[0]);
    bfs(n , dis[1]);
    int cnt[2] = {0 , 0};
    rep(i,1,n+1) cnt[dis[1][i] < dis[0][i]]++;
    puts(cnt[0] > cnt[1] ? "Fennec" : "Snuke");
    return 0;
}
