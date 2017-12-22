/*
F函数
分析：直接写就好了，但有一个有趣的地方F(x)=91 (x<=100) 
*/
#include<iostream>
using namespace std;
int F(int x){
	if(x<=100)return F(F(x+11));
	return x-10;
}
int x;
int main(){
	ios::sync_with_stdio(false);
	cin>>x;
	while(x!=0){
		cout<<F(x)<<endl;cin>>x;
	}
	return 0;
}
