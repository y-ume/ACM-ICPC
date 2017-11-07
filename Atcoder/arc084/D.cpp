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
int K , dis[N];
deque<int> Q;

int main(){
    cin >> K;
    rep(i,0,K) dis[i] = 1<<30;
    Q.push_back(1);dis[1] = 1;
    while(sz(Q)){
        int c = Q.front();Q.pop_front();
        int t = c * 10 % K;
        if(dis[t] > dis[c]) Q.push_front(t) , dis[t] = dis[c];
        t = (c + 1) % K;
        if(dis[t] > dis[c] + 1) Q.push_back(t) , dis[t] = dis[c] + 1;
    }
    printf("%d\n",dis[0]);
    return 0;
}
