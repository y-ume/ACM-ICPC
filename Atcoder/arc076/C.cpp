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

const int P = 1e9 + 7;
int n , m;
int fac(int x){
    int res=1;
    rep(i,1,x+1) res=ll(res)*i%P;
    return res;
}

int main(){
    cin >> n >> m;
    int ans=ll(fac(n))*fac(m)%P;
    if(n==m) ans=ans*2%P;
    else if(abs(n-m)!=1) ans=0;
    cout<<ans<<endl;
    return 0;
}
