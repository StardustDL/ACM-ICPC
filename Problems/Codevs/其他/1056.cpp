/*
圆内三角形统计
分析：在圆内先画一个三角形，然后延长三角形各边，你会发现延长线与圆周有6个交点，所以答案是C(6,n)，即N个数选6个的组合 
*/
#include<iostream>
using namespace std;
int main(){
	long long n;
	cin>>n;
	cout<<n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)/6/5/4/3/2;
	return 0;
} 
