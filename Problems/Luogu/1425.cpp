/*
小鱼的游泳时间
*/
#include<iostream>
using namespace std;
int main(){
	int a,b,c,d,x,y;
	cin>>a>>b>>c>>d;
	x=a*60+b,y=c*60+d;
	cout<<(y-x)/60<<" "<<(y-x)%60;
	return 0; 
}
