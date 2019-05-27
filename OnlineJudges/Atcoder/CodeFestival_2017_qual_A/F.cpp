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

int n , a;

int main(){
    cin >> n;
    map<int,int> f , g;
    f.clear();
    f[0] = 0;
    rep(i,0,n) {
        cin >> a;
        int k = 31 - __builtin_clz(a);
        g.clear();
        auto Update = [&](int a,int b){
            if(!g.count(a)) g[a] = b;
            else g[a] = min(g[a] , b);
        };
        for(auto e : f){
            if(a == (1 << k))
                Update(k , e.se + k - min(e.fi , k));
            else
                Update(k , e.se + k + 1 - min(e.fi , k + 1)),
                Update(k + 1 , e.se + k + 1 - min(e.fi , k));
        }
        f = g;
    }
    int ans = 1 << 30;
    for(auto e : f) ans = min(ans , e.se);
    cout << ans << endl;
    return 0;
}
