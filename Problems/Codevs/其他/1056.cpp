/*
Բ��������ͳ��
��������Բ���Ȼ�һ�������Σ�Ȼ���ӳ������θ��ߣ���ᷢ���ӳ�����Բ����6�����㣬���Դ���C(6,n)����N����ѡ6������� 
*/
#include<iostream>
using namespace std;
int main(){
	long long n;
	cin>>n;
	cout<<n*(n-1)*(n-2)*(n-3)*(n-4)*(n-5)/6/5/4/3/2;
	return 0;
} 
