/*
To Bet or Not To Bet
���⣺������һ�����Ա���ʼλ��0������λ��m+1��ÿһ����Ӳ�Ҿ�������һ���������������ʸ�Ϊ0.5������ÿ���϶�����һ��˵��+n��-n��L������ 0���ֱ���ζ��������n��������n��ʧȥһ�ֻ��ᣬ���κ�˵�����������̵Ĵ�С���Լ�������ÿһ���˵��������t�ֻ�������t�ֱ��ߵ��յ㴦�ĸ��ʡ�
����������DP�����ƣ�ע������;��� 
*/
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN=60,INF=0x3fffffff;
const double eps=1e-9; 
int m,t,data[MAXN+3];
double opt[MAXN+3][MAXN+3];
void input(){
	char str[10];
	scanf("%d%d",&m,&t);
	memset(opt,0,sizeof(opt));
	data[0]=0,data[m+1]=0;
	data[m+2]=-1;//�����յ����յ�
	for (int i=1;i<=m;i++){
		scanf("%s",str);    
		if(str[0]=='L')data[i]=INF;
		else sscanf(str,"%d",&data[i]);
	}
	opt[0][0]=1.0;
}
double dp(){
	for(int i=0;i<t;i++){
		for(int j=0;j<m+1;j++){
			if(data[j+1]==INF)opt[i+2][j+1]+=opt[i][j]*0.5;
			else opt[i+1][j+1+data[j+1]]+=opt[i][j]*0.5;
			if(data[j+2]==INF)opt[i+2][j+2]+=opt[i][j]*0.5;
			else opt[i+1][j+2+data[j+2]]+=opt[i][j]*0.5;
		}
	}
	double ans=0;
	for(int i=0;i<=t;i++)ans+=opt[i][m+1];
	return ans;
}
int main(){
	int T;scanf("%d",&T);
	while(T-->0){
		input();
		double ans=dp();
		if(abs(ans-0.5)<eps)printf("Push. ");
		else if(ans>0.5)printf("Bet for. ");
		else printf("Bet against. ");
		printf("%.4lf\n",ans); 
	}
	return 0;
}
