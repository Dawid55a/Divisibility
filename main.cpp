#include <cstdio>
#include <string>
using namespace std;

string pad(string, int);
string multiplication(string, int);
string additionOnString(string, string);
bool divBy2(string);
bool divBy3(string);
bool divBy4(string);
bool divBy5(string);
bool divBy6(string);
bool divBy7(string);
bool divBy8(string);
bool divBy9(string);
bool divBy10(string);
bool divBy11(string);
bool divBy12(string);
bool divBy13(string);
bool divBy14(string);
bool divBy15(string);
bool divBy16(string);
bool divBy17(string);
bool divBy18(string);
bool divBy19(string);
bool divBy20(string);


string pad(string to_pad, int l) {
    string zeros;
    for (int i = 0; i < l - to_pad.length(); ++i) {
        zeros += '0';
    }
    to_pad = zeros + to_pad;
    return to_pad;
}

string multiplication(string first_number, int multiplier){

    string outcome;
    string second_number = first_number;
    int temp;
    int passed_number;
    int temp_int;
    char in;

    // multiple adding the same number
    for (int j = 1; j < multiplier; ++j) {

        outcome = "";
        passed_number = 0;

        // padding shorter with zeros so their the same length
        if (first_number.length() > second_number.length()) {
            second_number = pad(second_number, first_number.length());
        } else {
            first_number = pad(first_number, second_number.length());
        }

        // operations go from end to front
        for (int i = second_number.length() - 1; i >= 0; --i) {

            // adding number passed from last addition operation and our next numbers in column
            temp = passed_number + (first_number[i] - '0') + (second_number[i] - '0');
            // get number that needs to be passed to next iteration
            passed_number = temp / 10;
            // get number that will be in final outcome
            in = (char) (temp % 10) + '0';
            // patch it up together
            outcome = in + outcome;
        }
        // in case with last operation there where passed numbers
        if (passed_number == 0) first_number = outcome;
        else {
            outcome = (char) (passed_number + '0') + outcome;
            first_number = outcome;
        }
    }
    return outcome;
}

string additionOnString(string first_addend, string second_addend) {

    string outcome;
    int temp;
    int passed_number = 0;
    int temp_int;
    char in;
    char multiple_of_addend[12];


    // padding shorter with zeros so their the same length
    if (first_addend.length() > second_addend.length()) {
        second_addend = pad(second_addend, first_addend.length());
    } else {
        first_addend = pad(first_addend, second_addend.length());
    }

    // operations go from end to front
    for (int i = second_addend.length() - 1; i >= 0; --i) {

        // adding number passed from last addition operation and our next numbers in column
        temp = passed_number + (first_addend[i] - '0') + (second_addend[i] - '0');
        // get number that needs to be passed to next iteration
        passed_number = temp / 10;
        // get number that will be in final outcome
        in = (char) (temp % 10) + '0';
        // patch it up together
        outcome = in + outcome;
    }
    // in case with last operation there where passed numbers
    if (passed_number == 0) return outcome;
    else {
        outcome = (char) (passed_number + '0') + outcome;
        return outcome;
    }
}

bool divBy20(string number){
    char last_digit;
    char second_to_last_digit;

    last_digit = number[number.length()-1];
    second_to_last_digit = number[number.length()-2];

    if (last_digit == '0' && ((char)second_to_last_digit - '0')%2 == 0){
        return true;
    }else{
        return false;
    }

}

bool divBy19(string number){

    string last_digit;
    string rest;
    int outcome;

    while (number.length()>3){
        last_digit = number.substr(number.length()-1,1);
        last_digit = multiplication(last_digit, 2);

        rest = number.substr(0,number.length()-1);

        number = additionOnString(rest, last_digit);
    }
    sscanf(number.c_str(), "%d", &outcome);

    if (outcome%19 == 0){
        return true;
    }else{
        return false;
    }
}

bool divBy18(string number){
    if (divBy2(number) && divBy9(number)){
        return true;
    } else{
        return false;
    }
}

bool divBy17(string number){
    string last_digit;
    string rest;
    int outcome;

    while (number.length()>3){
        last_digit = number.substr(number.length()-1,1);
        last_digit = multiplication(last_digit, 9);

        rest = number.substr(0,number.length()-1);
        rest = multiplication(rest,5);

        number = additionOnString(rest, last_digit);
    }
    sscanf(number.c_str(), "%d", &outcome);

    if (outcome%17 == 0){
        return true;
    }else{
        return false;
    }
}

bool divBy16(string number){
    string last_four_digits;
    int lfd_int = 0;

    // check if last 4 digits are divisible by 16
    if (number.length() >= 4) {
        last_four_digits = number.substr(number.length() - 4, 4);
        sscanf(last_four_digits.c_str(), "%d", &lfd_int);
    } else{
        sscanf(number.c_str(), "%d", &lfd_int);
    }

    if (lfd_int%16 == 0){
        return true;
    }else{
        return false;
    }
}

bool divBy15(string number){
    if (divBy3(number) && divBy5(number)){
        return true;
    }else{
        return false;
    }
}

bool divBy14(string number){
    if (divBy2(number) && divBy7(number)){
        return true;
    }else{
        return false;
    }
}

bool divBy13(string number){
    string temp_str;
    int temp_int;
    int sum_of_tri = 0;
    int j = 0;

    for (int i = number.length(); i > 0; i-=3) {

        // border case for not full trio
        if (i<3){
            temp_str = number.substr(0,i);
            sscanf(temp_str.c_str(), "%d", &temp_int);
        }else {
            temp_str = number.substr(i - 3, 3);
            sscanf(temp_str.c_str(), "%d", &temp_int);
        }


        if (j%2 == 0){
            sum_of_tri += temp_int;
        }else{
            sum_of_tri -= temp_int;
        }

        j++;
    }

    // check if alternating sum of blocks of tree is divisible by 13
    if (sum_of_tri%13 == 0){
        return true;
    }else{
        return false;
    }

}

bool divBy12(string number){
    if (divBy3(number) && divBy4(number)){
        return true;
    }else{
        return false;
    }
}

bool divBy11(string number){
    int sum_of_even = 0;
    int sum_of_odd = 0;

    for (int i = 0; i < number.length(); i+=2) {
        sum_of_even += (char)number[i] - '0';
    }
    for (int i = 1; i < number.length(); i+=2) {
        sum_of_odd += (char)number[i] - '0';
    }

    if ((sum_of_even - sum_of_odd)%11 == 0){
        return true;
    }else{
        return false;
    }

}

bool divBy10(string number){

    // check if last number is 0
    if (number[number.length()-1] == '0'){
        return true;
    } else{
        return false;
    }
}

bool divBy9(string number){
    int sum_of_number = 0;

    for (int i = 0; i < number.length(); ++i) {
        sum_of_number += ((char)number[i]-'0');
    }

    // check if sum of number id divisible by 9
    if (sum_of_number%9 == 0){
        return true;
    }else{
        return false;
    }
}

bool divBy8(string number){
    string last_three_digits;
    int ltd_int = 0;

    // check if last 3 digits are divisible by 8
    if (number.length() >= 3) {
        last_three_digits = number.substr(number.length() - 3, 3);
        sscanf(last_three_digits.c_str(), "%d", &ltd_int);
    } else{
        sscanf(number.c_str(), "%d", &ltd_int);
    }

    if (ltd_int%8 == 0){
        return true;
    }else{
        return false;
    }
}

bool divBy7(string number){
    string temp_str;
    int temp_int;
    int sum_of_tri = 0;
    int j = 0;

    for (int i = number.length(); i > 0; i-=3) {

        // border case for not full trio
        if (i<3){
            temp_str = number.substr(0,i);
            sscanf(temp_str.c_str(), "%d", &temp_int);
        }else {
            temp_str = number.substr(i - 3, 3);
            sscanf(temp_str.c_str(), "%d", &temp_int);
        }


        if (j%2 == 0){
            sum_of_tri += temp_int;
        }else{
            sum_of_tri -= temp_int;
        }

        j++;
    }

    // check if alternating sum of blocks of tree is divisible by 7
    if (sum_of_tri%7 == 0){
        return true;
    }else{
        return false;
    }

}

bool divBy6(string number){

    // check if number is divisible by 2 and 3
    if (divBy2(number) && divBy3(number)){
        return true;
    }else{
        return false;
    }
}

bool divBy5(string number){

    // check if last number is divisible by 5
    if (((char)number[number.length()-1]-'0')%5 == 0){
        return true;
    }else{
        return false;
    }
}

// todo: check what happens on single digit input
bool divBy4(string number){
    int last_number;
    int one_before_last_number;

    last_number = (char)number[number.length()-1]-'0';
    one_before_last_number = (char)number[number.length()-2]-'0';

    if (((one_before_last_number*10)+last_number)%4 == 0){
        return true;
    }else{
        return false;
    }
}

// divisibility by 3
bool divBy3(string number){
    int sum_of_number = 0;

    for (int i = 0; i < number.length(); ++i) {
        sum_of_number += ((char)number[i]-'0');
    }

    // check if sum of number id divisible by 3
    if (sum_of_number%3 == 0){
        return true;
    }else{
        return false;
    }
}

// divisibility by 2
bool divBy2(string number){
    // check if last number is divisible by 2
    if (((char)number[number.length()-1]-'0')%2 == 0){
        return true;
    } else{
        return false;
    }
}

bool select(string number, int divider){

    switch (divider) {
        case 2: return divBy2(number);
        case 3: return divBy3(number);
        case 4: return divBy4(number);
        case 5: return divBy5(number);
        case 6: return divBy6(number);
        case 7: return divBy7(number);
        case 8: return divBy8(number);
        case 9: return divBy9(number);
        case 10: return divBy10(number);
        case 11: return divBy11(number);
        case 12: return divBy12(number);
        case 13: return divBy13(number);
        case 14: return divBy14(number);
        case 15: return divBy15(number);
        case 16: return divBy16(number);
        case 17: return divBy17(number);
        case 18: return divBy18(number);
        case 19: return divBy19(number);
        case 20: return divBy20(number);
    }
}

int main() {

    char number [256];
    int divider;

    //todo: check if input is number
    //todo: check if number is < 0

    printf("Number: ");
    scanf("%s", &number);
    printf("\nDivider: ");
    scanf("%d", &divider);

    if (select((string)number, divider)){
        printf("\nNumber %s is divided by %d", number, divider);
    }else{
        printf("\nNumber %s is not divided by %d", number, divider);
    }



    return 0;
}