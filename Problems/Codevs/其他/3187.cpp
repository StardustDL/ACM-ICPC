/*
∂”¡–¡∑œ∞ 3
*/
#include<iostream>
#include<queue>
using namespace std;
queue<int> q;
int main(){
	int n,i,m,t;
	cin>>n;
	bool b=true;
	for(i=1;i<=n;i++){
		cin>>m;
		if(m==1){
			cin>>t;
			q.push(t);
		}
		else if(m==2){
			if(q.empty()) cout<<"impossible!"<<endl;
			else q.pop();
		}
		else if(m==3){
		    b=false;
			cout<<q.front()<<endl;
		}
	}
	if(b)cout<<q.front();
	return 0;
}
