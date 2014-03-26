#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * This program demonstrates the use of the fork() and exec()
 * functions.
 */
int main() {
    /* String to hold the command to run. */
    while (1) {
        int noAmpersand = 1;
        char *arguments[10];
        char input[256];
        printf("Enter the command to run: ");
        fgets(input, sizeof(input), stdin);

         /* Check if & is last character BEFORE tokenizing*/
        if (input[strlen(input) - 2] == '&') {
            input[strlen(input) - 2] = '\0';
            noAmpersand = 0;
        }

        printf("%s", input);


        /* Tokenize */
        char * individualArgs = strtok(input, " \n");
        int index = 0;
        while (individualArgs != NULL) {
            arguments[index] = individualArgs;
            individualArgs = strtok(NULL, " \n");
            index++;
        }

        arguments[index] = NULL;

        /* Now for some checks. exit, cd, and secret-system-call are special cases. */
        if (strcmp("exit", arguments[0]) == 0) {
            return 1;
        } else if (strcmp("cd", arguments[0]) == 0) {
            chdir(arguments[1]);
        }

        /* Variable that will store the fork result. */
        pid_t pid;

        /* Perform the actual fork. */
        pid = fork();
        if (pid < 0) {
            /* Error condition. */
            fprintf(stderr, "Fork failed\n");
            return -1;
        } else if (pid == 0) {
            /* Child process. */
            printf("Running...\n");
            execvp(arguments[0], arguments);
        } else {
            /* Parent process. */
            int result;
            //If the last character is &, run concurrently with the shell
            if (noAmpersand) {
                wait(&result);
            }

            printf("All done; result = %d\n", result);
        }
    }

    return 0;
}
