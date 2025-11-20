Point = tuple[float, float]
Line = tuple[Point, Point]
Triangle = tuple[Point, Point, Point]

def point_is_in_triangle(p: Point, t: Triangle) -> bool:
    result: bool = False
    return result

if __name__ == "__main__":
    p0: Point = (0, 0.5)
    p1: Point = (9.7, 2.4)
    p2: Point = (6.6, 9.25)
    q: Point = (5.5, 4.5)

    t1: Triangle = (p0, p1, p2)

    print(point_is_in_triangle(q, t1))