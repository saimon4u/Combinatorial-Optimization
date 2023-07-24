#include<bits/stdc++.h>
#include "Heap.h"
#define Maximum_Tree_Height 50
using namespace std;


void GenerateHuffmanCode(char *list,int *freq,int size);
void PrintValue(int *arr,int size);
void PrintHuffmanCode(HuffmanNode *root,int *arr,int top);
HuffmanNode* BuildHuffmanTree(char *list,int *freq,int size);



int main(){
    char list[] = {'a','b','c','d','e','f'};
    int freq[] = {45,13,12,16,9,5};
    int size = sizeof(list)/sizeof(list[0]);
    cout << "Char->Code" << endl;
    GenerateHuffmanCode(list,freq,size);
    return 0;
}



void PrintValue(int *arr,int size){
    for(int i=0; i<size; i++) cout << arr[i];
    cout << endl;
}


void GenerateHuffmanCode(char *list,int *freq,int size){
    HuffmanNode *root = BuildHuffmanTree(list,freq,size);
    int arr [Maximum_Tree_Height], top = 0;
    PrintHuffmanCode(root,arr,top);
}


HuffmanNode* BuildHuffmanTree(char *list,int *freq,int size){
    HuffmanNode *left,*right,*top;
    HuffmanHeap *heap = FillHeapArray(list,freq,size);
    while(!IsSizeOne(heap)){
        left = ExtractMinimum(heap);
        right = ExtractMinimum(heap);
        top = CreateNode('*',left->frequency+right->frequency);
        top->left = left;
        top->right = right;
        InsertIntoHeap(heap,top);
    }
    return ExtractMinimum(heap);
}


void PrintHuffmanCode(HuffmanNode *root,int *arr,int top){
    if(root->left){
        arr[top] = 0;
        PrintHuffmanCode(root->left,arr,top+1);
    }
    if(root->right){
        arr[top] = 1;
        PrintHuffmanCode(root->right,arr,top+1);
    }
    if(IsLeaf(root)){
        cout << root->data << "->";
        PrintValue(arr,top);
    }
}