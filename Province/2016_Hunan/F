#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
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
const int N = 101010 * 2;
int n , m , u[N] , v[N] , c[N] , t[N] , vis[N];
ll dis[N];
vector<pii> V;
vector<pair<int,ll> > g[N];

int main(){
    while(~scanf("%d%d",&n,&m)){
        V.clear();
        rep(i,0,m){
            scanf("%d%d%d%d",u + i ,v + i,c + i,t + i);
            --u[i];--v[i];
            V.pb(mp(u[i] , c[i]));
            V.pb(mp(v[i] , c[i]));
        }
        sort(all(V));V.erase(unique(all(V)) , V.end());
        rep(i,0,sz(V)) g[i].clear();
        rep(i,0,m){
            int a = lower_bound(all(V) , mp(u[i] , c[i])) - V.begin();
            int b = lower_bound(all(V) , mp(v[i] , c[i])) - V.begin();
            g[a].pb(mp(b , t[i]));
            g[b].pb(mp(a , t[i]));
        }
        rep(i,1,sz(V)) if(V[i].fi == V[i-1].fi){
            g[i-1].pb(mp(i , V[i].se - V[i-1].se));
            g[i].pb(mp(i-1 , V[i].se - V[i-1].se));
        }
        priority_queue<pair<ll,int> > PQ;
        rep(i,0,sz(V)) {
            vis[i] = false;
            dis[i] = 1ll<<62;
            if(V[i].fi == 0) PQ.push(mp(0 , i)) , dis[i] = 0;
        }
        while(sz(PQ)){
            int c = PQ.top().se;PQ.pop();
            if(!vis[c]){
                vis[c] = true;
                rep(i,0,sz(g[c])){
                    int t = g[c][i].fi;
                    ll ndis = dis[c] + g[c][i].se;
                    if(ndis < dis[t]) dis[t] = ndis , PQ.push(mp(-ndis , t));
                }
            }
        }
        ll Min = 1ll<<62;
        rep(i,0,sz(V)) if(V[i].fi == n-1) Min = min(Min , dis[i]);
        printf("%lld\n",Min);
    }
    return 0;
}
