class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            
            // Check for overflow before multiplying by 10
            if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
            if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && pop < -8)) return 0;
            
            reversed = (reversed * 10) + pop;
        }
        return reversed;
    }
};

// The 7 and -8 come directly from the absolute last digits of the maximum and minimum values a signed 32-bit integer can hold. INT_MAX is exactly 2,147,483,647 (ends in 7) INT_MIN is exactly -2,147,483,648 (ends in 8)

// In C++, the modulo operator (%) preserves the sign of the dividend.