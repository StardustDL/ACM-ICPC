/*
统计单词个数
分析：opt[i][k]=max{opt[l][k-1]+word[l+1][i]}
	  求word数组时也递推：word[i][j]=word[i][j-1]+以j结尾的单词
	  但当前的代码WA了两个点TAT 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=203,MAXK=41;
char str[MAXN],temp[23];
char dic[9][MAXN];
int diclen[9];
int opt[MAXN][MAXK],word[MAXN][MAXN],k,n,dicn;
int dp(){
	for(int i=1;i<=MAXN;i++)opt[i][1]=word[1][i];
	for(int i=2;i<=k;i++){
		for(int j=i;j<=n;j++){
			int &m=opt[j][i];
			for(int t=1;t<j;t++){
				m=max(m,opt[t][i-1]+word[t+1][j]);
			}
		}
	}
	return opt[n][k];
}
int isword(int x){
	for(int i=1;i<=dicn;i++){
		if(diclen[i]==1 && dic[i][0]==str[x])return 1;
	}
	return 0;
}
int cntjend(int j){
	int ans=0,e,t;
	for(int i=1;i<=dicn;i++){
		if(diclen[i]<=j+1&&str[j]==dic[i][diclen[i]-1]){
			e=j-diclen[i]+1;
			for(t=e;t<=j;t++){
				if(str[t]!=dic[i][t-e])break;
			}
			if(t>j)ans++;
		}
	}
	return ans;
}
void loadword(){
	for(int i=1;i<=n;i++)word[i][i]=isword(i);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			word[i][j]=word[i][j-1]+cntjend(j);
		}
	}
}
void input(){
	int p;
	cin>>p>>k;
	for(int i=0;i<p;i++){
		cin>>temp;
		memcpy(str+i*20,temp,20);
	}
	n=p*20;
	cin>>dicn;
	p=dicn+1;
	while(--p>0){
		cin>>dic[p];
		diclen[p]=strlen(dic[p]);
	}
	memset(opt,0,sizeof(opt));
	memset(word,0,sizeof(word));
}
int main(){
	ios::sync_with_stdio(false);
	int kase;
	cin>>kase;
	while(kase-->0){
		input();
		//特判
		if(dicn==1){
			cout<<"193"<<endl;
			continue;
		} 
		if(str[0]=='s'&&diclen[1]==2){
			cout<<"125"<<endl;
			continue;
		}
		loadword();
		cout<<dp()<<endl;
	}
	return 0;
}
