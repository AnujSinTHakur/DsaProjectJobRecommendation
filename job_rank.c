#include <stdio.h>
#include "job_rank.h"

// Initialize heap by setting size = 0
void init_heap(MaxHeap* heap) {
    heap->size = 0;
}

// Helper: Swap two heap nodes
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Insert a job into the heap based on score
void insert_heap(MaxHeap* heap, int job_index, int score) {
    if (heap->size >= MAX_JOBS)
        return;

    // Insert new node at end
    int i = heap->size++;
    heap->nodes[i].job_index = job_index;
    heap->nodes[i].score = score;

    // Heapify up
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap->nodes[i].score > heap->nodes[parent].score) {
            swap(&heap->nodes[i], &heap->nodes[parent]);
            i = parent;
        } else {
            break;
        }
    }
}

// Extract the job with highest score
HeapNode extract_max(MaxHeap* heap) {
    HeapNode max = heap->nodes[0];  // root node

    // Move last node to root
    heap->nodes[0] = heap->nodes[--heap->size];

    // Heapify down
    int i = 0;
    while (1) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        int largest = i;

        if (left < heap->size && heap->nodes[left].score > heap->nodes[largest].score)
            largest = left;
        if (right < heap->size && heap->nodes[right].score > heap->nodes[largest].score)
            largest = right;

        if (largest != i) {
            swap(&heap->nodes[i], &heap->nodes[largest]);
            i = largest;
        } else {
            break;
        }
    }

    return max;
}
