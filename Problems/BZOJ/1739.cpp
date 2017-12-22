/*
[Usaco2005 mar]Space Elevator 太空电梯
分析：按高度上限，从低到高贪心的放。背包是不合适的。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=400,UP=40000,INF=0x3f3f3f3f;
struct data{
	int c,h,a;
	bool operator < (const data &d)const{
		return a<d.a;
	}
}ds[MAXN+3];
int n;
bool can[UP+3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&ds[i].h,&ds[i].a,&ds[i].c);
	sort(ds+1,ds+n+1);
	can[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=ds[i].a;j>=0;j--)
			if(can[j])
				for(int k=1;k<=ds[i].c && k*ds[i].h+j<=ds[i].a;k++)
					can[k*ds[i].h+j]=can[k*ds[i].h+j]||can[j];
	for(int i=UP;i>=0;i--)
		if(can[i]){printf("%d\n",i);break;} 
	return 0;
}

