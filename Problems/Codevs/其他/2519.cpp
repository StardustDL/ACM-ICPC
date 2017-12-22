/*
ฐยิหตนผฦสฑ
*/
#include<iostream>
using namespace std;
int getday(int y,int m){
	if(m==1||m==3||m==5||m==7||m==8||m==10||m==12)return 31;
	else if(m!=2)return 30;
	if(y%100!=0&&y%4==0||y%400==0)return 29;
	return 28;
}
int main(){
	int y,m,d;
	int ans=0;
	cin>>y>>m>>d;
	if(y==2008&&m==8){
		cout<<8-d;
		return 0;
	}
	ans+=getday(y,m)-d;
	if(y==2008){
		for(int i=m+1;i<=7;i++)ans+=getday(2008,i);
		ans+=8;
		cout<<ans;
		return 0;
	}
	for(int i=m+1;i<=12;i++)
		ans+=getday(y,i);
	for(int i=y+1;i<2008;i++)
		for(int j=1;j<=12;j++)
			ans+=getday(i,j);
	for(int i=1;i<=7;i++)
		ans+=getday(2008,i);
	ans+=8;
	cout<<ans;
	return 0;
}
