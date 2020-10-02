import random

import matplotlib.pyplot as plt

points = []

number_of_points = 10

for i in range(number_of_points):
    points.append((random.uniform(0, 1000), random.uniform(0, 1000)))

points.sort(key=lambda x: x[0])


def is_turning_left(point1, point2, point3):
    vector_1 = (point2[0] - point1[0], point2[1] - point1[1])
    vector_2 = (point3[0] - point2[0], point3[1] - point2[1])
    dot_product = vector_1[0] * vector_2[1] - vector_2[0] * vector_1[1]
    return dot_product > 0


UH = [points[0], points[1]]
# Upper hull
for i in range(2, len(points)):
    while len(UH) >= 2 and is_turning_left(UH[-2], UH[-1], points[i]):
        UH.pop()
    UH.append(points[i])

points.reverse()
LH = [points[0], points[1]]

for i in range(2, len(points)):
    while len(LH) >= 2 and is_turning_left(LH[-2], LH[-1], points[i]):
        LH.pop()
    LH.append(points[i])

hull = UH + LH

plt.scatter(*zip(*points))
plt.plot(*zip(*hull))
plt.show()

assert is_turning_left((1, 1), (1, 2), (2, 2)) is False
assert is_turning_left((1, 2), (2, 2), (3, 3)) is True
assert is_turning_left((1, 1), (2, 2), (3, 3)) is False
assert is_turning_left((3, 1), (1, 1), (0, 0)) is True
