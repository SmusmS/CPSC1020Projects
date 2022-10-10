/* Author: Stephen Samuelson
 * Class: CPSC 1020
 * Date: 9/29/22 (M/D/Y)
 * Assignment: Project 1
 * Description: cpp file for Date objects. Contains setter functions and showDate function.
 */

#include "Date.h"

//Checks that parameter d is valid and if so, changes Date variable day to d and returns true.
//Otherwise, set day to default value and return false.
bool Date::setDay(int d) {

    if ((d < 1) || (d > 31)) {
        day = 1;
        return false;
    } else {
        day = d;
        return true;
    }
}

//Checks that parameter m is valid and if so, changes Date variable month to m and returns true.
//Otherwise, set month to default value and return false.
bool Date::setMonth(int m) {

    if ((m < 1) || (m > 12)) {
        month = 1;
        return false;
    } else {
        month = m;
        return true;
    }
}

//Checks that parameter Y is valid and if so, changes Date variable year to y and returns true.
//Otherwise, set year to default value and return false.
bool Date::setYear(int y) {

    if ((y != 2021) && (y != 2022)) {
        year = 2021;
        return false;
    } else {
        year = y;
        return true;
    }
}

//Sets date variable to format MM/DD/YYYY and returns date.
string Date::showDate() {
    date = to_string(month) + '/' + to_string(day) + '/' + to_string(year);
    return date;
}