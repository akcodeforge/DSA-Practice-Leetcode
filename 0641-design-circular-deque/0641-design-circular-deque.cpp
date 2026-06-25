class MyCircularDeque {
public:
    int f; // fromt
    int b; // back/rear
    int s; // current size
    int c; // capacity
    vector<int> arr;
    MyCircularDeque(int k) {
        f = 0;
        b = 0;
        s = 0;
        c = k;
        vector<int> v(k);
        arr = v;
    }

    bool insertFront(int value) { /// push from front
        if (s == c)
            return false;
        f = (f - 1 + c) % c;
        arr[f] = value;
        s++;
        return true;
    }

    bool insertLast(int value) { /// push from back
        if (s == c)
            return false;
        arr[b] = value;
        b++;
        if (b == c)
            b = 0;
        s++;
        return true;
    }

    bool deleteFront() { /// pop front
        if (s == 0)
            return false;
        f++;
        if (f == c)
            f = 0;
        s--;
        return true;
    }

    bool deleteLast() { /// pop back
        if (s == 0)
            return false;
        b = (b - 1 + c) % c;
        s--;
        return true;
    }

    int getFront() {
        if (s == 0)
            return -1;
        return arr[f];
    }

    int getRear() {
        if (s == 0)
            return -1;
        if (b == 0)
            return arr[c - 1];
        return arr[b - 1];
    }

    bool isEmpty() {
        if (s == 0)
            return true;
        else
            return false;
    }

    bool isFull() {
        if (s == c)
            return true;
        else
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