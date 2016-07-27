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
const int N = 101010;
int T , x[N] , y[N] , vis[N<<1];

int main(){
    scanf("%d",&T);
    rep(i,0,T){
        int n , m;
        scanf("%d%d",&n,&m);
        rep(i,0,n) scanf("%d%d",x + i ,y + i);
        ll all = (ll)n * (n-1)/2;
        if(all > m+m+3) puts("YES");
        else{
            fill(vis , vis + m + m + 3 , 0);
            bool fd = false;
            rep(i,0,n) rep(j,i+1,n){
                int dis = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                if(vis[dis]) fd = true;
                vis[dis] = true;
            }
            puts(fd?"YES":"NO");
        }
    }
    return 0;
}
