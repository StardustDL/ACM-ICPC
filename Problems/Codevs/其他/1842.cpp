/*
╣щ╧И╣зр╩╢н
*/ 
#include<iostream>
using namespace std;
int f(int x){
	if(x>=0)return 5;
	else return f(x+1)+f(x+2)+1; 
} 
int n;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cout<<f(n);
	return 0;
} 
