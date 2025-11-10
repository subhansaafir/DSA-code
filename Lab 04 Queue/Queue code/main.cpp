#include"L_queue.cpp"

int main() {
    LQueue<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(100);
    cout<<q.top()<<endl;
    
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout << "Dequeued: " << q.dequeue() << endl;
    cout<<q.top()<<endl;
    cout<<q.size()<<endl;
    return 0;
}