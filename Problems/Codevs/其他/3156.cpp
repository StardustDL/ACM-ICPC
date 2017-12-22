/*
爱改名的小融 3
*/
#include<iostream>
#include<cstring>
#include<ctype.h>
#include<vector>
using namespace std;
int n;
char str[100003];
vector<int> rig;
bool check(){
	int k=strlen(str);
	for(int i=0;i<k;i++)
		if(!isalpha(str[i]))return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str;
		if(check())rig.push_back(i);
	}
	cout<<rig.size()<<endl;
	for(int i=0;i<rig.size();i++){
		cout<<rig[i]<<" ";
	}
	return 0;
}
