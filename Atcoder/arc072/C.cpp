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
int n , a[N];

ll solve(int sig) {
    ll sum = 0 , cost = 0;
    rep(i,0,n) {
        sum += a[i];
        if(sig > 0 && sum <= 0) {
            cost += 1 - sum;
            sum = 1;
        } else if(sig < 0 && sum >= 0){
            cost += sum + 1;
            sum = -1;
        }
        sig *= -1;
    }
    return cost;
}

int main(){
    scanf("%d",&n);
    rep(i,0,n) scanf("%d",a + i);
    printf("%lld\n",min(solve(1) , solve(-1)));
    return 0;
}
