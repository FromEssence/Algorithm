inv[1] = 1;
for(int i = 2; i < p; ++ i) //p为模数
    inv[i] = (p - p / i) 1ll** inv[p % i] % p; // care overflow
