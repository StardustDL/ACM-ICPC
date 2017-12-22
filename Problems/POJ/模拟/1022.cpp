/*

*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
#include<bitset> 
#include<queue>
using namespace std;
const int MAXN=100; 
int n,con[MAXN+3][9],move[MAXN+3][9],sta[9];//move[i][j]��¼��i��������8�������Ϸֱ�ȵ�1��������˼�����λ,sta[i]��¼ÿ�����������1��������Զ�ľ���
bitset<MAXN+3> vis;
queue<int>q;
map<int,int> pos;//pos[o]�������Ϊo�ķ������ڵ�����ʱ�Ĵ���i,������ŵĴ�С��Χ��û�и���
bool solve(){
   	while(!q.empty())q.pop();vis=0;
   	q.push(1);vis[1]=1;
   	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=1;i<=8;i++){
			int nxt=pos[con[u][i]];//ȡ��u����λ�ھӵĶ���ʱ�����
			if(con[u][i]&&pos[con[nxt][((i+1)^1)-1]]!=u)return false;//�ж���λnxt��Ӧ����ά�ϵķ�������ھ��Ƿ���u��������ǣ�˵�����벻�Ϸ�
			if(con[u][i]&&!vis[nxt]){
				q.push(nxt);vis[nxt]=1;
				memcpy(move[nxt],move[u],sizeof(move[u]));//��u����next��move
				move[nxt][i]++;//next��now��i�����϶�һ����λ
			}
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i])return false;//�ж��Ƿ��ǲ��Ϸ�����2�������ʱ���е�δ��ӣ�˵��������һ����ͨ����
	return true;
}
int main(){
	int T,t;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		pos.clear();
		for(int i=1;i<=n;i++){
			scanf("%d",&t);pos[t]=i;//����Ϊt�ķ����ǵ�i�������(��ɢ��) 
			for(int j=1;j<=8;j++){
				scanf("%d",&t);con[i][j]=t;//�����ĸ�ά�Ϲ��˸�������ھ�
			}
		}
		memset(move,0,sizeof(move));
		if(!solve()){puts("Inconsistent");continue;}
		memset(sta,0,sizeof(sta));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=8;j++){
				sta[j]=max(sta[j],move[i][j]);//�ҳ����������ϵ����ֵ������sta
			}
		}
		printf("%d\n",(sta[1]+sta[2]+1)*(sta[3]+sta[4]+1)*(sta[5]+sta[6]+1)*(sta[7]+sta[8]+1));//ͬһά���෴�ķ����ϵ�staֵҪ��ӣ�������Ȼ�ġ��������ڵ�1������Ҳ��1����λ�����Զ�Ҫ��1
	}
}
