/*
Õ»Á·Ï°1
*/
#include<iostream>
#include<stack>
using namespace std;
stack<int> q;
int main(){
	int n,i,m,t;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>m;
		if(m==1){
			cin>>t;
			q.push(t);
		}
		else if(m==2){
			if(q.empty()){
				cout<<"impossible!";
				return 0;
			}
			else q.pop();
		}
	}
	if(q.empty())cout<<"impossible!";
	else cout<<q.top();
	return 0;
}
