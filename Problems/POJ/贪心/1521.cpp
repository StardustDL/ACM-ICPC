/*
Entropy
分析：哈夫曼编码，但没必要实际建立树，利用其性质，优先队列即可 
*/
#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN=27;
string str;
int cnt[MAXN],old,r[MAXN];
bool cmp(const int i,const int j){
	return cnt[i]>cnt[j];
}
bool input(){
	cin>>str;
	if(str=="END")return false;
	memset(cnt,0,sizeof(cnt));old=str.length()*8;
	for(int i=0;i<str.length();i++){
		if(str[i]=='_')cnt[0]++;
		else cnt[str[i]-'A'+1]++;
	}
	return true;
}
priority_queue<int,vector<int>,greater<int> >q;
int solve(){
	/*for(int i=0;i<MAXN;i++)r[i]=i;
	sort(r,r+MAXN,cmp);
	int ans=0,i;
	for(i=1;cnt[r[i]];i++){
		ans+=cnt[r[i-1]]*i;
	}
	ans+=cnt[r[i-1]]*(i-1);
	cout<<ans<<endl;*/
	while(!q.empty())q.pop();
	for(int i=0;i<MAXN;i++)if(cnt[i])q.push(cnt[i]);
	if(q.size()==1)return q.top();
	int k=0,ans=0;
	while(!q.empty()){
		int t=q.top();q.pop();
		if(q.empty())break;
		int e=q.top();q.pop();
		ans+=t+e;//这里很关键，要好好理解：编码长度和其在树中的层数相关 
		//cout<<ans<<endl;
		q.push(t+e);
	}
	return ans; 
}
int main(){
	while(input()){
		int ans=solve();
		printf("%d %d %.1lf\n",old,ans,old*1.0/ans);
	}
	return 0;
} 
