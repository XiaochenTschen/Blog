#### 最大公因数 Greatest Common Divider
```c++
int gcd(int a, int b) {
    while(b) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}
```

#### 最小公倍数 Leatest Common Multiple
```c++
int lcm(int a, int b) {
    return (a*b)/gcd(a, b);
}
```

#### 筛选法计算质数 Count Primes
```c++
int countPrimes(int n) { /* return number of primes less than n */
    if(n < 2) return 0;
    std::vector<bool> isPrime(n, true);
    int count = n - 2; /* 1 are not prime and n is not considered*/
    for(int i = 2; i*i < n; ++i) {
        for(int j = i*i; j < n; j += i) {
            if(isPrime[j]) {
                isPrime[j] = false;
                --count;
            }
        }
    }
    return count;
}
```
#### 进制转换
```c++
/*十进制转其他进制，输是字符串*/
std::string decToBase(int num, int base) {
    bool isNegative = false;
    if(num< 0) {
        isNegative = true;
        num = -num;
    }
    std::string ans;
    while(num != 0) {
        int tmp = num%base;
        char c;
        if(tmp >= 10) {
            c = 'A' + tmp- 10;
        }
        else {
            c = '0' + tmp;
        }
        ans = c + ans;
        num = num/base;
    }
    return isNegative ? "-"+ans : ans;
}

/*其他进制转十进制*/
int baseToDec(const std::string& num, int base) {
    int result = 0;
    int power = 1; // 记录当前权重
    for (int i = num.size() - 1; i >= 0; --i) {
        int digit = (isdigit(num[i]) ? num[i] - '0' : num[i] - 'A' + 10);
        result += digit * power;
        power *= base;
    }
    return result;
}
```
