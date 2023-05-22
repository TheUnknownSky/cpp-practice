#include <iostream>
using namespace std;
int scores[3] = {};
string names[3] = {};
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
void check_answer(int quest_num, int &correct){
    char answer, *a = &answer;
    int *c = &correct;
    cout << "\nAnswer: ";
    cin >> *a;
    char answers[3] = {'A', 'B', 'C'};
    if (*a == answers[quest_num - 1]){
        ++correct;
    }
}
void ask_name(string &name){
    cout << "\n-----------------------------------------------------------\n" << endl;
    cout << "Enter name: "; cin >> name;
}
void quiz_prompt(int &i){
    string name, *n = &name; 
    int correct = 0, *c = &correct;
    ask_name(*n);
    question1();
    check_answer(1, *c);
    question2();
    check_answer(2, *c);
    question3();
    check_answer(3, *c);
    names[i] = *n;
    scores[i] = *c;
    ++i;
}
void show_result(){
    cout << endl;
    for(int i = 0; i < 3; ++i){
        cout << names[i] << ": " << scores[i] << endl;
    }
}
int main(){
    int i = 0;
    quiz_prompt(i);
    quiz_prompt(i);
    quiz_prompt(i);
    show_result();
}   