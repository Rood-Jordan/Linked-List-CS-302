//Jordan Rood
//Homework 1 - Linked List

template<class ItemType>
linkedList<ItemType>::linkedList(){
    itemCount = 0;
    headPtr = nullptr;
}

template<class ItemType>
bool linkedList<ItemType>::isEmpty() const{
    return itemCount == 0;
}

template<class ItemType>
int linkedList<ItemType>::getLength() const{
    return itemCount;
}

template<class ItemType>
bool linkedList<ItemType>::insert(int newPosition, const ItemType& newEntry){

    bool canInsert = newPosition >= 1 && newPosition <= itemCount + 1;

    if(canInsert){
        
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        if(itemCount == 0){
            headPtr = newNodePtr;
        }
        else if(newPosition == 1){
            newNodePtr->setNext(headPtr);
            headPtr = newNodePtr;
        }
        else {
            //find node pointer at previous position
            Node<ItemType>* temporaryPtr = headPtr;
            for(int i = 1; i < newPosition - 1; i++){
                temporaryPtr = temporaryPtr->getNext();   
            }
            //point newNode's next pointer at previous's next
            newNodePtr->setNext(temporaryPtr->getNext());
            //point previous's next pointer to new node
            temporaryPtr->setNext(newNodePtr);
        }
        itemCount++;
    }
    return canInsert;
}

template<class ItemType>
bool linkedList<ItemType>::remove(int position){

    bool canDelete = position >= 1 && position <= itemCount;
    
    if(canDelete){
        Node<ItemType>* nodeToDeletePtr = new Node<ItemType>();

        if(itemCount == 0){
            return false; //cannot remove items not there
        }
        else if(position == 1){
            nodeToDeletePtr = headPtr;
            headPtr = headPtr->getNext();
            delete nodeToDeletePtr;
        }
        else{
            //find node pointer at previous position
            Node<ItemType>* temporaryPtr = headPtr;
            for(int i = 1; i < position - 1; i++){
                temporaryPtr = temporaryPtr->getNext();
            }
            //save previous's next in nodeToDeletePtr
            nodeToDeletePtr = temporaryPtr->getNext();
            temporaryPtr->setNext(nodeToDeletePtr->getNext());
            delete nodeToDeletePtr;
        }
        itemCount--;
    }
    return canDelete;
}

template<class ItemType>
void linkedList<ItemType>::clear(){
    bool listStatus;

    for(int i = 0; i <= itemCount + 1; i++){
        remove(1);
    }
}

template<class ItemType>
ItemType linkedList<ItemType>::getEntry(int position) const{

    bool canGetEntry = position >= 1 && position <= itemCount;

    if(canGetEntry){
        Node<ItemType>* temporaryPtr = headPtr;
        for(int i = 0; i < position - 1; i++){
            temporaryPtr = temporaryPtr->getNext();   
        }
        return temporaryPtr->getItem();
    }
    else{
        throw "Item does not exist in list!!";
    }
}

template<class ItemType>
ItemType linkedList<ItemType>::replace(int position, const ItemType& newEntry){

    bool canReplace = position >= 1 && position <= itemCount;

    Node<ItemType>* temporaryPtr = headPtr;
    for(int i = 0; i < position - 1; i++){
        temporaryPtr = temporaryPtr->getNext();
    }
    return temporaryPtr->getItem();

    if(canReplace){
        bool success = remove(position);

        if(success){
            success = insert(position, newEntry);
        }
    }
    else{
        throw "Item cannot be replaced!!";
    }
}

template<class ItemType>
linkedList<ItemType>::~linkedList(){
    clear();
}
