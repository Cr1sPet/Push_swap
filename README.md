# PUSH_SWAP

[SUBJECT](subject/en.subject.pdf "push_swap subject")

* We have at our disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks. 

* push_swap program receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack.
* The program must display the smallest list of instructions possible to sort the stack a.

### Clone project
```
git clone git@github.com:CrsPet/my_push_swap.git
```
### How to use
```
cd my_push_swap
make
ARG="input numbers"; ./push_swap $ARG // get instructions to sort
ARG="input numbers"; ./push_swap $ARG | wc -l // number of instructions
ARG="input numbers"; ./push_swap $ARG | ./checker $ARG // "ОК" if stack sorted, else "KO", on error prints "Error!"

*input numbers - random sequence of unique int (integer)

```
---

### Examples:

![ps_example](https://user-images.githubusercontent.com/93244882/151348451-9ff81eab-9409-4b75-a591-2e6cebaa5b08.jpg)

---
![ps_example1](https://user-images.githubusercontent.com/93244882/151348586-4bdf01ed-fdc8-4100-959b-eee887393751.jpg)

---
### Bonus: checker program

![ps_example2](https://user-images.githubusercontent.com/93244882/151348623-0c210cea-88ef-4770-aae2-a3c519955734.png)

If the program checker displays KO, it means that your push_swap came up with
a list of instructions that doesn’t sort the list. 

---
The project is written in strict accordance with [Norminette codestyle](https://github.com/42School/norminette)

