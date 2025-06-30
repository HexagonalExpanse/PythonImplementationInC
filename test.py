from MathMethods import MathMethodsPy as jl

import time
import statistics

#input values
trial = []
with open('trial_array.txt', 'r') as file:
    for line in file:
        trial.append(float(line))


start = time.perf_counter()

std_deviation = statistics.stdev(trial)

end = time.perf_counter()

time_dif_python = end - start

print('Using Python statistics.stdev()')
print('Time to run:', time_dif_python)
print('Standard Deviation:', std_deviation)

print()


start = time.perf_counter()

std_deviation = jl.std_dev(trial)

end = time.perf_counter()

time_dif_jl = end - start

print('Using jl.std_dev()')
print('Time to run:', time_dif_jl)
print('Standard Deviation:', std_deviation)

print()

print((time_dif_python)/time_dif_jl, "Times Faster")