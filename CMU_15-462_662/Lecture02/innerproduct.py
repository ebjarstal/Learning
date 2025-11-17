Vector = tuple[float]
Basis = tuple[Vector]

def add(*args: Vector) -> Vector:
    res: list[float] = []
    for v in args:
        for i in range(len(v)):
            while len(res) <= i:
                res.append(0)
            res[i] += v[i]
    return Vector(res)

def get_norm(v: Vector) -> float:
    res: float = 0
    for u in v:
        res += u**2
    return res**(1/2)

def normalize(v: Vector) -> Vector:
    res: list[float] = []
    norm: float = get_norm(v)
    for u in v:
        res.append(u/norm)
    return Vector(res)

def inner_product(v1: Vector, v2: Vector) -> float:
    assert(len(v1) == len(v2))
    sum: float = 0
    for i in range(len(v1)):
        sum += v1[i] * v2[i]
    return sum

def gram_schmidt(b: Basis) -> Basis:
    assert(len(b) >= 1)
    res: list[Vector] = []
    e_0 = normalize(b[0])
    for i in range(1, len(b)):
        u_i = b[i]
        # todo
    return Basis(res)

if __name__ == "__main__":
    pass