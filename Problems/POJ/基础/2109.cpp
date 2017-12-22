/*
Power of Cryptography
题意：K ^ N = P, 给N 和 P， 求K。数据规模 ：1<=n<= 200, 1<=p<10101 and there exists an integer k, 1<=k<=109 。
分析：直接double就能过 
*/
#include<cmath> 
#include<iostream>
using namespace std;
double d,n;
int main(){
	while(cin>>n>>d)cout<<pow(d,1.0/n)<<endl;
	return 0;
}

