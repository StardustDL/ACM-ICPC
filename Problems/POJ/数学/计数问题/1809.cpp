/*
Regetni
���⣺����һЩ�����Ϊ�������꣬���ܹ��ɶ��ٸ����Ϊ�����������Ρ�������ʽ��A=|x1y2 - y1x2 + x2y3 - y2x3 + x3y1 - y3x1|/2
����������Ƿ�Ϊ����ֻ��Ҫ��|x1y2 - y1x2 + x2y3 - y2x3 + x3y1 - y3x1|mod2�Ƿ�Ϊ0�����Կ����ȶ�ÿ��x,y��mod2������Ӱ�����������ܹ���4�ֵ㣬01��00��10��11��3��ѭ��ö�������ε�3������ֱ������֣����ù�ʽ����������Ƿ�Ϊ��������Ϊ�������������ѧ֪ʶ��ͨ��ÿ�ֶ���ĸ��������ܹ��ɵ�����������
	  ����������ֻҪ��x1y2 ��y1x2 �� x2y3��y2x3�� x3y1 ��y3x1��������������ĸ���Ϊż��������0,2,4,6��
	  �������ǰѵ���ࣺ���棬żż����ż��ż�档�������֮����Է��֣�ֻҪ��֤������������������������ͬһ�࣬���ܱ�֤��ż���� ����� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef long long LL;
LL C(int m,int n){//m����ѡn��������� 
	if(m<n)return 0;
	if(m==n||n==0)return 1;
	LL ans=1;
	for(int i=1,j=m;i<=n;i++,j--)ans=ans*j/i;
	return ans;
}
int n,x,y,t,cnt[5];
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		memset(cnt,0,sizeof(cnt));
		while(n--){
			scanf("%d%d",&x,&y);
			if((x&1)&&(y&1))cnt[0]++;
			else if( !(x&1) && !(y&1))cnt[1]++;
			else if( !(x&1) && (y&1))cnt[2]++;
			else cnt[3]++; 
		}
		cnt[4]=cnt[0]+cnt[1]+cnt[2]+cnt[3];
		LL ans=0;
		for(int j=0;j<4;j++)
			ans+=C(cnt[j],3)+C(cnt[j],2)*(cnt[4]-cnt[j]);
		printf("Scenario #%d:\n%lld\n\n",i,ans);
	}
	return 0;
}

