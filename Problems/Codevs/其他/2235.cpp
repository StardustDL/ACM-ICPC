/*
��Ʊ����
ע�⣺�������� 
*/
#include<iostream>
using namespace std;
int t;
double d;
int main(){
	ios::sync_with_stdio(false);
	cin>>t>>d;
	t=(int)(t*0.1*d);
	cout<<(t%10>=5?((t/10+1)*10):(t/10*10));
	return 0;
}
