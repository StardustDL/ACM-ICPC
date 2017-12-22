/*
教官的游戏
分析：n%5==1或4时，不可能凑成，
	  n%5==0时，一定后手能胜
	  n%5==2或3时，一定先手能胜 
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
