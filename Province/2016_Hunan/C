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
const int P = 1e9 + 7 , N = 201010;
int Pow(int x,int t){int r=1;for(;t;t>>=1,x=1ll*x*x%P)if(t&1)r=1ll*r*x%P;return r;}
int a,b,c,f[N]={1},rf[N];
inline void pp(int &x,int d){
    x += d;
    if(x >= P) x -= P;
}
int C(int a,int b){
    return 1ll*f[a]*rf[a-b]%P*rf[b]%P;
}
int solve(int ab,int ba,int ac,int ca,int bc,int cb){
    int r=1ll*f[ab+ac-1]*f[ba+bc-1]%P*f[ca+cb-1]%P*(ab+ac)%P;
    r=1ll*r*C(a,ab)%P*C(b,ac)%P*C(c,bc)%P;
    int tw=1ll*(ab+ac)*(ba+bc)%P;
    pp(tw,P-(1ll*(P-ab)*(P-ba)%P));
    return 1ll*r*tw%P;
}

int main(){
    rep(i,1,N) f[i]=1ll*f[i-1]*i%P;
    rf[N-1]=Pow(f[N-1],P-2);
    for(int i=N-2;i>=0;--i) rf[i]=1ll*rf[i+1]*(i+1)%P;
    while(~scanf("%d%d%d",&a,&b,&c)){
        int up = min(a,min(b,c));
        int ans = 0;
        for(int i=0;i<=up;++i) if((a-i)%2==0&&(b-i)%2==0&&(c-i)%2==0){
            int d=(a-i)/2 , e=(b-i)/2 , f=(c-i)/2;
            pp(ans , solve(d , d + i , e + i , e , f , f + i));
            if(i) pp(ans , solve(d + i , d , e , e + i , f + i , f));
        }
        printf("%d\n",ans);
    }
    return 0;
}
