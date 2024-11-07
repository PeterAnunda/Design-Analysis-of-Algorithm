#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

class PatientQueue {
private:
    queue<string> q;

public:
    void enqueue(const string& patient) {
        q.push(patient);
        cout << "Patient " << patient << " added to the queue." << endl;
    }

    void dequeue() {
        if (!q.empty()) {
            cout << "Patient " << q.front() << " removed from the queue." << endl;
            q.pop();
        } else {
            cout << "No patients in the queue." << endl;
        }
    }

    bool isEmpty() const {
        return q.empty();
    }
};

class EmergencyStack {
private:
    stack<string> s;

public:
    void push(const string& emergencyPatient) {
        s.push(emergencyPatient);
        cout << "Emergency patient " << emergencyPatient << " added to the stack." << endl;
    }

    void pop() {
        if (!s.empty()) {
            cout << "Emergency patient " << s.top() << " removed from the stack." << endl;
            s.pop();
        } else {
            cout << "No emergency patients in the stack." << endl;
        }
    }

    bool isEmpty() const {
        return s.empty();
    }
};

// Example usage
int main() {
    PatientQueue pq;
    pq.enqueue("Patient 1");
    pq.enqueue("Patient 2");
    pq.dequeue();

    EmergencyStack es;
    es.push("Emergency Patient A");
    es.push("Emergency Patient B");
    es.pop();

    return 0;
}
