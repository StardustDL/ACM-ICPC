/*
字串变换
*/
#include<iostream>
#include<map>
#include<string>
#include<queue>
using namespace std;
struct node{
	string s;
	int t;
};
string a,b;
string str[7][2];
queue<node> q;
map<string,bool> mp;
int n=1;
int bfs(){
	q.push((node){a,0});
	mp[a]=1;
	while(!q.empty()){
		node t=q.front();q.pop();
		if(t.t>=10)return -1;
		string S=t.s;
		for(int i=1;i<=n;i++){
			int x=S.find(str[i][0],0);
			while(x!=string::npos){
				S.replace(x,str[i][0].size(),str[i][1].c_str(),str[i][1].size());
				if(!mp[S]){
					if(b==S)return t.t+1;
					node d=(node){S,t.t+1};
					q.push(d);
					mp[S]=1;
				}
				S=t.s;
				x=S.find(str[i][0],x+1);
			}
		}
	}
	return -1;//注意这里 
}
int main(){
	cin>>a>>b;
	while(cin>>str[n][0]>>str[n][1])n++;
	n--;
	int n=bfs();
	if(n==-1)cout<<"NO ANSWER!";
	else cout<<n;
	return 0;
}
