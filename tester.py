import random
import sys
import os
import subprocess

stack_size = input("Stack Size: ")
itterations = input("Number of Itterations: ")
average = 0

i = 0;
while (i < itterations):
	my_random = random.sample(range(1, 100000), stack_size)
	numbers = ' '.join(str(x) for x in my_random)
	proc = subprocess.Popen(["./push_swap " + numbers], stdout=subprocess.PIPE, shell=True)
	out = proc.stdout.readlines()
	if len(out) == 0:
		continue
	average += len(out)
        #solution = ''.join(out)
        #p = subprocess.Popen(["./checker " + numbers], shell=True, stdin=subprocess.PIPE)
        #p.stdin.write(solution)
        #i = i + 1
print "Average operations = ", average / itterations
