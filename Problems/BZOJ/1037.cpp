/*
[ZJOI2008]���վۻ�Party
������cnt[i][j][k][l]��ʾ����i�ˣ�Ů��j�ˣ���-Ů=k��Ů-��=l�ķ�����
	  ת�Ƽ��� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=150,MAXK=20,INF=0x3f3f3f3f,MOD=12345678;
int cnt[MAXN+3][MAXN+3][MAXK+3][MAXK+3],n,m,K; 
int main(){
	scanf("%d%d%d",&n,&m,&K);
	cnt[0][0][0][0]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;k<=K;k++){
				for(int l=0;l<=K;l++){
					int &t=cnt[i][j][k][l];
					if(k+1<=K){(cnt[i+1][j][k+1][max(l-1,0)]+=t)%=MOD;
					if(l+1<=K){(cnt[i][j+1][max(k-1,0)][l+1]+=t)%=MOD;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=K;i++)
		for(int j=0;j<=K;j++)(ans+=cnt[n][m][i][j])%=MOD;
	printf("%d\n",ans);
	return 0;
}

