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

const int N = (1e5 + 10) * 3, P = 998244353;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
inline int mul(int a,int b){return ll(a)*b%P;}
int fac[N] = {1} , ifac[N] , pw[N] = {1} , ipw[N] = {1};
int inv(int x){return x == 1 ? 1 : P-ll(P/x)*inv(P%x)%P;}
inline int comb(int a,int b){return mul(fac[a],mul(ifac[b],ifac[a-b]));}
int n , m , lsum[N];
string A , B , C , D;

int solve(){
    int left = 0;
    for(auto ch : A) left += ch == '1';
    int base = 0 , up = 0 , down = 0;
    rep(i,0,m) {
        lsum[i] = i ? lsum[i-1] : 0;
        if(C[i] == '1' || D[i] == '1') {
            if(left == 0) pp(lsum[i] , mul(ipw[base] , up == 0 && down == 0));
            else pp(lsum[i] , mul(ipw[base] , comb(left + up + down - 1 , left - 1)));
        }
        up += C[i] == '1';
        down += D[i] == '1';
        if(C[i] == '1' && D[i] == '1') base++;
    }
    int right = 0;
    for(auto ch : B) right += ch == '1';
    base = 0 , up = 0 , down = 0;
    int res = 0;
    per(i,0,m) {
        int tmp = 0;
        if(right == 0) tmp = mul(ipw[base] , up == 0 && down == 0);
        else tmp = mul(ipw[base] , comb(right + up + down - 1 , right - 1));
        up += C[i] == '1';
        down += D[i] == '1';
        if(C[i] == '1' || D[i] == '1') pp(res , mul(lsum[i] , tmp));
        if(C[i] == '1' && D[i] == '1') base++;
    }
    return mul(res , pw[base]);
}

int main(){
    rep(i,1,N) fac[i] = mul(fac[i-1] , i);
    ifac[N-1] = inv(fac[N-1]);
    per(i,1,N) ifac[i-1] = mul(ifac[i] , i);
    int inv2 = inv(2);
    rep(i,1,N) pw[i] = mul(pw[i-1] , 2);
    rep(i,1,N) ipw[i] = mul(ipw[i-1] , inv2);
    cin >> n >> m;
    cin >> A >> B >> C >> D;
    int ans = solve();
    swap(n , m);
    swap(A , C);
    swap(B , D);
    pp(ans , solve());
    bool has = false;
    for(auto ch : A) has |= ch == '1';
    for(auto ch : B) has |= ch == '1';
    for(auto ch : C) has |= ch == '1';
    for(auto ch : D) has |= ch == '1';
    if(has == false) ans ++;
    cout << ans << endl;
    return 0;
}
