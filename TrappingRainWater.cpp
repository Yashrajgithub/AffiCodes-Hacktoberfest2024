class Solution{

public: 
long long max(long long a, long long b) {
    return (a > b) ? a : b;
}

long long min(long long a, long long b) {
    return (a < b) ? a : b;
}
long long trappingWater(int arr[], int n) {
    if (n <= 2) return 0; // No water can be trapped if there are less than 3 elements
    
    long long int res = 0;
    long long int lmax[n], rmax[n];
    
    // Initialize lmax array
    lmax[0] = arr[0];
    for (long long int  i = 1; i < n; i++) {
        lmax[i] = max(arr[i], lmax[i-1]);
    }
    
    // Initialize rmax array
    rmax[n-1] = arr[n-1];
    for (long long int  i = n-2; i >= 0; i--) {
        rmax[i] = max(arr[i], rmax[i+1]);
    }
    
    // Calculate the accumulated water element by element
    for (long long int  i = 1; i < n-1; i++) {
        res += (min(lmax[i], rmax[i]) - arr[i]);
    }
    
    return res;
}
};
