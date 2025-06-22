#ifndef SKILL_MATCH_H
#define SKILL_MATCH_H

#include "job_data.h"  // Job struct ka use hoga

// Structure to hold matching result for each job
typedef struct {
    int job_index;   // Index of the job in jobs array
    int score;       // Number of matched skills
} MatchResult;


int match_skills(const char* user_skills, Job jobs[], int total_jobs, MatchResult results[]);

#endif
