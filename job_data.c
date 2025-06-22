#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "job_data.h"


int load_jobs(const char* filename, Job jobs[], int max_job) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File open Failed / not found");
        return -1;
    }

    char line[512];
    int count = 0;

    fgets(line, sizeof(line), file); // skip header

    while ((fgets(line, sizeof(line), file)) && count < max_job) {
        char* token;

        // Read Job ID
        token = strtok(line, ",");
        if (token == NULL) continue;
        jobs[count].id = atoi(token);

        // Read Title
        token = strtok(NULL, ",");
        if (token == NULL) continue;
        strncpy(jobs[count].title, token, MAX_TITLE_LEN);
        jobs[count].title[MAX_TITLE_LEN - 1] = '\0';

        // Read Skills
        token = strtok(NULL, "\n");
        if (token == NULL) continue;
        strncpy(jobs[count].skills, token, MAX_SKILLS_LEN);
        jobs[count].skills[MAX_SKILLS_LEN - 1] = '\0';

        count++;
    }

    fclose(file);
    return count;
}
