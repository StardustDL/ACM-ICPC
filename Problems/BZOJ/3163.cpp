/*
[Heoi2013]Eden���±�������
������ά��һ��ǰ׺���ر�����һ����׺���ر���
	  ÿ��ѯ��ʱ ö��ǰ��ѡ���ٺͺ���ѡ���� ����ͳ�ƴ𰸼��� 
	  ���Ӷȱ������ܻᳬʱ�ġ��������ǹ��� 
*/
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int n,q,a[MAXN+3],b[MAXN+3],c[MAXN+3];
int f[MAXN+3][MAXN+3],g[MAXN+3][MAXN+3];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1;i<=n;i++){
		memcpy(f[i],f[i-1],sizeof(f[i-1]));
		int up=c[i],*t=f[i];
		for(int j=1;up;j=min(j<<1,up)){
			for(int k=1000;k>=j*a[i];k--)t[k]=max(t[k],t[k-j*a[i]]+j*b[i]);
			up-=j;
		}
	}
	for(int i=n;i>=1;i--){
		memcpy(g[i],g[i+1],sizeof(g[i+1]));
		int up=c[i],*t=g[i];
		for(int j=1;up;j=min(j<<1,up)){
			for(int k=1000;k>=j*a[i];k--)t[k]=max(t[k],t[k-j*a[i]]+j*b[i]);
			up-=j;
		}
	}
	scanf("%d",&q);
	for(int d,e;q;q--){
		scanf("%d%d",&d,&e);
		int ans=0;d++;
		for(int i=0;i<=e;i++)ans=max(ans,f[d-1][i]+g[d+1][e-i]);
		printf("%d\n",ans);
	}
	return 0;
}

