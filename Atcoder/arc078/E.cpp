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

int N;
string str(ll n){
    stringstream ss;
    ss << n;
    string s;
    ss >> s;
    return s;
}

bool check(ll n,ll N) {
    return (n <= N && str(n) <= str(N)) ||
        (n > N && str(n) > str(N));
}

bool ask(ll n){
    printf("? %lld\n",n);
    fflush(stdout);
#ifdef LOCAL
    return check(n , N);
#endif
    static char s[100];
    scanf("%s",s);
    return s[0] == 'Y';
}

void answer(ll x){
    printf("! %lld\n",x);
    exit(0);
}

int main(){
    srand(time(NULL));
    N = rand() + 1;
    ll x = 1 , l = -1 , r = -1;
    rep(i,0,11) {
        if(!ask(x) && l == -1) {
            l = x , r = x * 10;
        }
        x *= 10;
    }
    if(l == -1) {
        for(ll x=10;;x*=10) {
            if(ask(x - 1)) {
                answer(x / 10);
            }
        }
    } else {
        while(l + 1 < r) {
            ll m = (l + r) >> 1;
            if(ask(m)) r = m;
            else l = m;
        }
        answer(r / 10);
    }
    return 0;
}
