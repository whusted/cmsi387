## Points to Ponder

#####1. Why did the cd command get special mention in this assignment?
###### cd cannot be forked and executed as a child process (via fork() and exec()) because it must change the parent process, not the child process. Therefore, chdir() is used as a special case to change directories. However, chdir() merely modifies the environment of the current process, and any changes of directory are restored when the shell exits. The directory it restores to is the directory where the shell began its execution, where ./a.out (or its equivalent) lives.

> JD: Ding ding, you got it!

##### 2. Can your shell run scripts? Why or why not? 
###### Yes and no. Given a script (i.e. ./a.out < testScript) the commands in testScript are executed but, as stated in the next answer, the while loop in my shell runs infinitely, constantly executing the first command given in testScript. So running a script is possible but not advised with my shell. 

> JD: You placed a workaround yourself—if you end your script with `exit`, then things are clean.
>     Meanwhile I added a note on how to catch this EOF.

##### 3. Does Ctrl-D exit your shell? Why or why not?
###### EDIT: Yes, Ctrl-D exits my shell. My *fixed* while loop checks for the End-of-File signal before executing. Ctrl-D on Mac Os X (and Linux) sends a signal that no more characters are available - the End-of-File or EOF signal - thus exiting my shell.

> JD: But there *is* a way to detect EOF with `fgets`, and that is the bit that was missed.
