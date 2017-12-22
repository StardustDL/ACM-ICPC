/*
外星人的密码数字
分析：就是LIS，写了个nlogn，WA了一个TAT 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char str[257];
int mp[27],stack[257],stn=0,a[257];
void load(){
	cin>>str;
	for(int i=0;i<strlen(str);i++){
		mp[str[i]-'a'+1]=i+1;
	}
	//for(int i=0;i<26;i++)cout<<mp[i]<<" ";
	//cout<<endl;
}
bool input(){
	if(!(cin>>str))return false;
	//cout<<strlen(str)<<endl;
	for(int i=0;i<strlen(str);i++){
		//cout<<"!!!"<<(mp[str[i]-'a'])<<endl;
		a[i]=mp[str[i]-'a'+1];
		//cout<<a[i]<<" ";
	}
	//cout<<endl;
	return true;
}
int lis(){
	memset(stack,0,sizeof(stack));
	/*stn=0;stack[0]=-1;
	for(int i=0;i<strlen(str);i++){
		int t=a[i];
		//cout<<t<<" ";
		if(t>=stack[stn]){
			stack[++stn]=t;
		}
		else{
			int *k=lower_bound(stack+1,stack+stn+1,t);
			while(*k==*(k-1))k--;
			*k=t;
		}
	}
	return stn;*/
	int ans=1;
	for(int i=0;i<strlen(str);i++){
		stack[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<=a[i])ans=max(ans,stack[i]=max(stack[i],stack[j]+1));
		}
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	load();
	while(input())cout<<lis();
	cout<<endl;
	return 0;
}
