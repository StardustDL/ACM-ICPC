/*
Blocks
���⣺��һЩ����ɫ�ĺ��ӣ����һЩ���ڵĺ��Ӷ�����ͬ����ɫ,������������(��������ڵĻ�)������(��������ڵĻ�)��������ɫ,���ǳ�֮Ϊ���жΡ���
	  ÿһ��,���Ե���һ������,Ȼ����������ʧ����������k���������,���õ�k * k�㡣�����ŵ��� 
����������DP��һĿ��Ȼ������״̬����̫����⣺
	  opt[i][j][k]��ʾ[i..j]Ȼ��ѵ�j�κ�����k�����Ӻϲ������Ž�
	  ��ת��Ϊ��
	  	1.ֱ����ȥ:opt[i][j][k]=opt[i][j-1][0]+(len[j]+k)^2
		2.��j����ͬk��һ���[i..j]��ĳһ��һ��ϲ���opt[i][j][k]=max{opt[i][p][len[j]+k]+opt[p+1][j-1][0]|i<=p<j&&color[p]==color[j]} 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#define sqr(x) ((x)*(x)) 
using namespace std;
const int INF=0x3f3f3f3f,MAXN=200;
int col[MAXN+3],len[MAXN+3],opt[MAXN+3][MAXN+3][MAXN+3],n,cntc,after[MAXN+3];
void input(){
	scanf("%d",&n);
	int x;scanf("%d",&x);
	cntc=1;col[1]=x;len[1]=1;
	for(int i=2;i<=n;i++){
		scanf("%d",&x);
		if(x==col[cntc])len[cntc]++;
		else {
			col[++cntc]=x;
			len[cntc]=1;
		}
	}
	n=cntc;
	for(int i=1;i<=n;i++){//ͳ��i֮�󣨲���i������i��ɫ��ͬ�ĸ����� 
		after[i]=0;
		for(int j=i+1;j<=n;j++)if(col[j]==col[i])after[i]+=len[j];
	}
}
int dp(){
	memset(opt,0,sizeof(opt));
	/*for(int i=1;i<=n;i++){
		for(int k=0;k<=after[i];k++){
			opt[i][i][k]=sqr(len[i]+k);
		}
	}*/
	for(int le=1;le<=n;le++){
		for(int i=1;i+le-1<=n;i++){
			int j=i+le-1;
			for(int k=0;k<=after[j];k++){
				opt[i][j][k]=opt[i][j-1][0]+sqr(len[j]+k);
				for(int p=i;p<j;p++){
					if(col[p]!=col[j])continue;
					opt[i][j][k]=max(opt[i][j][k],opt[i][p][len[j]+k]+opt[p+1][j-1][0]);
				}
			}
		}
	}
	return opt[1][n][0];
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		input();
		printf("Case %d: %d\n",i,dp());
	}
	return 0;
}

