//Call Power(a,b) return a raised to the power b in O(Logb) time Complexity. 

long long power(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}    


