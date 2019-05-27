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

namespace number_theory{
    int Phi(int n){
        int res(n);
        for(int i=2;i*i<=n;++i) if(n%i==0){
            res=res/i*(i-1);
            while(n%i==0) n/=i;
        }
        if(n>1) res=res/n*(n-1);
        return res;
    }
    ll Pow(ll x,ll t,ll P){ll r=1;for(;t;t>>=1,x=x*x%P)if(t&1)r=r*x%P;return r;}
    ll add(ll a,ll b){return (a%b+b)%b;}
    void exgcd(ll a,ll b,ll&x,ll&y){
        if(!b) x = 1 , y = 0;
        else exgcd(b,a%b,y,x) , y -= a/b*x;
    }
    ll inverse(ll a,ll b){ll x,y;exgcd(a,b,x,y);return (x%b+b)%b;}
    ll congruences(int n, ll *r, ll *m){
        ll ans = r[0], LCM = m[0];
        rep(i,1,n){
            ll g = __gcd(LCM , m[i]) , x = inverse(LCM , m[i]);
            if ((r[i] - ans) % g) return -1;
            ll tmp = ((r[i] - ans) / g * x) % (m[i] / g);
            (ans += LCM * tmp) %= (LCM / g * m[i]);
            LCM = LCM / g * m[i];
        }
        ans = (ans + LCM) % LCM;
        if(ans == 0) ans += LCM;
        return ans;
    }
    ll r[2] , m[2];
    ll solve(int a,int b){
        if(b == 1) return 1;
        int phi = Phi(b);
        int g = __gcd(phi , b);
        ll y = solve(a , g);
        r[0] = Pow(a , y , b) , m[0] = b;
        r[1] = y % phi , m[1] = phi;
        return congruences(2 , r , m);
    }
}

int main(){
    int Q;
    scanf("%d",&Q);
    rep(i,0,Q){
        int a,m;
        scanf("%d%d",&a,&m);
        ll res = number_theory::solve(a , m);
        assert(number_theory::Pow(a , res , m) % m == res % m);
        printf("%lld\n",res);
    }
    return 0;
}
