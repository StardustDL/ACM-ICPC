/*
Pollution
���⣺һ������ͼ��һЩ������ֵ��ÿ��λʱ���ڣ�һ������������ڵĵ�ƽ��������ֵ��w[i]/d[i]�����ʵ����е��ֵ���ٸı�ʱ��ÿ�����ֵ�Ƕ��� 
���������Խ���Ŀ�еġ����ٱ仯������ƽ�⣨��=��������֪ƽ��ʱÿ�����ֵ=������ͨ����ֵ*����ǰ�ڵ�Ķ���/��ͨ�����ܶ�������������ܶ���ָ���и���������֮�� 
	  ά����ͨ��ʹ�ò��鼯���ɣ�ע��µ����� 
*/ 
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100;
int n,m,pa[MAXN+3],d[MAXN+3],cnt[MAXN+3];
double w[MAXN+3],sum[MAXN+3];
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]); 
}
void merge(int a,int b){
	d[a]++;d[b]++;//��������ֱ�+1 
	a=find(a),b=find(b);
	if(a==b) cnt[a]+=2;
	else{
		pa[a]=b;
		sum[b]+=sum[a];
		cnt[b]+=cnt[a]+2;//�ܶ���+2 
	}
}
void input(){
	memset(w,0,sizeof(w));
	memset(sum,0,sizeof(sum));
	memset(d,0,sizeof(d));
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=n;i++){
		scanf("%lf",&w[i]);
		sum[i]=w[i];cnt[i]=0;pa[i]=i;
	}
	while(m--){
		scanf("%d %d",&x,&y);
		merge(x,y);
	}
}
double get(int x){
	if(!d[x])return sum[x];//�µ� 
	return d[x]*sum[find(x)]/cnt[find(x)];
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		input();
		for(int i=1;i<=n;i++)printf("%.3lf\n",get(i));
		puts("");
	}
	return 0;
}

