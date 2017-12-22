/*
Milking Time
题意：你有一头奶牛，你能够在一定的时间里挤奶。而且挤奶量也不同，每次挤奶要休息r时间，问你最大可以挤多少奶。
分析：对时间段dp，然后就是两个for的事了。只要前面能满足条件的状态就可以转移过来，然后取最大，不过要先排序。
	  转移：opt[i]=max{opt[j],j.y+r<=i.x} 
*/
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN=1000;
struct data{
	int x,y,w;
	bool operator <(const data &d)const{
		return x<d.x||x==d.x&&y<d.y;
	}
}ds[MAXN+3];
int n,m,r,opt[MAXN+3];
int main(){
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=m;i++)scanf("%d%d%d",&ds[i].x,&ds[i].y,&ds[i].w);
	sort(ds+1,ds+m+1);
	for(int i=1;i<=m;i++)opt[i]=ds[i].w;
	for(int i=1;i<=m;i++)
		for(int j=0;j<i;j++)
			if(ds[i].x>=ds[j].y+r)opt[i]=max(opt[i],opt[j]+ds[i].w);
	printf("%d\n",*max_element(opt+1,opt+m+1));
	return 0;
}
