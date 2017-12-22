/*
不好玩的罚金
*/
#include<iostream>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	a=b-a;
	cout<<"Enter the speed limit: Enter the recorded speed of the car: ";
	if(a>=1&&a<=20){
		cout<<"You are speeding and your fine is $ 100";
	}
	else if(a>=21&&a<=30){
		cout<<"You are speeding and your fine is $ 270";	
	}
	else if(a>=31){
		cout<<"You are speeding and your fine is $ 500";
	}
	else cout<<"Congratulations, you are within the speed limit";
	return 0;
}
