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

const int N = 50;
ll K , n , a[N];

int main(){
    cin >> K;
    n = 50;
    rep(i,0,n) a[i] = i + K / n;
    rep(i,0,K%n) {
        int p=min_element(a,a+n)-a;
        a[p]+=n;
        rep(i,0,n) if(i!=p) a[i]--;
    }
    cout<<n<<endl;
    rep(i,0,n) cout<<a[i]<<" \n"[i+1==n];
    return 0;
}
