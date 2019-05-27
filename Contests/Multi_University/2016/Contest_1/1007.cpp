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
const int N = 11 , P = 1e9 + 7;
int f[N][N] , p3[N*N] = {1} , C[N][N] = {{1}};
void pp(int &x,int d){
    x += d;if(x>=P) x-=P;
}

int main(){
    rep(i,1,N*N) p3[i] = (ll)p3[i-1] * 3 % P;
    rep(i,1,N) rep(j,0,i+1) C[i][j] = j ? (C[i-1][j-1] + C[i-1][j]) % P : 1;
    f[0][0] = f[0][1] = f[1][0] = 1;
    rep(n,1,N) rep(m,1,N){
        int &r=f[n][m];r = p3[n*m];
        rep(i,0,n) rep(j,0,m+1){
            if(i == n-1 && j == m) continue;
            pp(r , P - (ll)f[i+1][j] * p3[(n-i-1)*(m-j)] % P * C[n-1][i] % P * C[m][j] % P);
        }
    }
    int n , m;
    while(~scanf("%d%d",&n,&m)) printf("%d\n",f[n][m]);
    return 0;
}
