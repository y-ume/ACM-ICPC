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
const int N = 1010;
db x[N] , y[N] , r[N] , dis[N];
bool vis[N];
int n;

#define sq(x) (x)*(x)
db cal(int a,int b){
    return max(0. , sqrt(sq(x[a] - x[b]) + sq(y[a] - y[b])) - r[a] - r[b]);
}


int main(){
    cin >> x[0] >> y[0];
    cin >> x[1] >> y[1];
    cin >> n;
    rep(i,0,n) cin >> x[i+2] >> y[i+2] >> r[i+2];
    n += 2;
    rep(i,0,n) dis[i] = 1e50;
    dis[0] = 0;
    rep(i,0,n){
        int id = -1;
        rep(j,0,n) if(!vis[j] && (id == -1 || dis[j] < dis[id]))
            id = j;
        vis[id] = true;
        rep(j,0,n) if(!vis[j]) dis[j] = min(dis[j] , dis[id] + cal(id , j));
    }
    printf("%.16f\n",dis[1]);
    return 0;
}
