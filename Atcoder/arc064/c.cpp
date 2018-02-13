#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
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
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
const int N = 101010;
int n , x , a[N];

int main(){
    cin >> n >> x;
    rep(i,0,n) cin >> a[i];
    ll ans = 0;
    if(a[0] > x) ans += a[0] - x , a[0] = x;
    rep(i,1,n)
        if(a[i] + a[i-1] > x)
            ans += a[i] - (x - a[i-1]) , a[i] = x - a[i-1];
    cout << ans << endl;
    return 0;
}
