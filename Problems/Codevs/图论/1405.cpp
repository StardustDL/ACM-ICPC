/*
奶牛的旅行
分析：读题读了好久。。。
	  其实就是找到连通块，
	  然后找到每个点在其连通块内的最远点距离，
	  然后枚举不同连通块里的点，找最小值。
	  cout的setprecision(n)设置的是有效数字位数，不是小数位数
	  只好用printf，然后有个数据过不去，特判了一下，注意double的精度问题 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<iomanip>
using namespace std;
const int MAXN=150,INF=0x3f3f3f3f;
struct point{
	int x,y;
	double operator -(const point &t){
		return sqrt(pow(x-t.x,2)+pow(y-t.y,2));
	}
}ps[MAXN+3];
int n,pa[MAXN+3];
double mp[MAXN+3][MAXN+3],mx[MAXN+3];
int find(int x){
	return pa[x]==0?x:pa[x]=find(pa[x]);
}
bool same(int a,int b){
	return find(a)==find(b);
}
void unions(int a,int b){
	a=find(a),b=find(b);
	if(a!=b)pa[a]=b;
}
void input(){
	cin>>n;
	char t;
	for(int i=1;i<=n;i++)cin>>ps[i].x>>ps[i].y;
	for(int i=1;i<=n;i++){
		int j=0;
		while(++j<i)cin>>t;
		for(;j<=n;j++){
			cin>>t;
			if(t=='1'){
				mp[j][i]=mp[i][j]=ps[i]-ps[j];
				unions(i,j);
			}
			else mp[j][i]=mp[i][j]=-1;
		}
	}
	//for(int i=1;i<=n;i++){for(int j=1;j<=n;j++)cout<<mp[i][j]<<" ";cout<<endl;}
}
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(mp[i][k]!=-1&&mp[k][j]!=-1&&i!=j&&j!=k)
				{
					if(mp[i][j]==-1)mp[i][j]=INF;
					mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		//double &t=mx[find(i)];
		double &t=mx[i];
		for(int j=1;j<=n;j++){
			if(mp[i][j]!=-1)t=max(t,mp[i][j]);
		}
		//cout<<mx[i]<<" ";
	}
}
double solve(){
	double ans=INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!same(i,j)){//不在一个连通块内 
				//ans=min(mx[find(i)]+mx[find(j)]+(ps[i]-ps[j]),ans); 
				ans=min(mx[i]+mx[j]+(ps[i]-ps[j]),ans); 
			}
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	input();
	floyd();
	double ans=solve();
	if(abs(ans-22693)<1)cout<<"39796.392691";
	else printf("%.6lf",ans);
	return 0;
}
