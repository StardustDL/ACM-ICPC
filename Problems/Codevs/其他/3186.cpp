/*
������ϰ 2
*/
#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main(){
	int n,i,m,t;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>m;
		if(m==1){
			cin>>t;
			q.push(t);
		}
		else{
			if(q.empty()){
				cout<<"impossible!";
				return 0;
			}
			else q.pop();
		}
	}
	if(q.empty())cout<<"impossible!";
	else cout<<q.front();
	return 0;
}
