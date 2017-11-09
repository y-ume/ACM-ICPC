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

string s , t;

int solve(){
    int n = sz(s);
    vi sum(n << 1) , nxt(n) , pre(n);
    rep(i,0,sz(sum)) sum[i] = (i?sum[i-1]:0) + (t[i%n] == '1');
    rep(i,0,2){
        rep(i,0,n) pre[i]=t[i]=='1'?0:pre[(i-1+n)%n]+1;
        per(i,0,n) nxt[i]=t[i]=='1'?0:nxt[(i+1)%n]+1;
    }
    int ans = 1<<30;
    vector<pii> ex(n);
    rep(d,0,n){
        int flip = 0;
        rep(i,0,n){
            ex[i] = mp(0 , 0);
            if(s[i] == t[(i - d + n) % n])
                continue;
            flip++;
            //[i - d , i]
            if(sum[i + n] - sum[i - d - 1 + n] > 0)
                continue;
            ex[i] = mp(pre[(i - d + n) % n] , nxt[i]);
        }
        sort(all(ex));
        int tmp = 1<<30 , y = 0;
        per(i,0,n) {
            tmp = min(tmp , ex[i].fi + y);
            y = max(ex[i].se , y);
        }
        tmp = min(tmp , y);
        ans = min(ans , flip + tmp * 2 + d);
    }
    return ans;
}

int main(){
    cin >> s >> t;
    if(t.find('1') == string::npos){
        if(s == t) cout << 0 << endl;
        else cout << -1 << endl;
    } else {
        int ans = solve();
        reverse(all(s));
        reverse(all(t));
        ans = min(ans , solve());
        cout << ans << endl;
    }
    return 0;
}
