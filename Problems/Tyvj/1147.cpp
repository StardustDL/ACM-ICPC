/*
����̽��
��������f[i]��ʾ����ֵi��β�����еĳ��ȣ�f[i]=f[i-k]+1 ֻҪ���ն����˳��f[i]���������ľ��ǽ��
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=200010,INF=0x3f3f3f3f;
int n,opt[2*MAXN+3],k,*f=&opt[MAXN],ans=0,t;
int main(){
	scanf("%d%d",&n,&k);
	while(n--){
		scanf("%d",&t);
		ans=max(ans,f[t]=max(f[t],f[t-k]+1));
	}
	printf("%d\n",ans);
	return 0;
}

