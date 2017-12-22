#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str[10003];
int n;
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>str[i];
	sort(str+1,str+n+1);
	for(int i=1;i<=n;i++)cout<<str[i]<<endl;
	return 0;
}
