#include <bits/stdc++.h>
using namespace std;

class StudentAnalyzer {
    string names[100];
    int marks[100];
    int n;

public:
    void input();
    void display();
    void sort(bool ascending);
    void search();
    void average();
    void maxMin();
};

void StudentAnalyzer::input() {
    cout << "Enter number of students: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Enter Name and Marks for student " << i + 1 << ": ";
        getline(cin, names[i]);
        cin >> marks[i];
        cin.ignore();
    }
}

void StudentAnalyzer::display() {
    cout << "\nName\t\tMarks\n";
    for (int i = 0; i < n; i++)
        cout << names[i] << "\t\t" << marks[i] << endl;
}

void StudentAnalyzer::sort(bool ascending) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if ((ascending && marks[j] > marks[j + 1]) || (!ascending && marks[j] < marks[j + 1])) {
                swap(marks[j], marks[j + 1]);
                swap(names[j], names[j + 1]);
            }
    cout << (ascending ? "Sorted in ascending order.\n" : "Sorted in descending order.\n");
}

void StudentAnalyzer::search() {
    int key;
    cout << "Enter marks to search: ";
    cin >> key;

    bool found = false;
    for (int i = 0; i < n; i++) {
        if (marks[i] == key) {
            cout << "Marks found for Student: " << names[i] << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Marks not found.\n";
}


void StudentAnalyzer::average() {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += marks[i];
    cout << "Average marks: " << (float)sum / n << endl;
}

void StudentAnalyzer::maxMin() {
    int max = marks[0], min = marks[0];
    string maxName = names[0], minName = names[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > max) {
            max = marks[i];
            maxName = names[i];
        }
        if (marks[i] < min) {
            min = marks[i];
            minName = names[i];
        }
    }
    cout << "Maximum marks: " << max << " (Student: " << maxName << ")\n";
    cout << "Minimum marks: " << min << " (Student: " << minName << ")\n";
}

int main() {
    StudentAnalyzer obj;
    int choice;
    while (true) {
        cout << "\n--- Menu ---\n";
        cout << "1. Input Marks\n2. Display\n3. Sort\n4. Search\n5. Average\n6. Max & Min\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: obj.input(); break;
        case 2: obj.display(); break;
        case 3: {
            int order;
            cout << "Sort Order? (1 = Ascending, 2 = Descending): ";
            cin >> order;
            obj.sort(order == 1);
            break;
        }
        case 4: obj.search(); break;
        case 5: obj.average(); break;
        case 6: obj.maxMin(); break;
        case 0: return 0;
        default: cout << "Invalid choice.\n";
        }
    }
}
