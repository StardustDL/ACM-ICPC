/*
Communication System
���⣺N�����ӣ�ÿ������i����ѡ��Mi����ͬ��Ʒ��ÿ����Ʒ�������ԣ�bj,pj����ÿ������ѡti����Ʒ��
	  ��Ҫ�����min{b[ti]}/sum{p[ti]}
������������ֵ���������Ϊ��С��sum�����min������DPת��ö�ٷ��� 
	  DP��״̬��opt[i][j]��ʾ����ǰi�����ӣ�min{b[ti]}=jʱ����Сsum{p[ti]} 
	  ���У�opt[i][j]=min{opt[i-1][min(j,b[k])]+p[k]|1<=k<=mi} 
	  ע��i=1ʱ�ı߽紦�����ö��opt[n][i]��ע���е�״̬�ǲ��ɴ�� 
	  �߶��ߴ������Խ�ʡ�ռ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=100,MAXV=100;
int opt[MAXN+3][MAXV+3],n,cnt,a[MAXN+3],b[MAXN+3];
/*double dp(){
	memset(opt,INF,sizeof(opt));
	for(int i=0;i<=MAXV;i++)opt[0][i]=0; 
	for(int i=1;i<=n;i++){
		for(int j=MAXV;j>=0;j--){
			//opt[i][j]=opt[i-1][j];
			for(int k=1;k<=cnt[i];k++){
				if(a[i][k]>j)continue;
				opt[i][j]=min(opt[i-1][j],opt[i-1][j-a[i][k]]+b[i][k]);
			}
		}
	}
	double ans=0;
	for(int i=MAXV;i>=0;i--){
		if(abs(opt[n][i]-INF)<1e-5)continue;
		ans=max(ans,i*1.0/opt[n][i]);
	}
	return ans;
}
void input(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&cnt[i]);
		for(int j=1;j<=cnt[i];j++){
			scanf("%d%d",&a[i][j],&b[i][j]);
		}
	}
}*/
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(opt,-1,sizeof(opt));
		int maxa=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&cnt);
			for(int j=1;j<=cnt;j++){
				scanf("%d%d",&a[j],&b[j]);
				maxa=max(maxa,a[j]);
			}
			if(i==1){
				for(int j=1;j<=cnt;j++){
					opt[1][a[j]]=b[j];
				}
				continue;
			}
			for(int j=0;j<=maxa;j++){
				if(opt[i-1][j]==-1)continue;
				for(int k=1;k<=cnt;k++){
					int t=min(a[k],j);
					opt[i][t]=min(opt[i-1][j]+b[k],(opt[i][t]==-1?INF:opt[i][t]));
				}
			}
		}
		double ans=0;
		for(int i=1;i<=maxa;i++){
			if(opt[n][i]==-1)continue;
			ans=max(ans,i*1.0/opt[n][i]);
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}

