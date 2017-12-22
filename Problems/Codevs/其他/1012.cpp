/*
最大公约数和最小公倍数问题
分析：数据水，模拟即可，注意枚举时要缩小枚举范围 
*/
#include<iostream>
using namespace std;
int x,y,ans=0;
int gcd(int x,int y){
	return x%y==0?y:gcd(y,x%y);
} 
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>x>>y;
	for(int i=x;i<=y;i+=x){
		for(int j=x;j<=y;j+=x){
			if(gcd(i,j)==x && lcm(i,j)==y)ans++;
		}
	}
	cout<<ans;
	return 0;
}
