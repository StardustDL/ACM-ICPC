/*
Cow Exhibition
���⣺����N����Ʒ����i����Ʒ����������A_i��B_i��������ѡȡ���ɸ���Ʒ��ʹ��sum{A_i + B_i}���ͬʱsum{A_i}��sum{B_i}���Ǹ���sum{}��ʾ��ͣ���  
������������Ŀ�е�����i,suma,sumb
	  ��suma���������sumb���ɼ�ֵ�������Ϊ��һ�������� 
	  ��ע��suma�и��������ڸ������ת�ƣ���ѭ����������������
	  ����������ˣ�ע��ά����������mx,mn,�ͳ�ʼ����Сֵ��f[0]=0
	  һ�������������Ƶķ�����ʹ��һ��ָ�룬ָ�������м� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN=100,MAXV=100*1000+10,INF=0x3f3f3f3f;
int mn=0,mx=0,n,a[MAXN+3],b[MAXN+3],opt[MAXV+3],ans=0;
int *f=&opt[MAXV/2];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	for(int i=1;i<=n;i++)if(a[i]>0)mx+=a[i];else mn+=a[i];
	for(int i=mn;i<=mx;i++)f[i]=-INF;
	f[0]=0;mx=mn=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0)
			for(int j=(mx+=a[i]);j-a[i]>=mn;j--)
				f[j]=max(f[j],f[j-a[i]]+b[i]);
		else
			for(int j=(mn+=a[i]);j-a[i]<=mx;j++)
				f[j]=max(f[j],f[j-a[i]]+b[i]);
	}
	for(int i=0;i<=mx;i++)
		if(f[i]>=0)ans=max(f[i]+i,ans);
	printf("%d\n",ans); 
	return 0;
}

