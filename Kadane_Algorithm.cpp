/// Author: Raiz
#include <bits/stdc++.h>
using namespace std;

int Kadane_Algorithm(vector<int> &arr , const int &arr_size)
{
    int sum = arr[0] , max_sum = arr[0];
    
    for(int i = 0 ; i < arr_size ; ++i)
    {
        sum = max(sum + arr[i] , arr[i]);
        max_sum = max(sum , max_sum);
    }
    
    return max_sum;
}