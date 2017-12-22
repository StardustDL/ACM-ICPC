/*
保留两位小数
*/
#include<iostream>
#include<iomanip>
using namespace std;
double d;
int main(){
	ios::sync_with_stdio(false);
	cin>>d;
	cout<<setprecision(2)<<setiosflags(ios::fixed)<<d;
	return 0;
} 
