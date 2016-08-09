#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <complex>
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
int n , m;

int main(){
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        ll up = 1ll * n * (m - 1);
        ll dn = 1ll * m * m;
        ll g = __gcd(up,dn);
        up/=g,dn/=g;
        printf("%lld/%lld\n",up,dn);
    }
    return 0;
}
