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
const int N = 1010 , P = 1e9 + 7;
int T , n , x[N] , y[N] , sz[N] , p2[N] = {1};
map<pii,pii> Mp;
void pp(int &x,int d){
    x += d;if(x >= P) x -= P;
}
int cnt(int s){
    return (p2[s] - s - 1 + P)%P;
}
int main(){
    rep(i,1,N) p2[i] = p2[i-1] * 2 % P;
    scanf("%d",&T);
    rep(i,0,T){
        int ans = 0;
        scanf("%d",&n);
        rep(i,0,n) scanf("%d%d",x + i,y + i);
        map<pii,int> S;
        rep(i,0,n) S[mp(x[i],y[i])]++;
        n = 0;for(auto e : S) x[n] = e.fi.fi , y[n] = e.fi.se , sz[n++] = e.se;
        if(n == 1) printf("%d\n",cnt(sz[0]));
        else{
            rep(i,0,n){
                Mp.clear();
                rep(j,0,n) if(j != i){
                    int p = x[j] - x[i];
                    int q = y[j] - y[i];
                    if(p && q){
                        int g = __gcd(p , q);
                        p /= g , q /= g;
                    } else if(p == 0 && q) q = 1;
                    else if(q == 0 && p) p = 1;
                    if(p <= 0){
                        p = -p;
                        if(p) q = -q;
                    }
                    pii &a = Mp[mp(p,q)];
                    a.se += sz[j];
                    if(j < i) a.fi = -1;
                }
                for(auto e : Mp) if(e.se.fi != -1){
                    int all = sz[i] + e.se.se;
                    pp(ans , cnt(all));
                }
                pp(ans , P - ((ll)cnt(sz[i]) * (sz(Mp)-1) % P));
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
