#pragma once
#ifndef NODE_HPP
#define NODE_HPP

template <typename DATATYPE>
class Node {
public:
    DATATYPE* NodeData;
    Node<DATATYPE>* next;

    Node() {
        NodeData = nullptr;
        next = nullptr;
    }
    bool operator==(Node<DATATYPE>&) const;
};

template <typename DATATYPE>
bool Node<DATATYPE>::operator==(Node<DATATYPE>& right) const {
    if (*NodeData == right.*NodeData)
        return true;
    else
        return false;
}

template <typename NODETYPE>
class List {
private:
    NODETYPE* head;
    int listSize;

public:
    List() {
        head = nullptr;
        listSize = 0;
    }
    ~List();

    void appendNode(NODETYPE&);
    bool isNode(NODETYPE&);
    void deleteNode(NODETYPE&);
    NODETYPE* getListHead() const;
    int getListSize() const;

    
};

template <typename NODETYPE>

void List<NODETYPE>::appendNode(NODETYPE& newData) {
    auto newNode = new NODETYPE(newData);
    auto nodePtr = head;

    if (!head) {
        head = newNode;
    }
    else {
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
    ++listSize;
}

template <typename NODETYPE>
bool List<NODETYPE>::isNode(NODETYPE& searched) {
    if (!head) return false;

    NODETYPE* nodePtr = head;
    while (nodePtr) {
        if (nodePtr->NodeData == searched.NodeData) return true;
        nodePtr = nodePtr->next;
    }

    return false;
}

template <typename NODETYPE>
void List<NODETYPE>::deleteNode(NODETYPE& searched) {
    if (!head) return;

    NODETYPE* nodePtr = head;
    NODETYPE* prev = nullptr;

    while (nodePtr && nodePtr->NodeData != searched.NodeData) {
        prev = nodePtr;
        nodePtr = nodePtr->next;
    }

    if (nodePtr) {
        if (!prev) head = nodePtr->next;
        else prev->next = nodePtr->next;
        delete nodePtr;
        --listSize;
    }
}
template <typename NODETYPE>
NODETYPE* List<NODETYPE>::getListHead() const {
    return head;
}

template <typename NODETYPE>
int List<NODETYPE>::getListSize() const {
    return listSize;
}

template <typename NODETYPE>
List<NODETYPE>::~List() {
    NODETYPE* curr = head;
    while (curr) {
        NODETYPE* next = curr->next;
        delete curr;
        curr = next;
    }
}


#endif
