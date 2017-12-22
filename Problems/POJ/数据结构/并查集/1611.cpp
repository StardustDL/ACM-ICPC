/*
The Suspects
���⣺n���ˣ�m���飬0�Ǵ�Ⱦ�ߣ�ÿ�����ڻᴫȾ�����ж����˻Ỽ�� 
������������˺þã���ʵ�ܼ򵥣�Ϊ�˸��죬ά��һ�����ϴ�С�����飬�ںϲ�ʱ���� 
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
