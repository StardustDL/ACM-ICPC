/*
最大公约数
*/
#include<iostream>
using namespace std;
int x,y,ans=0;
int gcd(int x,int y){
	return x%y==0?y:gcd(y,x%y);
} 
int main(){
	ios::sync_with_stdio(false);
	cin>>x>>y;
	cout<<gcd(x,y); 
	return 0;
}
