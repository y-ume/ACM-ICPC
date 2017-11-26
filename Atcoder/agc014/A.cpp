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

int A , B , C;
vector<tuple<int,int,int> > V;

int main(){
    cin >> A >> B >> C;
    int times = 0;
    while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0){
        if(find(all(V) , make_tuple(A,B,C)) != V.end()){
            cout << -1 << endl;
            return 0;
        }
        V.pb(make_tuple(A,B,C));
        tie(A , B , C) = make_tuple((B+C)>>1,(A+C)>>1,(A+B)>>1);
        times++;
    }
    cout << times << endl;
    return 0;
}
