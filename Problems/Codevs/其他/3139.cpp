/*
Õ»Á·Ï°3
*/
#include<iostream>
#include<stack>
using namespace std;
stack<int> q;
int main(){
	int n,i,m,t;
	cin>>n;
	bool b = false;
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
		else if(m==3){
		    b=true;
		    if(q.empty()){
				cout<<"impossible!";
				return 0;
			}
			else cout<<q.top()<<endl;
		}
	}
	if(!b){
		if(q.empty())cout<<"impossible!";
		else cout<<q.top();
	}
	return 0;
}
