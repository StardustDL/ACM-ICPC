/*
The Suspects
题意：n个人，m个组，0是传染者，每个组内会传染，问有多少人会患病 
分析：读题读了好久，其实很简单，为了更快，维护一个集合大小的数组，在合并时更新 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=30000;
int n,m,k,t,e,ans=0;
struct uniset{
	int pa[MAXN+3],size[MAXN+3];
	void init(int n){
		for(int i=0;i<=n;i++){
			pa[i]=i;size[i]=1;
		}
	}
	int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
	bool unions(int a,int b){
		a=find(a),b=find(b);
		if(a==b)return false;
		size[b]+=size[a];
		pa[a]=b;
		return true;
	}
	int count(int x){
		return size[find(x)];
	}
}S;
int main(){
	while(cin>>n>>m&&n!=0){
		ans=0;S.init(n);
		while(m-->0){
			cin>>k>>e;k--;
			while(k-->0){
				cin>>t;
				S.unions(e,t);
			}
		}
		cout<<S.count(0)<<endl;
	}
	return 0;
} 
