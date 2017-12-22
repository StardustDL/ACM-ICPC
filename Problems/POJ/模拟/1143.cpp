/*
Number Game
分析：一个含有数字2-20的数列，轮流删去一个数，每次删数，都把所有可以用已删去数线性表示的数删去
	  现给出一个剩下的数列，问先删哪个数能必胜
	  首先注意到数字范围是2-20，然后给的数是剩下的，那么没有给的数就已经被选过了，所以如果只有2或只有3，那么选这个，就一定必胜，若同时有，那么两个人都不会主动去选，除非必须选，
	  用到博弈论：从当前的状态推断下一个状态，如果下一个状态中会出现必败态，则此状态会为必胜态，否则下一个状态中不会出现必败态，则此状态为必胜态，这是博弈论最基本的东西 
	  所以记忆化搜索+位压缩存储状态 
*/
#include<bitset>
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
const int MAXN=20;
int bs[1<<MAXN+1],st,kase=0;
vector<int> an;
bool has(int state,int x){//判断state第x位是否为1 
	return state&(1<<x);
}
/*void out(int x){//二进制输出x 
	for(int i=1;i<=MAXN;i++){
		if(has(x,i))cout<<1;else cout<<0;
	cout<<endl;
}*/
int change(int state,int x){//删去x，连同其它符合条件的也删去 
	int ans=state;
	ans^=1<<(x);//先删去x 
	for(int i=2;i<=MAXN;i++)
		if(!has(ans,i)&&x+i<=MAXN&&has(ans,x+i))//i已经被删除，且x+i在范围内，且序列中存在x+i 
			ans^=1<<(x+i);//将x+i位置0 
	return ans;
}

bool dfs(int state){
	if(bs[state]!=-1)return bs[state];//已经处理过此状态 
	if(state==0)return false;//无路可走 
	if(has(state,2)^has(state,3))return bs[state]=1;//只存在一个2或一个3 
	for(int i=2;i<=MAXN;i++)
		if(has(state,i)&&!dfs(change(state,i)))//如果下一步为必输，则此步必赢 
			return bs[state]=1;
	return bs[state]=0;
}
bool input(){
	int n,x;st=0;cin>>n;
	if(n==0)return false;
	while(n-->0){cin>>x;st|=1<<x;}
	return true;
}
int main(){
	while(input()){
		an.clear();
		memset(bs,-1,sizeof(bs));//注意初始化 
		for(int i=2;i<=MAXN;i++)
			if(has(st,i)&&!dfs(change(st,i)))//删除i数字后为必输 
				an.push_back(i);
		cout<<"Test Case #"<<++kase<<endl;
		if(an.size()!=0){
			cout<<"The winning moves are: ";
			for(int i=0;i<an.size();i++)cout<<an[i]<<" ";
			cout<<endl;
		}
		else cout<<"There's no winning move."<<endl;
		cout<<endl;
	}
	return 0;
}
