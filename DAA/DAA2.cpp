#include<iostream>
using namespace std;
#include <bits/stdc++.h>

struct MinHeapNode{
    char data;
    int freq;
    MinHeapNode * left, *right;
    MinHeapNode(char data, int freq){
        left= right= nullptr;
        this->data = data;
        this->freq = freq;
    }
};

struct compare{
    bool operator()(MinHeapNode * a, MinHeapNode *b){
        return (a->freq > b->freq);
    }
};

void printCodes(struct MinHeapNode * root, string str){
    if(root == nullptr){
        return;
    }
    if(root->data != '$'){
        cout << root->data << ": "<< str<< endl;
    }
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

void  HuffmanCode(char data[], int freq[], int size){
    MinHeapNode *left, *right, *temp;
    priority_queue<MinHeapNode *, vector<MinHeapNode *>, compare> minHeap;

    for(int i=0; i< size; i++){
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }

    while (minHeap.size() != 1)
    {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();
        temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        minHeap.push(temp);
    }
    printCodes(minHeap.top(), "");
}
int main()
{
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5,9, 12, 13,16,45};
    HuffmanCode(data, freq, 6);
    return 0;
}