// Write recursive C functions to perform the following:
// i. Compute the factorial of a given number.
// ii. Evaluate xⁿ (power of a number).
// iii. Find the GCD of two numbers using the Euclidean algorithm.
// iv. Display the intermediate results of each recursion.
#include <stdio.h>

long long factorial(int n);
double power(double x, int n);
int gcd(int a, int b);

int main() {
    int fact_n = 5;
    printf("--- 1. Calculating Factorial of %d ---\n", fact_n);
    long long fact_result = factorial(fact_n);
    printf("--------------------------------------\n");
    printf("Final Result: %d! = %lld\n\n", fact_n, fact_result);

    double base = 3.0;
    int exp = 4;
    printf("--- 2. Calculating Power(%.1f, %d) ---\n", base, exp);
    double pow_result = power(base, exp);
    printf("--------------------------------------\n");
    printf("Final Result: %.1f^%d = %.2f\n\n", base, exp, pow_result);

    base = 2.0;
    exp = -3;
    printf("--- 2b. Calculating Power(%.1f, %d) ---\n", base, exp);
    pow_result = power(base, exp);
    printf("--------------------------------------\n");
    printf("Final Result: %.1f^%d = %.3f\n\n", base, exp, pow_result);


    int a = 48;
    int b = 18;
    printf("--- 3. Calculating GCD(%d, %d) ---\n", a, b);
    int gcd_result = gcd(a, b);
    printf("--------------------------------------\n");
    printf("Final Result: GCD(%d, %d) = %d\n\n", a, b, gcd_result);

    return 0;
}

long long factorial(int n) {
    printf("factorial(%d) called.\n", n);

    if (n == 0) {
        printf("Base case: factorial(0) = 1. Returning 1\n");
        return 1;
    }
    else {
        long long prev_result = factorial(n - 1);
        long long result = n * prev_result;

        printf("factorial(%d) = %d * %lld (from factorial(%d)). Returning %lld\n",
               n, n, prev_result, n - 1, result);
        return result;
    }
}

double power(double x, int n) {
    printf("power(%.2f, %d) called.\n", x, n);

    if (n == 0) {
        printf("Base case: power(%.2f, 0) = 1. Returning 1.0\n", x);
        return 1.0;
    }
    else if (n > 0) {
        double prev_result = power(x, n - 1);
        double result = x * prev_result;

        printf("power(%.2f, %d) = %.2f * %.2f (from power(%d)). Returning %.2f\n",
               x, n, x, prev_result, n - 1, result);
        return result;
    }
    else {
        double positive_exp_result = power(x, -n);
        double result = 1.0 / positive_exp_result;

        printf("power(%.2f, %d) = 1.0 / %.2f (from power(%d)). Returning %.4f\n",
               x, n, positive_exp_result, -n, result);
        return result;
    }
}

int gcd(int a, int b) {
    printf("gcd(%d, %d) called. ", a, b);

    if (b == 0) {
        printf("Base case (b=0). Returning %d\n", a);
        return a;
    }
    else {
        int remainder = a % b;

        printf("-> Next call: gcd(%d, %d) (since %d %% %d = %d)\n",
               b, remainder, a, b, remainder);

        int result = gcd(b, remainder);

        printf("gcd(%d, %d) returns %d\n", a, b, result);
        return result;
    }
}

