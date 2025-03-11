#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIS87ujkvvT_H
#include <stdexcept>

// copied from assignment.
template <typename ItemType> struct Node {
  ItemType data;
  Node *nextPtr;
  Node() {
    data = 0;
    nextPtr = nullptr;
  }
};

// Sivkan: created class skeleton.
template <typename ItemType> // template class
class SingleLinkedList {
private:
  Node<ItemType> *head; // the head node.
  Node<ItemType> *tail; // the tail node.
  size_t numItems{};    // the number of items in the class.
public:
  // Maggie: constructor for class.
  SingleLinkedList() {
    head = nullptr; // set the head node to null parameter.
    tail = nullptr; // set the tail node to null parameter.
    numItems = 0;   // set the number of items to 0.
  }

  // ADDED
  // Katy: copy constructor.
  SingleLinkedList(const SingleLinkedList &other) {
    head = nullptr; // set the head node to null parameter.
    tail = nullptr; // set the tail node to null parameter.
    numItems = 0;   // set the number of items to 0.

    Node<ItemType> *current =
        other.head; // set the current node to the head node of the other list.
    while (current != nullptr) { // loop through the other list.
      pushBack(current->data);
      current = current->nextPtr;
    }
  }

  // ADDED
  // Katy: copy assignment operator
  SingleLinkedList &operator=(const SingleLinkedList &other) {
    // check for self-assignment
    if (this != &other) { // check if the two lists are the same.
      return *this;
    }
    // clear current list
    while (!empty()) {
      popFront();
    }

    // copy each node from the other list
    Node<ItemType> *current = other.head;
    while (current != nullptr) {
      pushBack(current->data);
      current = current->nextPtr;
    }
    return *this;
  }

  // ADDED
  // Katy: destructor for class.
  ~SingleLinkedList() {
    // delete all nodes
    while (!empty()) {
      popFront();
    }
  }

  // ADDED
  // Katy: pushFront function.
  // Pre: takes in an item of any item type.
  // Post: adds it to the front of the linked list. Returns nothing.
  void pushFront(ItemType item) {      // pass in an item of item type.
    auto *node = new Node<ItemType>(); // create a new node called node, node to
                                       // be added.
    node->data = item;     // set the data of this node to the item given.
    if (head == nullptr) { // case if linked list is empty.
      head = node;         // set both head and tail equal to the new node.
      tail = node;
    } else {                // otherwise...
      node->nextPtr = head; // new node points to the head.
      head = node;          // the head becomes the new node.
    }
    numItems++; // increment the number of items.
  }

  // Sivkan: popFront function.
  // Pre: takes in nothing.
  // Post: removes item from the front of the list and returns that node's data.
  ItemType popFront() {
    if (numItems == 0) {                             // case if list is empty:
      throw std::invalid_argument("List is empty."); // throw an error.
    }
    Node<ItemType> *node =
        head; // create a new node and set it to point to the head.
    ItemType data = node->data; // set a variable equal to the data to the data
                                // in the node we are deleting.
    if (numItems == 1) { // case if there is only one item in the linked list:
      delete head;       // delete the head,
      head = nullptr;    // set both head and tail equal to null parameter.
      tail = nullptr;
    } else {                // otherwise...
      head = head->nextPtr; // set the head to the next node in the list,
      delete node;          // delete the node.
    }
    numItems--;  // decrement  the number of items in the list.
    return data; // return the data that was removed.
  }

  // Maggie: front function.
  // Pre: takes in nothing.
  // Post: returns the data at the front of the linked list.
  ItemType front() {
    if (numItems == 0) { // case if the list is empty:
      throw std::invalid_argument("List is empty."); // throw an error.
    }
    return head->data; // otherwise, return the head node's data.
  }

  // Maggie: back function.
  // Pre: takes in nothing.
  // Post: returns the data at the back of the linked list.
  ItemType back() {
    if (numItems == 0) { // case if the list is empty:
      throw std::invalid_argument("List is empty."); // throw an error.
    }
    return tail->data; // return the tail node's data.
  }

  // Katy: empty function.
  // Pre: takes in nothing.
  // Post: returns a bool, T or F, if the list is empty.
  bool empty() const {
    return numItems == 0; // returns according to if numItems is 0.
  }

  // Katy: remove function.
  //  Pre: takes in an item of item type.
  //  Post: returns T or F whether the item was removed.
  bool remove(const ItemType &item) {
    if (numItems == 0) { // case if list is empty:
      return false;      // nothing to remove, so return false.
    }
    if (head->data == item) { // case if the item to remove is at the front,
      popFront();             // call the popFront function.
      return true;            // return true.
    }
    // otherwise...
    Node<ItemType> *current = head; // create a new node and point it to head.
    // loop to find the item or until we reach the end (which means item is not
    // in the list).
    while (current->nextPtr != nullptr && current->nextPtr->data != item) {
      current = current->nextPtr; // moves to the next node in the list.
    }
    if (current->nextPtr ==
        nullptr) {  // if current is equal to nullptr at the end of the list,
      return false; // return false because item is not in the list.
    }
    // Otherwise...
    Node<ItemType> *temp = current->nextPtr; // create a new temp node and store
                                             // data that is being deleted.
    current->nextPtr =
        temp->nextPtr; // skip over the node that is being deleted.
    // ADDED
    // update tail if we're removing the last node
    if (temp == tail) {
      tail = current;
    }

    temp->nextPtr =
        nullptr; // set the temp node to nullptr (disconnect it from list).
    delete temp; // delete the temp node.
    numItems--;  // decrement the number of items.
    return true; // return true.
  }

  // Sivkan: pushback function.
  // Pre: takes in an item.
  // Post: adds item to the back, returns nothing.
  void pushBack(ItemType item) {
    auto *node = new Node<ItemType>(); // allocate memory for the new node.
    node->data = item; // assign the data of the new node to item given.
    // ADDED
    node->nextPtr = nullptr; // set the next pointer of the new node to nullptr.
    if (head == nullptr) {   // case if list is empty:
      head = node;           // set head to new node,
      tail = node;           // and set tail to new node.
    } else {                 // otherwise...
      tail->nextPtr = node;  // link the tail to the new node.
      tail = node;           // set the tail pointer to new node.
    }
    numItems++; // increment number of items.
  }

  // Maggie: popBack function.
  // Pre: takes in nothing.
  // Post: deletes the node at the end of the list. Returns the data of the node
  // deleted.
  ItemType popBack() {
    // CHANGED moved ItemType data down
    // store data that will be deleted in a variable.
    if (numItems == 0) {                             // case if empty:
      throw std::invalid_argument("List is empty."); // throw an error.
    }
    if (numItems == 1) { // case if there is one item:
      return popFront(); // call pop front and return it.
    }
    // ADDED
    // store data that will be deleted in a variable.
    ItemType data = tail->data;
    // otherwise...
    Node<ItemType> *current = head; // create pointer and point it to head.
    // loop through the linked list until we reach the node before the tail
    // CHANGED
    while (current->nextPtr != tail) {
      current = current->nextPtr; // move to next pointer.
    }
    delete tail;    // delete the tail pointer.
    tail = current; // point tail to the current node.
    // ADDED
    tail->nextPtr = nullptr; // ensure the new tail points to nullptr
    numItems--;              // decrement number of items.
    return data;             // return the data that was deleted.
  }

  // Sivkan: getNumItems function.
  // Pre: takes in nothing
  // Post: returns the number of items.
  size_t getNumItems() const {
    return numItems; // returns numItems.
  }

  // Katy: find function.
  // Pre: takes in an item of item type.
  // Post: returns whether that item was found in the list or not.
  bool find(const ItemType &item) {
    Node<ItemType> *current = head; // create node called current.
    while (current != nullptr) {  // while we are not at the end of the list...
      if (current->data == item)  // if current's data is equal to item,
        return true;              // return truw.
      current = current->nextPtr; // traverse.
    }
    return false; // otherwise, return false.
  }

  // Sivkan addBefore function.
  // Pre: takes in an item of item type and a new value of item type.
  // Post: adds the new value given before the item given.
  void addBefore(const ItemType &item, const ItemType &newValue) {
    // ADDED
    // if list is empty, add new value
    if (numItems == 0) {
      pushFront(newValue);
      return;
    }

    // ADDED
    //  if item to insert before is first element
    if (head != nullptr && head->data == item) {
      pushFront(newValue);
      return;
    }

    // search for item
    Node<ItemType> *current =
        head; // create a new node called current and point it to head.

    // while loop that continues until you reach node before the end of the list
    // or the node before the item.
    while (current->nextPtr != nullptr && current->nextPtr->data != item) {
      current = current->nextPtr;
    }
    // CHANGED
    if (current->nextPtr == nullptr) { // item not found
      pushBack(newValue); // call the pushback function and pass in new value.
      return;             // return to exit out of the function.
    }

    // Otherwise...
    auto *node = new Node<ItemType>(); // create a new node for the new value.
    node->data = newValue; // set the data of the new node to new value.
    node->nextPtr = current->nextPtr; // link the new node to the list.
    current->nextPtr = node;          // point the current node to the new one.
    numItems++;                       // increment number of items.
  }

  // Maggie: insert function.
  // Pre: takes in pos of size_t and a new value of item type.
  // Post: inserts the new value at the pos given. Returns nothing.
  void insert(const size_t pos, const ItemType &newValue) {
    // CHANGED JUST CHECK WHOLE FUNCTION
    if (pos == 0) {        // case if the pos is at the end of the linked list.
      pushFront(newValue); // call the pushback function and pass in new value.
      return;              // return to exit out of the function.
    }

    if (pos == numItems) {
      pushBack(newValue);
      return;
    }
    if (pos > numItems) // case if the pos is more than the number of items:
      throw std::invalid_argument(
          "Position is out of bounds"); // throw an error.

    // Otherwise...
    Node<ItemType> *current = head; // create a new node and set it to head.

    // CHANGED
    // loop through until it reaches the pos given.
    for (size_t i = 0; i < pos - 1; i++) {
      current = current->nextPtr; // Traverse.
    }
    auto *node = new Node<ItemType>(); // new node space for new value.
    node->data = newValue; // set the data of the new node to the new value.
    node->nextPtr =
        current
            ->nextPtr; // point the new node to the node that points at the pos.
    current->nextPtr = node; // point prev node to the new node.
    numItems++;              // increment number of items.
  }
};

#endif // SINGLELINKEDLIST_H
