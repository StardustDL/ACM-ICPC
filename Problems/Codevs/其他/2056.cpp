/*
好色的XJP
分析：一道奇葩题目，根本不用网络流，一定是数据问题 
*/
#include<iostream>
using namespace std;
int m,v,w,ans=0,t=0; 
int main(){
	int n,a,b;
	cin>>n>>m>>v;
	while(n-->0){
		cin>>a>>b>>w;
		if(t+w<=v)t+=w;
		else{
			ans=n+1;break;
		}
	}
	if(ans)cout<<"Good News"<<endl<<ans;
	else cout<<v-t;
	return 0;
} 
