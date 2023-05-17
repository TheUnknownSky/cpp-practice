#include <iostream>
using namespace std;
void question1(){ 
    cout << "\nQuestion 1: What do we use to make an output in C++?" << endl;
    cout << "A. cout" << endl;
    cout << "B. cin" << endl;
    cout << "C. print" << endl;
    cout << "D. printf" << endl;
}
void question2(){ 
    cout << "\nQuestion 2: What is the contents-of operator in the following?" << endl;
    cout << "A. &" << endl;
    cout << "B. *" << endl;
    cout << "C. +" << endl;
    cout << "D. -" << endl;
}
void question3(){ 
    cout << "\nQuestion 3: What is the programming language that uses 'cout' syntax?" << endl;
    cout << "A. Java" << endl;
    cout << "B. Python" << endl;
    cout << "C. C++" << endl;
    cout << "D. C" << endl;
}
int check_answer(int quest_num){
    char answer, *a = &answer;
    int ctr, *c = &ctr;
    *c = 0;
    cout << "\nAnswer: ";
    cin >> *a;
    char answers[3] = {'A', 'B', 'C'};
    if (*a != answers[quest_num - 1])
    {
        *c = 1;
    }
    return *c;
}
void show_result(int correct, int wrong, int total){
    int *c = &correct, *w = &wrong, *t = &total;
    *c = *t - *w;
    *t = *c;
    cout << "\nCorrect: " << *c << endl;
    cout << "Wrong: " << *w << endl << endl;
    cout << "Total: " << *t << endl;
}
int main(){
    int correct = 0, *c = &correct;
    int wrong = 0, *w = &wrong;
    int total = 3, *t = &total;
    question1();
    *w += check_answer(1);
    question2();
    *w += check_answer(2);
    question3();
    *w += check_answer(3);
    show_result(*c, *w, *t);
    main();
}