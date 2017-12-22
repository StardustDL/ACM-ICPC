/*
[SCOI2009]生日礼物
分析：枚举起始点，把该点右边每种珠子的第一个的距离求最大值，这样就可以覆盖所有种的珠子，但不一定最优，之后枚举的会更新 
	  然后把每个起始点所求出的最优解取最小值即可。 
*/ 
#include<cstdio> 
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f,MAXK=60;
priority_queue<int,vector<int>,greater<int> >pq[MAXK+3]; 
int n,k;
void input(){
	scanf("%d %d",&n,&k);
	int t,e;
	for(int i=1;i<=k;i++){
		scanf("%d",&t);
		while(t--){
			scanf("%d",&e);
			pq[i].push(e);
			pq[0].push(e);
		}
	}
}
int solve(){
	int ans=INF;
	while(!pq[0].empty()){
		int s=pq[0].top(),t=0;pq[0].pop();
		for(int i=1;i<=k;i++){
			while(!pq[i].empty()&&pq[i].top()<s)pq[i].pop();
			if(pq[i].empty())return ans;
			t=max(t,pq[i].top());
		}
		ans=min(ans,t-s);
	}
	return ans;
}
int main(){
	input();
	printf("%d",solve());
	return 0;
}
