/*
[HEOI2015]小Z的房间
分析：生成树计数 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const LL MOD=1000000000,MAXN=100;
LL c[MAXN+3][MAXN+3];
LL det(int n){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)(c[i][j]+=MOD)%=MOD;
	bool flg=false;LL ans=1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			LL a=c[i][i],b=c[j][i];
			while(b){
				LL t=a/b;a%=b;swap(a,b);
				for(int k=i;k<=n;k++)
					((c[i][k]-=t*c[j][k]%MOD)+=MOD)%=MOD;
				for(int k=i;k<=n;k++)swap(c[i][k],c[j][k]);
				flg=!flg;
			}
		}
		if(!c[i][i])return 0;
		(ans*=c[i][i])%=MOD;
	}
	return flg?((MOD-ans)%MOD):ans;
}
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
int n,m,id[MAXN+3][MAXN+3],cnt=0;char ch;
char mp[MAXN+3][MAXN+3];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%s",mp[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='.')id[i][j]=++cnt;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1,p,q;j<=m;j++){
			if(mp[i][j]!='.')continue;
			p=id[i][j];
			for(int k=0;k<4;k++){
				int x=i+dx[k],y=j+dy[k];
				if(x<1||x>n||y<1||y>m||mp[x][y]!='.')continue;
				q=id[x][y];c[p][p]++;c[p][q]--;
			}
		}
	}
	printf("%lld\n",det(cnt-1));
	return 0;
}

