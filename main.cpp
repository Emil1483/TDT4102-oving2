// handout oving 2

#include "AnimationWindow.h"
#include "std_lib_facilities.h"

void inputAndPrintInteger() {
    // BEGIN: 1b
    cout << "Skriv inn et tall: ";
    int result;
    cin >> result;
    cout << "Du skrev " << result << endl;
    // END: 1b
}

int inputInteger() {
    // BEGIN: 1c
    cout << "Skriv inn et tall: ";
    int result;
    cin >> result;
    return result;
    // END: 1c
}

void printSumOfInputIntegers() {
    // BEGIN: 1d
    int a = inputInteger();
    int b = inputInteger();
    int c = a + b;
    cout << "Summen av tallene: " << c << endl;
    // END: 1d
}

bool isOdd(int n) {
    // BEGIN: 1f
    return n % 2 == 1;
    // END: 1f
}

void inputIntegersAndPrintSum() {
    // BEGIN: 2a
    cout << "Hvor mange heltall: ";
    int n;
    cin >> n;
    int result = 0;
    for (int i = 0; i < n; i++) {
        cout << "skriv tall: ";
        int number;
        cin >> number;
        result += number;
    }
    cout << "Total sum: " << result << endl;
    // END: 2a
}

void inputIntegersAndPrintSumUntilStopped() {
    // BEGIN: 2b
    int result = 0;
    while (true) {
        cout << "skriv tall: ";
        int number;
        cin >> number;
        if (number == 0) {
            break;
        }
        result += number;
    }
    cout << "total: " << result << endl;
    // END: 2b
}

double inputDouble() {
    // BEGIN: 2d
    cout << "Skriv inn et desimaltall: ";
    double result;
    cin >> result;
    return result;
    // END: 2d
}

void convertNOKtoEUR() {
    // BEGIN: 2e
    cout << "Hvor mange NOK har du?" << endl;
    double nok = inputDouble();
    if (nok < 0) {
        cout << "bruk et positivt tall!" << endl;
        return convertNOKtoEUR();
    }

    double result = nok / 10.5;
    ostringstream stream;
    stream << fixed << setprecision(2) << result;
    string formatted = stream.str();
    cout << "Da har du " << formatted << " EUR" << endl;
    // END: 2e
}

void printMultiplicationTable() {
    // BEGIN: 2g
    cout << "Enter height." << endl;
    int height = inputInteger();
    cout << "Enter width." << endl;
    int width = inputInteger();

    for (int i = 1; i < height + 1; i++) {
        for (int j = 1; j < width + 1; j++) {
            cout << setw(5) << to_string(i * j);
        }
        cout << endl;
    }
    // END: 2g
}

double discriminant(double a, double b, double c) {
    // BEGIN: 3a
    return pow(b, 2) - 4 * a * c;
    // END: 3a
}

void printRealRoots(double a, double b, double c) {
    // BEGIN: 3b
    if (discriminant(a, b, c) < 0) {
        cout << "No real roots :(" << endl;
        return;
    }

    if (discriminant(a, b, c) == 0) {
        double root = -b / (2 * a);
        cout << "One root: " << to_string(root) << endl;
        return;
    }

    double rootA = (-b - sqrt(discriminant(a, b, c))) / (2 * a);
    double rootB = (-b + sqrt(discriminant(a, b, c))) / (2 * a);

    cout << "Roots are " << rootA << " and " << rootB << endl;
    // END: 3b
}

void solveQuadraticEquations() {
    // BEGIN: 3c
    double a = inputDouble();
    double b = inputDouble();
    double c = inputDouble();
    printRealRoots(a, b, c);
    // END: 3c
}

void pythagoras() {
    // BEGIN: 4a
    // Alle deloppgaver i 4 skal løses her
    AnimationWindow win{100, 100, 600, 600, "Pythagoras"};

    win.draw_triangle(Point{200, 400}, Point{400, 400}, Point{400, 200},
                      Color::red);

    win.draw_quad(Point{200, 400}, Point{400, 400}, Point{400, 600},
                  Point{200, 600}, Color::green);

    win.draw_quad(Point{400, 400}, Point{600, 400}, Point{600, 200},
                  Point{400, 200}, Color::blue);

    win.draw_quad(Point{200, 400}, Point{400, 200}, Point{175, 50},
                  Point{50, 250}, Color::orange);

    win.wait_for_close();
    // END: 4a
}

vector<int> calculateBalance(int amount, int rate, int years) {
    // BEGIN: 5a
    vector<int> result(years);

    double rateDouble = static_cast<double>(rate);
    double amountDouble = static_cast<double>(amount);

    for (int i = 0; i < years; i++) {
        result[i] = round(amountDouble * pow(1 + rateDouble / 100, i));
    }

    return result;
    // END: 5a
}

void printBalance(vector<int> balanceVec) {
    // BEGIN: 5b
    cout << setw(10) << "Year" << setw(10) << "Saldo" << endl;
    for (int i = 0; i < balanceVec.size(); i++) {
        cout << setw(10) << i << setw(10) << balanceVec[i] << endl;
    }
    // END: 5b
}

class ExitException : public runtime_error {
  public:
    ExitException() : runtime_error("Exit") {}
};

int main() {
    // Oppgave 1a
    // Her kan du teste funksjonene dine ved hjelp av menysystem som beskrevet.
    // NB: Denne delen av koden blir IKKE automatisk rettet.

    // pythagoras();

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < v.size(); i++) {
        cout << v.at(i) << endl;
    }

    while (true) {
        cout << endl;
        cout << "Velg funksjon:" << endl;
        cout << "0) Avslutt" << endl;
        cout << "1) inputAndPrintInteger" << endl;
        cout << "2) inputInteger" << endl;
        cout << "3) printSumOfInputIntegers" << endl;
        cout << "4) isOdd" << endl;
        cout << "5) inputIntegersAndPrintSum" << endl;
        cout << "6) inputIntegersAndPrintSumUntilStopped" << endl;
        cout << "7) inputDouble" << endl;
        cout << "8) convertNOKtoEUR" << endl;
        cout << "9) printMultiplicationTable" << endl;
        cout << "10) solveQuadraticEquations" << endl;
        cout << "11) calculateBalance" << endl;
        cout << "Angi valg (0-11): ";

        int choise;
        cin >> choise;

        int integer;
        double real;

        cout << endl;
        try {
            switch (choise) {
            case 0:
                throw ExitException();
            case 1:
                inputAndPrintInteger();
                break;
            case 2:
                integer = inputInteger();
                cout << "Du skrev: " << integer << endl;
                break;
            case 3:
                printSumOfInputIntegers();
                break;
            case 4:
                for (int i = 0; i < 16; i++) {
                    cout << i << " is odd: " << (isOdd(i) ? "true" : "false")
                         << endl;
                }
                break;
            case 5:
                inputIntegersAndPrintSum();
                break;
            case 6:
                inputIntegersAndPrintSumUntilStopped();
                break;
            case 7:
                real = inputDouble();
                cout << "Du skrev: " << real << endl;
                break;
            case 8:
                convertNOKtoEUR();
                break;
            case 9:
                printMultiplicationTable();
                break;
            case 10:
                solveQuadraticEquations();
                break;
            case 11:
                printBalance(calculateBalance(5000, 2, 10));
                break;
            default:
                throw runtime_error(to_string(choise) + " not implemented");
            }
        } catch (const ExitException &e) {
            cout << "Goodbye :)" << endl;
            break;
        } catch (const runtime_error &e) {
            cout << e.what() << endl;
            break;
        }
    }

    return 0;
}
