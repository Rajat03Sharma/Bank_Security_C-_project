#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

int main()
{
    int a, i = 0;
    string name, pin, age, user, word, word1, old, pin1, pin2;
    string cred[2], bp[2];

    cout << "    BANK SECURITY SYSTEM" << endl;
    cout << "_+_+_+_+_+_+_+_+_+_+_+_+_" << endl << endl;
    cout << "+    1.Register         +" << endl;
    cout << "+    2.Login            +" << endl;
    cout << "+    3.Change PIN       +" << endl;
    cout << "+    4.Exit             +" << endl;
    cout << "+_+_+_+_+_+_+_+_+_+_+_+_+" << endl << endl;

    do {
        cout << endl << endl;
        cout << "enter option:- ";
        cin >> a;
        switch (a)
        {
        case 1: {
            cout << "_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+" << endl << endl;
            cout << "|~~~~~~~~~~~~~~Register~~~~~~~~~~~~~~|" << endl;
            cout << "enter Full Name:-";
            cin >> name;
            cout << "Create Pin:-\n";
            cin >> pin;
            cout << "Enter Age:-\n";
            cin >> age;

            ofstream of1;
            of1.open("locker.txt");
            if (of1.is_open()) {
                of1 << name << "\n";
                of1 << pin << "\n";
                of1 << age << "\n";
                cout << "Registered" << endl;
            }
            else {
                cout << "Error opening file" << endl;
            }
            break;
        }
        case 2: {
            i = 0;
            cout << "_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+" << endl << endl;
            cout << "+~~~~~~~~~~~~~~~Login~~~~~~~~~~~~~~~~+" << endl;
            cout << "_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+_+" << endl << endl;

            ifstream of2;
            of2.open("locker.txt");
            cout << "enter Full Name:- ";
            cin >> user;
            cout << "enter PIN: - ";
            cin >> pin;

            if (of2.is_open()) {
                while (!of2.eof()) {
                    string text;
                    while (getline(of2, text)) {
                        istringstream iss(text);
                        iss >> word;
                        cred[i] = word;
                        i++;
                    }
                    if (user == cred[0] && pin == cred[1]) {
                        cout << "~~~~Successful Login~~~~";
                        cout << endl << endl;
                        cout << " DETAILS:   " << endl;
                        cout << "Username: " + name << endl;
                        cout << "PIN: " + pin << endl<<endl;
                        cout << "Age: " + age << endl;
                    }
                    else {
                        cout << endl << endl;
                        cout << "INCORRECT DETAILS" << endl;
                        cout << "~~ 1.Press 2 to Login ~~" << endl;
                        cout << "~~ 1.Press 3 to Change PIN ~~" << endl;
                        break;
                    }
                }
            }
            else {
                cout << "Error opening file" << endl;
            }
            break;
        }
        case 3: {
            i = 0;
            cout << "~~~~~~~~~Change PIN~~~~~~~~" << endl;
            ifstream of0;
            of0.open("locker.txt");
            cout << "Enter old PIN:- ";
            cin >> old;
            if (of0.is_open()) {
                string text;
                while (getline(of0, text)) {
                    istringstream iss(text);
                    iss >> word1;
                    bp[i] = word1;
                    i++;
                }
                if (old == bp[1]) {
                    of0.close();
                    ofstream of1;
                    of1.open("locker.txt");
                    if (of1.is_open()) {
                        cout << "Enter new PIN:- ";
                        cin >> pin1;
                        cout << "Enter PIN again:- ";
                        cin >> pin2;
                        if (pin1 == pin2) {
                            of1 << bp[0] << "\n";
                            of1 << pin1;
                            cout << "PIN Changed successfully" << endl;
                        }
                        else {
                            of1 << bp[0] << "\n";
                            of1 << old;
                            cout << "PIN not matched" << endl;
                        }
                    }
                    else {
                        cout << "Error opening file" << endl;
                    }
                }
                else {
                    cout << "Enter valid PIN" << endl;
                }
            }
            else {
                cout << "Error opening file" << endl;
            }
            break;
        }
        case 4: {
            cout << "Thank You for Using Banking Services";
            break;
        }
        default:
            cout << "Choose a Valid Option";
        }
    } while (a != 4);

    return 0;
}

