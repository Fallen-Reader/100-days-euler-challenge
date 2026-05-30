#problem approach

problem sates that- "What is the nth prime number?"

means we have to check which prime number comes at nth position 

for example - n = 6

2,3,5,7,11,13 as you can see 13 is the prime number at 6th position

let count = 0 or j in the code , is the pointer that will trake the position of prime numbers 

create an infinte loop from 0:
	check if number is prime- if prime then increment count

if count will be equal as terms then return the number from loop 

note - to optimize the code for larger terms you should check only for odd number it will reduce the checks by half 
