/*
地鼠游戏
分析：按时间从后往前，每次取当前仍存在的地鼠中的最大价值，用堆维护 
*/
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=100; 
struct rice{
	int k,v;
	bool operator < (const rice &t)const{
		return v<t.v;
	}
}rs[MAXN+3];
priority_queue<rice> pq;
bool cmp(const rice &a,const rice &b){
	return a.k>b.k;
}
int n;
void input(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>rs[i].k;
	for(int i=1;i<=n;i++)cin>>rs[i].v;
	sort(rs+1,rs+n+1,cmp);
}
int solve(){
	int cur=1,ans=0;
	for(int t=rs[1].k;t>0;t--){
		while(rs[cur].k>=t&&cur<=n)pq.push(rs[cur++]);
		if(!pq.empty()){
			ans+=pq.top().v;pq.pop();
		}
	}
	return ans;
}
int main(){
	input();
	cout<<solve();
	return 0;
}
