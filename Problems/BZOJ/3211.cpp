/*
������������
��������������һ����Ȥ�����ʣ�sqrt(1) = 1,sqrt(0) = 0���������е����־������޴εĿ��������㶼����1��
		����������ά����״���飬���ò��鼯ά��ÿ�����ұߵ�һ������1�����֣�Ȼ���������ţ���һ�����ֱ��1��ʱ��Ͱ�������ڲ��鼯�еĸ����������ұߵ����ĸ����ϡ����޸����������ʱ��Ϳ�������������1�ˡ�
		�߶������������Ƕ�ÿһ���㱩�������ţ�Ȼ�������ĵ�Ȩ���1��ʱ��ʹ�һ����ǣ��´β���������ˡ����߶���ά���� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f;
typedef long long LL;
int n,a[MAXN+3],m;
LL c[MAXN+3];
#define lowbit(x) (x&-x)
void add(int x,int ad){
	for(;x<=n;x+=lowbit(x))c[x]+=ad;
}
LL sum(int x){
	LL ans=0;
	for(;x;x-=lowbit(x))ans+=c[x];
	return ans;
}
int pa[MAXN+3];
int find(int x){
	return pa[x]==x?x:pa[x]=find(pa[x]); 
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);add(i,a[i]);
		if(a[i]<=1)pa[i]=i+1;
		else pa[i]=i;
	}
	pa[n+1]=n+1;
	scanf("%d",&m);
	for(int i=1,x,l,r;i<=m;i++){
		scanf("%d%d%d",&x,&l,&r);
		if(x==1){printf("%lld\n",sum(r)-sum(l-1));}
		else{
			for(l=find(l);l<=r;l=find(l+1)){
				add(l,-a[l]);
				a[l]=sqrt(a[l])+(1e-7);
				add(l,a[l]);
				if(a[l]<=1)pa[l]=find(l+1);
			}
		}
	}
	return 0;
}


