#include<iostream>
#include<cstring>
using namespace std;
int main(){
	//ios::sync_stdio(false);
	int n;
	char str[63];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str;
		if((str[strlen(str)-1]-'0')&1){
			cout<<"odd"<<endl;
		}
		else cout<<"even"<<endl;
	}
	return 0;
}
