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
const int N = 1e7 + 10 , P = 1e9 + 7;
// a^b%p=a^(b%phi(p)+phi(p))%p   b>=phi(p)
int n , m , p;
int vis[N] , pri[N] , phi[N] , sum[N] , _;
void Phi(){
    phi[1] = 1;
    rep(i,2,N){
        if(!vis[i]) pri[_++] = i , phi[i] = i-1;
        for(int j=0,o;j<_&&(o=pri[j]*i)<N;++j){
            vis[o] = true;
            phi[o] = (pri[j] - 1) * phi[i];
            if(i % pri[j] == 0){
                phi[o] += phi[i];
                break;
            }
        }
    }
    rep(i,1,N) sum[i] = (sum[i-1] + phi[i]) % P;
}
vi fac;
map<pii,int> Mp;
int f(int n,int m,int dep){
    if(m == 1) return phi[n];
    if(m < 1) return 0;
    if(n == 1) return sum[m];
    if(Mp.find(mp(n,m)) != Mp.end()) return Mp[mp(n,m)];
    int ret = ((ll)phi[fac[dep]] * f(n/fac[dep] , m , dep + 1) + f(n , m/fac[dep] , dep)) % P;
    return Mp[mp(n,m)] = ret;
}
int Pow(int a,int b,int p){int r=1;for(;b;b>>=1,a=(ll)a*a%p)if(b&1)r=(ll)r*a%p;return r;}
int solve(int k,int p){
    if(p == 1) return 0;
    return Pow(k,solve(k,phi[p])+phi[p],p);
}

int main(){
    Phi();
    while(~scanf("%d%d%d",&n,&m,&p)){
        int nn = n;fac.clear();
        for(int i=2;i*i<=nn;++i) if(nn%i == 0) while(nn%i == 0) nn/=i , fac.pb(i);
        if(nn != 1) fac.pb(nn);
        int k = f(n , m , 0);
        printf("%d\n",solve(k,p));
    }
    return 0;
}
