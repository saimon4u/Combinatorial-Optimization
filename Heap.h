#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>
typedef struct Node{
    char data;
    int frequency;
    struct Node *left,*right;
}Node;


typedef struct Heap{
    int size;
    int capacity;
    Node **array;
}Heap;

//List of function used to implement heap data structure
Heap *AllocateMemory(int capacity);
Node *CreateNode(char data,int freq);
Node *ExtractMinimum(Heap *heap);
bool IsSizeOne(Heap *heap);
void BuildMinHeap(Heap *heap);
void Heapify(Heap *heap,int index);
void SwapNode(Node* *a, Node* *b);
void PushNewNodeToHeap(Heap *heap,Node *node);


void PushNewNodeToHeap(Heap *heap,Node *node){
    (heap->size)++;
    int i = heap->size - 1;
    //we pushing a new node into heap by comparing with it's parent
    while(i && node->frequency < heap->array[(i-1)/2]->frequency){
        heap->array[i] = heap->array[(i-1)/2];
        i = (i-1)/2;
    }
    heap->array[i] = node;
}


Node *ExtractMinimum(Heap *heap){
    //thus is the minheap we can get the minimum node by simply removing the root node
    Node *node = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    (heap->size)--;
    Heapify(heap,0);
    return node;
}


void SwapNode(Node* *a,Node* *b){
    Node *temp = *a;
    *a = *b;
    *b = temp;
}


void Heapify(Heap *heap,int index){
    int smallest = index;
    int left = index*2 + 1;
    int right = index*2 + 2;
    if(left<heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)smallest = left;
    if(right<heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)smallest = right;
    if(smallest!=index){
        SwapNode(&heap->array[smallest],&heap->array[index]);
        Heapify(heap,smallest);
    }
}


void BuildMinHeap(Heap *heap){
    int n = heap->size - 1;
    int i;
    //To create Minheap we have to heapify the heap with heapify algorithm
    for(i=(n-1)/2; i>=0; i--)Heapify(heap,i);
}


bool IsSizeOne(Heap *heap){
    return heap->size == 1;
}


Node *CreateNode(char data,int freq){
    Node *node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->frequency = freq;
    node->left = node->right = NULL;
    return node;
}


Heap *AllocateMemory(int capacity){
    Heap *heap = (Heap*)malloc(sizeof(Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (Node**)malloc(sizeof(Node*) * heap->capacity);
    return heap;
}