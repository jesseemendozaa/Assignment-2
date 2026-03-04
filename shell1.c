/*
 * File: shell1.c
 * Author: Jada-Lien Nguyen and Jesse Mendoza 
 * Description:
 * This program implements a simple UNIX shell. The shell reads user commands,
 * creates a child process using fork(), and executes the command using exec().
 * Output and error messages from executed programs are redirected to .out and .err files.
 */

// Include necessary header files for input/output, string manipulation, process control, and file handling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// Maximum length of a command line input
#define MAXLINE 1024

int main(void)
{
    // Redirect output and error to .out and .err files
    pid_t pid;
    int status;
    char buf[MAXLINE];

    printf("%% ");
    // Read commands from the user until EOF
    while (fgets(buf, MAXLINE, stdin) != NULL) {

        buf[strcspn(buf, "\n")] = '\0';

        /* A2 special case */
        char *args[128];
        int argc = 0;
        // Tokenize the input command into arguments
        char *tok = strtok(buf, " \t");
        while (tok != NULL) {
            args[argc++] = tok;
            tok = strtok(NULL, " \t");
            }
            // Null-terminate the arguments array
            if (argc > 0 && strcmp(args[0], "./countnames") == 0) {
            /* if user typed only ./countnames */
            if (argc == 1) {
                pid = fork();
                if (pid < 0) {
                    perror("fork");
                    } 
                else if (pid == 0) {
                    execlp("./countnames", "./countnames", (char *)0); // execute countnames with no arguments
                    perror("exec");
                    _exit(127);
                } else {
                    waitpid(pid, &status, 0);
                }
            printf("%% ");  // prompt again after executing countnames with no arguments
            continue;
            }
            // If the command is ./countnames with arguments, fork and execute countnames for each argument
            for (int i = 1; i < argc; i++) {
                pid = fork();
                if (pid < 0) {
                    perror("fork");
                    continue;
                }
                // In the child process, execute countnames with the current argument
                if (pid == 0) {
                    execlp("./countnames", "./countnames", args[i], (char *)0);
                    perror("exec");
                    _exit(127);
                    }
            }
            // In the parent process, wait for all child processes to finish
            for (int i = 1; i < argc; i++) {
                wait(&status);
                }

            printf("%% ");
            continue;
        }

        /* normal behavior */
        pid = fork();
        // In the child process, execute the command
        if (pid == 0) {
            execlp(buf, buf, (char *)0);
            perror("exec");
            _exit(127);
        }
        // In the parent process, wait for the child process to finish
        waitpid(pid, &status, 0);

        printf("%% ");
    }

    return 0;
}