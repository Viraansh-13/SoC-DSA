#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> printSpiral(vector<vector<int>> mat){
    vector<int> ans;
    int n = mat[0].size();
    int m = mat.size();
    int right_bound=n-1;
    int bottom_bound=m-1;
    int left_bound=0;
    int top_bound=0;

while (left_bound<=right_bound && top_bound<=bottom_bound)
{
    for (size_t i = left_bound; i <= right_bound; i++)
    {
        ans.push_back(mat[top_bound][i]);   
    }
    top_bound++;

    for (size_t i = top_bound; i <= bottom_bound; i++)
    {
        ans.push_back(mat[i][right_bound]);
    }
    right_bound--;

    if(top_bound<=bottom_bound){

        for (size_t i = right_bound; i >= left_bound; i--)
        {
            ans.push_back(mat[bottom_bound][i]);
        }
        bottom_bound--;
    }

    if(left_bound<=right_bound){

    for (size_t i = bottom_bound; i >= top_bound; i--)
    {
        ans.push_back(mat[i][left_bound]);
    }
    left_bound++;
    }
}

    return ans;
}

int main(){
    vector<vector<int>> mat ={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    vector<int> ans = printSpiral(mat);

    for (size_t i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;


}