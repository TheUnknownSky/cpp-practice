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
void check_answer(int &quest_num, int &ctr){
    char answer;
    cout << "\nAnswer: "; cin >> answer;
    // answer prompt
    char answers[3] = {'A', 'B', 'C'}; 
    // array of correct answers
    if(answer != answers[quest_num - 1]){ // checks if the answer is wrong
        ++ctr; 
        // this directly increases the value of the variable aliased to it, which is the 'wrong' or '*w' variable
    }
    ++quest_num;
    // this directly increases the value of the variable aliased to it, which is the 'quest_num' or '*q' variable
}
void show_result(int &correct, int &wrong, int &total){
    correct = total - wrong;
    total = correct;
    cout << "\nCorrect: " << correct << endl;
    cout << "Wrong: " << wrong << endl << endl;
    cout << "Total: " << total << endl;
}
int main(){
    int correct = 0, *c = &correct; 
    // 'correct' is the same as '*c'' and vice versa
    int wrong = 0, *w = &wrong; 
    // 'wrong' is the same as '*w' and vice versa
    int total = 3, *t = &total; 
    // 'total' is the same as '*t' and vice versa
    int quest_num = 1, *q = &quest_num;
    // 'quest_num' is the same as '*q' and vice versa
    question1();
    // calls out question1 function
    check_answer(*q, *w);
    // this function takes the value of *q and *w directly and changes it directly inside the function
    // the value of *w increases by one (1) if the answer is wrong, while the value of *q increases by one (1) after the function is called
    question2();
    // calls out question2 function
    check_answer(*q, *w); 
    // the same as the previous check_answer function
    question3();
    // calls out question3 function
    check_answer(*q, *w); 
    // the same as the previous check_answer function
    show_result(*c, *w, *t);
    // takes the values of correct, wrong, and total variables directly to the function show_result
    main();
    // goes back to the first line of code inside the main function, works as a loop without using while/do-while/for loops
}