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

int n , K;

int main(){
    scanf("%d%d",&K,&n);
    if(K % 2 == 0) {
        rep(i,0,n) printf("%d%c",i?K:K/2," \n"[i+1==n]);
    } else {
        vi v(n , (K + 1) / 2);
        int times = n / 2;
        rep(i,0,times) {
            if(v.back() == 1) v.pop_back();
            else {
                v[sz(v)-1]--;
                rep(j,sz(v),n) v.pb(K);
            }
        }
        rep(i,0,sz(v)) printf("%d%c",v[i]," \n"[i+1==n]);
    }
    return 0;
}
