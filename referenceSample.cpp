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
void check_answer(int quest_num, int &ctr){
    char answer;
    cout << "\nAnswer: "; cin >> answer; 
    char answers[3] = {'A', 'B', 'C'}; 
    if(answer != answers[quest_num - 1]){ 
        ++ctr; 
    }
}
void show_result(int &correct, int &wrong, int &total){
    correct = total - wrong;
    total = correct;
    cout << "\nCorrect: " << correct << endl;
    cout << "Wrong: " << wrong << endl << endl;
    cout << "Total: " << total << endl;
}
int main(){
    int correct = 0; 
    int wrong = 0;     
    int total = 3;   
    question1(); 
    check_answer(1, wrong); 
    question2(); 
    check_answer(2, wrong); 
    question3(); 
    check_answer(3, wrong); 
    show_result(correct, wrong, total); 
    main();
}