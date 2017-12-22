#include<iostream>
#include<algorithm>
using namespace std;
const int RV=17,MV=60,XH=10,RC=4,MAXT=300000;
int m,s,t,ct=0,opt[MAXT+3],run=0,ss=0,i;
int main(){
	cin>>m>>s>>t;
	for(i=1;i<=t;i++){
		run+=RV;
		if(m>=XH){
			m-=XH;
			ss+=MV;
		}
		else m+=RC;
		if(ss>run){
			run=ss;
			opt[i]=ss;
		}
		else opt[i]=run;
		if(opt[i]>s)break;
	}
	if(i>t){
		cout<<"No"<<endl<<opt[t]<<endl;
	}
	else cout<<"Yes"<<endl<<i<<endl;
	return 0;
}

