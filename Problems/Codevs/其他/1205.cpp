/*
���ʷ�ת
ע�⣺++��--��ʹ�� 
*/ 
#include<iostream>
using namespace std;
char str[51][255];
int n=0;
int main(){
	ios::sync_with_stdio(false);
	while(cin>>str[++n]);//����ʵ���ϻ���뵥����+1 
	while(n-->0)cout<<str[n]<<" ";//����������n--�����Ի��n-1��ʼ��� 
	return 0;
}
