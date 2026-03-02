// filepath: /countnames/src/countnames.c

/*
 * countnames.c
 * Reads names from a file (or stdin) and prints how many times each name appears.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_NAMES 100 // 100 distinct names
#define MAX_NAME_LENGTH 31
#define LINE_BUFFER_SIZE 256


static void redirect_pid_files(void)
{
    char out[64], err[64];

    snprintf(out, sizeof(out), "%d.out", getpid());
    snprintf(err, sizeof(err), "%d.err", getpid());

    int fdout = open(out, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fdout >= 0) {
        dup2(fdout, STDOUT_FILENO);
        close(fdout);
    }

    int fderr = open(err, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fderr >= 0) {
        dup2(fderr, STDERR_FILENO);
        close(fderr);
    }
}

int main(int argc, char *argv[])
{
    redirect_pid_files();
    //If a file name is provvided, attempt to open it 
    FILE *fp = NULL;
    if (argc == 2)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            return 1;
        }
    }
    else if (argc == 1)
    {
        fp = stdin;
    }
    else
    {
        return 0;
    }
    
    char names[MAX_NAMES][MAX_NAME_LENGTH];
    int counts[MAX_NAMES];
    int lengthCount = 0;

    for (int i = 0; i < MAX_NAMES; i++)
    {
        counts[i] = 0;
        names[i][0] = '\0';
    }

    char buffer[LINE_BUFFER_SIZE];
    int lineNum = 0;

    while (fgets(buffer, LINE_BUFFER_SIZE, fp) != NULL)
    {
        lineNum++;
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0)
        {
            if (argc == 2)
                fprintf(stderr, "Warning - file %s line %d is empty.\n", argv[1], lineNum);
            continue;
        }

        // Check if the name is already in the table
        int found = 0;
        for (int i = 0; i < lengthCount; i++)
        {
            if (strcmp(names[i], buffer) == 0)
            {
                counts[i]++;
                found = 1;
                break;
            }
        }

        // If not found, add it to the table
        if (!found && lengthCount < MAX_NAMES)
        {
            strncpy(names[lengthCount], buffer, MAX_NAME_LENGTH - 1);
            names[lengthCount][MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
            counts[lengthCount] = 1;
            lengthCount++;
            //increment the count of distinct names
        }
    }
    // Close the file after reading
    if (fp != stdin)
    {
        fclose(fp);
    }

    
    //This will print the final results of names and their counts
    for (int i = 0; i < lengthCount; i++)
    {
        printf("%s: %d\n", names[i], counts[i]);
    }

    return 0;
}