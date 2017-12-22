/*
×Ö·ûÑ¹Ëõ
*/
#include<iostream>
#include<cstring>
using namespace std;
char a[31],b[31];
int main(){
	cin>>a>>b;
	for(int i=0;i<strlen(a);i++){
		if(a[i]!=b[i]){
			cout<<"NO "<<i+1;
			return 0;
		}
	}
	cout<<"YES";
	return 0;
} 
