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

int main(){
    int n;
    cin >> n;
    map<int,int> Mp;
    rep(i,1,n+1){
        int t = i;
        for(int j=2;j*j<=t;++j) if(t % j == 0){
            while(t % j == 0) t /= j , Mp[j]++;
        }
        if(t > 1) Mp[t]++;
    }
    int ans = 1;
    for(auto e : Mp) ans = 1ll * ans * (e.se + 1) % P;
    cout << ans << endl;
    return 0;
}
