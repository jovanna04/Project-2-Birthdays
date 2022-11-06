/**
 * birthdays.cpp
 * Project UID: 59fc568b7f83f8c109ae360f448f7f821ba0a71
 * 
 * Jovanna Gallegos
 * jovanna
 *
 * EECS 183: Project 2
 *
 * Project 2 ladies and gentleman, or at least what I could make of the specs
 */

#include <cmath>
#include <iostream>
#include <string>

using namespace std;


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the initial heading for the program
 */
void printHeading();


/**
 * REQUIRES: nothing
 * MODIFIES: cout
 * EFFECTS:  Prints out the final greeting for the program
 */
void printCloser();


/**
 * REQUIRES: nothing
 * MODIFIES: cout 
 * EFFECTS:  Prints the menu text. Does not read from cin.
 */
void printMenu();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  1. Prints the menu
 *           2. Reads the input from the user
 *           3. Checks to make sure the input is within range for the menu
 *              If not prints "Invalid menu choice"
 *           4. Continues to print the menu and read an input until 
 *              a valid one is entered
 *           5. Returns the user's choice of menu options
 * 
 *           This function must call printMenu().
 */
int getMenuChoice();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year represent a valid date
 * MODIFIES: nothing
 * EFFECTS:  Returns true if the date is in the limits
 *           of the Gregorian calendar otherwise returns false
 *           See the spec for definition of "limits of the Gregorian calendar"
 */
bool isGregorianDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: year is a Gregorian year
 * MODIFIES: nothing
 * EFFECTS:  returns true if the year is a leap year
 *           otherwise returns false.
 *           See the spec for definition of a leap year.
 */
bool isLeapYear(int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year may represent a date
 * MODIFIES: nothing
 * EFFECTS:  returns true if the date is valid
 *           otherwise returns false
 *           See the spec for definition of "valid"
 */
bool isValidDate(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: month, day, year is a valid date
 *           i.e., the date passed to this function has already passed
 *               isValidDate()
 * MODIFIES: nothing
 * EFFECTS:  returns the value f that Zeller's formula calculates
 */
int determineDay(int month, int day, int year);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: day is a value of f output by Zeller's formula
*            (0 represents Saturday, 1 Sunday, 2 Monday, 3 Tuesday, etc)
 * MODIFIES: cout
 * EFFECTS:  prints the day of the week corresponding to day, suchas
 *           "Sunday", "Monday", ..., "Saturday"
 */
void printDayOfBirth(int day);

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cout, cin
 * EFFECTS:  Asks for the month / day / year of the user's birthday.
 *           If the date is valid, it will print the day
 *           of the week you were born on
 *           Otherwise, it will print "Invalid date" prompt.
 */
void determineDayOfBirth();

/**
 * Note:  write your test cases in test.cpp BEFORE you implement this function
 *
 * REQUIRES: nothing
 * MODIFIES: cin, cout
 * EFFECTS:  Asks for a Gregorian year and prints the
 *           10 leap years after (not including) the year entered.
 *           If the year is invalid, it prints nothing.
 *
 *           This function must call isLeapYear().
 */
void print10LeapYears();

/* 
 * EFFECTS: Main driver for the Birthdays program. See the
 *          "Putting it Together" section of the spec for what
 *          this function needs to accomplish.
 */
void birthdays() {
    printHeading();
    int userChoiceBirthdays = getMenuChoice();
    
    while (userChoiceBirthdays != 3) {
        if (userChoiceBirthdays == 1) {
            determineDayOfBirth();
            userChoiceBirthdays = getMenuChoice();
            
        } else if (userChoiceBirthdays == 2){
            print10LeapYears();
            userChoiceBirthdays = getMenuChoice();
        }
        if (userChoiceBirthdays == 3){
        }
    }
    return printCloser();
}

void printHeading() {
    cout << "*******************************" << endl
         << "      Birthday Calculator      " << endl
         << "*******************************" << endl << endl;
    return;
}

void printCloser() {
    cout << endl;
    cout << "****************************************************" << endl
         << "      Thanks for using the Birthday Calculator      " << endl
         << "****************************************************" << endl
         << endl;
    return;
}

void printMenu() {
    cout << endl;
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Determine day of birth" << endl;
    cout << "2) Print the next 10 leap years" << endl;
    cout << "3) Finished" << endl << endl;
    
    cout << "Choice --> ";
    return;
}

int getMenuChoice() {
    // calling printMenu()
    printMenu();
    int userChoice = 0;
    cin >> userChoice;
    // what to do after user inputs their choice
    while (!(userChoice == 1 || userChoice == 2 ||userChoice == 3)) {
        cout << endl << "Invalid menu choice" << endl;
        printMenu();
        cin >> userChoice;
    }
    // returning userChoice to avoid compile error
    return userChoice;
}

bool isGregorianDate(int month, int day, int year) {
    // any year before 1752 is not gregorian
    if (year < 1752) {
        return false;
    }
    // any date after September 14, 1752 is gregorian
    if (year == 1752 && month < 9) {
        return false;
    }   else if ((year == 1752) && (month == 9) && (day < 14)) {
        return false;
    }
        // returning false to avoid compile error
    return true;
}

bool isLeapYear(int year) {
    // any year that is not and is a leap year
    if ((year % 4)!= 0) {
        return false;
    } else if ((year % 100) == 0) {
        if ((year % 400) == 0) {
            return true;
        } else {
            return false;
        }
    }
    // returning true to avoid compile error
    return true;
}


bool isValidDate(int month, int day, int year) {
    // if it fails gregorian, it is not valid
    if (!isGregorianDate(month, day, year)) {
        return false;
    } else {
    // January, March, May , July, August
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8) {
            if (day >= 1 && day <= 31) {
                return true;
            } else {
                return false;
            }
        }
    // February
        if (month == 2) {
            if ((isLeapYear(year)) == false) {
                if (day >= 1 && day <= 28) {
                    return true;
                }
            } if (isLeapYear(year)) {
                if (day >= 1 && day <= 29) {
                    return true;
                } else {
                    return false;
                }
            }
        }
    // April, June, September, November
        if (month == 4 || month == 6 || month == 9 || month == 11) {
            if (day >= 1 && day <= 30) {
                return true;
            } else {
                return false;
            }
        }
    // October
        if (month == 10) {
            if (day >= 1 && day <= 31){
                return true;
            } else {
                return false;
            }
        }
    // December
        if (month == 12) {
            if (day >= 1 && day <= 31) {
                return true;
            } else {
                return false;
            }
        }
    // returning false to avoid compile error
            return false;
        }
    }
            
int determineDay(int month, int day, int year) {
    // TODO: implement
    //Start of Zeller's Formula section
    int D = day;
    int M = month;
        // Converting January to Zeller's
    if (month == 1) {
        M = 13;
        year = year - 1;
    }
        // Converting February to Zeller's
    if (month == 2) {
        M = 14;
        year = year - 1;
    }
    int Y = year % 100;
    int C = year / 100;
    int floorM = floor((13 * (M + 1)) / 5);
    int floorY = floor(Y / 4);
    int floorC = floor(C / 4);
    // End of Zeller's Formula section
    int f = (D + floorM + Y + floorY + floorC + 5 * C) % 7;
    //return f to avoid compilation error
    return f;
}

void printDayOfBirth(int day) {
    // 0 = Saturday, 1 = Sunday, 2 = Monday, 3 = Tuesday
    // 4 = Wednesday, 5 = Thursday, 6 = Friday
      if (day == 0) {
          cout << "Saturday";
      } else if (day == 1) {
          cout << "Sunday";
      } else if (day == 2) {
          cout << "Monday";
      } else if (day == 3) {
          cout << "Tuesday";
      } else if (day == 4) {
          cout << "Wednesday";
      } else if (day == 5) {
          cout << "Thursday";
      } else if (day == 6) {
          cout << "Friday";
      }
}

void determineDayOfBirth() {
    // Ask user for their DOB
    cout << endl << "Enter your date of birth" << endl;
    cout << "format: month / day / year  --> ";
    int userMonth;
    int userDay;
    int userYear;
    char userForward1;
    char userForward2;
    cin >> userMonth >> userForward1 >> userDay >> userForward2 >> userYear;
    // if it is not or is a valid date
    if (!isValidDate(userMonth, userDay, userYear)) {
        cout << endl << "Invalid date" << endl;
    } else {
        int userDOB = determineDay(userMonth, userDay, userYear);
        cout << endl << "You were born on a: ";
        printDayOfBirth(userDOB);
        cout << endl;
        cout << endl << "Have a great birthday!!!" << endl;
    }
    // avoid complilation error
    return;
}

void print10LeapYears() {
    // user has to input a year
    int userYear;
    int countLeaps = 0;
    cout << endl << "Enter year --> ";
    cin >> userYear;
    cout << endl;
    // year must be gregorian
    if (userYear >= 1752) {
        while (countLeaps < 10) {
            userYear++;
            if (isLeapYear(userYear)) {
                cout << "Leap year is " << userYear << endl;
                countLeaps++;
            }
        }
    }
}
