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

const int N = 2e5 + 10;
int n , a[N] , pos[N];

int main(){
    scanf("%d",&n);
    rep(i,1,n+1) scanf("%d",a + i) , pos[a[i]] = i;
    int t = 0 , last = -1;
    per(i,1,n) {
        if(t == 0) {
            if(pos[i] > pos[i + 1])
                t++ , last = pos[i + 1];
        } else {
            int a = pos[i] , b = pos[i + 1] , c = last;
            if((b < a && a < c) || (a < c && c < b) || (c < b && b < a))
                t++ , last = pos[i + 1];
        }
    }
    printf("%d\n",t);
    return 0;
}
