/*
���Լ������С����������
����������ˮ��ģ�⼴�ɣ�ע��ö��ʱҪ��Сö�ٷ�Χ 
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
