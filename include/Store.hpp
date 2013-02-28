#ifndef __STORE__
#define __STORE__


template <class T>
class StoreNode{

    public:
        T value;
        StoreNode* next;

};

template <class T>
class Store{

    private:
        unsigned int size;
        StoreNode<T>* origin;
        StoreNode<T>* tail;

    public:

        Store(){
            size = 0;
            origin = NULL;
            tail = NULL;
        }

        unsigned int getSize(){
            return size;
        }

        void push_back(T _obj){
            if (origin==NULL){
                origin = new StoreNode<T>();
                origin->value = _obj;
                origin->next = NULL;
                tail = origin;

            }
            else{
                tail->next= new StoreNode<T>();
                tail->next->value = _obj;
                tail->next->next = NULL;
                tail = tail->next;
            }
            size++;
        }

        T at(unsigned int _index){
            StoreNode<T>* pointer = origin;
            for(unsigned int i = 0;i<_index;i++){
                if(pointer->next!=NULL){
                    pointer = pointer->next;
                }
            }

            return pointer->value;

        }

};


#endif
