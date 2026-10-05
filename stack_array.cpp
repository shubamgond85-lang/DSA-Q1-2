// Q1: Stack using a fixed-size array (no STL stack)
#include <iostream>
using namespace std;

class Stack {
    int *arr;
    int top;       // index of top element, -1 when empty
    int capacity;

public:
    Stack(int size) : capacity(size), top(-1) { arr = new int[size]; }
    ~Stack() { delete[] arr; }

    bool isEmpty() const { return top == -1; }
    bool isFull() const { return top == capacity - 1; }

    // PUSH(x): O(1)
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << x << "\n";
            return;
        }
        arr[++top] = x;
        cout << x << " pushed\n";
    }

    // POP(): O(1)
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Nothing to pop\n";
            return;
        }
        cout << arr[top--] << " popped\n";
    }

    // PEEK(): O(1)
    void peek() const {
        if (isEmpty()) {
            cout << "Stack is empty, nothing to peek\n";
            return;
        }
        cout << "Top element: " << arr[top] << "\n";
    }

    // DISPLAY(): O(n)
    void display() const {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack (top -> bottom): ";
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << "\n";
    }
};

int main() {
    int size, choice, x;
    cout << "Enter stack capacity: ";
    cin >> size;
    Stack s(size);

    do {
        cout << "\n1.PUSH  2.POP  3.PEEK  4.DISPLAY  0.EXIT\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> x; s.push(x); break;
            case 2: s.pop(); break;
            case 3: s.peek(); break;
            case 4: s.display(); break;
            case 0: cout << "Bye\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
