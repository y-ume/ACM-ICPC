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

const int N = 2020 , P = 1e9 + 7;
int comb[N][N] , f[N][N] , sum[N][N] , A , B;
inline void pp(int &x,int d){if((x+=d)>=P)x-=P;}
inline int add(int a,int b){return (a+b)%P;}
inline int mul(int a,int b){return ll(a)*b%P;}

int main(){
    rep(i,0,N) rep(j,0,i+1) comb[i][j] = j ? add(comb[i-1][j-1] , comb[i-1][j]) : 1;
    rep(i,0,N) rep(j,0,i+1) sum[i][j] = add(j ? sum[i][j-1] : 0 , comb[i][j]);
    cin >> A >> B;
    rep(i,0,N) f[i][0] = f[0][i] = 1;
    rep(i,1,A+1) rep(j,1,B+1) f[i][j] = add(f[i-1][j] , sum[j-1][min(i,j-1)]);
    int ans = 0;
    rep(i,0,A+1) for(int j=0;i+j<=A&&j<B;++j)
        pp(ans,mul(f[i][j] , comb[B-1][j]));
    cout << ans << endl;
    return 0;
}
