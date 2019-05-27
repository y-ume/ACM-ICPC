#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
typedef long long ll;
ll Pow(int a,int t){ll r = 1;for(;t;t>>=1,a*=a)if(t&1)r*=a;return r;}
void setIO(){
    freopen("D-large.in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
int K , C , S , T;
int main(){
    setIO();
    scanf("%d",&T);
    rep(cs,1,T+1){
        scanf("%d%d%d",&K,&C,&S);
        printf("Case #%d:",cs);
        if(S * C < K) printf(" IMPOSSIBLE\n");
        else{
            for(int i=0;i<K;i+=C){
                ll pos = 0;
                for(int t=i;t<i+C;++t){
                    pos = pos * K + (t < K ? t : 0);
                }
                printf(" %lld",pos + 1);
            }
            printf("\n");
        }
    }
    return 0;
}
