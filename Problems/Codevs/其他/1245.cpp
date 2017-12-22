/*
最小的N个和
分析：先排序，然后依次放入优先队列中，取前n个 
*/
#include<iostream>
#include<queue>
#include<algorithm>
#define N 100002
using namespace std;
struct node{
	int sum,pos;
	bool operator < (node a)const{
		return sum>a.sum;
	}
};
int a[N],b[N],n;
priority_queue<node> pq;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	sort(a,a+n);sort(b,b+n);
	for(int i=0;i<n;i++)pq.push((node){a[i]+b[0],0});
	while(n-->0){
		node t=pq.top();pq.pop();
		cout<<t.sum<<' ';
		//if(t.pos<n)
		pq.push((node){t.sum-b[t.pos]+b[t.pos+1],t.pos+1});
	}
	return 0;
}
