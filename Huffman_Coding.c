#include<stdio.h>
#include "Heap.h"//A Header file that gives me the functionality of Heap
#define Max_Size 50

//List of Function used for Huffman Algorithm
void GetCode(Node *root,int *array,int top);
void GenerateCode(char *list,int *freq,int size);
void PrintCode(int *array,int size);
bool IsLeaf(Node *root);
Node *BuildTree(char *list,int *freq,int size);
Heap *CreateHeapWithData(char *list,int *freq,int size);


int main(){
    char list[] = {'a','b','c','d','e','f'};
    int freq[] = {45,13,12,16,9,5};
    int size = sizeof(list)/sizeof(list[0]);
    printf("Char->Code\n");
    //Main function is calling another function to create Huffman Code
    GenerateCode(list,freq,size);
    return 0;
}


void GenerateCode(char *list, int *freq,int size){
    //This function first build a huffman tree by calling another function
    Node *root = BuildTree(list,freq,size);
    int array[Max_Size];
    //After building the tree this function generate code by traversing that tree with the help of another function
    GetCode(root,array,0);
}


Node *BuildTree(char *list,int *freq,int size){
    Node *left,*right,*new;
    //Before building the huffman tree first we have to create a MinHeap with the help of another function
    Heap *heap = CreateHeapWithData(list,freq,size);
    while(!IsSizeOne(heap)){
        //Now we are done with the heap.Then we have to take two minimum node and create a new one
        left = ExtractMinimum(heap);
        right = ExtractMinimum(heap);
        new = CreateNode('@',left->frequency + right->frequency);
        new->left = left;
        new->right = right;
        //According to huffman algorithm we have to push that new node to heap
        PushNewNodeToHeap(heap,new);
    }
    //after iterating the whole loop we left with a single node which is our desire tree
    return ExtractMinimum(heap);
}


Heap *CreateHeapWithData(char *list,int *freq,int size){
    //To create a heap we have allocate memory for heap structure
    Heap *heap = AllocateMemory(size);
    //Then we create node for each element and put then into the heap
    for(int i=0; i<size; i++)heap->array[i] = CreateNode(list[i],freq[i]);
    heap->size = size;
    //Now we have to convert that heap structure into a minheap
    BuildMinHeap(heap);
    return heap;
}


void GetCode(Node *root,int *array,int top){
    if(root->left){
        array[top] = 0;
        GetCode(root->left,array,top+1);
    }
    if(root->right){
        array[top] = 1;
        GetCode(root->right,array,top+1);
    }
    if(IsLeaf(root)){
        printf(" %c  -> ",root->data);
        //If we come to a leaf node that means we get a data and now just we have to print its compressed value
        PrintCode(array,top);
    }
}


bool IsLeaf(Node *root){
    return !(root->left) && !(root->right);
}


void PrintCode(int *array,int size){
    for(int i=0; i<size; i++)printf("%d",array[i]);
    printf("\n");
}