/*
Ubiquitous Religions
���⣺n��ѧ����ÿ��ѧ�����������ڽ̣�Ȼ��֪��һ��ѧ��������ͬ���ڽ̣���ͬ�ڽ����� 
������ά��һ�����ϸ������ںϲ�ʱ���� 
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
