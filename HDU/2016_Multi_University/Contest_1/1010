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
const int N = 101010 , Q = 718678369 , P = 1403641;
int n , pp[N] = {1};
char s[20] , t[20];
struct Graph{
    vi g[N];
    map<string,int> Mp;
    vector<string> Name;
    int id(string s){
        if(Mp.find(s) != Mp.end()) return Mp[s];
        else {
            Mp[s] = sz(Name);
            Name.pb(s);
            return Mp[s];
        }
    }
    void in(){
        rep(i,0,n) g[i].clear();
        Mp.clear();Name.clear();
        rep(i,1,n){
            scanf("%s%s",s,t);
            int u = id(s) , v = id(t);
            g[u].pb(v);g[v].pb(u);
        }
    }
    int sz[N] , q[N] , par[N] , mx[N];
    vi getroot(){
        vi rt;int _ = 0;par[q[_++] = 0] = -1;
        rep(i,0,_){
            int c = q[i];sz[c] = 1;mx[c] = 0;
            for(auto t : g[c]) if(t != par[c]) par[q[_++] = t] = c;
        }
        for(int i=_-1;i>=0;--i){
            int c = q[i] , p = par[c];
            if(i) sz[p] += sz[c] , mx[p] = max(mx[p] , sz[c]);
            mx[c] = max(mx[c] , n - sz[c]);
            if(mx[c] * 2 <= n) rt.pb(c);
        }
        return rt;
    }
    int hs[N];
    int hash(int c){
        int _ = 0;par[q[_++] = c] = -1;
        rep(i,0,_){
            int c = q[i];sz[c] = 1;
            for(auto t : g[c]) if(t != par[c]) par[q[_++] = t] = c;
        }
        for(int i=_-1;i>=0;--i){
            int c = q[i];
            if(i) sz[par[c]] += sz[c];
            if(sz(g[c]) == 1) hs[c] = 1;
            else{
                int&h = hs[c] = 0;for(auto t : g[c]) if(t != par[c]) (h += (ll)pp[sz[t]]*hs[t]%Q) %= Q;
            }
        }
        return hs[c];
    }
    void bfs(int c){
        int _ = 0;par[q[_++] = c] = -1;
        rep(i,0,_){
            int c = q[i];
            sort(all(g[c]) ,[&](const int a,const int b){return hs[a]<hs[b];});
            for(auto t : g[c]) if(t != par[c]) par[q[_++] = t] = c;
        }
    }
}G[2];


void solve(Graph&a,Graph&b){
    vi A = a.getroot() , B = b.getroot();
    for(auto u : A) for(auto v : B) if(a.hash(u) == b.hash(v)) {
        a.bfs(u);b.bfs(v);
        rep(i,0,n) printf("%s %s\n",a.Name[a.q[i]].c_str() , b.Name[b.q[i]].c_str());
        return ;
    }
}


int main(){
    rep(i,1,N) pp[i] = (ll)pp[i-1] * P % Q;
    while(~scanf("%d",&n)){
        rep(i,0,2) G[i].in();
        if(n == 1){
            puts("a a");
        } else{
            solve(G[0] , G[1]);
        }
    }
    return 0;
}
