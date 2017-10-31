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


int f[1 << 26] , pattern[27];
string s;

int main(){
    rep(i,0,26) pattern[i] = 1 << i;
    memset(f , 0x37 , sizeof(f));
    f[0] = 0;
    cin >> s;
    int mask = 0;
    rep(i,0,sz(s)) {
        mask ^= 1 << (s[i] - 'a');
        int best = sz(s);
        rep(i,0,27) best = min(best , f[mask ^ pattern[i]] + 1);
        f[mask] = min(f[mask] , best);
        if(i == sz(s) - 1) cout << best << endl;
    }
    return 0;
}
