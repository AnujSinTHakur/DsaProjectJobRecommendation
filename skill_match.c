#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "skill_match.h"
#include "utils.h"  // helper functions yahin se aa rahe hain






// Core Function: Match user skills with each job and return results
int match_skills(const char* user_skills, Job jobs[], int total_jobs, MatchResult results[]) {
    int i;
    char user_copy[300];
    strncpy(user_copy, user_skills, 300);
    user_copy[299] = '\0';
    to_lowercase(user_copy);

    // Tokenize user skills
    char user_tokens[50][50];
    int user_count = tokenize(user_copy, user_tokens);

    for (i = 0; i < total_jobs; i++) {
        // Copy job skills and tokenize
        char job_copy[300];
        strncpy(job_copy, jobs[i].skills, 300);
        job_copy[299] = '\0';
        to_lowercase(job_copy);

        char job_tokens[50][50];
        int job_count = tokenize(job_copy, job_tokens);

        // Count how many user skills match with this job's skills
        int score = 0;
        int j;
        for (j = 0; j < user_count; j++) {
            if (contains(user_tokens[j], job_tokens, job_count))
                score++;
        }

        // Save result
        results[i].job_index = i;
        results[i].score = score;
    }

    return total_jobs;
}
