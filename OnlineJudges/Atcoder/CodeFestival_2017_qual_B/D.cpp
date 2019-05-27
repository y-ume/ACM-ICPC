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

const int N = 5e5 + 10;
char s[N];
int n,f[N];

int main(){
    scanf("%d%s",&n,s+1);
    rep(i,0,n+1) {
        if(i) f[i] = max(f[i-1] , f[i]);
        if(i >= 3 && s[i] == '1' && s[i-1] == '0'){
            for(int j=i-2;j>=1&&s[j]=='1';--j)
                f[i] = max(f[i] , f[j-1] + i - j - 1);
        }
        if(i+3<=n && s[i+1] == '1' && s[i+2] == '0'){
            for(int j=i+3;j<=n&&s[j]=='1';++j)
                f[j] = max(f[j] , f[i] + j - i - 2);
        }
    }
    printf("%d\n",f[n]);
    return 0;
}
