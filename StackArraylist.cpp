#include <iostream>
#include <string>
#include <chrono>
using namespace std::chrono;
using namespace std;

const int max_size = 100;
int Stack[max_size];
int top = -1;

string Push(int x) {
    if(top == max_size-1) {
       return "Stack is Overflow";
    } else {
       top++;
       Stack[top] = x;
       return "Pushed Successfully";
    }
}

string Pop() {
    if(top > -1) {
        top--;
        return "Popped Successfully";
    } else {
        return "Stack is Underflow";
    }
}

bool IsEmpty() {
    if (top < 0) {
        return true;
    } else {
        return false;
    }
}

bool IsFull() {
    if(top == max_size-1) {
        return true;
    } else {
        return false;
    }
}

int StackTop() {
    if(!IsEmpty()) {
        return Stack[top];
    } else {
        return -1;  // Return -1 for an empty stack
    }
}

void Display() {
    if(!IsEmpty()) {
        for(int i = top; i >= 0; i--) {
            cout << Stack[i] << " ";
        }
    } else {
        cout << "Stack is Empty";
    }
    cout << endl;
} 




int main() {
    auto start = high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    Pop(); Pop(); Pop(); Pop(); Pop();
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() <<" "<< "microseconds"<<endl;
    return 0;
}