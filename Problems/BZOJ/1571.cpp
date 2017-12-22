/*
[Usaco2009 Open]��ѩ��Ski
��������f[i][j]��ʾʱ��Ϊi������Ϊt�����Ž⣬��ô������ת��
	  f[i][j]=f[i-1][j]
	  		  f[�γ̿�ʼ][��������]
			  f[i-ĳ��ѩʱ��][j]     <��������>
		Ԥ������ͬһʱ�������������ͬ�Ŀγ�������ʼ�ĺ����㻬ѩ����a����̻�ѩʱ�䣨��һ�����ţ�
		Ȼ����g[i]=max{f[i][j]}�������ڶ���ת�ƾ�O(1)�� 
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
int f[MAXN+3][100+3],g[MAXN+3],les[MAXN+3][100+3],ski[100+3],T,s,n;
int main(){
	scanf("%d%d%d",&T,&s,&n);
	memset(f,128,sizeof(f));//����Сֵ��-2139062144����2�ᱬ������ 
	memset(ski,INF,sizeof(ski));
	for(int i=1,a,b,c;i<=s;i++){
		scanf("%d%d%d",&a,&b,&c);
		les[a+b-1][c]=max(les[a+b-1][c],a);
	}
	for(int i=1,a,b;i<=n;i++){
		scanf("%d%d",&a,&b);
		for(int j=a;j<=100;j++)ski[j]=min(ski[j],b);
	}
	f[0][1]=0;g[0]=0; 
	for(int i=1;i<=T;i++){
		for(int j=1;j<=100;j++){
			f[i][j]=f[i-1][j];
			if(les[i-1][j])f[i][j]=max(f[i][j],g[les[i-1][j]]);
			if(ski[j]&&i-ski[j]>=0)f[i][j]=max(f[i][j],f[i-ski[j]][j]+1);
			g[i]=max(g[i],f[i][j]);
		}
	}
	printf("%d\n",g[T]);
	return 0;
}
