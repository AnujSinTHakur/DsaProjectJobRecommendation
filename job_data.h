#ifndef JOB_DATA_H
#define JOB_DATA_H

#define MAX_JOBS 200
#define MAX_TITLE_LEN 100
#define MAX_SKILLS_LEN 300

typedef struct {
    int id;
    char title[MAX_TITLE_LEN];
    char skills[MAX_SKILLS_LEN];
}Job;


int load_jobs(const char* filename,Job jobs[],int max_jobs);

#endif