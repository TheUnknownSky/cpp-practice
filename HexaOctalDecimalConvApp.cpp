#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
/* ----------------------------------------------------------------------------------- */ 
// RETURNS THE EQUIVALENT DECIMAL OF THE HEXADECIMAL
int return_hexa_num(char hexa){
    int deci;
    switch(hexa){
        case '0':
            deci = 0; break;
        case '1':
            deci = 1; break;
        case '2':
            deci = 2; break;
        case '3':
            deci = 3; break;
        case '4':
            deci = 4; break;
        case '5':
            deci = 5; break;
        case '6':
            deci = 6; break;
        case '7':
            deci = 7; break;
        case '8':
            deci = 8; break;
        case '9':
            deci = 9; break;
        case 'A': 
            deci = 10; break;
        case 'B':
            deci = 11; break;
        case 'C':
            deci = 12; break;
        case 'D':
            deci = 13; break;
        case 'E':
            deci = 14; break;
        case 'F':
            deci = 15; break;
        default:
            cout << " --- INVALID INPUT --- " << endl;
            cout << " --- THE FOLLOWING CONVERSION ARE WRONG --- " << endl;
            break;
    }
    return deci;
}
// RETURNS THE EQUIVALENT DECIMAL OF THE OCTAL
int return_octa_num(char octa){
    int deci;
    switch(octa){
        case '0':
            deci = 0; break;
        case '1':
            deci = 1; break;
        case '2':
            deci = 2; break;
        case '3':
            deci = 3; break;
        case '4':
            deci = 4; break;
        case '5':
            deci = 5; break;
        case '6':
            deci = 6; break;
        case '7':
            deci = 7; break;
        default:
            cout << " --- INVALID INPUT --- " << endl;
            cout << " --- THE FOLLOWING CONVERSION ARE WRONG --- " << endl;
            break;
    }
    return deci;
}
/* ----------------------------------------------------------------------------------- */
// APP CHOICE PROMPT
char chooseApp(){
    char choice;
    cout << "\nHexadecimal, Octal, and Decimal Converter" << endl;
    cout << "What do you wish to convert? " << endl;
    cout << " H - Hexadecimal \n O - Octal \n D - Decimal \n E - Exit app" << endl;
    cout << "Input: ";
    cin >> choice;
    return choice;
}
/* ----------------------------------------------------------------------------------- */
// RETURNS BOOL VALUE TO CHECK IF ACCESS WILL BE GRANTED TO THE APP
bool checkAccess(char choice){
    bool access;
    if ((choice == 'H' || choice == 'h') || (choice == 'O' || choice == 'o') || (choice == 'D' || choice == 'd') || (choice == 'E' || choice == 'e')){
        access = true;
    } else {
        access = false;
    }
    return access;
}
/* ----------------------------------------------------------------------------------- */
// CALCULATION OF HEXADECIMAL TO DECIMAL
int hexa_to_deci(string hexa){
    char hexaTemp;
    int deci = 0;
    int j = 0;
    for (int i = (hexa.length() - 1); i >= 0; --i){
        hexaTemp = hexa[i];
        int powOf16 = pow(16, j);
        deci += return_hexa_num(hexaTemp) * powOf16;
        ++j;
    }
    return deci;
}
// CALCULATION OF OCTAL TO DECIMAL
int octa_to_deci(string octa){
    char octaTemp;
    int deci = 0;
    int j = 0;
    for (int i = (octa.length() - 1); i >= 0; --i){
        octaTemp = octa[i];
        int powOf8 = pow(8, j);
        deci += return_octa_num(octaTemp) * powOf8;
        ++j;
    }
    return deci;
}
/* ----------------------------------------------------------------------------------- */
// SHOWS THE OCTAL CONVERSION FROM DECIMAL
void deci_to_octal(int deci){
    int octalTemp = 0;
    vector<int> octalPrint;
    while (deci >= 1){
        octalTemp = deci % 8;
        octalPrint.push_back(octalTemp);
        deci /= 8;
    }
    for (auto ir = octalPrint.rbegin(); ir != octalPrint.rend(); ++ir)
        cout << *ir << "";
}
// SHOWS THE HEXADECIMAL CONVERSION FROM DECIMAL
void deci_to_hexa(int deci){
    char deciToHexaConv[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int hexaTemp = 0;
    vector<int> hexaPrint;
    while (deci >= 1){
        hexaTemp = deci % 16;
        hexaPrint.push_back(hexaTemp);
        deci /= 16;
    }
    for (auto ir = hexaPrint.rbegin(); ir != hexaPrint.rend(); ++ir)
        cout << deciToHexaConv[*ir] << "";
}
/* ----------------------------------------------------------------------------------- */
// HEXADECIMAL CONVERSION TO DECIMAL AND OCTAL
void hexadecimal_conversion_function(){
    string hexaNum;
    string octaNum;
    int deciNum;
    cout << endl;
    cout << "Enter hexadecimal(ONLY 0-9, A-F): "; cin >> hexaNum;
    deciNum = hexa_to_deci(hexaNum);
    cout << "Hexadecimal to Decimal: " << deciNum << endl;
    cout << "Hexadecimal to Octal: "; deci_to_octal(deciNum);
    cout << endl;
}
// OCTAL CONVERSION TO DECIMAL AND HEXADECIMAL
void octal_conversion_function(){
    string hexaNum;
    string octaNum;
    int deciNum;
    cout << endl;
    cout << "Enter octal(ONLY 0-7): "; cin >> octaNum;
    deciNum = octa_to_deci(octaNum);
    cout << "Octal to Decimal: " << deciNum << endl;
    cout << "Octal to Hexadecimal: "; deci_to_hexa(deciNum);
    cout << endl;
}
// DECIMAL CONVERSION TO HEXADECIMAL AND DECIMAL
void decimal_conversion_function(){
    string hexaNum;
    string octaNum;
    int deciNum;
    cout << endl;
    cout << "Enter decimal(ONLY 0-9): "; cin >> deciNum;
    cout << "Decimal to Hexadecimal: "; deci_to_hexa(deciNum);
    cout << endl;
    cout << "Decimal to Octal: "; deci_to_octal(deciNum);
    cout << endl;
}
/* ----------------------------------------------------------------------------------- */
// MAIN FUNCTION
int main(){
    char choice = '1';
    bool access = true;
    while (access == true){
        choice = chooseApp();
        access = checkAccess(choice);
        if (access == false){
            cout << "Wrong input." << endl;
            break;
        } else if (choice == 'H' || choice == 'h'){
            hexadecimal_conversion_function();
        } else if (choice == 'O' || choice == 'o'){
            octal_conversion_function();
        } else if (choice == 'D' || choice == 'd'){
            decimal_conversion_function();
        } else if (choice == 'E' || choice == 'e'){
            cout << "\nThank you for using the app. " << endl;
            break;
        }
    }
}
// CODE WRITTEN BY: VONN HAROLD MAMARIL, BSCS 11M1