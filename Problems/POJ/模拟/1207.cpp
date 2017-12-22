/*
The 3n + 1 problem
题意：计算多少步到达1，l..r中的最大值 
分析：暴力，但不知道错在哪。。。 
*/
#include<iostream>
using namespace std;
int get(int n){
	int ans=1;
	while(n!=1){
		ans++;
		if(n&1)n=3*n+1;
		else n>>=1;
	}
	return ans;
}
int l,r,mx=0;
int main(){
	while(cin>>l>>r){
		mx=0;
		l=min(l,r),r=max(l,r);
		for(int i=l;i<=r;i++){
			mx=max(mx,get(i));
		}
		cout<<l<<" "<<r<<" "<<mx<<endl;
	}
	return 0;
} 
/*int CycleNum(int i){  
    int count=1;  
    while(i!=1){  
        if(i%2)i=3*i+1;  
        else i/=2;  
        count++;  
    }  
    return count;  
}  
int main(){  
    int a,b;  
    while(cin>>a>>b){  
        int x=a<b?a:b;  
        int y=a>b?a:b;  
        int MaxCycle=0;  
        for(int i=x;i<=y;i++){  
            int temp=CycleNum(i);  
            if(MaxCycle<temp)MaxCycle=temp;  
        }  
        cout<<a<<' '<<b<<' '<<MaxCycle<<endl;  
    }  
    return 0;  
}*/ 

