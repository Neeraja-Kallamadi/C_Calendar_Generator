/*
These lines include standard C libraries. <stdio.h> is for input and output operations, and <stdlib.h> is for standard library functions, including system.
*/
#include <stdio.h>
#include <stdlib.h>

/*
This defines a function named getFirstDayOfYear that calculates and returns the day of the week for January 1st of a given year using Zeller's algorithm. It takes the year as input and returns an integer representing the day of the week (0 for Saturday, 1 for Sunday, and so on).
*/
int getFirstDayOfYear(int year){
    int day;
    day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;    // zeller algorithm
    return day;
}
/*

Note :

Zeller's Congruence formula is used to calculate the day of the week for a given date (day, month, and year).
It involves some mathematical operations to find the day of the week efficiently.
The formula is as follows:

day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;

Now, let's break down each part of the formula and understand what it represents:

1. year: The year for which you want to find the day of the week.

2. ((year - 1) * 365): This part calculates the total number of days in all the years before the given year. Since there are 365 days in a non-leap year, we multiply the number of years (excluding the given year) by 365.

3. ((year - 1) / 4): This part accounts for the extra day in a leap year. It calculates the number of leap years that occurred before the given year (excluding the given year). We divide the number of years (excluding the given year) by 4 because, on average, there is one leap year every four years.

4. ((year - 1) / 100): This part adjusts for the century years (e.g., 1800, 1900, 2000). Century years are not considered leap years unless they are divisible by 400. So, we subtract the number of century years that occurred before the given year (excluding the given year) divided by 100.

5. ((year) / 400): This part adds one day for every 400 years since a leap year repeats after 400 years. So, we add the number of 400-year cycles that occurred before the given year.

6. + 1: Adding 1 to account for the day January 1, 1 AD.
    In the Zeller's Congruence formula, adding "+1" is necessary because we want to account for the day January 1, 1 AD. In the Gregorian calendar, January 1, 1 AD, is the reference date that is considered as the starting point when counting the number of days.
    However, since the formula deals with integer division and modular arithmetic, the count of days starts from 0.

7. % 7: Finally, we take the modulo 7 of the total count. The result will be a number between 0 and 6, representing the day of the week (0 for Saturday, 1 for Sunday, 2 for Monday, and so on).

*/

int main(){
    system("Color 3F");	// main is the entry point of the program.
						// system("Color 3F"); sets the text and background color of the console window. This may be specific to certain Windows environments where the console supports color formatting.
    int year, month, day, weekDay, startingDay;	// These lines declare integer variables year, month, day, weekDay, and startingDay to store various values used in the program.
    printf("\nEnter your desired year : ");
    scanf("%d",&year);	// This line prompts the user to input a year and stores it in the year variable using scanf.
    char *months[] = {"January","February","March","April","May","June","July","August","September","October","November","December"};	// This line creates an array of strings called months to store the names of the months.
    int monthDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};	// This line creates an array called monthDay to store the number of days in each month. February is set to 28 days by default, but it will be adjusted for leap years later.

	// This conditional block checks if the input year is a leap year and adjusts the number of days in February (monthDay[1]) accordingly. Leap years are those that are divisible by 4 but not divisible by 100, or divisible by 400.
    if((year%4 == 0 && year%100 != 0) || year%400 == 0)
        monthDay[1] = 29;
	
	// This line calculates the starting day of the year using the getFirstDayOfYear function and stores it in the startingDay variable.
    startingDay = getFirstDayOfYear(year);

    for(month = 0;month < 12;month++){	// This loop iterates through each month of the year (from 0 to 11) and prints the name of the month.
        printf("\n\n---------------------%s---------------------",months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");	// This line prints the names of the days of the week.
		
		// This loop prints leading spaces to align the first day of the month with the correct day of the week.
        for(weekDay = 0;weekDay < startingDay;weekDay++){
            printf("     ");
        }
	
		// This loop iterates through each day of the month, printing the day's number.
		// weekDay is used to keep track of the current day of the week, and when it reaches 6 (Saturday), a newline character is printed to start a new row in the calendar.
		// startingDay is updated to weekDay to ensure the correct alignment for the next month.
        for(day = 1;day <= monthDay[month];day++){
            printf("%5d",day);	/*
								% indicates the beginning of a format specifier.
								5 specifies the minimum width for the output field. In this case, it's set to 5 characters. This means that if the integer being printed takes up fewer than 5 characters, spaces will be added before it to make it align properly within a 5-character-wide field.
								d indicates that the argument to be printed is an integer.
								*/

            if(++weekDay > 6){
                printf("\n");
                weekDay = 0;
            }
            startingDay = weekDay;
        }
    }
    printf("\n\n");	// This line prints two newline characters to separate the calendar from the following output.
    return 0;	// This line indicates the end of the main function and the end of the program. It returns 0 to indicate successful execution to the operating system.
}