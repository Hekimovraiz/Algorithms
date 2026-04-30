/// Author: Raiz
#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> Buble_Sort(vector<int> &vec, const int vec_size)
{
    for (int _ = 1; _ <= vec_size; ++_)
    {
        bool flag_swapped = false;
        for (int i = 0; i < vec_size; ++i)
        {
            if (i < vec_size - 1 && vec[i] > vec[i + 1])
            {
                swap(vec[i], vec[i + 1]);
                flag_swapped = true;
            }
        }
        if(!flag_swapped)
        {
            break;
        }
    }
    return vec;
}