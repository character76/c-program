


typedef struct {
    int key;
    int* data;
    struct MyHashSet* next;
}MyHashSet;

/** Initialize your data structure here. */

MyHashSet* myHashSetCreate() {
    MyHashSet* hash=malloc(sizeof(MyHashSet));
    hash->next=NULL;
    return hash;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    MyHashSet* obj_next=malloc(sizeof(MyHashSet));
    obj->next=obj_next;
    obj->key=key;
    obj_next->next=NULL;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    MyHashSet* a=obj;//used to act the moving pointer
    MyHashSet* b;
    if(obj->next!=NULL)
    {
        b=obj->next;
    }
    else return;
    while (b->next!=NULL)
    {
        if(b->key==key)
        {
            a=b->next;
            free(b);
            return;
        }
        a=b;
        b=b->next;
    }
    
}

/** Returns true if this set contains the specified element */
bool myHashSetContains(MyHashSet* obj, int key) {
    MyHashSet* a=obj;//used to act the moving pointer
    MyHashSet* b;
    if(obj->next==NULL&&obj->key==key)
    {
        return 1;
    }
    else if(obj->next==NULL&&obj->key!=key)
    {
        return 0;
    }
    else if(obj->next!=NULL)
    {
        b=obj->next;
    }

    while (b->next!=NULL)
    {
        if(b->key==key)
        {
            return 1;
        }
        a=b;
        b=b->next;
    }
    return 0;
}

bool judger(MyHashSet* obj,int key)
{
    if(obj->key!=key&&obj->next!=NULL)
    {
        return judger(obj->next,key);
    }
    else if(obj->key==key)
    {
        return 1;
    }
    else if(obj->next==NULL&&obj->key!=key)
    {
        return 0;
    }
}

void myHashSetFree(MyHashSet* obj) 
{
    MyHashSet* myHashSetFreeHelp(MyHashSet* obj);
    free(myHashSetFreeHelp(obj));
}
MyHashSet* myHashSetFreeHelp(MyHashSet* obj)
{
    if(obj->next!=NULL)
    {
        free(myHashSetFreeHelp(obj->next));
        return obj;
    }
    if(obj->next==NULL)
    {
        return obj;
    }
    return obj;
} 
