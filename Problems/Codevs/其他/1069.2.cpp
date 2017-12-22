/*
¹ØÑº×ï·¸
*/
#include<iostream>
#include<algorithm>
using namespace std;
struct edge{
	int u,v,val;
	friend bool operator <(edge a,edge b){
		return a.val>b.val;
	}
}e[100010];
int f[20010],v[20010],n,m,ans=0;
int find(int x){
	if(f[x]==x)return x;
	else{
		int t=find(f[x]);
		v[x]=v[f[x]]^v[x];//(v[f[x]]+v[x])%2
		f[x]=t;
		return f[x];
	}
}
void join(int a,int b){
	int fa=find(a),fb=find(b);
	f[fa]=fb;
	v[fa]=!(v[a]^v[b]);//(v[b]+v[a]+1)%2
}
bool judge(int a,int b){
	if(find(a)!=find(b))return false;
	else if(v[a]==v[b])return true;
		else return false;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>e[i].u>>e[i].v>>e[i].val;
	for(int i=1;i<=n;i++)f[i]=i;
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++)
		if(judge(e[i].u,e[i].v)){
			ans=e[i].val;break;
		}
		else join(e[i].u,e[i].v);
	cout<<ans;
	return 0;
}
