/*
ͻ������
������ɨһ�飬��¼ÿ��K������� 
*/ 
#include<iostream>
using namespace std;
const int MAXN=100000;
int a[MAXN+3],b[MAXN+3],n,al=0,ak=0,s[6],l[6];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			if(a[i]!=j&&b[i]!=j)l[j]=0;
			else{
				if(l[j]++==0)s[j]=i;
				if(l[j]>al)al=l[j],ak=j;
			}
		}
	}
	cout<<al<<" "<<ak;
	return 0;
}
