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
const int P = 1e9 + 7;
int Pow(int a,int t){
    int r=1;for(;t;t>>=1,a=1ll*a*a%P)if(t&1)r=1ll*r*a%P;
    return r;
}
void pp(int &a,int b){
    a += b;
    if(a >= P) a -= P;
}
int n , K;

int main(){
    cin >> n >> K;
    int ans = 0;
    if(n == -1){
        ans = 1ll * Pow(K , n/2+1) * n % P;
        pp(ans , P - 1ll * K * (n - 1) % P);
    } else {
        int x = n / 2;
        set<int> S;
        map<int,int> Mp;
        for(int i=1;i*i<=n;++i) if(n % i == 0) S.insert(i) , S.insert(n / i);
        for(auto e : S){
            int t = 0;
            if(n % 2 == 0 && x % e == 0) t = Pow(K , e);
            else t = Pow(K , (e + 1) / 2);
            for(auto f : Mp) if(e % f.fi == 0) pp(t , P - f.se);
            pp(ans , 1ll * t * e % P);
            Mp[e] = t;
        }
    }
    printf("%d\n",ans);
    return 0;
}
