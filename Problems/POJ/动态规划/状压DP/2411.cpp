/*
Mondriaan's Dream
���⣺��1*2��שȥǡ������n*m�Ŀռ䣬�󷽰���
������ֻ�к�����������������֣�����ö������״̬���ж��ܷ�ת��
	  ���������˷ѣ�dfs���ܵ���״̬i��״̬j,�Ͳ���Ҫö������״̬j 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define INF 99999999
typedef long long LL;
using namespace std;
const int MAXN=(1<<11)+10;
int n,m;
LL temp[MAXN],cnt[MAXN];
bool check(int i){
	while(i){
		if(i&1){
			i>>=1;
			if(!(i&1))return false;//��i����1���i+1�б�����1 
			i>>=1;//�����ж���һ�� 
		}else i>>=1;//�����ж���һ�� 
	}
	return true;
}
void dfs(int k,int i,int j){//���i������Щ״̬ת�Ƶ� 
	if(k==m){cnt[i]+=temp[j];return;}
	if(k>m)return;
	if((i>>k)&1){
		dfs(k+1,i,j);
		if((i>>(k+1))&1)dfs(k+2,i,j|(1<<k)|(1<<(k+1)));
	}
	else dfs(k+1,i,j|(1<<k));
}
LL dp(){
	memset(temp,0,sizeof(temp));//��ʼ����һ��
	memset(cnt,0,sizeof(cnt));
	for(int i=0;i<(1<<m);++i)if(check(i))cnt[i]=1;
	for(int k=2;k<=n;++k){
		memcpy(temp,cnt,sizeof(temp));
		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<(1<<m);++i)dfs(0,i,0);
	}
	return cnt[(1<<m)-1];
}
int main(){
	while(~scanf("%d%d",&n,&m),n+m){
		if(n<m)swap(n,m);//ʼ�ձ���m<n,���Ч�� 
		printf("%lld\n",dp());//������һ�е���ʱ��״̬����ȫ����1 
	}
	return 0;
}
