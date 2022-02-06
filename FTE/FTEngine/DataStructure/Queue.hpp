//
//  Queue.hpp
//  FTE
//
//  Created by minseoi on 2022/02/06.
//

#ifndef Queue_hpp
#define Queue_hpp

/*
 This Queue is only safe for 'value type'
 */
template<typename T>
class Queue
{
private:
    struct Node
    {
        Node* nextNode = nullptr;
        T value;
    };
    
    Node* head;
    Node* tail;
    int queueSize;
public:
    Queue()
    :head(nullptr),
     tail(nullptr),
     queueSize(0)
    {}
    
    void Push(T newValue)
    {
        Node* newNode = new Node;
        newNode->value = newValue;
        
        if(queueSize == 0)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->nextNode = newNode;
        }
        ++queueSize;
    }
    
    bool Pop(T& poppedValue)
    {
        if(queueSize == 0) return false;
        
        poppedValue = head->value;
        Node* headTemp = head;
        if(head->nextNode != nullptr)
        {
            head = head->nextNode;
        }
        delete headTemp;
        --queueSize;
        
        return true;
    }
};

#endif /* Queue_hpp */
