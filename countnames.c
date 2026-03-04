// filepath: /countnames/src/countnames.c

/*
 * countnames.c
 * Reads names from a file (or stdin) and prints how many times each name appears.
 * GitHub : https://github.com/jesseemendozaa/Assignment-2?tab=readme-ov-file
 * Author : 
 * Jesse Mendoza 
 * Jada-Lien Nguyen
 * Date modified : 03/04/2026
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_NAMES 100 // 100 distinct names
#define MAX_NAME_LENGTH 31
#define LINE_BUFFER_SIZE 256


static void redirect(void)
{
    char out[64];
    char errName[64];

    snprintf(out, sizeof(out), "%d.out", getpid());
    snprintf(errName, sizeof(errName), "%d.err", getpid());

    close(STDOUT_FILENO);
    open(out, O_WRONLY | O_CREAT | O_TRUNC, 0777);

    close(STDERR_FILENO);
    open(errName, O_WRONLY | O_CREAT | O_TRUNC, 0777);
}

int main(int argc, char *argv[])
{
    redirect();
    
    //If a file name is provvided, attempt to open it 
    FILE *fp = NULL;
    if (argc == 2)
    {
        fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            fprintf(stderr, "error: cannot open file %s\n", argv[1]);
            return 1;
        }
    }
    else if (argc == 1)
    {
        return 0;
    }
    else
    {
        return 0;
    }

    // Initialize the names and counts arrays
    char names[MAX_NAMES][MAX_NAME_LENGTH];
    int counts[MAX_NAMES];
    int lengthCount = 0;
    // Set all counts to 0 and names to empty strings
    for (int i = 0; i < MAX_NAMES; i++)
    {
        counts[i] = 0;
        names[i][0] = '\0'; // Initialize the first character to null terminator to indicate an empty string
    }
    // Read the file line by line and process the names
    char buffer[LINE_BUFFER_SIZE];
    int lineNum = 0;
    // Read each line from the file until EOF
    while (fgets(buffer, LINE_BUFFER_SIZE, fp) != NULL)
    {
        lineNum++;
        // Remove newline character if present
        buffer[strcspn(buffer, "\n")] = '\0';

        if (strlen(buffer) == 0)    // Check if the line is empty
        {
            if (argc == 2)
            {
                fprintf(stderr, "Warning - file %s line %d is empty.\n", argv[1], lineNum);  // Print a warning message to stderr if the line is empty
            }
            continue; // Skip empty lines
        }

        // Check if the name is already in the table
        int found = 0;
        for (int i = 0; i < lengthCount; i++) // Loop through the existing names to check for a match
        {
            if (strcmp(names[i], buffer) == 0)  // If a match is found, increment the count for that name
            {
                counts[i]++;
                found = 1;  // Set found to 1 to indicate that the name was found in the table
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