/*
����
����������Ŀ�������������뵽����ת������nתΪ2���ƣ�Ȼ���䵱��k����ת��10���� 
*/
#include<iostream>
using namespace std;
long long n,k,ans=0,t=1;
int main(){
	cin>>k>>n;
	for(int i=0;(1<<i)<=n;i++){
		if(n&(1<<i))ans+=t;
		t*=k;
	}
	cout<<ans;
	return 0;
}
