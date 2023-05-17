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
        correct = correct + 1;
    }
}
void ask_name(string &name){
    cout << "\n-----------------------------------------------------------\n" << endl;
    cout << "Enter name: "; cin >> name;
}
void quiz_prompt(string &name, int &correct, int &i){
    ask_name(name);
    question1();
    check_answer(1, correct);
    question2();
    check_answer(2, correct);
    question3();
    check_answer(3, correct);
    names[i] = name;
    scores[i] = correct;
    ++i;
    correct = 0;
}
void show_result(){
    cout << endl;
    cout << names[0] << ": " << scores[0] << endl;
    cout << names[1] << ": " << scores[1] << endl;
    cout << names[2] << ": " << scores[2] << endl;
}
int main(){
    int correct = 0, *c = &correct, i = 0;
    string name, *n = &name;
    quiz_prompt(*n, *c, i);
    quiz_prompt(*n, *c, i);
    quiz_prompt(*n, *c, i);
    show_result();
}   