/*
Sliding Window
���⣺��������ģ��
������ע��q[0]�����ã�ע��Ҫ�����±꣬����ֱ���ж��г��ȣ��ⲻһ���Ϸ��� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000000;
int n,m,t,a[MAXN+3],q[MAXN+3],p[MAXN+3],l=1,r=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]); 
	
	l=1;r=0;q[r]=-INF;
	for(int i=1;i<m;i++){
		while(q[r]>a[i]&&r>=l)r--;
		q[++r]=a[i];
		p[r]=i;
	}
	for(int i=m;i<=n;i++){
		while(q[r]>a[i]&&r>=l)r--;
		q[++r]=a[i];
		p[r]=i;
		while(p[r]-p[l]+1>m)l++;
		printf("%d ",q[l]);
	}
	
	puts("");
	
	l=1;r=0;q[r]=INF;
	for(int i=1;i<m;i++){
		while(q[r]<a[i]&&r>=l)r--;
		q[++r]=a[i];
		p[r]=i;
	}
	for(int i=m;i<=n;i++){
		while(q[r]<a[i]&&r>=l)r--;
		q[++r]=a[i];
		p[r]=i;
		while(p[r]-p[l]+1>m)l++;
		printf("%d ",q[l]);
	}
	return 0;
}

