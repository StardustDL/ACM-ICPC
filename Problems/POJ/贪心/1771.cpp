/*
Elevator Stopping Plan 
���⣺N����Ҫ��f1,f2...fn��¥����֪����ÿ��һ��Ҫ4�룬��ĳһ��Ҫͣ��10�룬����¥����һ��Ҫ20�롣��������˶������Լ���ȥ��¥������ʱ�䡣
����������+̰�ġ���ʱ����֣�̰�ĵ��ж�����̶���ʱ�����Ƿ����������˵����Լ���ȥ��¥�㡣̰�ĵ��жϾ����õ��ݾ����ܵ������ܣ��Ը�Ҫ���ϸ�¥����˽�ʡ�м�ͣ��ʱ�䣬����ʱ��Ƚϳ�ԣ�ĵ��ϵͲ���˾����ܶ���¥�ݣ��Ӷ�������ʱ����С��
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
using namespace std;
int fl[33],n,Ans;
vector<int> ans;
vector<int> temp;
bool check(int time){
	temp.clear(); 
    int pos=1,curt=0,tmp;
    for(int i=1;i<=n;i++){
        if(fl[i]<=pos||curt+(fl[i]-pos)*20<=time)continue;
        tmp=(time-curt+4*pos+20*fl[i]-(pos!=1?10:0))/24;//ʣ��ʱ������������ 
        if(tmp<fl[i])return false;
		curt+=(tmp-pos)*4+(pos!=1?10:0);
		pos=tmp;
		temp.push_back(pos);
    }
    return true;
}
int main(){
    int st,ed;
    while(scanf("%d",&n),n){
        for(int i=1;i<=n;i++)scanf("%d",&fl[i]);
        Ans=fl[n]*4+20*(fl[n]-fl[1]);
        int l=0,r=Ans-1,mid;
        while(l<r){
        	mid=(l+r)>>1;
        	if(check(mid)){
        		Ans=mid,ans=temp; 
        		r=mid;
			}
			else l=mid+1;
		}
		printf("%d\n%d ",Ans,ans.size());
        for(int i=0;i<ans.size();i++)printf("%d ",ans[i]);puts("");
    }
    return 0;
}


