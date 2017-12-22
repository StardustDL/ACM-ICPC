/*
十进制转m进制
*/
#include<iostream>
#include<cstring>
using namespace std;
char ans[103];
int n,m,t[103];
void work(int a,int m){
	if(a==0)ans[0]='0';
	int cur=0;
	while(a>0){
		t[++cur]=a%m;
		a/=m;
	}
	for(int i=1;i<=cur;i++){
		if(t[i]<10)
			ans[cur-i]='0'+t[i];
		else ans[cur-i]='A'+t[i]-10;
	}
	ans[cur+1]='\0';
} 
int main(){
	cin>>n>>m;
	work(n,m);
	cout<<ans;
	return 0;
}
