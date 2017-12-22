#include<iostream>
using namespace std;
int t,m,u,f,d,ans=0,tm;
char c;
int main(){
	cin>>m>>t>>u>>f>>d;
	for(int i=1;i<=t;i++){
		cin>>c;
		switch(c){
			case 'u':
			case 'd':
				tm+=u+d;
				break;
			case 'f':
				tm+=f+f;
				break;
		}
		if(tm>m){
			cout<<ans<<endl;
			return 0;
		}
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
