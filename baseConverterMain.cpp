#include <iostream>
#include <stdlib.h>
//base 1 - 16 to decimal converter

int base();
int switcher(int num);
std::string input();

//Main converts base x to decimal form
int main(){
    int x = base();
    std::string num = input();
    int y = 0;
    int dec = 0;
    for (int n = num.length() - 1; n >= 0; n--) {
        //num.length() - 1  because string selection [] begins at 0, while the .length() counter begins at 1
        if (switcher(num[n]) > x - 1) {
            /*x - 1 because any base x doesn't include digit x, it completes at x - 1. Base 2
             * only has digits 0 and 1, not 2*/
            std::cout << "That's an incorrect notation of base " << x << ". Please try again.";
            return 0;
        }
        dec = dec + switcher(num[n]) * pow(x, y);
        y++;
    }
    std::cout << num << " in base " << x << " is written as " << dec << " in decimal form.\n";
    return 0;
}

//Asks the user to input the base they're converting from
int base() {
    int base;
    do {
        std::cout << "Input the base: ";
        std::cin >> base;
    }
    while (base > 16);
    return base;
}

//Asks the user to input their chosen integer
std::string input() {
    std::cout << "Input an integer: ";
    std::string num;
    std::cin >> num;
    return num;
}

//Translates each char from input string into their respective integer form from 1-9
int switcher(int num){
    switch (num) {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        case 'A':
            return 10;
        case 'B':
            return 11;
        case 'C':
            return 12;
        case 'D':
            return 13;
        case 'E':
            return 14;
        case 'F':
            return 15;
        default:
            std::cout << "You have entered an invalid integer\n";
            exit(0);
    }
}
