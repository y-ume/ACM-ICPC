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
const int N = 5005 , M = 202;
int a[N] , b[N][M] , n , m;
int st[N][M] , tp[M] , s[N][M];
ll del[N];


int main(){
    scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d",a + i);
    rep(i,1,n+1) rep(j,1,m+1) scanf("%d",&b[i][j]);
    ll ans = 0;
    rep(j,1,m+1) ans += b[1][j] , del[1] += s[1][j] = b[1][j] , st[tp[j]++][j] = 1;
    rep(i,2,n+1){
        rep(j,1,m+1){
            del[i] += s[i][j] = b[i][j];
            while(tp[j] > 0 && b[i][j] >= b[st[tp[j] - 1][j]][j]){
                int tt = st[tp[j] - 1][j];
                del[tt] -= s[tt][j];
                tp[j]--;
            }
            if(tp[j] > 0){
                int tt = st[tp[j] - 1][j];
                del[tt] -= s[tt][j];
                del[tt] += s[tt][j] = b[tt][j] - b[i][j];
            }
            st[tp[j]++][j] = i;
        }
        //rep(k,1,i+1) printf("%lld%c",del[k]," \n"[k==i]);
        //rep(k,1,m+1) printf("%d%c",tp[k]," \n"[k==m]);
        ll tmp = 0;
        for(int j=i;j>=1;--j){
            tmp += del[j];
            if(j != i) tmp -= a[j];
            ans = max(ans , tmp);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
