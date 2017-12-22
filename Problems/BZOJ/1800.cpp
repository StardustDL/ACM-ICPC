/*
[Ahoi2009]fly 飞行棋
分析：维护前缀和，枚举模拟 
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,ans,tot;
int t[21],dis[21];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&t[i]);
	    dis[i]=dis[i-1]+t[i];
	    tot+=t[i];
	}
	for(int a=1;a<=n;a++)
		for(int b=a+1;b<=n;b++)
			for(int c=b+1;c<=n;c++)
				for(int d=c+1;d<=n;d++)
				    if((dis[b]-dis[a]==dis[d]-dis[c])&&(tot-dis[d]+dis[a]==dis[c]-dis[b]))
				        ans++;
	printf("%d",ans);
	return 0;
}
