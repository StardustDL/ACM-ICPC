/*
Get Luffy Out
题意：m个门，每个门上有两把锁，打开一个就可以通过 
		2n个钥匙，每两个绑在一起，只能选用一个 ，选了一个，另一个就被废弃。  
		问最多可以通过几扇门？ 
分析：二分查找能上的层数。每次对于一个确定的层数，也就确定了哪些门需要开。变为一个2-sat问题。其中两两一组的钥匙就是图中的节点。当然图中还需要一些矛盾。矛盾如下，某层有x,y两种锁，x的钥匙a与钥匙b一组，y的要是c与钥匙d一组。如果在某次选了钥匙b，那么本层的x将无法被打开，只能开y，就必须选钥匙c，不能选钥匙d。所以钥匙b与钥匙d是矛盾的。
	  	a、b绑在一起，则选a就不选b，选b就不选a，建边a->!b,b->!a   
		c、d在同一个门上，则不开c就开d，不开d就开c，建边!c->d,!d->c   
	  注意：拆点，n会翻倍 
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;
const int NN=1300*4;
int n,m,dfn[NN],low[NN],tmp,cnt,fa[NN],vis[NN];
vector<int>mp[NN];
stack<int> mystack;
int key1[NN],key2[NN];
int door1[NN],door2[NN];
void init(){
    for(int i=0;i<n*2*2+10;i++)mp[i].clear();
    tmp=0;
    cnt=0;
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(vis,0,sizeof(vis));
    memset(fa,0,sizeof(fa));
    memset(low,0,sizeof(low));
}
void tarjan(int u){
    vis[u]=1;
    dfn[u]=low[u]=tmp++;
    mystack.push(u);
    for(int i=0;i<mp[u].size();i++){
        int v=mp[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[v],low[u]);
        }
        else if(vis[v])low[u]=min(dfn[v],low[u]);
    }
    if(dfn[u]==low[u]){
		cnt++;int t;
		do{
			t=mystack.top();
        	mystack.pop();
        	vis[t]=0;
        	fa[t]=cnt;
      	}while(t!=u);
    }
}
void built(int to){
	init();
	for(int i=1;i<=n;i++){
    	mp[key1[i]*2].push_back(key2[i]*2+1);
    	mp[key2[i]*2].push_back(key1[i]*2+1);
  	}
  	for(int i=1;i<=to;i++){
  	    mp[door1[i]*2+1].push_back(door2[i]*2);
   	   	mp[door2[i]*2+1].push_back(door1[i]*2);
  	}
}
bool solve(){
    for(int i=0;i<2*n*2;i++)
        if(!dfn[i])tarjan(i);
    for(int i=0;i<2*n;i++)
        if(fa[i*2]==fa[i*2+1])return 0;
    return 1;
}
int main(){
   	while(cin>>n>>m,n+m){
   		for(int i=1;i<=n;i++)
    		cin>>key1[i]>>key2[i];
    	for(int j=1;j<=m;j++)
    		cin>>door1[j]>>door2[j];
    	int L=0,R=m,mid,ans=0;
  		while(L<=R){
	        mid=(L+R)/2;
        	built(mid);
        	if(solve())ans=max(ans,mid),L=mid+1;
        	else R=mid-1;
    	}
   		cout<<ans<<endl;
  	}
  	return 0;
}
