/*
���̷ָ�
�����������ʽ�Ƚϸ��ӣ��Ƚ�����Σ�X��ʾ��ֵ  
		S^2 = 1/n��(Xi - X)^2
		   = 1/n(n*X^2 + ��Xi^2 - 2*X��Xi)
		   = 1/n��Xi^2 - X^2;   
		������С�� ��Xi^2����
		DP����Ԥ����ÿ�����εĺ͵�ƽ����Ȼ����������ࣺ�����У�������
		  ÿ���ж��λ��[x1..x2][y1..y2] 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=9,MAXK=15;
typedef int MAP[MAXN][MAXN][MAXN][MAXN]; 
MAP opt[MAXK+3],sum;
int g[MAXN][MAXN],K; 
void init(){
	for(int i=0;i<MAXN;i++){//����Ҫ�ദ���һλ��9*9������ΪDPʱ���õ������ĵ��� 
		for(int j=0;j<MAXN;j++){
			for(int k=i;k<MAXN;k++){
				for(int l=j;l<MAXN;l++){
					int ans=0;
					for(int p=i;p<=k;p++)
						for(int q=j;q<=l;q++)
							ans+=g[p][q];
					sum[i][j][k][l]=sum[i][l][k][j]=sum[k][l][i][j]=sum[k][j][i][l]=ans*ans;
				}
			}
		}
	}
}
int dp(int k,int x1,int y1,int x2,int y2){
	int &C=opt[k][x1][y1][x2][y2];
	if(C>=0)return C;
	if(k==K-1)return sum[x1][y1][x2][y2];
	C=INF;
	for(int i=x1;i<=x2;i++)
		C=min(C,min(dp(k+1,x1,y1,i,y2)+sum[i+1][y1][x2][y2],dp(k+1,i+1,y1,x2,y2)+sum[x1][y1][i][y2]));
	for(int i=y1;i<=y2;i++){
		C=min(C,min(dp(k+1,x1,y1,x2,i)+sum[x1][i+1][x2][y2],dp(k+1,x1,i+1,x2,y2)+sum[x1][y1][x2][i]));
	return C;
}
int main(){
	double arge=0;
	scanf("%d",&K);
	for(int i=0;i<MAXN-1;i++){
		for(int j=0;j<MAXN-1;j++){
			scanf("%d",&g[i][j]);
			arge+=g[i][j];
		}
	}
	init();
	arge/=K*1.0;
	memset(opt,-1,sizeof(opt));
	printf("%.3lf\n",sqrt(dp(0,0,0,7,7)*1.0/K-arge*arge)); 
	return 0;
}

