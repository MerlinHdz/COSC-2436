#include <iostream>

class Date 
{
private:
    int month;
    int day;
    int year;

public:
    /**
     * @brief Construct a new Date object
     * 
     * @param m positive integer representing month
     * @param d positive integer representing day
     * @param y positive integer representing year
     */
    Date(int m, int d, int y) : month(m), day(d), year(y) {}

    //*** Accessors ***

    /**
     * @brief Get the month value of Date object
     * @return int month
     */
    int getMonth()
    {
        return month;
    }

    int getDay()
    {
        return day;
    }

    int getYear()
    {
        return year;
    }

    // Method to advance the date by one day
    void advanceByOneDay() {
        // Update day
        day++;

        // Reset day and update month if necessary
        if (day > daysInMonth(month, year)) {
            day = 1;
            month++;

            // Reset month and update year if necessary
            if (month > 12) {
                month = 1;
                year++;
            }
        }
    }
   
   /**
    * @brief Helper function - to determine days in a month
    * @param m int representing month of this Date 
    * @param y int representing year of this Date
    * @return int representing number of days in month.
    */
   int daysInMonth(int m, int y) 
   {
        const bool isLeap = (y % 4 == 0) && ((y % 100 != 0) || (y % 400 == 0));

        int days = 0;
        switch(m)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                days = 31;
                break;
            case 4: case 6: case 9: case 11:
                days = 30;
                break;
            case 2:
                days = (isLeap) ? 29 : 28;
                break;
            default:
                // Handle invalid month 
                days = 0;
                break;
        }

        return days;
    }

};



int main() {
    // Example usage
    Date myDate(1, 20, 2024);
    myDate.advanceByOneDay();

    // Display the updated date
    std::cout << "Updated Date: " << myDate.getMonth() << "/" << myDate.getDay() << "/" << myDate.getYear() << std::endl;

    return 0;
}
