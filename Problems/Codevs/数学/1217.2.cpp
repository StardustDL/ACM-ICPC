/*
�����
��������Ϊ������ֻ�����������Զ��ִ𰸣����ǰK���������Ƿ���в�֧�ֵ����
	  ��ǰ׺��ʵ�֣����ڶ���(l,r,d)����������a[l]+=d,a[r+1]-=d������ÿ�����ǰ׺�;��Ǵ˵�������� 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000;
int n,m,r[MAXN+3],d[MAXN+3],s[MAXN+3],t[MAXN+3],q[MAXN+3];
bool work(int k){
	memset(q,0,sizeof(q));
	for(int i=1;i<=k;i++){
		q[s[i]]-=d[i];
		q[t[i]+1]+=d[i];
	}
	long long sum=0;
	for(int i=1;i<=n;i++)
		if(-(sum+=q[i])>r[i])return false;
	return true;
}
int ef(int l,int r){
	while(l<r){
		int mid=(l+r)>>1;
		if(work(mid))l=mid+1;
		else r=mid;
	}
	return l;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&r[i]);
	for(int i=1;i<=m;i++)
		scanf("%d %d %d",&d[i],&s[i],&t[i]);
	int ans=ef(1,m+1);
	if(ans>m)printf("0");
	else printf("-1\n%d",ans);
	return 0; 
}
