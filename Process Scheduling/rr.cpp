#include<bits/stdc++.h>
using namespace std;

void waitTime(int p[],int bt[],int n,int tq,int wt[]){
    int remBT[n];
    for(int i=0;i<n;i++) remBT[i]=bt[i];
    int curTime=0;
    while(true){
        bool done=true;
        for(int i=0;i<n;i++){
            if(remBT[i]>0){
                done=false;
                if(remBT[i]>tq){
                    curTime+=tq;
                    remBT[i]-=tq;
                }
                else{
                    curTime+=remBT[i];
                    wt[i]=curTime-bt[i];
                    remBT[i]=0;
                }
            }
        }
        if(done) break;
    }
}

void turnAroundTime(int p[],int bt[],int wt[],int n,int tat[]){
    for(int i=0;i<n;i++) tat[i]=wt[i]+bt[i];
}

void avgTimeCalc(int p[],int bt[],int n,int tq){
    int wt[n],tat[n];
    waitTime(p,bt,n,tq,wt);
    turnAroundTime(p,bt,wt,n,tat);
    cout<<"Process ID\t"<<"Burst Time\t"<<"Waiting Time\t"<<"Turn Around Time\n";
    int totwt=0,tottat=0;
    for(int i=0;i<n;i++){
        totwt+=wt[i];
        tottat+=tat[i];
        cout<<p[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    cout<<endl<<endl;
    cout<<"Average Waiting Time:"<<float(totwt)/float(n)<<endl;
    cout<<"Average Turn Around Time:"<<float(tottat)/float(n)<<endl;
}

int main(){
    int p[]={0,1,2,3};
    int bt[]={10,5,15,20};
    int tq=5;
    int n=4;
    avgTimeCalc(p,bt,n,tq);
    return 0;
}