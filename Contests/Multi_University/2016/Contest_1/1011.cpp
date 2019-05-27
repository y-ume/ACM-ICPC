#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef long double db;
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
struct P{
    ll x , y , z;
    P(ll _x=0,ll _y=0,ll _z=0){
        x = _x , y = _y , z = _z;
    }
    void in(){
        cin >> x >> y >> z;
    }
    P operator - (const P&b){
        return P(x-b.x,y-b.y,z-b.z);
    }
    ll operator * (const P&b){
        return x*b.x + y*b.y + z*b.z;
    }
    P operator ^ (const P&b){
        return P(y*b.z-z*b.y , z*b.x-x*b.z , x*b.y-y*b.x);
    }
    void out(){
        cout << x << " " << y<< " " << z <<endl;
    }
}p[4];
db s[4];
#define sq(x) ((x)*(x))
db dis(P a,P b){
    return sqrt(sq(a.x-b.x) + sq(a.y-b.y) + sq(a.z-b.z));
}
db area(P a,P b,P c){ // *2
    P t = (b-a)^(c-a);
    return dis(t,P(0,0,0));
}
ll V(P a,P b,P c,P d){ // *6
    b = b-a , c = c-a , d = d-a;
    return abs((b^c)*d);
}
void pp(db&a,db&b,db&c,P d,db k){
    a+=d.x*k , b+=d.y*k , c+=d.z*k;
}
db eps = 1e-8;
int main(){
    while(cin >> p[0].x >> p[0].y >> p[0].z){
        rep(j,1,4) p[j].in();
        ll v = V(p[0],p[1],p[2],p[3]);
        if(v == 0) puts("O O O O");
        else{
            s[0] = area(p[1],p[2],p[3]);
            s[1] = area(p[0],p[2],p[3]);
            s[2] = area(p[1],p[0],p[3]);
            s[3] = area(p[1],p[2],p[0]);
            db S = 0;
            rep(i,0,4) S += s[i];
            db r = (db)v / S;
            db x(0),y(0),z(0);
            rep(i,0,4) pp(x,y,z,p[i],s[i]);
            printf("%.4lf %.4lf %.4lf %.4lf\n",(double)(x/S + eps),(double)(y/S + eps),(double)(z/S + eps),(double)(r + eps));
        }
    }
    return 0;
}
