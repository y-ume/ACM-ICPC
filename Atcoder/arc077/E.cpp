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

const int N = 1e5 + 10;
int a[N] , n , m;
ll w[N + N] , t[N + N];

int main(){
    scanf("%d%d",&n,&m);
    rep(i,0,n) scanf("%d",a + i) , --a[i];
    ll full = 0;
    rep(i,1,n) {
        int l = a[i-1] , r = a[i];
        if(r < l) r += m;
        full += r - l;
        t[l + 1]++;
        t[r + 1]--;
        w[l + 1]+=l+1;
        w[r + 1]-=l+1;
    }
    ll Mx=0;
    rep(i,1,m+m) {
        t[i] += t[i-1];
        w[i] += w[i-1];
    }
    rep(i,0,m) Mx=max(Mx,t[i]*i+t[i+m]*(i+m)-w[i]-w[i+m]);
    printf("%lld\n",full-Mx);
    return 0;
}
