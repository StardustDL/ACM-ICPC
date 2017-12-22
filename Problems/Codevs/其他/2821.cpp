/*
天使之城
*/ 
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
stack<int> st;
queue<int> ans;
int main(){
	int n,cur=0,stn=0;
	char c;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c;
		switch(c){
			case 'A':ans.push(++cur);break;
			case 'B':
				if(stn==5){cout<<"No";return 0;}
				st.push(++cur);
				stn++;
				break;
			case 'C':
				if(stn==0){cout<<"No";return 0;}
				ans.push(st.top());
				st.pop();
				stn--;
				break;
		}
	}
	cout<<"Yes"<<endl;
	while(!ans.empty()){
		cout<<ans.front()<<endl;
		ans.pop();
	}
	return 0;
}
