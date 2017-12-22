/*
[HEOI2012]����Ȧ
������������Ǹ�����ͼ��������š�Ȼ��һ��ͼ���������NP�������=��ͼ����������� 
	  ��������ϸ���⣬���Է��֣����췴ͼ��A������������š�����ż
	  B����ż֮�乹�ɶ���ͼ������ͼ�ɵڶ����������Եõ� 
	  ����Aͼ�п��ܹ���0,1,2���㣬�������B��һЩ��ʧЧ��
	  ��ôö��A�������������B��ȥ������ѡ�ĵ㣬�ܶ���ͼ���ƥ�䣬�õ����ƥ�䣬����������=�ܵ���-���ƥ��=B-����ѡ�ĵ���-���ƥ��
	  �漣����ܵĺܿ�0.0��496 MS 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector> 
using namespace std;
const int MAXN=3000,INF=0x3f3f3f3f;
bool mp[MAXN+3][MAXN+3];
int match[MAXN+3];
bool vis[MAXN+3],can[MAXN+3];
vector<int> g[MAXN+3];
int A,B,m;
int a[MAXN+3],b[MAXN+3];
int count_one(int x){//������lowbit�ķ���ͳ��1�ĸ��� 
	int ans=0;
	while(x)x-=(x&-x),ans++;
	return ans;
}
bool hungry(int x){
	if(can[x]==0)return false;//��������ȥ�����Ͳ�ѡ 
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int t=g[x][i];
		if(!can[t] || vis[t])continue;
		if(match[t]==0 || hungry(match[t])){
			match[x]=t;
			return true; 
		} 
	}
	return false;
}
int get_max_point(int x=0,int y=0){
	int ans=B;memset(can,1,sizeof(can));
	for(int i=1;i<=B;i++)//������Ҫȥ���ĵ� 
		if(mp[x][i] || mp[y][i])ans--,can[i]=0;
	memset(match,0,sizeof(match));
	for(int i=1;i<=B;i++){//��ƥ�䣬ע����ݽ��ߣ���������ż�� 
		if(b[i]&1){
			memset(vis,0,sizeof(vis));
			if(hungry(i))ans--;
		}
	}
	return ans;
}
int main(){
	scanf("%d%d%d",&A,&B,&m);
	for(int i=1;i<=A;i++)scanf("%d",&a[i]);
	for(int i=1;i<=B;i++)scanf("%d",&b[i]);
	memset(mp,1,sizeof(mp));
	for(int x,y,i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		mp[x][y]=0;//ע���Ƿ�ͼ 
	}
	for(int i=1;i<=B;i++){//��������ż������ 
		if(b[i]&1){
			for(int j=1;j<=B;j++){
				if(!(b[j]&1)){
					if(!(count_one(b[i]|b[j])&1))g[i].push_back(j);
				}
			}
		}
	}
	for(int i=1;i<=B;i++)mp[0][i]=0;
	int ans=get_max_point();//��ѡA 
	for(int i=1;i<=A;i++)ans=max(ans,get_max_point(i)+1);//A��ѡһ�� 
	for(int i=1;i<=A;i++){
		if(a[i]&1){
			for(int j=1;j<=A;j++)
				if(!(a[j]&1))ans=max(ans,get_max_point(i,j)+2);//A��ѡ������ע����żҪ��ͬ�� 
		}
	}
	printf("%d\n",ans);
	return 0;
}

