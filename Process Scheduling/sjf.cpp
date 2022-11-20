#include<bits/stdc++.h>
using namespace std;

void waitTime(int p[],int bt[],int n,int wt[]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                swap(bt[j],bt[j+1]);
                swap(p[j],p[j+1]);
            }
        }
    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=bt[i-1]+wt[i-1];
    }
}

void turnAroundTime(int p[],int bt[],int wt[],int n,int tat[]){
    for(int i=0;i<n;i++) tat[i]=wt[i]+bt[i];
}

void avgTimeCalc(int p[],int bt[],int n){
    int wt[n],tat[n];
    waitTime(p,bt,n,wt);
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
    int bt[]={12,15,5,10};
    int n=4;
    avgTimeCalc(p,bt,n);
    return 0;
}