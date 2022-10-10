/* Author: Stephen Samuelson
 * Class: CPSC 1020
 * Date: 9/29/22 (M/D/Y)
 * Assignment: Project 1
 * Description: Header file for new Date objects.
 */

#ifndef MAINPROJECT1_DATE_H
#define MAINPROJECT1_DATE_H

//Include string library for showDate return and use std by default when required.
#include <string>
using namespace std;

class Date {

//Private variables for new Date object.
private:
    int day;
    int month;
    int year;

    string date;

//Public functions for manipulating variable data.
public:

    //Default constructor for Date creation. Sets variables to default values 1 for day, 1 for month, and 2021 for year.
    Date() {
        day = 1;
        month = 1;
        year = 2021;
    }

    //Overloaded constructor for Date creation using variables passed from main.
    Date(int m, int d, int y) {

        //Check that parameter d is between the values 1 and 31.
        if ((d < 1) || (d > 31)) {
            day = 1;
        } else {
            day = d;
        }

        //Check that parameter m is between the values 1 and 12.
        if ((m < 1) || (m > 12)) {
            month = 1;
        } else {
            month = m;
        }

        //Check that parameter y is either 2021 or 2022.
        if ((y != 2021) && (y != 2022)) {
            year = 2021;
        } else {
            year = y;
        }
    }

    //Setter functions return true if parameter is valid input.
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);

    //Getter functions return stored value for each Date object.
    int getDay() {return day;}
    int getMonth() {return month;}
    int getYear() {return year;}

    //Return full date string.
    string showDate();
};


#endif //MAINPROJECT1_DATE_H
