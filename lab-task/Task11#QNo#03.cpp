#include <iostream>
#include <stdexcept>
using namespace std;
class RingBuffer {
    int* buffer;
    int capacity, count, readCursor;
public:
    RingBuffer(int cap) {
        capacity = cap;
        count = 0;
        readCursor = 0;
        buffer = new int[capacity];
    }
    RingBuffer(const RingBuffer& r) {
        capacity = r.capacity;
        count = r.count;
        readCursor = r.readCursor;
        buffer = new int[capacity];
        for (int i = 0; i < capacity; i++) buffer[i] = r.buffer[i];
    }
    ~RingBuffer() { delete[] buffer; }
    RingBuffer& operator=(const RingBuffer& rhs) {
        if (this == &rhs) return *this;
        delete[] buffer;
        capacity = rhs.capacity;
        count = rhs.count;
        readCursor = rhs.readCursor;
        buffer = new int[capacity];
        for (int i = 0; i < capacity; i++) buffer[i] = rhs.buffer[i];
        return *this;
    }
    void push(int reading) {
        if (count < capacity) {
            buffer[(readCursor + count) % capacity] = reading;
            count++;
        } else {
            buffer[readCursor] = reading;
            readCursor = (readCursor + 1) % count;
        }
    }
    int& operator[](int index) {
        if (index < 0 || index >= count) throw out_of_range("Invalid index");
        return buffer[(readCursor + index) % count];
    }
    RingBuffer& operator++() {
        if (count > 0) readCursor = (readCursor + 1) % count;
        return *this;
    }
    RingBuffer operator++(int) {
        RingBuffer old(*this);
        if (count > 0) readCursor = (readCursor + 1) % count;
        return old;
    }
    bool operator!() const { return count == 0; }
    friend ostream& operator<<(ostream& out, const RingBuffer& r) {
        for (int i = 0; i < r.count; i++) out << r.buffer[(r.readCursor + i) % r.count] << " ";
        return out;
    }
};
int main() {
    int cap, n, x;
    cout << "Buffer capacity: ";
    cin >> cap;
    RingBuffer buf(cap);
    if (!buf) cout << "Buffer is empty" << endl;
    cout << "How many readings: ";
    cin >> n;
    cout << "Enter readings: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        buf.push(x);
    }
    if (!buf) cout << "Buffer is empty" << endl;
    else cout << "Buffer is not empty" << endl;
    cout << "Buffer: " << buf << endl;
    cout << "After ++buf: " << ++buf << endl;
    RingBuffer old = buf++;
    cout << "buf++ gave old: " << old << endl;
    cout << "buf now: " << buf << endl;
    try {
        cout << "buf[0] = " << buf[0] << endl;
        cout << buf[cap] << endl;
    }
    catch (out_of_range& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
