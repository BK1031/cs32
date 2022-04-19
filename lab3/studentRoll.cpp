#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
    if (head == nullptr) {
        head = new Node;
        tail = head;
        head->s = new Student(s);
        head->next = nullptr;
    }
    else {
        Node *n = head;
        while (n->next) {
            n = n->next;
        }
        n->next = new Node;
        n->next->s = new Student(s);
        n->next->next = nullptr;
    }
}

std::string StudentRoll::toString() const {
    Node *n = head;
    std::string returnString = "[";
    while (n) {
        returnString += n->s->toString();
        if (n->next) {
            returnString += ",";
        }
        n = n->next;
    }
    returnString += "]";
    return returnString;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
    head = tail = NULL;
    Node *n = orig.head;
    while (n) {
        insertAtTail(*n->s);
        n = n->next;
    }
}

StudentRoll::~StudentRoll() {
    Node *n = head;
    while (n) {
        Node *temp = n;
        n = n->next;
        delete temp->s;
        delete temp;
    }
    head = nullptr;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
    // The next two lines are standard, and you should keep them.
    // They avoid problems with self-assignment where you might free up
    // memory before you copy from it.  (e.g. x = x)

    if (&right == this)
    return (*this);

    Node *n = head;
    while (n) {
        Node *temp = n;
        n = n->next;
        delete temp->s;
        delete temp;
    }
    head = nullptr;

    n = right.head;
    while (n) {
        insertAtTail(*n->s);
        n = n->next;
    }

    // KEEP THE CODE BELOW THIS LINE
    // Overloaded = should end with this line, despite what the textbook says.
    return (*this);
}





