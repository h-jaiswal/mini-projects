#include <iostream>

using namespace std;
int * bin_search( int * arr, int n, int l, int r, int x, int * out, int i)
{
    if (r>=l)
    {
        int mid = (l + (r-1) ) / 2;
        if (arr[mid] == x)
        {
            out[i] = mid;
            l = mid + 1;
            r = n - 1;
            return out;
        }
        if (arr[mid] > x)
        {
            return bin_search(arr, n, l, mid-1, x, out, i+1);
        }
        return bin_search(arr, n, mid+1, r, x, out, i+1);
    }
    out[i] = -1;
    return out;
}
int main() {
    int n;
    cin >> n;
    int * arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    int * out = new int[n];
    for (int i = 0; i < n; i++)
    {
        out[i] = -2;
    }
    
    out = bin_search( arr, n, 0, n-1, x , out, 0);

    for (int i = 0; i < n; i++)
    {
        if (out[i] == -2)
        {
            break;
        }

        cout << out[i] << " ";
    }
    
    delete [] out;
    delete [] arr;
    return 0;
}