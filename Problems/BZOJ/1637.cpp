/*
[Usaco2007 Mar]Balanced Lineup
��������0��ţ���-1��Ȼ��ά��ǰ׺�ͣ��������Ʋ�֣�ʹ����ȵ�����ụ����������������ǰ�ߵ�ţ��ǰ��һ��ţ��ǰ׺�͵�������������ߵ�ţ��ǰ׺��
	  ɨһ�鼴�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=50000,INF=0x3f3f3f3f;
struct data{
	int p,w;
	bool operator <(const data &d)const{
		return p<d.p;
	}
}a[MAXN+3];
int vis[MAXN*2+3],n,sum=0,ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d%d",&a[i].w,&a[i].p);if(!a[i].w)a[i].w=-1;}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=a[i].w;
		if(vis[sum])ans=max(ans,a[i].p-vis[sum]);
		else vis[sum]=a[i+1].p;
	}
	printf("%d\n",ans);
	return 0;
}

