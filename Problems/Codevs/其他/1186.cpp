/*
F����
������ֱ��д�ͺ��ˣ�����һ����Ȥ�ĵط�F(x)=91 (x<=100) 
*/
#include<iostream>
using namespace std;
int F(int x){
	if(x<=100)return F(F(x+11));
	return x-10;
}
int x;
int main(){
	ios::sync_with_stdio(false);
	cin>>x;
	while(x!=0){
		cout<<F(x)<<endl;cin>>x;
	}
	return 0;
}
