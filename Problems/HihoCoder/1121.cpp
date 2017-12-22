#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=10000;
vector<int> g[MAXN+3];
int n,m;
int c[MAXN+3];
inline void init(){
    for(int i=1;i<=n;i++){
        g[i].clear();
        c[i]=-1;
    }
}
bool judge(int s){
    for(int i=0;i<g[s].size();i++){
        int v=g[s][i];
        if(c[v]==-1){
            c[v]=c[s]^1;
            if(judge(v)==false)return false;
        }
        else if(c[v]==c[s])return false;
    }
    return true;
}
int main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>m;init();
        while(m--){
            int x,y;cin>>x>>y;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        bool flg=true;
        for(int i=1;i<=n&&flg;i++){//The graph can be disconnected
            if(c[i]==-1){
                c[i]=0;
                flg&=judge(i);
            }
        }
        puts(flg?"Correct":"Wrong");
    }
    return 0;
}