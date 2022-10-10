//
// Created by Stephen Samuelson on 9/29/22.
//

#include "calcDays.h"

//Calculate the date difference between two passed Date objects.
//Convert the dates to their day value and return the difference.
int calcDays(Date& dateOne, Date& dateTwo) {

    //daysMonth array holds the day values for every month of the year
    int daysMonth[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysDiff1;
    int daysDiff2;

    //Default date is 01/01/2021. To translate that to days we multiply the year by days in a year
    int defaultDate = 2021 * 365;

    //To start, set daysDiff1 to the year times days in a year and add the amount of days left over in the object
    daysDiff1 = (dateOne.getYear() * 365) + dateOne.getDay();

    //Loop through daysMonth, adding the current index's day count to daysDiff
    for (int i = 0; i < dateOne.getMonth(); ++i) {
        daysDiff1 += daysMonth[i];
    }

    //Subtract default date from daysDiff1 to get correct value for subtraction with daysDiff2
    daysDiff1 -= defaultDate;

    //Do everything we did for daysDiff1 but for daysDiff2
    daysDiff2 = (dateTwo.getYear() * 365) + dateTwo.getDay();

    //Loop through daysMonth, adding the current index's day count to daysDiff
    for (int i = 0; i < dateTwo.getMonth(); ++i) {
        daysDiff2 += daysMonth[i];
    }

    //Subtract default date from daysDiff2 to get correct value for subtraction with daysDiff1
    daysDiff2 -= defaultDate;

    return daysDiff1 - daysDiff2;
}