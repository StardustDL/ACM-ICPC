/*
����
�����������Կӣ����ȿ϶��뵽�������򣬵�����⣬ÿ��һ���߶�Ҫ��һ�Σ���ȷ�������� 
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
struct edge{
	int u,v;
};
vector<edge> es;
vector<int> g[27];
bitset<1003> can=0;
int d[27],d0[27],n;
queue<int>cur,ans;
void add(char x,char y){
	es.push_back((edge){x-'A'+1,y-'A'+1});
	g[x-'A'+1].push_back(es.size()-1);
}
int topo(){
	while(!ans.empty())ans.pop();
	for(int i=1;i<=n;i++)d[i]=d0[i];
	for(int i=1;i<=n;i++)if(d[i]==0)cur.push(i);
	bool flg=true;//��¼�Ƿ����ֶ�⣬�������������Ƿ���г���1���ڵ�ǰ������ 
	while(!cur.empty()){
		if(cur.size()>1)flg=false;
		int k=cur.front();cur.pop();
		ans.push(k);
		for(int i=0;i<g[k].size();i++){
			int t=g[k][i];
			if(!can[t])continue;
			if(--d[es[t].v]==0)cur.push(es[t].v);
		}
	}
	if(ans.size()<n)return -1;//������������n������˵���л� 
	if(flg)return 1;
	return 0;
}
int main(){
	int m;char x,y,z;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>x>>y>>z;
		add(x,z);
	}
	memset(d0,0,sizeof(d0));
	for(int i=0;i<es.size();i++){
		d0[es[i].v]++;
		can[i]=1;
		int k=topo();
		if(k==-1){
			cout<<"Inconsistency found after "<<i+1<<" relations.";
			return 0;
		}
		else if(k==1){
			cout<<"Sorted sequence determined after "<<i+1<<" relations: ";
			while(!ans.empty()){
				cout<<(char)(ans.front()+'A'-1);ans.pop();
			}
			cout<<".";
			return 0;
		}
	}
	cout<<"Sorted sequence cannot be determined.";
	return 0;
}
