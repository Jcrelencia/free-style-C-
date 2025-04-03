#include <iostream>

// Declaring functions
bool is_power_of_2_with_loops(int num);
bool is_power_of_2_without_loops(int num);
bool is_prime_number(int num);
bool reduce_fraction(int den);  //numerator and denominator
void result_reduce_fraction(int numerator ,int denominator);
void test_prime_number(int num);
void test_power_of_two(int num);


int main() {
    // Loop to test numbers 1-10
    for (int num = 1; num <= 10; num++) {
        result_reduce_fraction(12,14);
        result_reduce_fraction(3,2);
        std::cout << "Checking number: " << num << "\n";
        test_power_of_two(num);
        test_prime_number(num);
        std::cout << "------------------------\n";  // Separator for clarity
    }
    return 0;
}

// Function to test both methods and print results
void test_power_of_two(int num) {
    // Test using the loop method
        bool result_with_loops = is_power_of_2_with_loops(num);
        if (result_with_loops) { //also meaning if true
            std::cout << "Using loops, " << num << " is a power of two.\n";
        } else { //meaning if false
            std::cout << "Using loops, " << num << " is not a power of two.\n";
        }

    // Test using the bitwise method
    bool result_without_loops = is_power_of_2_without_loops(num);
    if (result_without_loops) {
        std::cout << "Without loops, " << num << " is a power of two.\n";
    } else {
        std::cout << "Without loops, " << num << " is not a power of two.\n";
    }
}

// Function to find if a number is a power of 2 using loops
bool is_power_of_2_with_loops(int num) {
    if (num <= 0) return false; // Ensure num is positive
    while (num != 1) {
        if (num % 2 != 0) {
            return false; // If num is not divisible by 2, it's not a power of 2
        }
        num = num / 2; // Keep dividing by 2
    }
    return true; // If we reach 1, it's a power of 2
}

// Function to find if a number is a power of 2 without using loops (using bitwise operations)
bool is_power_of_2_without_loops(int num) {
    return num > 0 && (num & (num - 1)) == 0; // Check if num has exactly one bit set
}

void test_prime_number(int num) {
    bool result_prime_number = is_prime_number(num);
    if (result_prime_number) {
        std::cout << "PASS.\n" << std::endl;
    } else {
        std::cout << "FAIL.\n" << std::endl;
    }
}


bool is_prime_number(int num) {
    if (num <= 1) return false;  //prime numbers cant be lower than 2
    for ( int i  = 2; i <= (num / 2 ); i++) {  // This loop basically sees if the number when divisible down to its lower self will return with a remainder of zero
        if (num % i == 0) return false; // since it's divisible by other numbers than itself, that means it is not a prime number.
    }
    return true;

}
int gcd(int numerator, int denominator) {
    // to reduce a fraction once, it's easiest by finding the gcd.
    while (denominator != 0) { //fractoion cant have zero
        int temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
    }
    return numerator;
}

bool is_reduced_fraction(int numerator, int denominator) { // I did look up online to see how to make this function return a correct bool.
    int divisor = gcd(numerator, denominator); //so the divsor is the gcd of the fraction, which is calculated by the gcd above
    if (divisor > 1) {
        numerator = numerator / divisor;
        denominator = denominator / divisor;
        return true;
    }
    return false;
}

void result_reduce_fraction(int num, int den) {
    int divisor = gcd(num, den);
    if (divisor > 1){
        std::cout << "TRUE" << std::endl;
    } else {
        std::cout << "FALSE" << std::endl;
    }
}