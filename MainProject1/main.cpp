/* Author: Stephen Samuelson
 * Class: CPSC 1020
 * Date: 9/29/22 (M/D/Y)
 * Assignment: Project 1
 * Description: Main file for Project 1. Contains main function.
 */

#include "Date.h"
#include "calcDays.h"

#include <string>
#include <iostream>
using namespace std;

int main() {

    string testResult;
    int day;
    int month;
    int year;

    //Prompt user for test result and store in string variable testResult
    cout << "Enter test result: " << endl;
    cin >> testResult;

    //Loop through testResult and pull each character at location i. Store that character in c, convert it tolower
    //then put the lowercase character back into testResult at location i. (Convert testResult to lowercase)
    int i = 0;
    char c;
    while (testResult[i]) {
        c = testResult[i];
        testResult[i] = tolower(c);
        ++i;
    }

    //If statement tests if testResult is equal to positive or negative.
    if (testResult == "positive") {

        //Prompt user for date they tested positive. Read in each int seperated by a / character.
        cout << "Enter date you tested positive: " << endl;
        scanf("%d/%d/%d",&month,&day,&year);

        //Create a new Date object positiveDate.
        Date positiveDate;

        //Set positiveDate to user values using the setter functions. Setters also validate input.
        positiveDate.setMonth(month);
        positiveDate.setDay(day);
        positiveDate.setYear(year);

        //Output result. A positive test should always be a 5 day isolation time.
        cout << "Test result: " << testResult << endl;
        cout << "Date tested positive: " << positiveDate.showDate() << endl;
        cout << "Length of isolation: 5 days" << endl;

        return 0;
    } else {

        //Ask user if they were exposed to a positive case and store that string in wasExposed
        cout << "Were you exposed to a positive case? " << endl;
        string wasExposed;
        cin >> wasExposed;

        //Convert wasExposed string to lowercase for easier validation.
        int j = 0;
        char d;
        while (wasExposed[j]) {
            d = wasExposed[j];
            wasExposed[j] = tolower(d);
            ++j;
        }

        //Check if wasExposed is equal to yes or no. If yes then get the date they were exposed from user
        if (wasExposed == "yes") {

            cout << "What date were you exposed to Covid? " << endl;
            scanf("%d/%d/%d",&month,&day,&year);

            //Create a new Date object named exposureDate
            Date exposureDate;

            //Use setter functions to set exposureDate variables to user input variables
            exposureDate.setMonth(month);
            exposureDate.setDay(day);
            exposureDate.setYear(year);

            //Ask user if they have received the Second covid vaccine
            cout << "Have you received the second Covid vaccine? " << endl;
            string secondVaccine;
            cin >> secondVaccine;

            //Convert secondVaccine to lowercase
            int k = 0;
            char e;
            while (secondVaccine[k]) {
                e = secondVaccine[k];
                secondVaccine[k] = tolower(e);
                ++k;
            }

            //Check if secondVaccine is equal to yes or no. If yes then get the date they received vaccine
            if (secondVaccine == "yes") {

                cout << "What date did you receive the second vaccination dose? " << endl;
                scanf("%d/%d/%d",&month,&day,&year);

                //Create a new Date object named vaccineDate
                Date vaccineDate;

                //Use setter functions to set vaccineDate variables to user input variables
                vaccineDate.setMonth(month);
                vaccineDate.setDay(day);
                vaccineDate.setYear(year);

                //Calculate vaccination status at time of exposure. If exposure date is larger than vaccine date then
                //user is not fully vaccinated. Maximum isolation length.
                if (calcDays(exposureDate, vaccineDate) < calcDays(vaccineDate, exposureDate)) {
                    cout << "Test result: " << testResult << endl;
                    cout << "Exposed to positive case: " << wasExposed << endl;
                    cout << "Date exposed to positive case: " << exposureDate.showDate() << endl;
                    cout << "Second vaccination does received: " << secondVaccine << endl;
                    cout << "Date second vaccination dose received: " << vaccineDate.showDate() << endl;
                    cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
                    cout << "Length of isolation: 10 days" << endl;

                    //program is done. Return 0
                    return 0;

                } else {
                    //User is fully vaccinated. 5 day isolation length

                    cout << "Test result: " << testResult << endl;
                    cout << "Exposed to positive case: " << wasExposed << endl;
                    cout << "Date exposed to positive case: " << exposureDate.showDate() << endl;
                    cout << "Second vaccination does received: " << secondVaccine << endl;
                    cout << "Date second vaccination dose received: " << vaccineDate.showDate() << endl;
                    cout << "Vaccination status at time of exposure: fully vaccinated" << endl;
                    cout << "Length of isolation: 5 days" << endl;

                    //program is done. Return 0
                    return 0;
                }

            } else {
                //User test negative, was exposed to a positive case, and has no vaccine. Maximum isolation

                cout << "Test result: " << testResult << endl;
                cout << "Exposed to positive case: " << wasExposed << endl;
                cout << "Date exposed to positive case: " << exposureDate.showDate() << endl;
                cout << "Second vaccination dose received: " << secondVaccine << endl;
                cout << "Vaccination status at time of exposure: not fully vaccinated" << endl;
                cout << "Length of isolation: 10 days" << endl;

                //Program is done. Return 0
                return 0;

            }

        } else {
            //Test result is negative and they were not exposed to a positive case so no isolation necessary

            cout << "Test result: " << testResult << endl;
            cout << "Exposed to positive case: " << wasExposed << endl;
            cout << "Length of isolation: 0 days";

            //Program is over. Return 0
            return 0;
        }
    }
}