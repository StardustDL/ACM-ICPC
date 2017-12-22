/*
»»¿À
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
struct data{
	int to,next,w;
}e[12401];
int t,c,ts,te,sum=0,head[2501],dis[2501];
void insert(int u,int v,int w){
	sum++;
	e[sum].to=v;
	e[sum].next=head[u];
	e[sum].w=w;
	head[u]=sum;
}
void spfa(){
	queue<int> q;
	q.push(ts);
	dis[ts]=0;
	int s;
	while(!q.empty()){
		s=head[q.front()];
		while(s!=0){
			if(dis[e[s].to]>dis[q.front()]+e[s].w){
				dis[e[s].to]=dis[q.front()]+e[s].w;
				q.push(e[s].to);
			}
			s=e[s].next;
		}
		q.pop();
	}
}
int main(){
	memset(dis,127/3,sizeof(dis));
	scanf("%d %d %d %d",&t,&c,&ts,&te);
	for(int i=1;i<=c;i++){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		insert(x,y,z);
		insert(y,x,z);
	}
	spfa();
	printf("%d",dis[te]);
	return 0;
}
