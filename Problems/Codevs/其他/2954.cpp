/*
��Ȼ������
����������������Եõ�+1/-1����ô������ż�Լ��� 
*/
#include<iostream>
using namespace std;
long long n;
int t;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		if(n&1){
			if(!((n-1)%4))cout<<1;else cout<<0;
		}
		else if(!(n%4))cout<<0;else cout<<1;
		cout<<endl;
	}
	return 0;
}
