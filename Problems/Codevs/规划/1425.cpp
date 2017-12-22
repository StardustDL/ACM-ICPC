/*
最长公共子串
*/
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=256;
typedef char str[MAXN+3];
int opt[MAXN+3],n;
str stra,strb;
void lcs(str a,str b,str out){
	memset(opt,0,sizeof(opt));
	int la=strlen(a),lb=strlen(b),maxl=0,poi=0;
	for(int i=1;i<=la;i++){
		for(int j=lb;j>=1;j--){//注意这里要逆序 
			if(a[i-1]==b[j-1]){
				opt[j]=opt[j-1]+1;
				if(opt[j]>maxl){
					poi=j-1;maxl=opt[j];//记录LCS的结尾和长度 
				}
			}
			else opt[j]=0;
		}
	}
	for(int i=0;i<maxl;i++)
		out[maxl-i-1]=b[poi-i];
	out[maxl]='\0';
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>stra;
	for(int i=2;i<=n;i++){
		cin>>strb;
		lcs(stra,strb,stra);
	}
	cout<<stra;
	return 0;
}
