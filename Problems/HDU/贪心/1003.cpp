/*
Max Sum
���⣺������������кͣ������ʼ��ͽ����㣨��һ���� 
������̰�ģ�ά����ǰ�����ͣ���<0������0�������Ը��´𰸣�ͬʱ��¼�˵�
	  DP˼·��f[i]��ʾһ��ѡ��i����ǰi���������ֵ��f[i]=max(f[i-1]+a[i],0)������¼���䲢�����㣨�����ǵ�һ�����䣩
	  ע�������Ҫ�ж������ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int n,a[MAXN+3],opt[MAXN+3];
int main(){
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		scanf("%d",&n);
		//memset(opt,0,sizeof(opt));
		int ans=-INF,l,r,t=0,p=1;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			t+=a[i];
			if(t>ans){
				ans=t;
				l=p;r=i;
			}
			if(t<0){
				p=i+1;t=0;
			}
		}
		printf("Case %d:\n%d %d %d\n",k,ans,l,r);
		if(k<T)puts("");
	}
	return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100000;
int n,a[MAXN+3],opt[MAXN+3];
int main(){
	int T;
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		scanf("%d",&n);
		//memset(opt,0,sizeof(opt));
		int ans=-INF,l,r,t;
		for(int i=1;i<=n;i++)scanf("%d",&a[i]);
		for(int i=n;i>=1;i--){
			opt[i]=max(opt[i+1]+a[i],0);
			if(opt[i]>=ans){
				ans=opt[i];l=i;
			}
		}
		r=l-1;t=0;
		while(t!=ans){
			t+=a[++r];
		}
		printf("Case %d:\n%d %d %d\n\n",k,ans,l,r);
	}
	return 0;
}
*/
