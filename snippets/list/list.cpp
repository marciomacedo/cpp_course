#include <iostream>

// class definitions
class ListElement {
    public:
        int data;
        ListElement *next;
        ListElement(int data);
};
class List {
    private:
        int size;
        ListElement *head;
        ListElement *cursor;
    
    public:
        List();
        void append(int data);
        void prepend(int data);
        bool remove(int data);
        ListElement* get_element_at(int position);
        void print();

        ~List();
};

//Method implementations

ListElement::ListElement(int data)
{
    this->data = data;
    this->next = NULL;
}

List::List()
{
    this->size = 0;
    head = cursor = NULL;
}

void List::append(int data)
{
    ListElement *e;

    e = new ListElement(data);

    if(head == NULL) { // the list is empty
        head = e;
        cursor = e;
    }
    else{
        cursor->next = e;
        cursor  = e;
    }
    this->size++;
}

bool List::remove(int data)
{
    // first we need to find the element;
    ListElement *iterator, *temp;
    
    // is the element to remove at the head of the list?
    if(head->data == data)
    {
        temp = head;
        head = head->next;
        delete temp; // delete the ListElement from memory
        this->size--;
        return true;
    }

    iterator = this->head;
    while(iterator->next != NULL)
    {
        if(iterator->next->data == data)
        {
            // we found the element. Now we need to remove it.
            temp = iterator->next;
            iterator->next = temp->next; //re-link the elements
            if(iterator->next == NULL) // update cursor if we are removing the last element
                cursor = iterator; 
            delete temp; // delete the ListElement from memory
            this->size--;    

            return true;
        }

        iterator = iterator->next;
    }
    
    return false; //element not found
}

ListElement* List::get_element_at(int position)
{
    ListElement *iterator;
    int i = 0;
   
    if(position > this->size)
        return NULL; // out of bonds

    iterator = this->head;
    while(iterator != NULL)
    {
        if(i == position)
        {
            // fount the element
            return iterator;
        }
        iterator = iterator->next;
        i++;
    }
    return NULL;
}

List::~List()
{
    ListElement *iterator, *temp;
    iterator = this->head;
    while(iterator != NULL)
    {
       temp = iterator;
       iterator = iterator->next;
       delete temp;
    }
    std::cout << "destructor called" << std::endl;
}
void List::prepend(int data)
{
    ListElement *e;

    e = new ListElement(data);
    e->next = head;
    head = e;
    this->size++;
}

void List::print()
{
    ListElement *iterator;
     
    iterator = this->head;
    std::cout << "List: ";
    while(iterator != NULL)
    {
        std::cout << iterator->data << " -> " ;
        iterator = iterator->next;
    } 
    std::cout << "END, size = " << this->size << std::endl;
}
int main(int argc, char **argv)
{
   
    List *l;

    l = new List();

    l->append(1);
    l->append(1);
    l->append(2);
    l->append(3);
    l->append(4);
    l->append(5);

    l->print();

    std::cout << "removing 1" << std::endl;
    if(!l->remove(1))
        std::cout << "could not find element to remove" << std::endl;

    l->print ();

    l->prepend(6);
    l->print();
    std::cout << "removing 4" << std::endl;
    if(!l->remove(4))
        std::cout << "could not find element to remove" << std::endl;
    l->append(7);
    l->print();
    std::cout << "removing 7" << std::endl;
    if(!l->remove(7))
        std::cout << "could not find element to remove" << std::endl;
    l->print();
    l->append(8);
    l->print();

    std::cout << "removing 8" << std::endl;
    if(!l->remove(8))
        std::cout << "could not find element to remove" << std::endl;

    std::cout << "removing 5" << std::endl;
    if(!l->remove(5))
        std::cout << "could not find element to remove" << std::endl;
    l->append(9);
    l->print();

    ListElement *e;

    e = l->get_element_at(4);
    std::cout << "got element at position 4: " << e->data << std::endl;
    e->data = 100;
    std::cout << "changed element at position 4 to 100" << std::endl;
    l->print();

    e = l->get_element_at(8);
    if(e == NULL)
        std::cout << "Index out of bounds" << std::endl;
    
    delete l;
    return 0;
}
