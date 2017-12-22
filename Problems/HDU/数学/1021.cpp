/*
Fibonacci Again
题意：定义一个新的斐波那契数列，求f(n)%3==0?
分析：打出来之后，发现规律！！！ 
*/
#include<iostream>
using namespace std;
int main(){
	int n;
	while(cin>>n)cout<<(n%4==2?"yes":"no")<<endl;
	return 0;
}

