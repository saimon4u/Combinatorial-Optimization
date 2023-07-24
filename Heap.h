#include<bits/stdc++.h>


struct HuffmanNode{
    int frequency;
    char data;
    HuffmanNode *left,*right;
};


struct HuffmanHeap{
    int size;
    int capacity;
    HuffmanNode* *array;
};


HuffmanHeap* AllocateMemory(int capacity){
    HuffmanHeap *heap = (HuffmanHeap *) malloc(sizeof(HuffmanHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (HuffmanNode **) malloc(heap->capacity * sizeof(HuffmanNode *));
    return heap;
}


HuffmanNode* CreateNode(char data,int freq){
    HuffmanNode *temp = (HuffmanNode *) malloc(sizeof(HuffmanNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = freq;
    return temp;
}


void SwapNode(HuffmanNode* *a,HuffmanNode* *b){
    HuffmanNode *temp = *a;
    *a = *b;
    *b = temp;
}


void ArrangeHeap(HuffmanHeap *heap,int index){
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency) smallest = left;
    if(right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency) smallest = right;
    if(smallest!=index){
        SwapNode(&heap->array[smallest],&heap->array[index]);
        ArrangeHeap(heap,smallest);
    }
}


HuffmanHeap* FillHeapArray(char *list,int *freq,int size){
    HuffmanHeap *heap = AllocateMemory(size);
    for(int i=0; i<size; i++) heap->array[i] = CreateNode(list[i],freq[i]);
    heap->size = size;
    BuildHeap(heap);
    return heap;
}


void BuildHeap(HuffmanHeap *heap){
    int n = heap->size -1;
    int i;
    for(i = (n-1)/2; i>=0; i--) ArrangeHeap(heap,i);
}


bool IsSizeOne(HuffmanHeap *heap){
    return heap->size == 1;
}


bool IsLeaf(HuffmanNode *root){
    return !(root->left) && !(root->right);
}


HuffmanNode* ExtractMinimum(HuffmanHeap *heap){
    HuffmanNode *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size-1];
    --heap->size;
    ArrangeHeap(heap,0);
    return temp;
}


void InsertIntoHeap(HuffmanHeap *heap,HuffmanNode *node){
    ++heap->size;
    int i = heap->size - 1;
    while(i && node->frequency < heap->array[(i-1)/2]->frequency){
        heap->array[i] = heap->array[(i-1)/2];
        i = (i-1)/2;
    }
    heap->array[i] = node;
}