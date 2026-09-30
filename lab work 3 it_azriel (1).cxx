#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double totalRevenue = 0.0;
    int openDaysCount = 0;
    double maxSales = 0.0;
    int bestDayNumber = 0;
    bool auditAborted = false;
    int closedDays = 0;
    double average = 0.0;

    cout << "==================================================\n";
    cout << "        THE CAMPUS COFFEE CO. - SALES AUDIT       \n";
    cout << "==================================================\n";

    cout << fixed << setprecision(2);

    for (int day = 1; day <= 7; day++) {

        double currentSales = 0.0;

        cout << "Enter gross sales for Day " << day << " ($): ";
        cin >> currentSales;

        if (currentSales < 0) {
            cout << "--> [ALERT] Corrupted/negative entry detected ("
                 << currentSales << "). Aborting weekly audit immediately!\n";
            auditAborted = true;
            break;
        }

        if (currentSales == 0 || currentSales == 0.00) {
            cout << "--> [INFO] Store was closed on Day " << day
                 << ". Skipping daily calculation.\n";
            closedDays = closedDays + 1;
            continue;
        }

        if (currentSales > 0) {
            if (currentSales != 0) {
                totalRevenue = totalRevenue + currentSales;
                openDaysCount = openDaysCount + 1;

                if (currentSales > maxSales) {
                    maxSales = currentSales;
                    bestDayNumber = day;
                }
            }
        }
    }

    cout << "\n---------------- WEEKLY AUDIT REPORT -------------\n";

    cout << "Days Evaluated        : " << openDaysCount << " active day(s) ";
    if (auditAborted == true) {
        cout << "(Audit aborted early)";
    } else if (auditAborted == false) {
        cout << "(" << closedDays << " closed day skipped)";
    }
    cout << "\n";

    cout << fixed << setprecision(2);
    cout << "Total Gross Revenue   : $" << totalRevenue << "\n";

    if (openDaysCount > 0) {
        average = totalRevenue / openDaysCount;
    } else {
        average = 0.0;
    }
    cout << fixed << setprecision(2);
    cout << "Average Daily Sales   : $" << average << "\n";

    cout << "Best Sales Day        : Day " << bestDayNumber
         << " with $" << maxSales << "\n";
    cout << "==================================================\n";

    return 0;
}
