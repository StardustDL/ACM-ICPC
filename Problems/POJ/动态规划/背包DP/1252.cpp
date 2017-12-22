/*
Euro Efficiency
���⣺���������⡣������ֽ������һ��һ����1�������ٵ�������ֽ�Ҵճ�1-100����ֵ������1-100��Ҫ��ֽ�����е����ֵ�����ܺ�/100��ע��ֽ�ҿɼӿɼ�
��������ȫ������BFS��ע����ȫ�������Ϊ������ʱ�򷴹�������
	  ��������������ƣ����ڵ�һ������1������ÿ���������100����������������أ���Χ�����ֵ���50�Σ����Ϊ5000������ʵ���������ĸ�����Ӱ�죬Զ������������� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1500;
int p[6],opt[(MAXN<<2)+3],T;
int main(){
	for(scanf("%d",&T);T;T--){
		for(int i=0;i<6;i++)scanf("%d",&p[i]);
		memset(opt,INF,sizeof(opt)); 
		opt[0]=0;
		for(int i=0;i<6;i++)
			for(int j=p[i];j<=MAXN;j++)opt[j]=min(opt[j],opt[j-p[i]]+1);
		for(int i=0;i<6;i++)
			for(int j=MAXN-p[i];j>=1;j--)opt[j]=min(opt[j],opt[j+p[i]]+1);
		int sum=0;
		for(int i=1;i<=100;i++)sum+=opt[i];
		printf("%.2lf %d\n",sum/100.0,*max_element(opt+1,opt+100+1));
	}
	return 0;
}

