#include <iostream>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)

void setIO(){
    freopen("A-large.in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}

int main(){
    setIO();
    int T , n;
    scanf("%d",&T);
    rep(cs,1,T+1){
        scanf("%d",&n);
        if(n == 0) printf("Case #%d: INSOMNIA\n",cs);
        else{
            int vis[10];
            fill(vis , vis + 10 , 0);
            for(int c=n,cnt=0;;c+=n){
                for(int t=c;t;t/=10){
                    if(vis[t%10] == false)
                        cnt++ , vis[t%10] = true;
                }
                if(cnt == 10){
                    printf("Case #%d: %d\n",cs,c);
                    break;
                }
            }
        }
    }
    return 0;
}
