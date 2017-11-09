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

ll n , cost[4];

int main(){
    rep(i,0,4) cin >> cost[i];
    cin >> n;
    rep(i,1,4) cost[i] = min(cost[i] , cost[i-1] * 2);
    n *= 4;
    ll ans = 0;
    per(i,0,4) {
        ll c = n >> i;
        ans += c * cost[i];
        n -= c << i;
    }
    cout << ans << endl;
    return 0;
}
