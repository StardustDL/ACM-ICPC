/*
Power of Cryptography
���⣺K ^ N = P, ��N �� P�� ��K�����ݹ�ģ ��1<=n<= 200, 1<=p<10101 and there exists an integer k, 1<=k<=109 ��
������ֱ��double���ܹ� 
*/
#include<cmath> 
#include<iostream>
using namespace std;
double d,n;
int main(){
	while(cin>>n>>d)cout<<pow(d,1.0/n)<<endl;
	return 0;
}

