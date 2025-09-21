#include <iostream>
#include <cstdlib>
using namespace std;

enum enOpType { Add = 1, Minus = 2, Multiply = 3, Divide = 4 };

struct stNumbers {
    float Number[10];
    int HowManyNumbers;
};

int ReadHowManyNumbers() {
    int count;
    do {
        cout << "                                   Enter How Many Numbers (1 to 10): ";
        cin >> count;
    } while (count < 1 || count > 10);

    cout << endl << endl;
    return count;
}

stNumbers ReadNumbers() {
    stNumbers Numbers;
    Numbers.HowManyNumbers = ReadHowManyNumbers();
    for (int i = 0; i < Numbers.HowManyNumbers; i++) {
        cout << "                                   Enter Number " << i + 1 << " : ";
        cin >> Numbers.Number[i];
    }
    cout << endl;
    return Numbers;
}

enOpType ReadOpType() {
    int Op;
    do {
        cout << "                                   Enter Operation Type : " << endl << endl;
        cout << "                                   (1) Add " << endl;
        cout << "                                   (2) Minus " << endl;
        cout << "                                   (3) Multiply " << endl;
        cout << "                                   (4) Divide " << endl;
        cout << "                                            : ";
        cin >> Op;
    } while (Op < 1 || Op > 4);

    cout << endl << endl;
    return (enOpType)Op;
}

void CalculateNumbers() {
    stNumbers Numbers = ReadNumbers();
    enOpType OpType = ReadOpType();

    float result = Numbers.Number[0]; // نبدأ بالعدد الأول

    switch (OpType) {
    case enOpType::Add:
        for (int i = 1; i < Numbers.HowManyNumbers; i++)
            result += Numbers.Number[i];
        cout << "                                   Result = " << result;
        break;

    case enOpType::Minus:
        for (int i = 1; i < Numbers.HowManyNumbers; i++)
            result -= Numbers.Number[i];
        cout << "                                   Result = " << result;
        break;

    case enOpType::Multiply:
        for (int i = 1; i < Numbers.HowManyNumbers; i++)
            result *= Numbers.Number[i];
        cout << "                                   Result = " << result;
        break;

    case enOpType::Divide:
        for (int i = 1; i < Numbers.HowManyNumbers; i++) {
            if (Numbers.Number[i] == 0) {
                cout << "                               Error: You cant divide by zero!" << endl;
                return;
            }
            result /= Numbers.Number[i];
        }
        cout << "                                   Result = " << result;
        break;
    }
}

void Design() {
    cout << "                                   ----------------------------------" << endl;
    cout << "                                   ----------------------------------" << endl;
    cout << "                                               CALCULATOR            " << endl;
    cout << "                                   ----------------------------------" << endl;
    cout << "                                   ----------------------------------" << endl;
}

void Start() {
    char CalculateAgain = 'Y';
    do {
        system("cls");
        Design();
        CalculateNumbers();
        cout << endl << endl;
        cout << "                                   Do you want to calculate more numbers Y/N ? ";
        cin >> CalculateAgain;
    } while (CalculateAgain == 'Y' || CalculateAgain == 'y');
}

int main() {
    Start();
}
