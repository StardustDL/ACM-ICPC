/*
[Usaco2007 Dec]��ʯ����
������01������Ȼ����ʵ���Ӷ���nm��= = 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int f[12880+3],n,m,w,d;
int main(){
	scanf("%d%d",&n,&m);
	for(;n;n--){
		scanf("%d%d",&w,&d);
		for(int j=m;j>=w;j--)f[j]=max(f[j],f[j-w]+d);
	}
	printf("%d\n",f[m]);
	return 0;
}

