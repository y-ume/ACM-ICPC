//#include {{{
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


int PRO_NUMBER , SECOND_MAX;
db HOUR;
#define ERROR -1
#define ACCESS 1
#define MODIFY 2
#define CLOSE 3
struct state{
    int h,m,s,op;char pro;
#define err() {op=ERROR;return;}
    state(){pro='?';}
    state(vector<string> S){
        if(sz(S) != 4) {err();}
        else{
            if(sscanf(S[0].c_str() ,
                "%*d%*c%*d%*c%*d%*c%d%*c%d%*c%d" ,&h,&m,&s) != 3) {err();}
            if(S[1] == "ACCESS") op = ACCESS;
            else if(S[1] == "MODIFY") op = MODIFY;
            else if(S[1] == "CLOSE") op = CLOSE;
            else {err();}

            auto split = [&](string s,char ch){
                vector<string> res;
                for(int i=0,j=0;i<sz(s);i=j){
                    for(j=i;j<sz(s)&&s[j]!=ch;++j) ;
                    if(j!=i) res.pb(s.substr(i,j-i));
                    else ++j;
                }
                return res;
            };

            vector<string> V(split(S[3] , '.'));

            auto typecheck = [&](string s){
                return s == "cpp" || s == "in" || s == "py";
            };

            if(sz(V) == 3 && V[2] == "swp" && typecheck(V[1])){
                pro = V[0][0];
                if('a' <= pro && pro <= 'z') pro += 'A' - 'a';
                if(pro < 'A' || pro > 'A' + PRO_NUMBER - 1) {err();}
            } else if(sz(V) == 2 && typecheck(V[1])){
                pro = V[0][0];
                if('a' <= pro && pro <= 'z') pro += 'A' - 'a';
                if(pro < 'A' || pro > 'A' + PRO_NUMBER - 1) {err();}
            } else {err();}

            //cout << h << " " << m << " " << s << " " << op << " " << pro << endl;
        }
    }
    int timediff(state y){
        return ((((h - y.h) * 60 + (m - y.m)) * 60 + s - y.s) + 3600 * 24) % (3600 * 24);
    }
};

int belong[24 * 60 * 60];
set<int> vis;
char graph[26][24 * 60];

int col[14] = {31 , 32 , 33 , 35 , 36 , 37 , 38 , 31 , 32 , 33 , 35 , 36 , 37 , 38};
void output(){
    int duration = 3 * 60 , Sum = 0;
    int seg = SECOND_MAX / duration;
    vi time(PRO_NUMBER , 0);
    for(int i=0;i<SECOND_MAX;i+=duration){
        vi cnt(PRO_NUMBER , 0);
        rep(j,0,duration) if(belong[j + i] != -1)
            cnt[belong[j + i]] ++ , time[belong[j + i]] ++ , Sum++;
        rep(j,0,PRO_NUMBER) graph[j][i / duration] =
            " -="[cnt[j] >= duration * 0.5 ? (j >= 8 ? 2 : 1) : 0];
    }
    rep(i,0,PRO_NUMBER){
        printf("[  %c  ] : ",i+'A');
        rep(j,0,seg) printf("\x1b[%d;%dm%c\x1b[0m",40,col[i],graph[i][j]);
        if(time[i] >= 3600) printf(" [%02d:%02d:%02d]",time[i]/3600,time[i]/60%60,time[i]%60);
        if(time[i]) printf(" [%02d:%02d]",time[i]/60,time[i]%60);
        puts("");
    }
    printf("[ SUM ] : ");
    rep(i,0,seg) {
        int who = -1;
        rep(j,0,PRO_NUMBER) if(graph[j][i] != ' ') who = j;
        if(who == -1) putchar(' ');
        else printf("\x1b[%d;%dm%c\x1b[0m",40,col[who],graph[who][i]);
    }
    puts("");
    printf("          ");
    rep(i,0,seg) {
        int who = -1;
        rep(j,0,PRO_NUMBER) if(graph[j][i] != ' ') who = j;
        if(who == -1) putchar(' ');
        else printf("\x1b[%d;%dm%c\x1b[0m",40,col[who],who+'A');
    }
    if(Sum >= 3600) printf(" [%02d:%02d:%02d]",Sum/3600,Sum/60%60,Sum%60);
    else if(Sum) printf(" [%02d:%02d]",Sum/60,Sum%60);
    puts("");

}

int stringtoint(string s){
    stringstream ss(s);
    int x;
    ss>>x;
    return x;
}


db stringtodouble(string s){
    stringstream ss(s);
    db x;
    ss>>x;
    return x;
}

int main(int argc,char *argv[]){
    if(argc != 3 && argc != 6){
        puts("argc should be 3 or 6");
        puts("argc = 3 : input the problem_number and contest_hours.");
        puts("For example : ./post 13 5");
        puts("argc = 6 : input the problem_number, contest_hours, start_hour, start_minute ans start_second.");
        puts("For example : ./post 13 5 9 0 0");
        return 0;
    }
    PRO_NUMBER = stringtoint(argv[ 1 ]);
    HOUR = stringtodouble(argv[ 2 ]);
    SECOND_MAX = HOUR * 3600 + 0.5;
    rep(i,0,SECOND_MAX) vis.insert(i);
    string s;
    state pre , start;
    if(argc == 6){
        start.h = stringtoint(argv[ 3 ]);
        start.m = stringtoint(argv[ 4 ]);
        start.s = stringtoint(argv[ 5 ]);
        start.pro = '!';
    }
    memset(belong , -1 , sizeof(belong));
    while(getline(cin , s)){
        vector<string> S;
        stringstream ss(s);
        while(ss >> s) S.pb(s);
        state cur(S);
        if(start.pro == '?') start = cur;
        if(cur.op != ERROR){
            if(cur.pro == pre.pro && cur.timediff(pre) <= 60){
                int from = pre.timediff(start) , to = cur.timediff(start);
                while(1){
                    auto e = vis.lower_bound(from);
                    if(e == vis.end() || *e > to) break;
                    belong[*e] = cur.pro - 'A';
                    vis.erase(e);
                }
            }
            pre = cur;
        }
    }
    output();
    return 0;
}
