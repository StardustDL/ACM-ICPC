/*
хЩ╫гпнеп╤о
*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	if(a[0]+a[1]>a[2])cout<<"yes";
	else cout<<"no";
	return 0;
}
