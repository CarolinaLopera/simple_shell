# simple shell
## description
In this project we develop a command line interpreter (shell), whose main function is to receive commands from users in the terminal and interpret those instructions which is expected to be executed in the operating system kernel,this shell is similar to la bourne shell (sh).
You can see the flowchart of the main function of the program in [this link](https://miro.com/welcomeonboard/NHNlcnJyTUxlaHBQdDJNMXR3aFZSUmRURVgyMGhVeWU5dm9yYldwVVJCcHZCUDlwdWZUVDJCaHl4RzU1MFhmb3wzMDc0NDU3MzYwMDYxNDk1Njc1).

## project information
### Requirements
 * Allowed editors: vi, vim, emacs
   * All your files will be compiled on Ubuntu 20.04 LTS using.
     * All your files should end with a new line.
     * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
     * Your shell should not have any memory leaks
     * No more than 5 functions per file
     * All your header files should be include guarded
       ## List of allowed functions and system calls
       | function | description |
       | --- | --- |
       | exceve(2) |  execute the program |
       | fork(2) | create a child process |
       | close(2) | close the file descriptor |
       |  malloc(3), free(3) | free dynamic memory and allocate |
       |  write(2) | write to file descriptor |
       | wait(2) | wait for proces to change |
       | strtok(3) | Extract tokens from strings |
       | stat(2) | Get file status |
       ## our own functions
       ### main.c
       This is the main function of our simple shell, in which we use three fundamental functions which are: getline issaty.
       getline helped us to read what the user sent through the command line, issaty helped us to understand in a better way, how our shell worked in an interactive and non-interactive way.
       the functions that we created in our simple shell were the following:
       | function | description |
       | --- | --- |
       | prompt() | Display a prompt and wait for the user to type a command |
       | *get_line() | read all the information that is entered by the keyboard |
       | **token(char *line) | get token of string |
       | void exe(char **words, char *line) | execute a string |
       | **split_path(char *path) | this function split the path  |
       | discover_path(char *line, char **env, int num_c) | walk the path and find where the command is going to be executed |
       | length(char *string) | count number of characters |
       | number_words(char *str) | count number of words |
       | *_strcat(char *dest, char *src) | concatenate two strings |
       | *_strcpy(char *dest, char *src) | copy a string |
       | error_found(char *argv[], int num_c, char *words) | print a menssage about command not fount in stdout. |
       | error_permisions(char *argv[], int num_c, char *words | print a menssage about permissions denied. |
       ## compilation
       we will compile as follows
       gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
       ## testing
       our shell works interactively as follows:
       ![exe](https://user-images.githubusercontent.com/85572579/130726248-482e16c7-b606-4259-8af0-4a2517c435f1.png)
       ![exe3](https://user-images.githubusercontent.com/85572579/130729120-997e151b-3b49-43cb-9ff1-6528fb190f3e.png)
       and it also works in non-interactive mode as follow:
       ![exe4](https://user-images.githubusercontent.com/85572579/130832781-4588c364-74ef-4c1d-b1d6-5f1c7a167e5c.png)
       ## Authors
       **Carolina Lopera**
       * [GitHub](https://github.com/CarolinaLopera)
       **Jarold Hakins**
       * [GitHub](https://github.com/jaroldhakins)
       **Andres Duque**
       * [GitHub](https://github.com/totod8)
       ![holberton1](https://user-images.githubusercontent.com/85572579/130709393-dc415475-4e34-4c6a-bc4e-ea10d448003e.png)
