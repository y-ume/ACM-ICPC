#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
int n , A , B , C , D;
int f[N] , g[N];
int Pow(int x,int t){
    int ret=1;for(;t;t>>=1,x=1ll*x*x%P) if(t&1)ret=1ll*ret*x%P;return ret;
}

void pp(int &x,int d){
    x += d;if(x >= P) x -= P;
}

int a[N]={1},r[N];
int cb(int x,int y){
    return 1ll * a[x] * r[y] % P * r[x-y] % P;
}

int main(){
    rep(i,1,N) a[i] = 1ll * a[i-1] * i % P;
    rep(i,0,N) r[i] = Pow(a[i] , P - 2);
    cin >> n >> A >> B >> C >> D;
    f[0] = 1;
    rep(i,A,B+1){
        for(int j=n;j>=0;--j){
            int cof = Pow(r[i] , C);
            for(int k=C;k<=D && j-k*i>=0;++k,cof = 1ll * cof * r[i] % P)
                pp(f[j] , 1ll * f[j-k*i] * cb(n - j + k * i , k * i) % P * a[k * i] % P * r[k] % P * cof % P);
        }
    }
    printf("%d\n",f[n]);
    return 0;
}
