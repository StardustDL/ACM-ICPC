#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
struct stu{
	string name;
	int qm,bj,lw;
	bool isgb,isxb;
	
	int getjxj(){
		int sum = 0;
		if((qm>80)&&(lw>=1))sum+=8000;
		if((qm>85)&&(bj>80))sum+=4000;
		if(qm>90)sum+=2000;
		if((qm>85)&&(isxb))sum+=1000;
		if((bj>80)&&(isgb))sum+=850;
		return sum;
	}
}t;
int money[101],n,max=0,sum=0;
char yn1,yn2;
string maxname;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t.name;
		scanf("%d %d %c %c %d",&t.qm,&t.bj,&yn1,&yn2,&t.lw);
		t.isgb=yn1=='Y';
		t.isxb=yn2=='Y';
		int p=t.getjxj();
		if(p>max){
			max=p;
			maxname=t.name;
		}
		sum+=p;
	}
	cout<<maxname<<endl<<max<<endl<<sum<<endl;
	return 0;
}
