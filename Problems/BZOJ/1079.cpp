/*
[SCOI2008]��ɫ����
�������������뵽һ��15ά��DP����̫���ˣ�
	  ����ע����һ�����ۣ���һ��״̬�£����ڿ�Ⱦ������ͬ����ɫ��������ʵ�ǵȼ۵ģ�����һ���ǣ��Ե�ǰλ�ã���������������Ⱦ������ͬ����ɫ�ĸ������ɡ� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=1000,INF=0x3f3f3f3f;
const LL MOD=1000000007LL;
LL cnt[15+1][15+1][15+1][15+1][15+1][5+1];
int sz[5+1],k;
LL dp(int a,int b,int c,int d,int e,int x){
	LL &t=cnt[a][b][c][d][e][x];
	if(t!=-1)return t;
	if(a+b+c+d+e==0)return t=1;
	t=0;
	if(a)t+=(a-(x==2))*dp(a-1,b,c,d,e,1);//ע���ȥ���ϴ�Ⱦ��ɫת�ƹ�����1������Ϊ������ɫ�� 
	if(b)t+=(b-(x==3))*dp(a+1,b-1,c,d,e,2);
	if(c)t+=(c-(x==4))*dp(a,b+1,c-1,d,e,3);
	if(d)t+=(d-(x==5))*dp(a,b,c+1,d-1,e,4);
	if(e)t+=e*dp(a,b,c,d+1,e-1,5);
	return t%=MOD;
}
int main(){
	memset(cnt,-1,sizeof(cnt));
	scanf("%d",&k);
	for(int i=1,x;i<=k;i++){
		scanf("%d",&x);
		sz[x]++;
	}
	printf("%d\n",dp(sz[1],sz[2],sz[3],sz[4],sz[5],0));
	return 0;
}

