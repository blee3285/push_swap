import random
import sys
import os
import subprocess

stack_size = input("Stack Size: ")

random_num = random.sample(range(1, 100000), stack_size)
print(random_num)
numbers = ' '.join(str(x) for x in random_num)
proc = subprocess.Popen(["./push_swap " + numbers], shell=True)
