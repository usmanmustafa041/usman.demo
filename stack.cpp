#include<iostream>

class stack {
private:
    int* data;
    int TOP;
    int SIZE;

public:
    stack(int s = 100) {
        data = new int[s];
        TOP = 0;
        SIZE = s;
    }

    void push(const int& val) {
        if (!(TOP == SIZE)) {
            data[TOP] = val;
            TOP++;
        }
        else {
            throw("stack overflow");
        }
    }

    int top() const {
        if (!(TOP == 0)) {
            return data[TOP - 1];
        }
        else {
            throw("stack is empty");
        }
    }

    void pop() {
        if (!(TOP == 0)) {
            TOP--;
        }
        else {
            throw("stack underflow");
        }
    }

    bool full() const {
        return (TOP == SIZE);
    }

    int size() const {
        return TOP;
    }

    bool empty() const {
        return (TOP == 0);
    }

    stack& operator=(const stack& rhs) {
        if (this != &rhs) {
            if (this->data != NULL) {
                delete[] this->data;
            }
            this->data = new int[rhs.SIZE];
            this->TOP = rhs.TOP;
            this->SIZE = rhs.SIZE;
            for (int i = 0; i < TOP; ++i) {
                this->data[i] = rhs.data[i];
            }
        }
        return *this;
    }

    bool operator==(const stack& rhs) const {
        if (this->size() != rhs.size()) {
            return false;
        }
        for (int i = 0; i < this->size(); ++i) {
            if (this->data[i] != rhs.data[i]) {
                return false;
            }
        }
        return true;
    }

    void display() const {
        if (this->empty()) {
            std::cout << "Stack is empty." << std::endl;
        }
        else {
            std::cout << "Stack elements: ";
            for (int i = 0; i < this->size(); ++i) {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    ~stack() {
        delete[] data;
    }
};

void main() {
    stack s1(5);
    stack s2;

    try {
        s1.push(4);
        s1.push(2);
        s1.push(5);
        s1.push(8);
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    std::cout << "Size of s1: " << s1.size() << std::endl;
    std::cout << "Top of s1: " << s1.top() << std::endl;
    s1.display();

    try {
        s1.pop();
    }
    catch (const char* msg) {
        std::cout << msg << std::endl;
    }

    std::cout << "After deleting top value: " << s1.top() << std::endl;
    s1.display();

    if (s1.empty()) {
        std::cout << "Stack s1 is empty." << std::endl;
    }

    s2 = s1;
    std::cout << "Size of s2: " << s2.size() << std::endl;
    s2.display();

    // Testing the == operator
    if (s1 == s2) {
        std::cout << "s1 and s2 are equal." << std::endl;
    }
    else {
        std::cout << "s1 and s2 are not equal." << std::endl;
    }

}
