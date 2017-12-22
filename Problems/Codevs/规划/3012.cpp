/*
线段覆盖 4
分析：这道题和前几道线段覆盖有所不同，线段数等于点数，
	  所以状态还是线段数就不太合适了，改为
	  opt[i]表示到第i个位置的最优解，
	  先按右端点排序，
	  转移稍微复杂一点：
	  首先对于opt[i]，要保证所有opt[j|j<i]均为最优解，所以要先检查
	  然后转移：opt[区间i的右端点]=max{opt[区间i的左端点]+区间i的价值}
	  输出时，还要保证最优解性质，所以再检查一遍 
*/
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000000;
typedef long long LL; 
struct block{
	int x,y,w;
	bool operator < (const block &t)const{
		return y<t.y||(y==t.y&&x<t.x);
	}
}bs[MAXN+3];
LL n,opt[MAXN+3],ans=0,cur=1;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>bs[i].x>>bs[i].y>>bs[i].w;
	sort(bs+1,bs+n+1);
	for(int i=1;i<=n;i++){
		while(cur<=bs[i].x){
			opt[cur]=max(opt[cur],opt[cur-1]);cur++;
		}
		opt[bs[i].y]=max(opt[bs[i].x]+bs[i].w,opt[bs[i].y]);
	}
	while(cur<=bs[n].y){
		opt[cur]=max(opt[cur],opt[cur-1]);cur++;
	}
	cout<<opt[bs[n].y];
	return 0;
} 
