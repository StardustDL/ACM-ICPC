/*
装箱问题
分析：01背包DP，体积=价值 
*/
#include<iostream>
#include<algorithm>
using namespace std; 
const int MAXV=20003; 
int v,n,opt[MAXV],cv;
int main(){
	ios::sync_with_stdio(false);
	cin>>v>>n;
	while(n-->0){
		cin>>cv;
		for(int j=v;j>=cv;j--){
			opt[j]=max(opt[j],opt[j-cv]+cv);
		}
	}
	cout<<v-opt[v];
	return 0;
} 
