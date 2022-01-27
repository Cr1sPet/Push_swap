#PUSH_SWAP

[SUBJECT](subject/en.subject.pdf "push_swap subject")

* We have at our disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks. 

* push_swap program receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack.
* The program must display the smallest list of instructions possible to sort the stack a.

####How to use
```
git clone git@github.com:CrsPet/my_push_swap.git
make
ARG="input numbers"; ./push_swap $ARG // get instructions to sort
ARG="input numbers"; ./push_swap $ARG | wc -l // number of instructions
ARG="input numbers"; ./push_swap $ARG | ./checker $ARG // "ОК" if stack sorted, else "KO", on error prints "Error!"

*random numbers - sequence of unique int (integer)

```
---

####Examples:

![example1](example/ps_example1.jpg)

![example1](example/ps_example.jpg)

---
####Bonus: checker program

![example1](example/ps_example2.png)

If the program checker displays KO, it means that your push_swap came up with
a list of instructions that doesn’t sort the list. 

---
The project is written in strict accordance with [Norminette codestyle](https://github.com/42School/norminette)

