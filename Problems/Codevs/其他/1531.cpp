/*
山峰
分析：维护递减的单调栈 
*/ 
#include<iostream>
#include<stack>
using namespace std;
int n,h,ans=0;
stack<int> S;
int main(){
	cin>>n;
	while(n--){
		cin>>h;
		ans+=S.size();
		while(!S.empty()&&h>S.top())S.pop();
		S.push(h);
	}
	cout<<ans;
	return 0;
}
