#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Функція для додавання студента
void addStudent(string*& names, double*& grades, int& size, const string& name, double grade) {
    string* newNames = new string[size + 1];
    double* newGrades = new double[size + 1];

    for (int i = 0; i < size; ++i) {
        newNames[i] = names[i];
        newGrades[i] = grades[i];
    }

    newNames[size] = name;
    newGrades[size] = grade;

    delete[] names;
    delete[] grades;

    names = newNames;
    grades = newGrades;
    ++size;

    cout << "Студент \"" << name << "\" з оцінкою " << grade << " доданий до списку." << endl;
}

// Функція для видалення студента за іменем
void deleteStudent(string*& names, double*& grades, int& size, const string& name) {
    int index = -1;

    for (int i = 0; i < size; ++i) {
        if (names[i] == name) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Студента з ім'ям \"" << name << "\" не знайдено." << endl;
        return;
    }

    string* newNames = new string[size - 1];
    double* newGrades = new double[size - 1];

    for (int i = 0, j = 0; i < size; ++i) {
        if (i != index) {
            newNames[j] = names[i];
            newGrades[j] = grades[i];
            ++j;
        }
    }

    delete[] names;
    delete[] grades;

    names = newNames;
    grades = newGrades;
    --size;

    cout << "Студента \"" << name << "\" видалено зі списку." << endl;
}

// Функція для обчислення середнього бала
double calculateAverage(const double* grades, int size) {
    if (size == 0) return 0.0;

    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += grades[i];
    }
    return sum / size;
}

// Функція для виведення списку студентів
void displayStudents(const string* names, const double* grades, int size) {
    if (size == 0) {
        cout << "Список студентів порожній." << endl;
        return;
    }

    cout << left << setw(20) << "Ім'я" << "Оцінка" << endl;
    cout << string(30, '-') << endl;

    for (int i = 0; i < size; ++i) {
        cout << left << setw(20) << names[i] << grades[i] << endl;
    }
}

int main() {
    string* names = nullptr;
    double* grades = nullptr;
    int size = 0;

    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. Додати студента\n";
        cout << "2. Видалити студента\n";
        cout << "3. Показати список студентів\n";
        cout << "4. Розрахувати середній бал\n";
        cout << "5. Вийти\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                double grade;
                cout << "Введіть ім'я студента: ";
                cin.ignore();
                getline(cin, name);
                cout << "Введіть оцінку: ";
                cin >> grade;
                addStudent(names, grades, size, name, grade);
                break;
            }
            case 2: {
                string name;
                cout << "Введіть ім'я студента для видалення: ";
                cin.ignore();
                getline(cin, name);
                deleteStudent(names, grades, size, name);
                break;
            }
            case 3:
                displayStudents(names, grades, size);
                break;
            case 4: {
                double avg = calculateAverage(grades, size);
                cout << "Середній бал студентів: " << fixed << setprecision(2) << avg << endl;
                break;
            }
            case 5:
                cout << "Програма завершена. До побачення!" << endl;
                break;
            default:
                cout << "Невірний вибір. Спробуйте ще раз." << endl;
        }
    } while (choice != 5);

    delete[] names;
    delete[] grades;

    return 0;
}
