#include <iostream>
using namespace std;
void question1(){ // self-explanatory
    cout << "\nQuestion 1: What do we use to make an output in C++?" << endl;
    cout << "A. cout" << endl;
    cout << "B. cin" << endl;
    cout << "C. print" << endl;
    cout << "D. printf" << endl;
}
void question2(){ // self-explanatory
    cout << "\nQuestion 2: What is the contents-of operator in the following?" << endl;
    cout << "A. &" << endl;
    cout << "B. *" << endl;
    cout << "C. +" << endl;
    cout << "D. -" << endl;
}
void question3(){ // self-explanatory
    cout << "\nQuestion 3: What is the programming language that uses 'cout' syntax?" << endl;
    cout << "A. Java" << endl;
    cout << "B. Python" << endl;
    cout << "C. C++" << endl;
    cout << "D. C" << endl;
}
int check_answer(int quest_num){
    char answer, *a = &answer; // the variable 'answer' is basically the same as *a; if answer = 'A', then *a = 'A', and vice versa
    int ctr, *c = &ctr; // the variable 'ctr' is basically the same as *c; if ctr = 0, then *c = 0, and vice versa
    *c = 0; // *c or ctr is equal to 0
    cout << "\nAnswer: "; cin >> *a; // answer prompt
    char answers[3] = {'A', 'B', 'C'}; // array of correct answers
    if(*a != answers[quest_num - 1]){ // checks if the answer or *a is wrong
        *c = 1; // if the answer or *a is wrong, the ctr or *c will be equal to 1
    }
    return *c; // returns the value of ctr or *c; returns 0 if correct, returns 1 if wrong
}
void show_result(int correct, int wrong, int total){
    int *c = &correct, *w = &wrong, *t = &total; // take the values of the parameters to the pointer variables
    *c = *t - *w; // correct = total - wrong
    *t = *c; // total = correct
    cout << "\nCorrect: " << *c << endl;
    cout << "Wrong: " << *w << endl << endl;
    cout << "Total: " << *t << endl;
}
int main(){
    int correct = 0, *c = &correct; // the variable 'correct' is basically the same as *c; if correct = 0, then *c = 0, and vice versa
    int wrong = 0, *w = &wrong;     // the variable 'wrong' is basically the same as *w; if wrong = 0, then *w = 0, and vice versa
    int total = 3, *t = &total;     // the variable 'total' is basically the same as *t; if total = 3, then *t = 3, and vice versa
    question1(); // calls out question1 function
    *w += check_answer(1); // prompts the user to answer, and checks the answer of question 1 if it is wrong. If it is wrong, then the wrong counter or *w will be increased by 1 as the function returns the value of 1 if the answer is wrong
    question2(); // calls out question 2 function
    *w += check_answer(2); // the same thing, but checks the answer of question 2
    question3(); // calls out question 3 function
    *w += check_answer(3); // the same thing, but checks the answer of question 3
    show_result(*c, *w, *t); // takes the values of correct, wrong, and total variables to the function show_result
    main();
}