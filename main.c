#include <stdio.h>
#include <string.h>
#include "job_data.h"
#include "skill_match.h"
#include "job_rank.h"
#include "utils.h"

#define MAX_RESULTS 200
#define TOP_N 5  // Number of top jobs to show

int main() {
    int i;
    Job jobs[MAX_JOBS];
    MatchResult results[MAX_RESULTS];
    MaxHeap heap;

    char user_skills[300];

    // User input
    printf("Enter your skills (space-separated): ");
    fgets(user_skills, sizeof(user_skills), stdin);

    // Remove newline from input if present
    size_t len = strlen(user_skills);
    if (len > 0 && user_skills[len - 1] == '\n') {
        user_skills[len - 1] = '\0';
    }

    // Load jobs from CSV
    int total_jobs = load_jobs("jobs.csv", jobs, MAX_JOBS);
    if (total_jobs <= 0) {
        printf("No jobs loaded.\n");
        return 1;
    }

    // Match user skills with jobs
    match_skills(user_skills, jobs, total_jobs, results);

    // Rank jobs using max heap
    init_heap(&heap);
    for ( i = 0; i < total_jobs; i++) {
        if (results[i].score > 0) {
            insert_heap(&heap, results[i].job_index, results[i].score);
        }
    }

    // Show top N matching jobs
    printf("\nTop %d matching jobs:\n", TOP_N);
    int shown = 0;
    while (heap.size > 0 && shown < TOP_N) {
        HeapNode top = extract_max(&heap);
        Job job = jobs[top.job_index];
        printf("%d. %s\t[%s]\t→ Score: %d\n", shown + 1, job.title, job.skills, top.score);
        shown++;
    }

    if (shown == 0) {
        printf("Sorry, no matching jobs found for your skills.\n");
    }

    return 0;
}
