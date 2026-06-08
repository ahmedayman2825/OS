#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include "shell.h"

void run_shell() {
    char input[100];
    char *args[10];
    char *args2[10];

    char history[100][100];
    int count = 0;

    // signal handling
    signal(SIGINT, SIG_IGN);   // ignore Ctrl+C in shell
    signal(SIGTSTP, SIG_IGN);  // ignore Ctrl+Z completely

    while (1) {
        int out = 0, in = 0, background = 0, pipeFlag = 0;
        char *outfile = NULL;
        char *infile = NULL;

        printf("myShell> ");
        fflush(stdout);

        if (fgets(input, sizeof(input), stdin) == NULL)
            continue;

        input[strcspn(input, "\n")] = 0;

        // save history
        if (strlen(input) > 0)
            strcpy(history[count++], input);

        // parse
        int i = 0;
        char *token = strtok(input, " ");
        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if (args[0] == NULL) continue;

        // exit
        if (strcmp(args[0], "exit") == 0) break;

        // history
        if (strcmp(args[0], "history") == 0) {
            for (int k = 0; k < count; k++)
                printf("%d %s\n", k + 1, history[k]);
            continue;
        }

        // cd
        if (strcmp(args[0], "cd") == 0) {
            if (args[1]) {
                if (chdir(args[1]) != 0)
                    perror("cd error");
            } else {
                printf("cd: missing argument\n");
            }
            continue;
        }

        // pwd
        if (strcmp(args[0], "pwd") == 0) {
            char cwd[100];
            getcwd(cwd, sizeof(cwd));
            printf("%s\n", cwd);
            continue;
        }

        // background
        if (i > 0 && strcmp(args[i - 1], "&") == 0) {
            background = 1;
            args[i - 1] = NULL;
        }

        // output redirection
        for (int j = 0; args[j]; j++) {
            if (strcmp(args[j], ">") == 0) {
                out = 1;
                outfile = args[j + 1];
                args[j] = NULL;
                break;
            }
        }

        // input redirection
        for (int j = 0; args[j]; j++) {
            if (strcmp(args[j], "<") == 0) {
                in = 1;
                infile = args[j + 1];
                args[j] = NULL;
                break;
            }
        }

        // pipe
        for (int j = 0; args[j]; j++) {
            if (strcmp(args[j], "|") == 0) {
                pipeFlag = 1;
                args[j] = NULL;

                int k = 0;
                j++;
                while (args[j])
                    args2[k++] = args[j++];
                args2[k] = NULL;
                break;
            }
        }

        // PIPE CASE
        if (pipeFlag) {
            int fd[2];

            if (pipe(fd) < 0) {
                perror("pipe failed");
                continue;
            }

            pid_t p1 = fork();
            if (p1 < 0) {
                perror("fork failed");
                continue;
            }

            if (p1 == 0) {
                signal(SIGINT, SIG_DFL);

                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]);

                execvp(args[0], args);
                printf("Command not found: %s\n", args[0]);
                exit(1);
            }

            pid_t p2 = fork();
            if (p2 < 0) {
                perror("fork failed");
                continue;
            }

            if (p2 == 0) {
                signal(SIGINT, SIG_DFL);

                dup2(fd[0], STDIN_FILENO);
                close(fd[1]);
                close(fd[0]);

                execvp(args2[0], args2);
                printf("Command not found: %s\n", args2[0]);
                exit(1);
            }

            close(fd[0]);
            close(fd[1]);

            wait(NULL);
            wait(NULL);
            continue;
        }

        // NORMAL CASE
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork failed");
            continue;
        }

        if (pid == 0) {
            signal(SIGINT, SIG_DFL);

            // input redirection
            if (in) {
                int fd = open(infile, O_RDONLY);
                if (fd < 0) {
                    perror("input file error");
                    exit(1);
                }
                dup2(fd, STDIN_FILENO);
                close(fd);
            }

            // output redirection
            if (out) {
                int fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
                if (fd < 0) {
                    perror("output file error");
                    exit(1);
                }
                dup2(fd, STDOUT_FILENO);
                close(fd);
            }

            execvp(args[0], args);
            printf("Command not found: %s\n", args[0]);
            exit(1);

        } else {
            if (!background)
                wait(NULL);
            else
                printf("Running in background (PID: %d)\n", pid);
        }
    }
}
