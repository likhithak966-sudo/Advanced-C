#include<stdio.h>

int maxsum(int arr[],int n,int K){
    int windowsum=0;
    int maxsum=0;
    for(int i=0;i<k;i++){
        windowsum=arr[i];
    }
    maxsum=windowsum;
    for(int i=k;i<n;i++){
        windowsum=windowsum+arr[i]-arr[i-k];
        if(windowsum>maxsum){
            maxsum=windowsum;
        }
}

int main(){
    int arr[]={2,1,5,1,3,2};
    int n=6;
    int k=3;
}