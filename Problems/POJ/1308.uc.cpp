/*
Is It A Tree?
分析：刚开始想用入度来判断，但就是WA。。。只好用并查集了 
*/
#include<iostream>
#include<cstdio>
#include<bitset>
#include<cstring>
using namespace std;
const int MAXN=100000;
int n,m,a,b,rd[MAXN+3],kase=0;
bitset<MAXN+3> vis;
bool check(){
	int k=0;
	for(int i=1;i<=n;i++)k+=vis[i];
	n=k;
	if(n==0)return true;
	//if(m>=n)return false;
	int t=0;
	for(int i=1;i<=n;i++){
		if(rd[i]==0)t++;
		else if(rd[i]!=1)return false;
	}
	return t==1;
}
int main(){
	while(1){
		cin>>a>>b;if(a<0||b<0)break;
		if(a==0||b==0){
			printf("Case %d is%sa tree.\n",++kase,check()?" ":" not ");
			memset(rd,0,sizeof(rd));n=m=0;vis=0;
		}
		else{
			vis[a]=vis[b]=1;
			n=max(n,max(a,b));
			m++;
			rd[b]++;
		}
	}
	return 0;
}
