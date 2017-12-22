/*
导弹拦截
分析：由于要拦截所有导弹，可以贪心
	  先按距A的距离从大到小排序，先处理离A最远的，维护它离B的距离，
	  相当于点不断靠近A，然后维护这些点到B的最远距离， 
	  因为答案是平方和，且开方不开方大小关系不会变，所以不必开方，还便于后续处理 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXN=100000,INF=0x3f3f3f3f; 
struct node{
	int da,db;
	bool operator < (const node &t)const{
		return da>t.da;
	}
}nd[MAXN+3];
int dist(int a,int b,int x,int y){
	return (int)(pow(a-x,2)+pow(b-y,2));
}
int xa,ya,xb,yb,n;
void input(){
	cin>>xa>>ya>>xb>>yb;
	cin>>n;
	int a,b;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		nd[i].da=dist(a,b,xa,ya);
		nd[i].db=dist(a,b,xb,yb);
	}
	sort(nd+1,nd+n+1);//按距A的距离从大到小排序 
}
int solve(){
	int ans=INF,s=0;
	for(int i=1;i<=n;i++){
		//注意这两句的顺序，ans的更新使用的是上次的s值 
		ans=min(ans,nd[i].da+s);//更新答案，以当前的点距A的距离为半径 
		s=max(s,nd[i].db);//维护前i个的到B距离的最大值 
	}
	return ans;
}
int main(){
	input();
	cout<<solve();
	return 0;
}
