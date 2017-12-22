/*
Maya Calendar
题意：两种日历的转换，注意从0 
*/
#include<cstdio>
#include<cstring>
int main(){
    int t,a,b,mon,day;
    char s[10],ans[21][10]={" ","imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
    scanf("%d",&t);
    printf("%d\n",t);
    while(t--){
        scanf("%d. %s%d",&a,s,&b);
        if(strcmp(s,"pop")==0)mon=1;
        else if(strcmp(s,"no")==0)mon=2;
        else if(strcmp(s,"zip")==0)mon=3;
        else if(strcmp(s,"zotz")==0)mon=4;
        else if(strcmp(s,"tzec")==0)mon=5;
        else if(strcmp(s,"xul")==0)mon=6;
        else if(strcmp(s,"yoxkin")==0)mon=7;
        else if(strcmp(s,"mol")==0)mon=8;
        else if(strcmp(s,"chen")==0)mon=9;
        else if(strcmp(s,"yax")==0)mon=10;
        else if(strcmp(s,"zac")==0)mon=11;
        else if(strcmp(s,"ceh")==0)mon=12;
        else if(strcmp(s,"mac")==0)mon=13;
        else if(strcmp(s,"kankin")==0)mon=14;
        else if(strcmp(s,"muan")==0)mon=15;
        else if(strcmp(s,"pax")==0)mon=16;
        else if(strcmp(s,"koyab")==0)mon=17;
        else if(strcmp(s,"cumhu")==0)mon=18;
        else if(strcmp(s,"uayet")==0)mon=19;
        day=b*365+(mon-1)*20+a+1;
        printf("%d %s %d\n",(day+12)%13+1,ans[(day+19)%20+1],(day-1)/260);
    }
    return 0;    
}
