/*
�̹ٵ���Ϸ
������n%5==1��4ʱ�������ܴճɣ�
	  n%5==0ʱ��һ��������ʤ
	  n%5==2��3ʱ��һ��������ʤ 
*/
#include<iostream>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n<0)cout<<120;
	else switch(n%5){
		case 0:cout<<-1;break;
		case 1:case 4:cout<<0;break;
		case 2:case 3:cout<<1;break; 
	}
	return 0;
}
