/*
 * ISBN Verifier.
 * This program will verify the check digit in any 13 digit ISBN number.
 * Constraints:  Each digit must be processed one at a time and cannot be stored.
 */

#include <iostream>
#define EOL 10
#define CHECKSUM_DIGIT 12
#define MULTIPLIER 3
#define CALCULATED_CHECKSUM 10 - running_total%10
#define DIGIT (digit - 48)


int main() {
    char digit{0};
    int running_total{0};
    int total_digits{0};

    std::cout << "Enter the ISBN Number" << std::endl;
    digit = std::cin.get();

    while(digit != EOL){
        //check for even
        if(0 == (++total_digits % 2)){
            running_total += DIGIT * MULTIPLIER;
        }

        else {
            running_total += DIGIT;
        }

        digit = std::cin.get();
        if(digit == EOL){
            std::cout << "ISBN enter less than 13 digits";
        }

        if(CHECKSUM_DIGIT == total_digits){
            if(DIGIT == CALCULATED_CHECKSUM){
                std::cout << "ISBN number valid" << std::endl;
                digit = EOL;
            }

            else{
                std::cout << "ISBN number invalid" << std::endl;
                digit = EOL;
            }
        }
    }
    return 0;
}