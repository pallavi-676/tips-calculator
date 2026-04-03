#include <iostream>
#include <iomanip>
using namespace std;

// Display menu
void tips_menu() {
    cout << "\n💸 Tip Menu\n";
    cout << "1. 15%\n";
    cout << "2. 20%\n";
    cout << "3. 25%\n";
    cout << "4. Custom\n";
}

// Convert choice → percentage
int get_percentage(int choice) {
    int percent;

    switch(choice) {
        case 1: percent = 15; break;
        case 2: percent = 20; break;
        case 3: percent = 25; break;
        case 4:
            cout << "Enter custom tip (%): ";
            cin >> percent;
            break;
        default:
            cout << "Invalid choice! Defaulting to 15%.\n";
            percent = 15;
    }

    return percent;
}

// Calculate tip
double tips_calculator(double bill, int percent) {
    return (bill * percent) / 100;
}

int main() {
    char again;

    cout << fixed << setprecision(2); 

    do {
        double bill;
        int choice;

        // Input bill
        cout << "\nEnter bill amount: ";
        cin >> bill;

        if (bill <= 0) {
            cout << "Invalid bill amount!\n";
            continue;
        }

        // Show menu
        tips_menu();

        // Input choice
        cout << "Choose tip option: ";
        cin >> choice;

        int percent = get_percentage(choice);

        // Calculate tip
        double tip = tips_calculator(bill, percent);
        double total = bill + tip;

        // Split bill
        int people;
        cout << "Enter number of people: ";
        cin >> people;

        if (people <= 0) {
            cout << "Invalid number of people!\n";
            continue;
        }

        double per_person = total / people;

        // Output
        cout << "\n====== 🧾 BILL SUMMARY ======\n";
        cout << "Bill: ₹" << bill << endl;
        cout << "Tip (" << percent << "%): ₹" << tip << endl;
        cout << "Total: ₹" << total << endl;
        cout << "Each person pays: ₹" << per_person << endl;
        cout << "=============================\n";

        // Repeat
        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using the Tip Calculator! 🙌\n";

    return 0;
} 