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
const int N = 20;
int T,p,n,m,x[N];
ll f[1<<N],F[N + 10];
int blood[1<<N] , sum[1<<N] , cnt[1<<N];
#define lb(x) (x&(-x))

void main2(){
    scanf("%d%d%d",&p,&n,&m);n+=m;
    rep(i,0,m) scanf("%d",x + i);
    rep(i,0,n) sum[1<<i] = i<m?-1:1 , blood[1<<i] = i<m?x[i]:0;
    fill_n(f,1<<n,0);f[0] = 1;
    sum[0] = 0;
    rep(i,1,1<<n){
        int j = lb(i);
        blood[i] = blood[j] + blood[i^j];
        sum[i] = sum[j] + sum[i^j];
        //cout << i << " " << blood[i] << " " << sum[i] << endl;
    }
    rep(i,0,1<<N) sum[i]++;
    ll all = 0;
    int up = 1<<n;up--;
    rep(mask,0,1<<n){
        if(blood[mask] >= p){
            int cc = n - cnt[mask];
            all += f[mask] * F[cc];
        }
        else if(f[mask] >= 1){
            if(sum[mask] <= 0) continue;
            int k = mask^up;
            for(int t=k;t;t^=lb(t)){
                int j = lb(t);
                f[mask | j] += f[mask];
            }
        }
    }
    ll Sum = F[n];
    ll g = __gcd(all,Sum);
    all /= g , Sum /= g;
    printf("%lld/%lld\n",all,Sum);
}

int main(){
    rep(i,1,1<<N) cnt[i] = cnt[i^(lb(i))] + 1;
    F[0] = 1;
    rep(i,1,N+1) F[i] = F[i-1] * i;
    scanf("%d",&T);
    rep(re,0,T) main2();
    return 0;
}
