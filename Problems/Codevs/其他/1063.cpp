/*
合并果子
分析：每次选择最小的两堆合并 
*/
#include<iostream>
#include<queue>
using namespace std;
const int MAXN=10000;
int n,x,ans=0;
priority_queue<int,vector<int>,greater<int> > pq;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		pq.push(x);
	}
	ans+=pq.top();pq.pop();
	ans+=pq.top();pq.pop();
	pq.push(ans);
	while(!pq.empty()){
		int a=pq.top();pq.pop();
		if(pq.empty())break;
		int b=pq.top();pq.pop();
		ans+=a+b;
		pq.push(a+b);
	}
	cout<<ans;
	return 0;
}
