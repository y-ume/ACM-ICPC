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
const int N = 10;
int n , m;
int g[N][N] , a[N];

template<class T>
struct Dinic{ // [0,n) init!!
    const static int N = 30 , M = N * N;
    int s , t , n , h[N] , cur[N] , level[N] , q[N] , e , ne[M] , to[M];
    T cap[M] , flow;
    void liu(int u,int v,T w){ to[e] = v;ne[e] = h[u];cap[e] = w;h[u] = e++;}
    void link(int u,int v,T w){ liu(u , v , w);liu(v , u , 0);}
    void ini(int _n = N) { fill(h , h + _n , -1);e = 0;}
    bool bfs(){
        int L = 0 , R = 0;
        fill(level , level + n , -1);
        level[q[R++] = s] = 0;
        while(L < R && level[t] == -1){
            int c = q[L++];
            for(int k=h[c];~k;k=ne[k])
                if(cap[k] > 0 && level[to[k]] == -1)
                    level[q[R++] = to[k]] = level[c] + 1;
        }
        return ~level[t];
    }
    T dfs(int c,T mx){
        if(c == t) return mx;
        T ret = 0;
        for(int &k = cur[c];~k;k = ne[k]){
            if(level[to[k]] == level[c] + 1 && cap[k] > 0){
                T flow = dfs(to[k] , min(mx , cap[k]));
                ret += flow;cap[k] -= flow , cap[k^1] += flow;mx -= flow;
                if(!mx) return ret;
            }
        }
        level[c] = -1;
        return ret;
    }
    T run(int _s,int _t,int _n){
        s = _s , t = _t , n = _n;
        flow = 0;
        while(bfs()){
            copy(h , h + n , cur);
            flow += dfs(s,~0U>>1);
        }
        return flow;
    }
};
Dinic<int> it;
int solve(){
    it.ini(2 * n + 2);
    int S = 2 * n , T = S + 1;
    rep(i,0,n) it.link(S , i , 1) , it.link(i + n , T , 1);
    rep(i,0,n) rep(j,0,n){
        if(g[i][a[j]] == 0 && g[i][a[(j+1)%n]] == 0) it.link(i , j + n , 1);
    }
    return it.run(S,T,T+1);
}

int main(){
    while(~scanf("%d%d",&n,&m)){
        memset(g,0,sizeof(g));
        if(n == 0){
            puts("0");
        } else {
            rep(i,0,m){
                int u , v;
                scanf("%d%d",&u,&v);--u;--v;
                g[u][v] = true;
            }
            a[0] = 0;
            rep(i,1,n) a[i] = i;
            int ans = 0;
            do{
                ans = max(ans , solve());
            }while(next_permutation(a + 1, a + n));
            printf("%d\n",n - ans);
        }
    }
    return 0;
}
