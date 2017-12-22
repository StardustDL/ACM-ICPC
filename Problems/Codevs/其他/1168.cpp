/*
»ð²ñ°ôµÈÊ½
*/
#include<iostream>
using namespace std;
const int js[10]={6,2,5,5,4,5,6,3,7,6};
int n,ans=0;
int get(int t){
	if(t==0)return js[0];
	int ans=0;
	while(t>0){
		ans+=js[t%10];
		t/=10;
	}
	return ans;
}
int main(){
	cin>>n;
	n-=4;
	for(int i=0;i<=1000;i++)
       for(int j=0;j<=1000;j++) 
           if(get(i+j)==n-get(i)-get(j))ans++;
	cout<<ans;
	return 0;
}
