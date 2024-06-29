#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int largestElement(int arr[], int n){
    int largest=arr[0];
    int index=0;
    for (size_t i = 1; i < n; i++)
    {
        if(arr[i]>largest){
            largest=arr[i];
            index = i;

        }
    }
    return index;
    
}

int bananas(int arr[],int n,int h){
    int index = largestElement(arr,n);
    int largest = arr[index];
    int temp_arr[largest];
    int low=0;
    int high=largest - 1;
    int mid;
    

    for (size_t i = 1; i <= largest; i++)
    {
        temp_arr[i-1] = i;
        // cout<<temp_arr[i]<<" ";
    }

    if(h==n){
        return largest;
    }
    else{
        while (low<=high)
        {
            mid = (high+low)/2;
            cout<<temp_arr[mid]<<" ";
            int time=0;

            for (size_t i = 0; i < n; i++)
            {
                time = time + ceil(float(arr[i])/float(temp_arr[mid]));
            }
            // cout<<time<<endl;
            if(time==h){
                return temp_arr[mid];
            }
            else if(time>h){
                low = mid+1;
            }
            else if(time<h){
                high = mid-1;

            }
            




        }
        
    }
    return -1;
}

int main(){
    int arr[] = {25,12,8,14,19,56,23,96,32};
    int n = sizeof(arr)/sizeof(arr[0]);
    int h=20;
    int ans = bananas(arr,n,h);
    cout<<ans<<endl;


}