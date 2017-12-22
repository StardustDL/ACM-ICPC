/*
修复公路
分析：并查集 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000,MAXM=100000;
int n,m;
struct road{
	int x,y,t;
	bool operator < (const road &a)const{
		return t<a.t;
	}
}dat[MAXM+3];
struct uniset{
	int pa[MAXN+3],size[MAXN+3],cnt;
	void init(int n){
		for(int i=0;i<=n;i++){
			pa[i]=i;
		}
		cnt=n;
	}
	int find(int x){return pa[x]==x?x:pa[x]=find(pa[x]);}
	bool unions(int a,int b){
		a=find(a),b=find(b);
		if(a==b)return false;
		pa[a]=b;cnt--;
		return true;
	}
	int count(){
		return cnt;
	}
}S;
int main(){
	cin>>n>>m;S.init(n);
	for(int i=1;i<=m;i++)cin>>dat[i].x>>dat[i].y>>dat[i].t;
	sort(dat+1,dat+m+1);
	int cur=0;
	while(S.count()>1&&cur<=m){
		cur++;//cout<<S.count()<<endl;
		S.unions(dat[cur].x,dat[cur].y);
	}
	if(cur<=m)cout<<dat[cur].t;
	else cout<<-1;
	return 0;
}
