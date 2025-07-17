#include <iostream>

int read() {
    int n;
    std::cout << "Enter number: ";
    std::cin >> n;
    return n;
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int reverse(int n) {
    int r = 0;
    while (n) r = r * 10 + n % 10, n /= 10;
    return r;
}

bool isPalindrome(int n) {
    return n >= 0 && n == reverse(n);
}

int sumDigits(int n) {
    int s = 0;
    while (n) s += n % 10, n /= 10;
    return s;
}

int main() {
    int c;
    do {
        std::cout << "\n1. Digit sum\n2. Reverse\n3. Prime?\n4. Palindrome?\n5. Exit\nChoice: ";
        std::cin >> c;
        if (c < 1 || c > 5) continue;
        if (c == 5) break;
        int n = read();
        if (c == 1) std::cout << "Sum: " << sumDigits(n) << "\n";
        else if (c == 2) std::cout << "Reverse: " << reverse(n) << "\n";
        else if (c == 3) std::cout << (isPrime(n) ? "Prime\n" : "Not prime\n");
        else if (c == 4) std::cout << (isPalindrome(n) ? "Palindrome\n" : "Not palindrome\n");
    } while (true);
    return 0;
}
