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

const int N = 3e5 + 10;
int n , a[N];
ll Mx[N];

int main(){
    scanf("%d",&n);
    rep(i,1,3*n+1) scanf("%d",a + i);
    priority_queue<int> Q;
    ll s = 0;
    for(int i=n,j=1;i<=n+n;++i){
        for(;j<=i;++j){
            s += a[j];
            Q.push(-a[j]);
        }
        if(sz(Q) > n){
            s += Q.top();
            Q.pop();
        }
        Mx[i] = s;
    }
    while(sz(Q)) Q.pop();
    s = 0;
    ll ans = -1e18;
    for(int i=n+n+1,j=n*3;i>n;--i){
        for(;j>=i;--j){
            s += a[j];
            Q.push(a[j]);
        }
        if(sz(Q) > n){
            s -= Q.top();
            Q.pop();
        }
        ans = max(ans , Mx[i-1] - s);
    }
    printf("%lld\n",ans);
    return 0;
}
