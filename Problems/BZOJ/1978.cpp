/*
[BeiJing2010]ȡ����Ϸ game
������DP����������������У�ά��һ��pril[i]=x��ʾ��i������ӵ������±������������±�Ϊx��
	  ������opt[i]=max{opt[pril[j]]+1|j>=l} 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=50000,MAXL=1000000,INF=0x3f3f3f3f;
int opt[MAXN+3],pril[MAXL+3],a[MAXN+3],n,l,ans=0;
int main(){
	scanf("%d%d",&n,&l);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;ans=max(ans,opt[i++])){
		for(int j=1,r=sqrt(a[i]);j<=r;j++){
			if(a[i]%j)continue;
			if(j>=l)opt[i]=max(opt[pril[j]]+1,opt[i]);
			if(a[i]/j>=l)opt[i]=max(opt[pril[a[i]/j]]+1,opt[i]);
			pril[j]=pril[a[i]/j]=i;
		}
	}
	printf("%d",ans);
	return 0;
}

