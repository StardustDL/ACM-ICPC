/*

*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cctype>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000000;
char str[13],t[MAXN+3];
int ans=0,fir=-1;
int main(){
	scanf("%s\n",str);
	for(int i=0;i<strlen(str);i++){
		str[i]=tolower(str[i]);
	}
	//cout<<str<<endl;
	//scanf("%s\n",t);
	//cin.getline(t,MAXN,'\n');
	int len=strlen(t);
	for(int i=0;i<len;i++){
		t[i]=tolower(t[i]);
	}
	cout<<t<<endl;
	for(int i=0;;i++){
		scanf("%c",&t[i]);
		if(t[i]=='\n')break;
		if(t[i]==' ')continue;
		int flag=1,j;
		for(j=0;j+i<=len&&t[j+i+1]!=' ';j++){
			if(str[j]!=t[j+i])flag=0;
		}
		if(flag){
			ans++;
			cout<<i<<endl;
			if(fir==-1){
				fir=i;
			}
		}
		i+=j;
	}
	if(!ans)cout<<-1;
	else cout<<ans<<" "<<fir;
	return 0;
}

