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

const int N = 2e5 + 10;
int n , K , a[N];
ll sum[N] , ans;

void solve(int l,int r){
    if(l == r) return;
    int m = (l + r) >> 1;
    solve(l , m);
    solve(m + 1 , r);
    for(int i=m+1,j=l;i<=r;++i){
        for(;j<=m&&sum[j]<=sum[i];++j);
        ans+=j-l;
    }
    inplace_merge(sum+l,sum+m+1,sum+r+1);
}

int main(){
    scanf("%d%d",&n,&K);
    rep(i,1,n+1) scanf("%d",a + i) , sum[i] = sum[i-1] + a[i];
    rep(i,1,n+1) sum[i] -= ll(K) * i;
    solve(0 , n);
    printf("%lld\n",ans);
    return 0;
}
