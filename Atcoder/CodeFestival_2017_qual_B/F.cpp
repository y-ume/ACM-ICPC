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

int main(){
    multiset<string> S;
    rep(i,0,3){
        int x;
        cin >> x;
        rep(j,0,x) S.insert(string(1 , i + 'a'));
    }
    while(sz(S) > 1){
        auto it = S.end();
        --it;
        string a = *S.begin() + *it;
        S.erase(it);
        S.erase(S.begin());
        S.insert(a);
    }
    cout << *S.begin() << endl;
    return 0;
}
