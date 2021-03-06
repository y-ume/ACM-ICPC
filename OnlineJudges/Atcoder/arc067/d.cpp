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
int n , A , B , x[N];

int main(){
    scanf("%d%d%d",&n,&A,&B);
    rep(i,1,n+1) scanf("%d",x + i);
    ll ans = 0;
    rep(i,2,n+1) ans += min(1ll * (x[i] - x[i-1]) * A , (ll)B);
    printf("%lld\n",ans);
    return 0;
}
