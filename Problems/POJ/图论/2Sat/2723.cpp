/*
Get Luffy Out
���⣺m���ţ�ÿ������������������һ���Ϳ���ͨ�� 
		2n��Կ�ף�ÿ��������һ��ֻ��ѡ��һ�� ��ѡ��һ������һ���ͱ�������  
		��������ͨ�������ţ� 
���������ֲ������ϵĲ�����ÿ�ζ���һ��ȷ���Ĳ�����Ҳ��ȷ������Щ����Ҫ������Ϊһ��2-sat���⡣��������һ���Կ�׾���ͼ�еĽڵ㡣��Ȼͼ�л���ҪһЩì�ܡ�ì�����£�ĳ����x,y��������x��Կ��a��Կ��bһ�飬y��Ҫ��c��Կ��dһ�顣�����ĳ��ѡ��Կ��b����ô�����x���޷����򿪣�ֻ�ܿ�y���ͱ���ѡԿ��c������ѡԿ��d������Կ��b��Կ��d��ì�ܵġ�
	  	a��b����һ����ѡa�Ͳ�ѡb��ѡb�Ͳ�ѡa������a->!b,b->!a   
		c��d��ͬһ�����ϣ��򲻿�c�Ϳ�d������d�Ϳ�c������!c->d,!d->c   
	  ע�⣺��㣬n�ᷭ�� 
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
