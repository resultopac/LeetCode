class MyCircularDeque {
public:

    int* arr;
    int front;
    int rear;
    int size;
    int maxSize;

    MyCircularDeque(int k) {
        arr = new int[k];
        front = rear = -1;
        size = 0;
        maxSize = k;
    }

    ~MyCircularDeque() {
        delete[] arr;
    }

    bool insertFront(int value) {
        if (size == maxSize) {
            return false;
        }
        if (front == -1) {
            front++;
            rear++;
        }else {
            front = (front-1 + maxSize)%maxSize;
        }
        arr[front] = value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if (size == maxSize) {
            return false;
        }
        size++;
        if (rear == -1) {
            rear++;
            front++;
        }else {
            rear = (rear+1)%maxSize;
        }
        arr[rear] = value;
        return true;
    }
    
    bool deleteFront() {
        if (size == 0) {
            return false;
        }
        front = (front+1)%maxSize;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if (size == 0) {
            return false;
        }
        rear = (rear-1 + maxSize)%maxSize;
        size--;
        return true;
    }
    
    int getFront() {
        if( size == 0){
            return -1;
        }
        return arr[front];
    }
    
    int getRear() {
        if( size == 0){
            return -1;
        }
        return arr[rear];
    }
    
    bool isEmpty() {
        if (size == 0) {
            return true;
        }

        return false;
    }
    
    bool isFull() {
        if (size == maxSize) {
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */