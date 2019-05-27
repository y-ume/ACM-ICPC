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
int n;

int main(){
    scanf("%d",&n);
    int cnt0 = 0 , cnt2 = 0;
    rep(i,0,n) {
        int a;
        scanf("%d",&a);
        if(a & 1) cnt0 ++;
        else if(a % 4 == 0) cnt2 ++;
    }
    if(cnt2 >= cnt0) puts("Yes");
    else if(cnt0 - cnt2 == 1 && cnt0 + cnt2 == n) puts("Yes");
    else puts("No");
    return 0;
}
