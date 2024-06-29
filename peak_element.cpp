#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[],int n){
    int high=n-1;
    int low=0;
    int mid,ans;

    while (low<=high)
    {
        mid = (high+low)/2;
 
        if(arr[mid-1]>arr[mid] && arr[mid+1]>arr[mid]){
            mid++;
        }

        if(0<mid<n-1){

            if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
                ans = mid;
                low = mid+1;

            }
            else if(arr[mid-1]>arr[mid] && arr[mid]>arr[mid+1]){
                ans = mid;
                high = mid-1;
            }
            else if(arr[mid-1]<arr[mid] && arr[mid+1]<arr[mid]){
                ans = mid;
                break;
            }

            
        }
        else{
            if(mid==n-1 && arr[mid-1]<arr[mid]){
                ans = mid;
            }
            else if(mid==0 && arr[mid]>arr[mid+1]){
                ans = mid;
            }            

        }
    }
    return ans;
}

int main(){
    int arr[] = {5,4,3,2,1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int ans = peakElement(arr,n);
    cout<<"Index: "<<ans<<endl;

}