/*
��ɫ��XJP
������һ��������Ŀ������������������һ������������ 
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
