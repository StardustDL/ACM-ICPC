#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN=100000;
int n,m;
vector<int> g[MAXN+3];
queue<int> q;
int d[MAXN+3];
bool topo(){
    int r=n;
    for(int i=1;i<=n;i++)if(d[i]==0)q.push(i);
    while(!q.empty()){
        int u=q.front();q.pop();r--;
        for(auto v : g[u]){
            if(--d[v]==0)q.push(v);
        }
    }
    return r==0;
}
int main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){d[i]=0;g[i].clear();}
        for(int i=1,u,v;i<=m;i++){
            cin>>u>>v;d[v]++;g[u].push_back(v);
        }
        puts(topo()?"Correct":"Wrong");
    }
    return 0;
}