/*
[HAOI2006]��������
��������һ��b[i]=a[i]-i������������� ����ʵ��ϸ�����Ҳ�ǿ��Եģ����������ڶ��ʾͲ��Ǻܺ����ˣ� 
		���� a ��ԭ���飬���� i,j,i < j ʹ�� i,j �����޸ĵı�Ҫ������ aj-ai ��j-i, ��������ͨ�����м� j-i-1 �����޸��������ϸ��������֮�޽�
	  ��¼��һ��ת�ƣ�g[i]��ʾ��С����
	  g[i]=min{g[j]+w(j+1,i) | f[j]+1=f[i]}
	  w(l,r)��ʾ��b(l..r)�ĳɵ�����������С���ۣ�����ȼ���a�ϸ�����
	   �����jת�Ƶ�i�Ļ���Ҫ��j<i&&a[j]<=a[i]������ô�м�һ����һ��k(k>=j&&k<i)��ʹ��j~k�ĸ߶ȶ���b[j]��k+1~i�ĸ߶ȶ���b[i]���������Ļ��������ŵ�
	   ������ݣ��ɹ� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL; 
const int MAXN=35000+5,INF=0x3f3f3f3f;
int n;
int a[MAXN+3],sta[MAXN+3],top,f[MAXN+3];
LL g[MAXN+3],s1[MAXN+3],s2[MAXN+3];
vector<int> gr[MAXN+3];//gr[i]��ʾf[x]=i������x 
void dp(){
	memset(sta,INF,sizeof(sta));
	sta[0]=-INF;
	for(int i=1;i<=n;i++){
		int t=upper_bound(sta+1,sta+top+1,a[i])-sta;
		f[i]=t;
		top=max(top,t);
		sta[t]=min(sta[t],a[i]);
	}
}
void solve(){
	for(int i=0;i<=n;i++){
		gr[f[i]].push_back(i);
		g[i]=1LL<<60;
	}
	g[0]=0;a[0]=-INF;
	for(int x=1;x<=n;x++)
		for(int i=0;i<gr[f[x]-1].size();i++){//ö��f[x]����һ��ת�� 
			int p=gr[f[x]-1][i];
			if(p>x)break;//���ǲ�����ת�ƣ�ע������(gr[t]���ǵ�����) 
			if(a[p]>a[x])continue;//���ǲ�����ת�� 
			for(int j=p;j<=x;j++)
				s1[j]=abs(a[p]-a[j]),s2[j]=abs(a[x]-a[j]);
			for(int j=p+1;j<=x;j++)
				s1[j]+=s1[j-1],s2[j]+=s2[j-1];
			for(int j=p;j<x;j++)
				g[x]=min(g[x],g[p]+(s1[j]-s1[p])+(s2[x]-s2[j]));
		}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);a[i]-=i;}
	a[++n]=INF;
	dp();
	solve();
	printf("%d\n%lld\n",n-f[n],g[n]);
	return 0;
}
