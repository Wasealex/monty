The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). 
It relies on a unique stack, with specific instructions to manipulate it. 
The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files
Files containing Monty byte codes usually have the .m extension. 
Most of the industry uses this standard but it is not required by the specification of the language. 
There is not more than one instruction per line. 
There can be any number of spaces before or after the opcode and its argument:
<<<<<<< HEAD


Facts about monty bytecode
-extension is .m
-one instruction perline
-instruction is called 'opcode'
-there can be any number of space before or after the opcode
-if the line is blank(empty or only space) then its EOF, that means any instruction
after us not considered


common opcodes used here will be
pull, insert_at_begin()
pall, print_list()
pint, insert_at_end()
pop, remove_at_end()
swap, swap_first_two()
add, add_first_two()
=======
basic operations push and pull to add and remove from stack respectively
>>>>>>> refs/remotes/origin/main
