
/*
Elevator Stopping Plan 
���⣺N����Ҫ��f1,f2...fn��¥����֪����ÿ��һ��Ҫ4�룬��ĳһ��Ҫͣ��10�룬����¥����һ��Ҫ20�롣��������˶������Լ���ȥ��¥������ʱ�䡣
����������+̰�ġ���ʱ����֣�̰�ĵ��ж�����̶���ʱ�����Ƿ����������˵����Լ���ȥ��¥�㡣̰�ĵ��жϾ����õ��ݾ����ܵ������ܣ��Ը�Ҫ���ϸ�¥����˽�ʡ�м�ͣ��ʱ�䣬����ʱ��Ƚϳ�ԣ�ĵ��ϵͲ���˾����ܶ���¥�ݣ��Ӷ�������ʱ����С��
*/
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int fl[30010],n;
bool OK(int time){
    int pos=1,curt=0,tmp;
    bool mark=false;
    for(int i=0;i<n;i++){
        if((fl[i]-pos)*20+curt>time){//���в����� 
            if(mark)curt+=10;
            if((fl[i]-pos)*4+curt>time)return false;
            for(tmp=fl[i];(tmp-pos)*4+(tmp-fl[i])*20+curt<=time;tmp++);//���������ߣ�ֱ���ߵ�����Ҫͣ 
            tmp--;
            curt+=(tmp-pos)*4;
            pos=tmp;mark=true;
        }
    }
    return true;
}
int main(){
    int st,ed;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++)scanf("%d",&fl[i]);
        st=(fl[0]-1)*4-1;
        ed=(fl[n-1]-1)*20;
        while(ed-st>1){
            int m=(st+ed)>>1;
            if(OK(m))ed=m;
            else st=m;
        }
        printf("%d\n",ed);
    }
    return 0;
}


