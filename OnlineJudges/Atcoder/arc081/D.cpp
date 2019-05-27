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

const int N = 100 , P = 1e9 + 7;
int n;
string s , t;

int main(){
    cin >> n;
    cin >> s >> t;
    int bf=0;
    int ans=1;
    for(int i=0;i<n;){
        if(i!=n-1&&s[i]==s[i+1]){
            if(bf==2) ans=ll(ans)*3%P;
            else if(bf==1) ans=ll(ans)*2%P;
            else ans=ll(ans)*6%P;
            bf=2;
            i+=2;
        } else {
            if(bf==2) ;
            else if(bf==1) ans=(ll)ans*2%P;
            else ans=(ll)ans*3%P;
            bf=1;
            i++;
        }
    }
    printf("%d\n",ans);
    return 0;
}
