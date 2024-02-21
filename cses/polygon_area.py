n = int(input())
 
def fa(p1, p3, p2):
    v1 = [p1[0]-p2[0], p1[1]-p2[1]]
    v2 = [p1[0]-p3[0], p1[1]-p3[1]]
    out = v1[0]*v2[1] - v1[1]*v2[0]
    return out
 
area = 0
points = [[0,0]]
for i in range(n):
    a, b = map(int, input().split(' '))
    points.append([a,b])
    if len(points) > 2:
        area += fa(points[0], points[len(points)-1], points[len(points)-2])
area += fa(points[0], points[1], points[len(points)-1])
 
print(abs(area))