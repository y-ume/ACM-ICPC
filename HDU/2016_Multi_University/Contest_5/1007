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

int b[20];
map<vi,ll> Mp[20][6];

ll dfs(int pos,bool up,int has,vi&v,int K){
    if(pos < 0) return 1;
    if(!up && Mp[pos][K].find(v) != Mp[pos][K].end()) return Mp[pos][K][v];
    vi nv;
    if(sz(v) == K) rep(i,1,sz(v)) nv.pb(v[i]);
    else nv = v;
    int mask = 0;
    rep(i,0,sz(nv)) mask |= 1<<nv[i];
    int pp = up ? b[pos] : 9;
    ll ret = 0;
    for(int i=0;i<=pp;++i) if(!(mask>>i&1)){
        if(i || has) nv.pb(i);
        ret += dfs(pos-1,up&&(i==pp),has||(i),nv,K);
        if(i || has) nv.pop_back();
    }
    if(!up) Mp[pos][K][v] = ret;
    return ret;
}

ll solve(ll x,int K){
    int _ = 0;
    for(;x;x/=10) b[_++] = x%10;
    vi v;
    return dfs(_-1,1,0,v,K);
}


int main(){
    ll l , r;int K;
    while(~scanf("%lld%lld%d",&l,&r,&K)) printf("%lld\n",solve(r,K) - solve(l-1,K));
    return 0;
}
