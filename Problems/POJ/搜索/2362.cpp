/*
���⣺����һ�鲻ͬ���ȵ�ľ��,�п��ܼ������ǵĶ˵����γ�һ����������? 
����������1011����������档ֱ�ӵ���dfs�ж�sum/4�Ƿ���м��� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=20;
int T,n,a[MAXN+3],sum;
bool vis[MAXN+3];
bool dfs(int* stick,bool* vist,int len,int InitLen,int s,int num){//len:��ǰ������ϵİ���  InitLen:Ŀ�����  s:stick[]���������  num:���õİ������� 
	if(num==n)return true;
	int sample=-1;
	for(int i=s;i<n;i++){
		if(vist[i] || stick[i]==sample)continue;//��֦3,�ȳ���ľ��ֻ����һ��
		vist[i]=true;
		if(len+stick[i]<InitLen){
			if(dfs(stick,vist,len+stick[i],InitLen,i,num+1))return true;
			else sample=stick[i];//��Ҫֱ�Ӻ�i-1�Ƚϣ��п���i-1�����Ϸ��������ã� 
		}
		else if(len+stick[i]==InitLen){
			if(dfs(stick,vist,0,InitLen,0,num+1))return true;
			else sample=stick[i];
		}
		vist[i]=false;
		if(len==0)break;//��֦4�������°�ʱ�������°��ĵ�һ�����ӣ������������а��Ӻ��޷���ϣ���˵���ð����޷��ڵ�ǰ��Ϸ�ʽ����ϣ�������������(������������ð��ӱ�����)��ֱ�ӷ�����һ�� 
	}
	return false;
}
bool cmp(int a,int b){return a>b;} 
int main(){
	for(scanf("%d",&T);T;T--){
		scanf("%d",&n);sum=0;
		for(int i=0;i<n;i++){scanf("%d",&a[i]);sum+=a[i];}
		sort(a,a+n,cmp);
		memset(vis,0,sizeof(vis));
		if(sum%4==0&&dfs(a,vis,0,sum/4,0,0))puts("yes");
		else puts("no");
	}
	return 0;
}

