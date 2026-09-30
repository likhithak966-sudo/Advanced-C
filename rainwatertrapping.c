#include<stdio.h>

int maxSum(int arr[],int n,int k)
{
    int windowSum=0;
    int maxSum=0;
     //first window
     for(int i=0;i<k;i++)
     {
        windowSum=windowSum=arr[i];
     }
     maxSum=windowSum;
     for(int i=k;i<n;i++)
     {
        windowSum=windowSum+arr[i]-arr[i-k];
        if(windowSum>windowSum)
        {
            maxSum=windowSum;
        }
     }

}
int main()
{
    int arr[]={2,1,5,1,3,2};
    int n=6;
    int k=3;

}