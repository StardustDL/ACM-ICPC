/*
[POI2006]Kra-The Disks
分析：首先可以把半径做一个前缀min，这样得到一个递减的半径序列，然后对于一个询问x，就是询问这个递减序列[1..lastans-1]的最后一个>=x的位置。
	  把序列变成负的，得到一个递增的，直接调用upper_bound(x)-1即可，判一下在lastans的上面还是下面。 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=300000,INF=0x3f3f3f3f;
int a[MAXN+3],n,m,lst;
int main(){
	scanf("%d%d",&n,&m);a[0]=-INF;
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);a[i]=max(a[i-1],-a[i]);}
	lst=n+1;
	for(int x,i=1;i<=m;i++){
		scanf("%d",&x);
		int t=upper_bound(a+1,a+n+1,-x)-a-1;//取到最后一个等于t的 
		if(t>=lst)lst--;else lst=t;
	}
	printf("%d\n",max(lst,0));//注意这里，最后lst可能为负 
	return 0;
}

