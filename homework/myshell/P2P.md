## Points to Ponder

#####1. Why did the cd command get special mention in this assignment? 
##### 2. Can your shell run scripts? Why or why not? 
###### Yes and no. Given a script (i.e. ./a.out < testScript) the commands in testScript are executed but, as stated in the next answer, the while loop in my shell runs infinitely, constantly executing the first command given in testScript. So running a script is possible but not advised with my shell. 
##### 3. Does Ctrl-D exit your shell? Why or why not?
###### No, Ctrl-D does not exit my shell; instead, it puts it into an infinite loop of constantly calling the last command that was inputed. Ctrl-D on Linux and Mac OS X sends a signal that no more characters are available, i.e. the current process (my shell) receives the [End-of-File] signal. My while loop, therefore, runs infinitely, ignoring the [End-of-File] signal and simply checking the always-true condition of 1.

