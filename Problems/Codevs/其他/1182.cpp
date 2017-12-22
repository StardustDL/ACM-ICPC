/*
小球
分析：从大到小模拟 
*/
#include<iostream>
#include<algorithm>
using namespace std;
int a,b,i=0;
int main(){
	cin>>a>>b;
	while(a!=0 && b!=0){
		if(a<b)swap(a,b); 
		a-=b;b*=2;
		if(i==100000){i=-1;break;}
		i++;
	}
	cout<<i;
	return 0;
}   
