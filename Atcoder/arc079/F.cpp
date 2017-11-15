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

const int N = 2e5 + 10;
int p[N] , n , du[N] , sg[N];
vi son[N];

int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",p + i) , du[p[i]]++;
    vi q;
    rep(i,1,n+1) if(!du[i]) q.pb(i);
    rep(ii,0,sz(q)){
        int c=q[ii];
        vi&v=son[c];
        sort(all(v));
        v.erase(unique(all(v)),v.end());
        int&t=sg[c]=0;
        while(t<sz(v)&&v[t]==t) ++t;
        son[p[c]].pb(t);
        if(!--du[p[c]]) q.pb(p[c]);
    }
    rep(i,1,n+1) if(du[i]) {
        vector<pii> cir;
        for(int s=i;s!=i||!sz(cir);s=p[s]){
            vi&v=son[s];
            sort(all(v));
            v.erase(unique(all(v)),v.end());
            int t=0;
            while(t<sz(v)&&v[t]==t) ++t;
            v.insert(v.begin()+t,t);
            int u=t;
            while(u<sz(v)&&v[u]==u) ++u;
            cir.pb(mp(t,u));
        }
        auto check = [&](int x){
            int s=x;
            rep(i,1,sz(cir)) {
                if(x==cir[i].fi) x=cir[i].se;
                else x=cir[i].fi;
            }
            if(x==cir[0].fi) x=cir[0].se;
            else x=cir[0].fi;
            return s==x;
        };
        if(check(cir[0].fi) || check(cir[0].se)) puts("POSSIBLE");
        else puts("IMPOSSIBLE");
        break;
    }
    return 0;
}
