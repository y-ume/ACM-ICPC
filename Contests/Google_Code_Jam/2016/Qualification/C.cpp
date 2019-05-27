#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define sz(x) (int)(x).size()
typedef long long ll;
void setIO(){
    freopen("C-large.in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
const int N = 100001;
bool vis[N];
int pri[N] , _p;

void Prime(){
    for(int i=2;i<N;++i){
        if(!vis[i]) pri[_p++] = i;
        for(int j=0,o;j<_p && (o=pri[j]*i) < N;++j){
            vis[o] = true;
            if(i % pri[j] == 0)
                break;
        }
    }
}

vector<int> ans;
bool isPrime(ll x){
    for(int i=0;i<_p && (long long)pri[i] * pri[i] < x;++i)
        if(x % pri[i] == 0){
            ans.push_back(pri[i]);
            return false;
        }
    return true;
}
bool ok(int x){
    ans.clear();
    rep(i,2,11){
        ll y = 0;
        for(ll t=x,k=1;t;t/=2,k*=i)
            y += k * (t%2);
        if(isPrime(y)) return false;
    }
    return true;
}
vector<int> V;
vector<vector<int> > divisor;
int main(){
    setIO();
    Prime();
    int cnt = 0;
    rep(i,0,1<<14){
        int a = (1<<15|1)|(i<<1);
        if(ok(a)){
            cnt++;
            V.push_back(a);
            divisor.push_back(ans);
        }
    }
    int n , J , T;
    scanf("%d",&T);
    rep(cs,1,T+1){
        scanf("%d%d",&n,&J);
        printf("Case #%d:\n",cs);
        rep(i,0,J){
            if(n == 16)
                cout << bitset<16>(V[i]);
            else if(n == 32)
                cout << bitset<16>(V[i]) << bitset<16>(V[i]);
            rep(j,0,sz(divisor[i]))
                cout << " " << divisor[i][j];
            cout << endl;
        }
    }
    return 0;
}
