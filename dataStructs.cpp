#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void stackPrompt(stack<int> &s);
void enterValues(stack<int> &s);
void removeValues(stack<int> &s);
void deleteAllValues(stack<int> &s);

void queuePrompt(queue<int> &q);
void enterValues(queue<int> &q);
void removeValues(queue<int> &q);
void deleteAllValues(queue<int> &q);

// Stack
void stackPrompt(stack<int> &s){
    bool access = true;
    while (access){
        int choice;
        cout << "\n----- STACK -----\n\n1. Enter Stack Values\n2. Remove Stack Values\n3. Delete All Elements\n4. Exit" << endl;
        cout << "\nChoose an action: "; cin >> choice;
        switch (choice){
            case 1: enterValues(s); break;
            case 2: removeValues(s); break;
            case 3: deleteAllValues(s); break;
            default: access = false;
        }
    }
}
void enterValues(stack<int> &s){
    int stackSize, stackElement;
    cout << "\nCurrent stack size: " << s.size() << endl;
    cout << "Number of stack elements to add: "; cin >> stackSize;
    for (int i = 0; i < stackSize; ++i){
        cout << "Enter stack element: "; cin >> stackElement;
        s.push(stackElement);
    }
}
void removeValues(stack<int> &s){
    cout << "Current stack size: " << s.size() << endl;
    if (!s.empty()){
        int stackSize, stackSizeToRemove;
        cout << "Enter number of elements to be removed: "; cin >> stackSizeToRemove;
        for (int i = 0; i < stackSizeToRemove; ++i){
            cout << "Top element to be popped: " << s.top() << endl;
            s.pop();
            if (s.empty()){
                cout << "ERROR: Stack Underflow - No more elements to pop!" << endl;
                break;
            }
        }
        if (!s.empty()){
            cout << "Current top element in the stack: " << s.top() << endl;
        }
        
    } else {
        cout << "No stack elements to remove." << endl;
    }
}
void deleteAllValues(stack<int> &s){
    while(!s.empty()){
        cout << "Top element to be popped: " << s.top() << endl;
        s.pop();
    }
}

// Queue

void queuePrompt(queue<int> &q){
    bool access = true;
    while (access){
        int choice;
        cout << "\n----- QUEUE -----\n\n1. Enter Queue Values\n2. Remove Queue Values\n3. Delete All Elements\n4. Exit" << endl;
        cout << "\nChoose an action: "; cin >> choice;
        switch (choice){
            case 1: enterValues(q); break;
            case 2: removeValues(q); break;
            case 3: deleteAllValues(q); break;
            default: access = false;
        }
    }
}
void enterValues(queue<int> &q){
    int queueSize, queueElement;
    cout << "\nCurrent queue size: " << q.size() << endl;
    cout << "Number of queue elements to add: "; cin >> queueSize;
    for (int i = 0; i < queueSize; ++i){
        cout << "Enter queue element: "; cin >> queueElement;
        q.push(queueElement);
    }
}
void removeValues(queue<int> &q){
    cout << "Current queue size: " << q.size() << endl;
    if (!q.empty()){
        int queueSize, queueSizeToRemove;
        cout << "Enter number of elements to be removed: "; cin >> queueSizeToRemove;
        for (int i = 0; i < queueSizeToRemove; ++i){
            cout << "Element in the back: " << q.back() << endl;
            cout << "Element to dequeue: " << q.front() << endl;
            q.pop();
            if (q.empty()){
                cout << "ERROR: No more elements to dequeue!" << endl;
                break;
            }
        }
        if (!q.empty()){
            cout << "Current front element in the queue: " << q.front() << endl;
        }
        
    } else {
        cout << "No queue elements to dequeue." << endl;
    }
}
void deleteAllValues(queue<int> &q){
    while(!q.empty()){
        cout << "Top element to be popped: " << q.front() << endl;
        q.pop();
    }
}

int main(){
    stack<int> myStack;
    queue<int> myQueue;
    int choice;
    bool access = true;
    cout << "\n1. Stack\n2. Queue\n3. Exit\n";
    cout << "Choose data structure: "; cin >> choice;
    switch (choice){
        case 1: stackPrompt(myStack); main(); break;
        case 2: queuePrompt(myQueue); main(); break;
        default: access = false; break;
    }
}