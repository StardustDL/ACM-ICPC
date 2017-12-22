/*
[POI2007]天然气管道Gaz
分析：1.天然井必须向南或向东建设管道
      2.是曼哈顿距离而不是欧几里得距离
      把行列分开考虑，对于答案来说，所有气井的x都是负的，y都是正的，而中转站则相反 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
typedef long long LL;
int n;
LL ans=0;
int main(){
	scanf("%d",&n); 
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		ans-=x,ans+=y;
	}
	for(int i=1,x,y;i<=n;i++){
		scanf("%d%d",&x,&y);
		ans+=x,ans-=y;
	}
	printf("%lld",ans);
	return 0;
}

