def calculate_time(N, segments, initial_velocity):
    time = 0
    velocity = initial_velocity

    for i in range(N):
        d_i, a_i = segments[i]
        if velocity**2 + 2 * a_i * d_i < 0:
            return 0
        # Calculate the time taken to traverse the current segment
        t_i = (-velocity + (velocity**2 + 2 * a_i * d_i)**0.5) / a_i
        time += t_i
        # Update the velocity for the next segment
        velocity += a_i * t_i

    return time


n = int(input())

wds = []
was = []
for _ in range(n):
    d, a = map(int, input().split())
    wds.append(d)
    was.append(a)

V = []
Vsum = 0
for i in range(n):
    Vsum += wds[i]*was[i]
    V.append(Vsum)

if min(V) >= 0:
    ans = 0
else:
    ans = (2*abs(min(V)))**0.5 + 1e-9


print(ans, calculate_time(n, list(zip(wds, was)), ans))



import sys

# Function to calculate the time it takes to traverse the wormhole with a given initial velocity
#
# # Read input
# N = int(input())
# segments = []
#
# for _ in range(N):
#     d_i, a_i = map(int, input().split())
#     segments.append((d_i, a_i))
#
# # Binary search for the minimum velocity
# low = 0
# high = 1e9  # Adjust the upper bound as needed
#
# while high - low > 1e-9:
#     mid = (low + high) / 2
#     # Calculate the time with the current velocity
#     time_with_velocity = calculate_time(N, segments, mid)
#     if time_with_velocity > 0:
#         # If the time is positive, it means the spacecraft exits
#         high = mid
#     else:
#         # If the time is negative, increase velocity
#         low = mid
#
# # Calculate the time it takes to traverse with the minimum velocity
# minimum_velocity = (low + high) / 2 + 1e-9
# time_to_traverse = calculate_time(N, segments, minimum_velocity)
#
# # Print the result
# print(f"{minimum_velocity:.9f} {time_to_traverse:.9f}")

