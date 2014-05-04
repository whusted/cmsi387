## CSI: Process

### Mac OS X

##### Terminal Hot Mess
<img src="mac_terminal_hot_mess.png"></img>
###### This shows Sum.java running concurrently with ls -l and ping google.com

##### Evidence of Threading
<img src="mac_threading.png"></img>
###### This shows Sum.java running in the back terminal while ps -eLf displays the threads of the current program.

> JD: Erm, no, those aren't threads—those are the available columns.

### Linux

##### Terminal Hot Mess
<img src="linux_terminal_hot_mess.png"></img>
###### This shows Sum.java running concurrently with a pwd call in the middle.


##### Evidence of Threading
<img src="linux_threading.png"></img>
###### This shows Sum.java running in the back terminal while ps -eLf displays the threads of the current program.

##### How do the different operating systems represent the threads?
###### While both Linux and Mac OS X use ps -eLf to track the threads of a program, they display the "evidence" differently, as seen in the screenshots. Mac OS X displays the threads in a single, readable string set; Linux displays the threads in a table, with other information included, such as the user, process ID, etc.

> JD: Your use of `ps` is right but you didn't look closely enough.  Definitely not
>     enough on the Mac (otherwise you would have realized those weren't threads)
>     and on Linux, there was one other thing I was hoping you would spot there.
