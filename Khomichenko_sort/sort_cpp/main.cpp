#include <iostream>

struct Node {
    int data;
    Node* next;
};

struct DoubleNode {
    int data;
    DoubleNode* next;
    DoubleNode* prev;
};

Node* generateRandomLinkedList(int n) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        newNode->data = rand() % 100;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

DoubleNode* generateRandomDoubleLinkedList(int n) {
    DoubleNode* head = nullptr;
    DoubleNode* tail = nullptr;

    for (int i = 0; i < n; i++) {
        DoubleNode* newNode = new DoubleNode;
        newNode->data = rand() % 100;
        newNode->next = nullptr;
        newNode->prev = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    return head;
}

void displayDoubleLinkedList(DoubleNode* head) {
    DoubleNode* current = head;

    while (current != nullptr) {
        std::cout << current->data  << ", ";
        current = current->next;
    }

    std::cout << std::endl;
}

void displayDoubleLinkedListPointerAndValue (DoubleNode* head) {
    DoubleNode* current = head;

    while (current != nullptr) {
        std::cout << "(" << current << " " << current->data << "), ";
        current = current->next;
    }

    std::cout << std::endl;
}

void displayPointers(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

void displayLinkedList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->data  << ", ";
        current = current->next;
    }

    std::cout << std::endl;
}

void displayLinkedListPointerAndValue (Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << "(" << current << " " << current->data << "), ";
        current = current->next;
    }

    std::cout << std::endl;
}

Node* quickSort(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* pivot = head;
    Node* current = head->next;
    Node* smaller = nullptr;
    Node* larger = nullptr;

    while (current != nullptr) {
        Node* next = current->next;

        if (current->data < pivot->data) {
            current->next = smaller;
            smaller = current;
        } else {
            current->next = larger;
            larger = current;
        }

        current = next;
    }

    smaller = quickSort(smaller);
    larger = quickSort(larger);

    pivot->next = larger;

    if (smaller == nullptr) {
        return pivot;
    }

    Node* tail = smaller;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = pivot;

    return smaller;
}

Node* quickSortReverse (Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* pivot = head;
    Node* current = head->next;
    Node* smaller = nullptr;
    Node* larger = nullptr;

    while (current != nullptr) {
        Node* next = current->next;

        if (current->data < pivot->data) {
            current->next = smaller;
            smaller = current;
        } else {
            current->next = larger;
            larger = current;
        }

        current = next;
    }

    larger = quickSortReverse(larger);
    smaller = quickSortReverse(smaller);

    pivot->next = smaller;

    if (larger == nullptr) {
        return pivot;
    }

    Node* tail = larger;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = pivot;

    return larger;
}


DoubleNode* quickSort(DoubleNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    DoubleNode* pivot = head;
    DoubleNode* current = head->next;
    DoubleNode* smaller = nullptr;
    DoubleNode* larger = nullptr;

    while (current != nullptr) {
        DoubleNode* next = current->next;

        if (current->data < pivot->data) {
            current->next = smaller;
            current->prev = nullptr;

            if (smaller != nullptr) {
                smaller->prev = current;
            }

            smaller = current;
        } else {
            current->next = larger;
            current->prev = nullptr;

            if (larger != nullptr) {
                larger->prev = current;
            }

            larger = current;
        }

        current = next;
    }

    smaller = quickSort(smaller);
    larger = quickSort(larger);

    pivot->next = larger;
    pivot->prev = nullptr;

    if (larger != nullptr) {
        larger->prev = pivot;
    }

    if (smaller == nullptr) {
        return pivot;
    }

    DoubleNode* tail = smaller;

    while (tail->next != nullptr) {
        tail = tail->next;
    }

    tail->next = pivot;
    pivot->prev = tail;

    return smaller;
}


int * generateRandomIntArray (int n) {
    int* arr = new int[n];

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    return arr;
}


void displayIntArray (int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ", ";
    }

    std::cout << std::endl;
}

void displayArrayPointerAndValue (int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "(" << arr + i << " " << arr[i] << "), ";
    }

    std::cout << std::endl;
}

void quickSort(int* arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    quickSort(arr, left, j);
    quickSort(arr, i, right);
}


int main() {
    srand(time(0));

    Node* randList = generateRandomLinkedList(5);

    std::cout << "Random list: " << std::endl;
    displayLinkedList(randList);

    std::cout << "Random list with pointers: " << std::endl;
    displayLinkedListPointerAndValue(randList);

    std::cout << "\n" << std::endl;

    Node* sortedList = quickSort(randList);

    std::cout << "Sorted list: " << std::endl;
    displayLinkedList(sortedList);

    std::cout << "Sorted list with pointers: " << std::endl;
    displayLinkedListPointerAndValue(sortedList);

    Node* sortedListReverse = quickSortReverse(sortedList);

    std::cout << "Sorted list reverse with pointers: " << std::endl;
    displayLinkedListPointerAndValue(sortedListReverse);

    std::cout << "\n\n" << std::endl;

    DoubleNode* randDoubleList = generateRandomDoubleLinkedList(10);
    displayDoubleLinkedList(randDoubleList);
//    displayDoubleLinkedListPointerAndValue(randDoubleList);

    std::cout << "\n" << std::endl;

    DoubleNode* sortedDoubleList = quickSort(randDoubleList);

//    displayDoubleLinkedList(sortedDoubleList);
//    displayDoubleLinkedListPointerAndValue(sortedDoubleList);

    std::cout << "\n\n" << std::endl;

    int* randIntArray = generateRandomIntArray(5);

    std::cout << "Random int array: " << std::endl;

    displayIntArray(randIntArray, 5);

    std::cout << "Random int array with pointers: " << std::endl;
    displayArrayPointerAndValue(randIntArray, 5);

    std::cout << "\n" << std::endl;

    quickSort(randIntArray, 0, 4);

    std::cout << "Sorted int array: " << std::endl;
    displayIntArray(randIntArray, 5);

    std::cout << "Sorted int array with pointers: " << std::endl;
    displayArrayPointerAndValue(randIntArray, 5);

    return 0;
}

