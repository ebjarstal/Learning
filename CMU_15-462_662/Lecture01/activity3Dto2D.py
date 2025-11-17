c = (2,3,5)  # camera
vertices3d = [(1,1,1),(-1,1,1),(1,-1,1),(-1,-1,1),
            (1,1,-1), (-1,1,-1), (1,-1,-1), (-1,-1,-1)]

vertices2d = []
for (X,Y,Z) in vertices3d:
    point = (X-c[0], Y-c[1], Z-c[2])
    vertices2d.append((point[0]/point[2], point[1]/point[2]))

for point in vertices2d:
    print(point)
