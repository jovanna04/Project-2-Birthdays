/**
 * test.cpp
 * Project UID: d27ac2f9d9ef51141f8207ca61bd9b22d96076f1
 * 
 * Jovanna Gallegos
 * jovanna
 *
 * EECS 183: Project 2
 *
 * Tests for each function in birthdays.cpp
 */

#include <cassert>
#include <cctype>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


//************************************************************************
// You should have implemented the following functions in birthdays.cpp
//************************************************************************
int getMenuChoice();
bool isLeapYear (int year);
bool isGregorianDate(int m, int d, int y);
bool isValidDate(int month, int day, int year);
int determineDay (int month, int day, int year);
void printDayOfBirth(int day);
void determineDayOfBirth();
void print10LeapYears();

//************************************************************************
// Testing function declarations. Function definition is below main.
// Tests not run by these functions will not be run by the autograder.
//************************************************************************
void test_getMenuChoice();
void test_isGregorianDate();
void test_isLeapYear();
void test_isValidDate();
void test_determineDay();
void test_printDayOfBirth();
void test_determineDayOfBirth();
void test_print10LeapYears();

void startTests()
{
    // TEST FUNCTIONS BELOW:
    test_getMenuChoice();
    test_isGregorianDate();
    test_isLeapYear();
    test_isValidDate();
    test_determineDay();
    test_printDayOfBirth();
    test_determineDayOfBirth();
    test_print10LeapYears();
}

void test_getMenuChoice()
{
    // getMenuChoice reads from cin, so you will need to
    // provide directions to the user for each test case
    cout << "Now testing funtion getMenuChoice()\n";
    cout << "Please enter 3:" << endl;
    int choice1 = getMenuChoice();
    cout << "Test result: expected: 3, actual: " << choice1 << endl;

    cout << "Please enter 5 then 1:";
    int choice2 = getMenuChoice();
    cout << "Test result: " << endl;
    cout << "Expected: \"Invalid menu choice\", then 1." << endl;
    cout << "Actual: " << choice2 << endl;

    cout << "Please enter 1:" << endl;
    int choice3 = getMenuChoice();
    cout << "Test result: Expected: 1, actual: " << choice3 << endl;
}

void test_isGregorianDate()
{
    cout << "Now testing function isGregorianDate()\n";
    
    cout << "9/2/2019:  Expected: 1, Actual: " << isGregorianDate(9, 2, 2019) << endl;
    cout << "1/31/1001: Expected: 0, Actual: " << isGregorianDate(1, 31, 1001) << endl;
    cout << "7/6/2004: Expected 1, Actual: " << isGregorianDate(7, 6, 2004) << endl;
    cout << "9/13/1752: Expected: 0, Actual: " << isGregorianDate(9, 13, 1752) << endl;
    cout << "11/11/1111: Expected: 0, Actual: " << isGregorianDate(11, 11, 1111) << endl;
    cout << "9/14/1752: Expected: 1, Actual: " << isGregorianDate(9, 14, 1752) << endl;
    cout << "10/7/2001: Expected: 1, Actual: " << isGregorianDate(10, 7, 2001) << endl;
    cout << "3/13/1751: Expected: 0, Actual: " << isGregorianDate(3, 13, 1751) << endl;
    
    cout << "End testing isGregorianDate()" << endl << endl;
}

void test_isLeapYear()
{
    cout << "Now testing function isLeapYear()\n" << endl;
    
    cout << "2004: Expected: 1, Actual: " << isLeapYear(2004) << endl;
    cout << "2000: Expected: 1, Actual: " << isLeapYear(2000) << endl;
    cout << "2001: Expected: 0, Actual: " << isLeapYear(2001) << endl;
    cout << "1972: Expected: 1, Actual: " << isLeapYear(1972) << endl;
    cout << "1897: Expected: 0, Actual: " << isLeapYear(1897) << endl;
    cout << "2022: Expected: 0, Actual: " << isLeapYear(2022) << endl;
    
    cout << "End testing isLeapYear()" << endl << endl;
}

void test_isValidDate()
{
    cout << "Now testing function isValidDate()\n" << endl;
    
    cout << "1/11/1111: Expected: 0, Actual: " << isValidDate(1, 11, 1111) << endl;
    cout << "10/7/2001: Expected: 1, Actual: " << isValidDate(10, 7, 2001) << endl;
    cout << "2/29/1972: Expected: 1, Actual: " << isValidDate(2, 29, 1972) << endl;
    cout << "2/29/1979: Expected: 0, Actual: " << isValidDate(2, 29, 1979) << endl;
    cout << "3/40/2022: Expected: 0, Actual: " << isValidDate(3, 40, 2022) << endl;
    
    cout << "End testing isValidDate()\n" << endl << endl;
}

void test_determineDay()
{
    cout << "Now testing function determineDay()\n" << endl;
    
    cout << "4/21/1759: Expected: 0, Actual: " << determineDay(4, 21, 1759) << endl;
    cout << "3/17/1968: Expected: 1, Actual: " << determineDay(3, 17, 1968) << endl;
    cout << "1/7/2002: Expected: 2, Actual: " << determineDay(1, 7, 2002) << endl;
    cout << "2/29/1972: Expected: 3, Actual: " << determineDay(2, 29, 1972) << endl;
    cout << "9/28/2022: Expected: 4, Actual: " << determineDay(9, 28, 2022) << endl;
    cout << "12/24/1812: Expected: 5, Actual: " << determineDay(12, 24, 1812)<< endl;
    cout << "8/1/2003: Expected: 6, Actual: " << determineDay(8, 1, 2003) << endl;
    
    cout << "End testing determineDay()\n" << endl << endl;
}

void test_printDayOfBirth()
{
    cout << "Now testing function printDayOfBirth()\n";
    
    cout << "0: Expected: Saturday, Actual: ";
        printDayOfBirth(0);
        cout << endl;
    cout << "1: Expected: Sunday, Actual: ";
        printDayOfBirth(1);
        cout << endl;
    cout << "2: Expected: Monday, Actual: ";
        printDayOfBirth(2);
        cout << endl;
    cout << "3: Expected: Tuesday, Actual: ";
        printDayOfBirth(3);
        cout << endl;
    cout << "4: Expected: Wednesday, Actual: ";
        printDayOfBirth(4);
        cout << endl;
    cout << "5: Expected: Thursday, Actual: ";
        printDayOfBirth(5);
        cout << endl;
    cout << "6: Expected: Friday, Actual: ";
        printDayOfBirth(6);
        cout << endl;
    
    cout << "End testing funtion printDayOfBirth()\n";
}

void test_determineDayOfBirth()
{
    cout << "Now testing function determineDayOfBirth()\n" << endl;
    
    cout << "Please enter 9 / 28 / 2022: " << endl;
        cout << "Expected: You were born on a Wednesday... , Actual: " << endl;
        determineDayOfBirth();
        cout << endl;
    cout << "Please enter 7 / 6 / 2004: " << endl;
        cout << "Expected: You were born on a Tuesday... , Actual: " << endl;
        determineDayOfBirth();
        cout << endl;
    cout << "Please enter 1 / 11 / 1750: " << endl;
        cout << "Expected: Invalid Date, Actual: " << endl;
        determineDayOfBirth();
        cout << endl;
    cout << "Please enter 2 / 23 / 1752: " << endl;
        cout << "Expected: Invalid Date, Actual: " << endl;
        determineDayOfBirth();
        cout << endl;
    cout << "Please enter 1 / 11 / 1111: " << endl;
        cout << "Expected: Invalid Date, Actual: " << endl;
        determineDayOfBirth();
        cout << endl;
    
    cout << "End testing function print10LeapYears()\n" << endl;
}

void test_print10LeapYears()
{
    cout << "Now testing function print10LeapYears()\n" << endl;
    
    cout << "Year 1996: Expected: " << endl;
        cout << "Leap year is 2000" << endl << "Leap year is 2004" << endl;
        cout << "Leap year is 2008" << endl << "Leap year is 2012" << endl;
        cout << "Leap year is 2016" << endl << "Leap year is 2020" << endl;
        cout << "Leap year is 2024" << endl << "Leap year is 2028" << endl;
        cout << "Leap year is 2032" << endl << "Leap year is 2036" << endl;
        cout << "Year 1996: Actual: " << endl;
        print10LeapYears();
        cout << endl;
    cout << "Year 1752: Expected: " << endl;
        cout << "Leap year is 1756" << endl << "Leap year is 1760" << endl
            << "Leap year is 1764" << endl << "Leap year is 1768" << endl
            << "Leap year is 1772" << endl << "Leap year is 1776" << endl
            << "Leap year is 1780" << endl << "Leap year is 1784" << endl
            << "Leap year is 1788" << endl << "Leap year is 1792" << endl;
        cout << "Year 1752: Actual: " << endl;
        print10LeapYears();
        cout << endl;
    cout << "Year 2048: Expected: " << endl;
        cout << "Leap year is 2052" << endl << "Leap year is 2056" << endl;
        cout << "Leap year is 2060" << endl << "Leap year is 2064" << endl;
        cout << "Leap year is 2068" << endl << "Leap year is 2072" << endl;
        cout << "Leap year is 2076" << endl << "Leap year is 2080" << endl;
        cout << "Leap year is 2084" << endl << "Leap year is 2088" << endl;
        cout << "Year 2048: Expected: " << endl;
        print10LeapYears();
        cout << endl;
    
    cout << "End testing function print10LeapYears()\n" << endl;
}
