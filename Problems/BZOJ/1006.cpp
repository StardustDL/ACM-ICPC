/*
[HNOI2008]����Ĺ���
���������е��˹��ɵĹ�ϵͼ��һ����ͼ�����ȳ��� 3 �Ļ��б���һ���ң�����������������������У���������������������̰�ĵ�Ⱦɫ���������õ�ɫ�����Ǳ���Ĵ�
	  �����������У����е��һ�����У�ʹ��vi��{vi..n}�������յ���ͼ����һ�������㣨�����㣺{v}��v���ڵĵ㣬����һ���ţ��� 
	  �������������е� MCS ���ǵ��Ž�ģ�Ҳ�����������еĵ� n ���������еĵ� n-1 ��
		ÿ��ѡȡͼ�о�������ŵĵ���Ϊ�������������ж�Ӧλ�õĵ㣬���������������к����ڽӵĲ��������еĵ�ı��ֵ
		����һ����ͼ��Ⱦɫ���������������п��ԺܺõĽ���������������������еĵ㵹�Ÿ�ͼ�еĵ�̰�ĵ�Ȼ������С����ɫ
		���գ�һ���ܹ�����С����ɫ������ͼ�е����е�Ⱦɫ
	  O(n+m):
	  	ά��ÿ����ı�ţ�ά�����0,1,2,...������ά�������ֵ
		��ʼʱÿ������Ϊ0��������0�������best=0��
		�ٸ��²�����ĳ���u���ƴ�x��Ϊx+1ʱ��ֻҪ��u�嵽x+1�����ͷ�������轫���x������ɾ�������Բ���д˫��������Ȼ�����bestֵ��
		��ȡ��������ȡ����ƽ��ʱ��best�����ͷ��ʼȡ�����ȡ�������ѱ��������еĽ���ɾ������������ȡ����ȡ������--best��ֱ��ȡ��һ��δ���������еĵ㡣
		������ÿ��O(1)���ܹ�ִ��O(m)�Ρ�best++Ҳ��ִ��O(m)�Σ���ô��������--bestҲֻ��O(m)�Ρ�������ÿ�β�һ����㣬���ܹ���O(n+m)����㣬����������ÿ����ȡһ����ɾһ��������Ҳ��O(n+m)�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue> 
#include<vector>
using namespace std;
const int MAXN=10000,INF=0x3f3f3f3f;
vector<int> g[MAXN+3];
vector<int> sta[MAXN+3];
int head[MAXN+3];
bool vis[MAXN+3];
int top,v[MAXN+3];
int n,m;
vector<int> ans;
int getmax(){
	while(1){
		if(head[top]==sta[top].size())top--;
		int x=sta[top][head[top]];
		if(vis[x])head[top]++;
		else return x;
	}
}
void calc(){
	for(int i=1;i<=n;i++){sta[0].push_back(i);v[i]=0;head[i]=0;}
	top=0;
	for(int i=1;i<=n;i++){
		int t=getmax();
		vis[t]=1;ans.push_back(t);
		for(int j=0;j<g[t].size();j++){
			if(vis[g[t][j]])continue;
			sta[++v[g[t][j]]].push_back(g[t][j]);
			top=max(top,v[g[t][j]]);
		}
	}
}
int col[MAXN+3],tmp[MAXN+3],Ans=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	calc();
	memset(tmp,-1,sizeof(tmp));
	for(int i=0,k;i<n;i++){
		for(int j=0;j<g[ans[i]].size();j++)tmp[col[g[ans[i]][j]]]=i;
		for(k=1;tmp[k]==i;k++);
		col[ans[i]]=k;Ans=max(k,Ans);
	}
	printf("%d\n",Ans);
	return 0;
}

