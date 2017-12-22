/*
判断浮点数是否相等
*/
#include<iostream>
#include<cmath>
using namespace std;
const double eps=1e-8;
double a,b;
int main(){
	ios::sync_with_stdio(false);
	cin>>a>>b;
	if(abs(a-b)<=eps)cout<<"yes";
	else cout<<"no";
	return 0;
}
