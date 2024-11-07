class PatientQueue:
    def __init__(self):
        self.queue = []

    def enqueue(self, patient):
        """Add a patient to the end of the queue."""
        self.queue.append(patient)
        print(f"Patient {patient} added to the queue.")

    def dequeue(self):
        """Remove and return the patient at the front of the queue."""
        if not self.is_empty():
            patient = self.queue.pop(0)
            print(f"Patient {patient} removed from the queue.")
            return patient
        else:
            print("No patients in the queue.")
            return None

    def is_empty(self):
        """Check if the queue is empty."""
        return len(self.queue) == 0

class EmergencyStack:
    def __init__(self):
        self.stack = []

    def push(self, emergency_patient):
        """Add a patient to the top of the stack."""
        self.stack.append(emergency_patient)
        print(f"Emergency patient {emergency_patient} added to the stack.")

    def pop(self):
        """Remove and return the patient at the top of the stack."""
        if not self.is_empty():
            patient = self.stack.pop()
            print(f"Emergency patient {patient} removed from the stack.")
            return patient
        else:
            print("No emergency patients in the stack.")
            return None

    def is_empty(self):
        """Check if the stack is empty."""
        return len(self.stack) == 0

# Example usage
pq = PatientQueue()
pq.enqueue("Patient 1")
pq.enqueue("Patient 2")
pq.dequeue()

es = EmergencyStack()
es.push("Emergency Patient A")
es.push("Emergency Patient B")
es.pop()
