#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef double db;
#define sz(x) (int)(x).size()
#define set(a,x) memset(a,x,sizeof(a))
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,a,b) for(int i=a;i<b;++i)
#define de(x) cout << #x << "=" << x << endl
#define setIO(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
const int hs = 1234567 ,P = 1000007 ,  N = 2020;
int n , m , a[N];
map<pair<vi,ll> , vector<pii> > Mp[4];

int gt(int a,int b){
	return (a&1)<<1 | (b&1);
}
int cc[] = {0 , 1 , 1 , 2};
bool can(int l,int r,ll sum){
	return sum + cc[gt(l , r)] <= m && m <= sum + (l&1 ? a[l] : 0) + (r&1 ? a[r] : 0);
}
bool Cmp(const pii&a,const pii&b){
	if(a.fi != b.fi) return a.fi > b.fi;
	return a.se > b.se;
}

ll Query(vector<pii>v,int x,int n){
	if(x == 0){
		if(n) return 0;
		sort(all(v) , Cmp);
		int Max = v[0].se;
		ll r = (ll)Max * v[0].fi;
		rep(i,1,sz(v)){
			if(v[i].fi < v[i-1].fi){
				if(v[i].se > Max){
					r += (ll)(v[i].se - Max) * v[i].fi;
					Max = v[i].se;
				}
			}
		}
		return r;
	} else if(x == 1){
		int r = 0;
		rep(i,0,sz(v)) if(v[i].se >= n) r = max(r , v[i].fi);
		return r;
	} else if(x == 2){
		rep(i,0,sz(v)) swap(v[i].fi , v[i].se);
		return Query(v , 1 , n);
	} else if(x == 3){
		vector<pii> p;
		rep(i,0,sz(v)) if(v[i].fi + v[i].se >= n)
			p.pb(mp( max(1 , n - v[i].se), min(n - 1, v[i].fi)));
		sort(all(p));
		ll r = 0;int c = 0;
		rep(i,0,sz(p)){
			if(p[i].se > c) r += p[i].se - max(c , p[i].fi - 1) , c = p[i].se;
		}
		return r;
	}
	return 0;
}

ll main2(){
	scanf("%d%d",&n,&m);
	rep(i,1,n+1) scanf("%d",a + i);
	ll ans = 0;
	if(m == 0){
		rep(i,1,n+1) if(!(i&1)) ans = max(ans , (ll)a[i]);
		return ans;
	}
	rep(i,0,4) Mp[i].clear();
	rep(i,1,n+1) if((i&1) && a[i] >= m) ans = 1;
	int d1 = 0 , d2 = 0;
	rep(i,1,n+1){
		if(i != n){
			if(i&1){
				if(a[i] >= m) d1 = max(d1 , a[i+1]);
			}
			else
				if(a[i+1] >= m) d2 = max(d2 , a[i]);
		}
		ll sum = 0;
        vi v;
		if(i != 1) rep(j,i,n){
			if(j&1) sum += a[j];
            v.pb(a[j]);
			if(can(i-1 , j+1 , sum)) Mp[gt(i - 1 , j + 1)][mp(v , sum)].pb(mp(a[i-1], a[j+1]));
		}
	}
	rep(i,0,4) for(map<pair<vi,ll> , vector<pii> >::iterator it = Mp[i].begin();it != Mp[i].end();++it){
//		int tmp = Query(it->se , i , m - it->fi.se);
		ans += Query(it->se , i , m - it->fi.se);
	}
	return ans + d1 + d2;
}


int main(){
	int T;
	scanf("%d",&T);
	rep(i,0,T) printf("%lld\n",main2());
	return 0;
}

/*
1
3 2
3 3 3
 */
