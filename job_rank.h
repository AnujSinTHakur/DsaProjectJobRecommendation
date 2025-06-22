#ifndef JOB_RANK_H
#define JOB_RANK_H

#include "skill_match.h"  // MatchResult se job_index aur score use hoga

#define MAX_JOBS 200

// Represents a single node in the max heap (job index + matching score)
typedef struct {
    int job_index;
    int score;
} HeapNode;

// Max heap structure
typedef struct {
    HeapNode nodes[MAX_JOBS];
    int size;  // current number of elements in heap
} MaxHeap;

// Initializes the heap
void init_heap(MaxHeap* heap);

// Inserts a job into the heap based on its score
void insert_heap(MaxHeap* heap, int job_index, int score);

// Removes and returns the job with the highest score
HeapNode extract_max(MaxHeap* heap);

#endif
