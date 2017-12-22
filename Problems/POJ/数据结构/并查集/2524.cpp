/*
Ubiquitous Religions
题意：n个学生，每个学生可能信仰宗教，然后知道一对学生信仰相同的宗教，求不同宗教种数 
分析：维护一个集合个数，在合并时更新 
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=50000;
int n,m,a,b,kase=0;
struct uniset{
	int pa[MAXN+3],cnt;
	void init(int n){
		for(int i=0;i<=n;i++)pa[i]=i;
		cnt=n;
	}
	int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
	bool unions(int a,int b){
		a=find(a),b=find(b);
		if(a==b)return false;
		pa[a]=b;cnt--;
		return true;
	}
}S;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>n>>m&&n!=0){
		S.init(n);
		while(m-->0){
			cin>>a>>b;
			S.unions(a,b);
		}
		cout<<"Case "<<++kase<<": "<<S.cnt<<endl;
	}
	return 0;
} 
