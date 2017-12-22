/*
线段覆盖 2
分析：先按右端点排序， 
	  opt[i]表示到第i个区间的最优解，
	  转移为opt[i]=max{opt[j]|j<i&&j.y<=i.x} 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000;
struct block{
	int x,y,w;
	bool operator < (const block &t)const{
		return y<t.y||(y==t.y&&x<t.x);
	}
}bs[MAXN+3];
int n,opt[MAXN+3],ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>bs[i].x>>bs[i].y>>bs[i].w;
	}
	sort(bs+1,bs+n+1);
	for(int i=1;i<=n;i++){
		opt[i]=0;
		for(int j=1;j<i;j++){
			if(bs[j].y<=bs[i].x){
				opt[i]=max(opt[j],opt[i]);
			}
		}
		opt[i]+=bs[i].w;
		ans=max(ans,opt[i]);
	}
	cout<<ans;
	return 0;
} 
