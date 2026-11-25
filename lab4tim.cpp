#include <iostream>
using namespace std;

void task1() {
    int orderCount;

    cout << "Enter the number of orders (1-30): ";
    if (!(cin >> orderCount) || orderCount < 1 || orderCount > 30) {
        cout << "Invalid number of orders.\n";
        return;
    }

    const double discountThreshold = 300.0;
    const double discountRate = 0.15;
    double revenue = 0;
    int discountedOrders = 0;

    for (int i = 1; i <= orderCount; i++) {
        int dishCount;
        double dishPrice;

        cout << "Order " << i
            << ": enter the dish count (1-10) and unit price (1-100): ";

        if (!(cin >> dishCount >> dishPrice) ||
            dishCount < 1 || dishCount > 10 ||
            dishPrice < 1 || dishPrice > 100) {
            cout << "Invalid order data.\n";
            return;
        }

        double orderTotal = dishCount * dishPrice;

        if (orderTotal > discountThreshold) {
            orderTotal -= orderTotal * discountRate;
            discountedOrders++;
        }

        cout << "Order total: " << orderTotal << '\n';
        revenue += orderTotal;
    }

    cout << "Total revenue: " << revenue << '\n';
    cout << "Discounted orders: " << discountedOrders << '\n';
}

void task2() {
    int tip;
    long long totalTips = 0;
    int maxTip = 0;
    int recordCount = 0;

    cout << "Enter integer tips (-1 to finish):\n";

    while (cin >> tip && tip != -1) {
        if (tip <= 0) {
            continue;
        }

        totalTips += tip;

        if (tip > maxTip) {
            maxTip = tip;
            recordCount++;
        }
    }

    cout << "Total tips: " << totalTips << '\n';
    cout << "Maximum tip: " << maxTip << '\n';
    cout << "New records: " << recordCount << '\n';
}

void task3() {
    double budget;

    cout << "Enter the budget (8-200): ";
    if (!(cin >> budget) || budget < 8 || budget > 200) {
        cout << "Invalid budget.\n";
        return;
    }

    const int lunchPrice = 8;
    int guestCount;
    int totalCost = 0;

    do {
        cout << "Enter the number of guests (1-15): ";
        if (!(cin >> guestCount)) {
            cout << "Invalid input. Expected an integer.\n";
            if (cin.eof()) {
                return;
            }

            cin.clear();
            while (cin.get() != '\n' && cin) {
            }
            continue;
        }

        if (guestCount < 1 || guestCount > 15) {
            cout << "The number of guests must be between 1 and 15.\n";
            continue;
        }

        totalCost = guestCount * lunchPrice;

        if (totalCost > budget) {
            cout << "The order exceeds the budget.\n";
            continue;
        }

        break;
    } while (true);

    cout << "Total cost: " << totalCost << '\n';
    cout << "Change: " << budget - totalCost << '\n';
}

void task4() {
    int rows;

    cout << "Enter the number of rows (3-9): ";
    if (!(cin >> rows) || rows < 3 || rows > 9) {
        cout << "Invalid number of rows.\n";
        return;
    }

    int totalSum = 0;

    for (int i = 1; i <= rows; i++) {
        int rowSum = 0;

        for (int j = 1; j <= i; j++) {
            int value = i * j;
            cout << value << ' ';
            rowSum += value;
        }

        cout << "| " << rowSum << '\n';
        totalSum += rowSum;
    }

    cout << "Total sum: " << totalSum << '\n';
}

int main() {
    int choice;

    cout << "Choose a task (1-4): ";
    if (!(cin >> choice)) {
        cout << "Invalid input.\n";
        return 1;
    }

    switch (choice) {
    case 1:
        task1();
        break;
    case 2:
        task2();
        break;
    case 3:
        task3();
        break;
    case 4:
        task4();
        break;
    default:
        cout << "Invalid task number.\n";
        return 1;
    }

    return 0;
}