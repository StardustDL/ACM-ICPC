/*
River Hopscotch
���⣺ţҪ���Ӷ԰�������Ӱ���ֱ��һ�����ϣ�������N��ʯͷ�������Ӱ����L���Լ�ÿһ��ʯͷ��ţ���ںӰ��ľ��룬
          ����ȥ��M��ʯͷ��Ҫ��ȥ��M��ʯͷ��ʣ�µ�ʯͷ֮���Լ�ʯͷ��Ӱ�����С��������ֵ��
���������ּ��ɣ������ڵ�ʯͷ�ľ���С�ڵ���mid���Ϳ���ȥ�� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=50000;
int l,m,n,d[MAXN+3];
inline bool check(int val){
	int ans=0;
	for(int i=1,last=0;i<=n+1;i++){
		if(val>=d[i]-d[last])ans++;
		else last=i;
	}
	return ans<=m;
}
int erfen(int l,int r){
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(!check(mid))r=mid-1;
		else l=mid+1;
	}
	return l;
}
int main(){
	scanf("%d%d%d",&l,&n,&m);
	d[0]=0;d[n+1]=l;
	for(int i=1;i<=n;i++)scanf("%d",&d[i]);
	sort(d+1,d+n+1);
	printf("%d\n",erfen(0,l));
	return 0;
}

