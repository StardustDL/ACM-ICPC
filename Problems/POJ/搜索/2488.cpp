/*
A Knight's Journey
���⣺��ʿ������һ��n*m���̣���1��1����A1��ʾ��2��1����A2��ʾ�����ܷ�ÿ����ֻ����һ�������������̣�����ֵ�����С���߷�
������DFS���ɣ�ע�����ʱ����˳���෴���ֵ�����С����һ��Ҫ���(1,1)�㿪ʼ�ѣ�ֻҪ�п��н�һ������(1,1)������תΪ(1,1)��ʼ��
	  ����˳��ҲҪע�Ᵽ���ֵ�����С��һ��С���ɣ���¼ÿ���㱻���ʵ�ʱ�䣬��������������ɴ� 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=26;
const int dx[8]={-1,1,-2,2,-2,2,-1,1},dy[8]={-2,-2,-1,-1,1,1,2,2};//�����ֵ��� 
int mp[MAXN+3][MAXN+3];
int n,m,ans[MAXN*MAXN+3],ans2[MAXN*MAXN+3];
void loadans(){
	for(int i=1;i<=n;i++){ 
		for(int j=1;j<=m;j++){ 
			ans[mp[i][j]]=char('A'-1+j);//С���� 
			ans2[mp[i][j]]=i;
		}
	} 
}
bool dfs(int x,int y,int cnt){
	if(cnt==n*m)return true;
	for(int i=0;i<8;i++){
		int p=x+dx[i],q=y+dy[i];
		if(p>0&&q>0&&p<=n&&q<=m&&!mp[p][q]){
			mp[p][q]=cnt+1;
			if(dfs(p,q,cnt+1))return true;
			mp[p][q]=0;//ע������ 
		}
	}
	return false;
}
int main(){
	int T=0;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d %d",&n,&m);
		printf("Scenario #%d:\n",i);
		memset(mp,0,sizeof(mp));
		mp[1][1]=1;
		if(dfs(1,1,1)){
			loadans();
			for(int i=1;i<=n*m;i++)
				printf("%c%d",ans[i],ans2[i]);
			puts("");
		}
		else puts("impossible");
		puts("");
	}
	return 0;
}

