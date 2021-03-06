#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<cassert>
#define LL long long
#define eps 1e-8
#define zero(a) fabs(a)<eps
#define N 450005
using namespace std;
struct Point{
	Point() {}
	Point(double x, double y) : x(x), y(y) {}
	double x,y;
	Point operator - (const Point&c) const {
		Point ans;
		ans.x = x - c.x; ans.y  = y - c.y;
		return ans;
	}
}p[N*2];
struct Segment{
	Point s,e;
	double angle;
	void get_angle(){angle=atan2(e.y-s.y,e.x-s.x);}
}seg[N];
int m;
//叉积为正说明，p2在p0-p1的左侧
double xmul(Point p0,Point p1,Point p2){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
Point Get_Intersect(Segment s1,Segment s2){
	double u=xmul(s1.s,s1.e,s2.s),v=xmul(s1.e,s1.s,s2.e);
	Point t;
	t.x=(s2.s.x*v+s2.e.x*u)/(u+v);t.y=(s2.s.y*v+s2.e.y*u)/(u+v);
	return t;
}
bool cmp(Segment s1,Segment s2){
	//先按极角排序
	if(s1.angle>s2.angle) return true;
	//极角相等，内侧的在前
	else if(zero(s1.angle-s2.angle)&&xmul(s2.s,s2.e,s1.e)>-eps) return true;
	return false;
}
void HalfPlaneIntersect(int n){
	sort(seg,seg+n,cmp);
	int tmp=1;
	for(int i=1;i<n;i++)
		if(!zero(seg[i].angle-seg[tmp-1].angle))
			seg[tmp++]=seg[i];
	n=tmp;
	Segment deq[N];
	deq[0]=seg[0];deq[1]=seg[1];
	int head=0,tail=1;
	for(int i=2;i<n;i++){
		while(head<tail&&xmul(seg[i].s,seg[i].e,Get_Intersect(deq[tail],deq[tail-1]))<-eps) tail--;
		while(head<tail&&xmul(seg[i].s,seg[i].e,Get_Intersect(deq[head],deq[head+1]))<-eps) head++;
		deq[++tail]=seg[i];
	}
	while(head<tail&&xmul(deq[head].s,deq[head].e,Get_Intersect(deq[tail],deq[tail-1]))<-eps) tail--;
	while(head<tail&&xmul(deq[tail].s,deq[tail].e,Get_Intersect(deq[head],deq[head+1]))<-eps) head++;
	if(head==tail) return;
	m=0;
	for(int i=head;i<tail;i++)
		p[m++]=Get_Intersect(deq[i],deq[i+1]);
	if(tail>head+1)
		p[m++]=Get_Intersect(deq[head],deq[tail]);
}
double Get_area(Point p[],int &n){
	double area=0;
	for(int i=1;i<n-1;i++)
		area+=xmul(p[0],p[i],p[i+1]);
	return fabs(area)/2.0;
}

const int M = 15;
int n, mm, T;
int a[M * M], b[M * M];
int c[M][M], d[M][M];
int vis[M];
double ans;
int sn;
const double inf = 1e18;

void dfs(int u, int sc, int sd) {
	if (u == n) {
		seg[sn].s.x = T; seg[sn].s.y = 1.0 * sc * T + sd;
		seg[sn].e.x = 0; seg[sn].e.y = sd; seg[sn].get_angle(); sn++;
		return;
	} 
	for (int i = 2; i <= n; i++) {
		if (vis[i]) continue;
		if (c[u][i] == -1) continue;
		if (i != n && c[u][n] != -1 && c[u][i] >= c[u][n] && d[u][i] >= d[u][n]) continue;
		vis[i] = 1;
		dfs(i, sc + c[u][i], sd + d[u][i]);
		vis[i] = 0;
	}
}

int main(){
	while (~scanf("%d%d%d", &n, &mm, &T)) {
		memset(c, -1, sizeof(c));
		memset(d, -1, sizeof(d));
		for (int i = 0; i < mm; i++) {
			scanf("%d%d", &a[i], &b[i]);
			scanf("%d", &c[a[i]][b[i]]);
			scanf("%d", &d[a[i]][b[i]]);
		}
		sn = 0;
		dfs(1, 0, 0);
		seg[sn].s.x = 0; seg[sn].s.y = inf; seg[sn].e.x = 0; seg[sn].e.y = 0; seg[sn].get_angle(); sn++;
		seg[sn].s.x = 0; seg[sn].s.y = 0; seg[sn].e.x = T; seg[sn].e.y = 0; seg[sn].get_angle(); sn++;
		seg[sn].s.x = T; seg[sn].s.y = 0; seg[sn].e.x = T; seg[sn].e.y = inf; seg[sn].get_angle(); sn++;
		//seg[sn].s.x = T; seg[sn].s.y = inf; seg[sn].e.x = 0; seg[sn].e.y = inf; seg[sn].get_angle(); sn++;
		HalfPlaneIntersect(sn);
		printf("%.12f\n", Get_area(p, m) / T);
	}
	return 0;
}

