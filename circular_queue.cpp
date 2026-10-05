// Q2: Circular Queue using an array
// Full/empty distinction: a separate 'count' variable tracks the number of
// elements, so all 'capacity' slots can be used and
//   empty  <=> count == 0
//   full   <=> count == capacity
#include <iostream>
using namespace std;

class CircularQueue {
    int *arr;
    int front, rear, count, capacity;

public:
    CircularQueue(int size) : capacity(size), front(0), rear(-1), count(0) {
        arr = new int[size];
    }
    ~CircularQueue() { delete[] arr; }

    bool isEmpty() const { return count == 0; }
    bool isFull() const { return count == capacity; }

    // ENQUEUE(x): O(1)
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot enqueue " << x << "\n";
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = x;
        count++;
        cout << x << " enqueued\n";
    }

    // DEQUEUE(): O(1)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue\n";
            return;
        }
        cout << arr[front] << " dequeued\n";
        front = (front + 1) % capacity;
        count--;
    }

    // FRONT(): O(1)
    void getFront() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Front element: " << arr[front] << "\n";
    }

    // DISPLAY(): O(n)
    void display() const {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue (front -> rear): ";
        for (int i = 0, idx = front; i < count; i++, idx = (idx + 1) % capacity)
            cout << arr[idx] << " ";
        cout << "\n";
    }
};

int main() {
    int size, choice, x;
    cout << "Enter queue capacity: ";
    cin >> size;
    CircularQueue q(size);

    do {
        cout << "\n1.ENQUEUE  2.DEQUEUE  3.FRONT  4.DISPLAY  0.EXIT\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1: cout << "Value: "; cin >> x; q.enqueue(x); break;
            case 2: q.dequeue(); break;
            case 3: q.getFront(); break;
            case 4: q.display(); break;
            case 0: cout << "Bye\n"; break;
            default: cout << "Invalid choice\n";
        }
    } while (choice != 0);
    return 0;
}
