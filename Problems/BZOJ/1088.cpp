/*
[SCOI2005]ɨ��Mine
������ͨ��ö��ǰ���������Ƿ����׾Ϳ���ȷ��״̬�Ƿ���У�ģ�⼴�� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
int a[MAXN+3],b[MAXN+3],n,ans=0; 
bool judge(){
	for(int i=2;i<=n;i++)if((b[i+1]=a[i]-b[i]-b[i-1])<0)return 0;
	return a[n]==b[n]+b[n-1];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	switch(a[1]){
		case 0:
			ans+=judge();
			break;
		case 1:
			memset(b,0,sizeof(b));
			b[1]=1;
			ans+=judge();
			memset(b,0,sizeof(b));
			b[2]=1;
			ans+=judge();
			break;
		case 2:
			memset(b,0,sizeof(b));
			b[1]=b[2]=1;
			ans+=judge();
			break;
	}
	printf("%d",ans);
	return 0;
}

