/*
[Usaco2014 Open]Fair Photography
��������0����-1������������޸���ô��last[x]��¼ǰ׺��Ϊx�ĵ�һ��λ�ã�Ȼ��ɨһ��
		�����޸ľ��ǣ� �赱ǰλ��pos��ǰ׺��Ϊx����pos-last[x]��pos-last[x+2]�����ܸ��´�
		������֮ǰ
		for(int i=2*n;i>=0;i�C)
			last[i]=min(last[i+2],last[i]);
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000000,INF=0x3f3f3f3f;
struct data{
	int p,v;
	bool operator <(const data &d)const{
		return p<d.p;
	}
}ds[MAXN+3];
int n,lst[2*MAXN+3],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char s[5];scanf("%d %s",&ds[i].p,s);
		if(s[0]=='W')ds[i].v=-1;else ds[i].v=1;
	}
	sort(ds+1,ds+n+1);
	memset(lst,INF,sizeof(lst)); 
	int sum=n;lst[sum]=ds[1].p;
	for(int i=1;i<n;i++){
		sum+=ds[i].v;
		lst[sum]=min(lst[sum],ds[i+1].p);
	}
	for(int i=2*n;i>=0;i--)lst[i]=min(lst[i],lst[i+2]);
	sum=n;ans=0;
	for(int i=1;i<=n;i++){
		sum+=ds[i].v;
		ans=max(ans,ds[i].p-lst[sum]);
	}
	printf("%d\n",ans);
	return 0;
}

