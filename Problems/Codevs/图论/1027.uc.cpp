/*
姓名与ID
分析：二分图匹配，字符串比较烦人，但是如何判断是否一定呢？ 
*/ 
#include<iostream>
#include<bitset>
#include<string>
#include<map>
#include<cstdlib> 
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=20;
bitset<MAXN+3> mp[MAXN+3];
bitset<MAXN+3> in,vis;
int match[MAXN+3],n,nn=0,clock;
map<string,int> id;
map<string,int> name;
string ids[MAXN+3],names[MAXN+3];
void input(){
	char c;string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		id[s]=i;
		ids[i]=s;
	}
	while(1){
		cin>>c;
		if(c=='Q')break;
		cin>>s;
		if(c=='E'){
			if(!name.count(s)){
				name[s]=++nn;
				names[nn]=s;
			}
			in[name[s]]=1;
		}
		else if(c=='L'){
			in[name[s]]=0;
		}
		else if(c=='M'){
			for(int i=1;i<=nn;i++){
				if(in[i]){
					mp[i][id[s]]=1;
				}
			}
		}
	}
	sort(names+1,names+nn+1);
}
bool dfs(int u){
	for(int i=1;i<=n;i++){
		if(vis[i] || mp[u][i]==0)continue;
		vis[i]=1;
		if(!match[i]||dfs(match[i])){
			match[i]=u;
			return true;
		}
	}
	return false;
}
bool check(int u){
	if(match[u]==0)return false;
	int v=match[u];
	match[u]=0;vis=0;
	mp[u][v]=0;
	if(!dfs(u)){
		vis[0]=1;
	}
	mp[u][v]=1;
	match[u]=v;
	return vis[0];
}
int main(){
	input();
	memset(match,0,sizeof(match));
	for(int i=1;i<=n;i++){
		if(!match[i]){
			vis=0;
			dfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<names[i]<<":";
		int x=name[names[i]];
		vis=0;
		if(check(x)){
			for(int j=1;j<=n;j++){
				if(match[j]==x){
					cout<<ids[j];break;
				}
			}
		}
		else cout<<"???";
		cout<<endl; 
	}
	return 0;
}
