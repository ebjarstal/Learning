# Lecture05: Spatial Transformations

## Types of transformations

- Translation
- Rotation
- Scaling
- Shear

## A transformation is determined by the invariants it preserves

For instance, rotations are defined by three basic properties:

- fixed origin,
- preserved distance between points of object,
- preserved orientation of sides.

Ps: The first two properties imply linearity.

## 2D rotations

### Rotation of unit vectors

How do we represent the rotation of $\vec{u_1} = (1, 0)$ by an angle $\theta$ ?
This one is pretty straight forward: $\vec{u'_1} = (cos(\theta), sin(\theta))$.

Now what about rotating $\vec{u_2} = (0, 1)$ by an angle $\theta$ ?
Gotta visualize it with the unit circle but it's $\vec{u'_2} = (-sin(\theta), cos(\theta))$.

### Using the unit vectors to represent the rotation of a random vector

If we have $\vec{x} = (x_1, x_2) = x_1 \vec{u_1} + x_2 \vec{u_2}$, then we can represent its rotation by:

$\vec{x'_{\theta}} = x_1 \vec{u'_1} + x_2 \vec{u'_2} = x_1 (cos(\theta), sin(\theta)) + x_2 (-sin(\theta), cos(\theta))$

### In terms of a 2x2 matrix

Let 
$ R_{\theta} =
\begin{bmatrix}
cos(\theta) & -sin(\theta)\\
sin(\theta) & cos(\theta)
\end{bmatrix}
$

Then $\vec{x'_{\theta}} = R_{\theta} \vec{x}$.

Let's verify it:

$ R_{\theta} \vec{x} =
\begin{bmatrix}
cos(\theta) & -sin(\theta)\\
sin(\theta) & cos(\theta)
\end{bmatrix}
\begin{bmatrix}
x_1\\
x_2
\end{bmatrix} =
\begin{bmatrix}
cos(\theta) x_1 - sin(\theta) x_2\\
sin(\theta) x_1 + cos(\theta) x_2
\end{bmatrix} =
x_1
\begin{bmatrix}
cos(\theta)\\
sin(\theta)
\end{bmatrix} +
x_2
\begin{bmatrix}
-sin(\theta)\\
cos(\theta)
\end{bmatrix} =
\vec{x'_{\theta}}
$

## 3D rotations

Say we're working in $(\vec{i}, \vec{j}, \vec{k})$.

What would the rotation matrix for rotating around $\vec{k}$ look like ?

Well since it'd kinda be like a 2D rotation relative to the plane formed by $(\vec{i}, \vec{j})$ then we can reuse the 2x2 matrix:

$
\begin{bmatrix}
cos(\theta) & -sin(\theta) & 0\\
sin(\theta) & cos(\theta) & 0\\
0 & 0 & 1
\end{bmatrix}
$

We can reason similarly for the two other unit vectors.

### The inverse of a rotation is a transpose

Say we're working with the orthonormal basis $(\vec{e_1}, \vec{e_2}, \vec{e_3})$.

Then if we define
$R = 
\begin{bmatrix}
\vec{e_1} & \vec{e_2} & \vec{e_3}\\
\vec{e_1} & \vec{e_2} & \vec{e_3}\\
\vec{e_1} & \vec{e_2} & \vec{e_3}\\
\end{bmatrix}
$

We got
$R^{T} =
\begin{bmatrix}
\vec{e_1} & \vec{e_1} & \vec{e_1}\\
\vec{e_2} & \vec{e_2} & \vec{e_2}\\
\vec{e_3} & \vec{e_3} & \vec{e_3}\\
\end{bmatrix}
$

And surprisingly, 
$R^{T} R =
\begin{bmatrix}
1 & 0 & 0\\
0 & 1 & 0\\
0 & 0 & 1\\
\end{bmatrix} =
I
$

Which means: $R^{T} = R^{-1 }$

## Reflections

Question: does every matrix $Q$ such that $Q^{T}Q = I$ describe a rotation ?

Let's look at
$Q =
\begin{bmatrix}
-1 & 0\\
0 & 1
\end{bmatrix}
$

We got
$Q^{T}Q =
\begin{bmatrix}
(-1)^2 & 0\\
0 & 1
\end{bmatrix} =
I
$

So does it represent a rotation ? Well no, it only flips the x-axis, so it represents a reflection across the y-axis and therefore fails to preserve orientation (therefore not a rotation)

## Orthogonal Transformations

Transformations that preserve distances and the origin are called orthogonal transformations. And they are represented by matrices such that $Q^{T}Q = I$

- Rotations additionally preserve orientation: $det(Q) > 0$
- Reflections reverse orientation: $det(Q) < 0$

## Scaling

Scaling preserves the direction of all vectors. And it is a linear transformation.

### Matrix representation

How do we scale a vector $\vec{u} = (u_1, u_2, u_3)$ by $a$ ?

Well the result should be $\vec{u'_a} = (a u_1, a u_2, a u_3)$, so pretty easy to deduce that the equation is
$\begin{bmatrix}
a & 0 & 0\\
0 & a & 0\\
0 & 0 & a\\
\end{bmatrix} \begin{bmatrix}
u_1\\
u_2\\
u_3
\end{bmatrix} = \begin{bmatrix}
a u_1\\
a u_2\\
a u_3
\end{bmatrix}
$

### Negative scaling

We can think of negative as a sequence of reflections. For instance in 2D:
$\begin{bmatrix}
-1 & 0\\
0 & -1
\end{bmatrix} =
\begin{bmatrix}
-1 & 0\\
0 & 1
\end{bmatrix} \begin{bmatrix}
1 & 0\\
0 & -1
\end{bmatrix}
$

Since each reflection reverses orientation, so orientation is preserved. So basically negative scaling is rotation in 2D. But not in 3D since it is a sequence of 3 reflections!

### Nonuniform scaling

If each axis is scaled by a different amount then it's called nonuniform scaling. The matrix representation is pretty straightforward:

$\begin{bmatrix}
a & 0 & 0\\
0 & b & 0\\
0 & 0 & c\\
\end{bmatrix} \begin{bmatrix}
u_1\\
u_2\\
u_3
\end{bmatrix} = \begin{bmatrix}
a u_1\\
b u_2\\
c u_3
\end{bmatrix}
$

The overall transformation is represented by a symmetric matrix $A = R^{T}DR$. (Reminder that for rotations, $R^{T} = R^{-1}$)

### Do all symmetric matrices represent nonuniform scaling ?

Yes, the **Spectral theorem** says a symmetric matrix $A = A^{T}$ has orthonormal eigenvectors and real eigenvalues. Equivalently, $AR = RD$ where $R = [e_1, ..., e_n]$ and $D$ is a diagonal matrix with the eigenvalues.

We can also write $A = RDR^{T}$

Therefore every symmetric matrix performs a nonuniform scaling along some set of orthogonal axes. And if $A$ is **definite positive** ($\lambda_{i} > 0$) then this scaling is positive.

## Shear

A shear displaces each point $x$ in a direction $\vec{u}$ according to its distance along a fixed vector $\vec{v}$ :

$f_{\vec{u},\vec{v}}(\vec{x}) = \vec{x} + \langle \vec{v}, \vec{x} \rangle \vec{u}$

Is this a linear transformation ? Yes.

### Matrix representation

$A_{\vec{u}, \vec{v}} = I + u v^{T}$

## Composite transformations

From these 4 transformations (rotation, reflection, scaling and shear) we can build complex transformations via matrix multiplication.

### But how do we decompose a complex transformation into pieces ?

- There is no unique way to decompose a given linear transformation.

But there are many useful decompositions :

- singular value decomposition
- LU factorization
- polar decomposition
- ...

### Polar decomposition

Decompose any matrix $A$ into an orthogonal matrix $Q$ and a symmetric positive-semidefinite matrix $P$.

For instance :

$A =
\begin{bmatrix}
0.34 & -0.11 & -0.89\\
-0.65 & 0.52 & -0.70\\
0.25 & 0.23 & -0.69
\end{bmatrix}
$

$A = QP$

$Q$ is for reflection/rotation, $P$ is for nonnegative, nonuniform scaling. Since $P$ is symmetric we can take it further using the spectral decomposition :

$P = VDV^{T}$

So $A = QVDV^{T} = UDV^{T}$ where $U$ is for rotation, $D$ for axis-aligned scaling, $V$ for rotation.

Why is that useful for graphics ?

## Interpolating transformations

I got a model with two transformations $A_0$ and $A_1$, how do I interpolate the continuous motion ?

### Linear interpolation

We can write $A(t) = (1-t)A_0 + tA_1$ where $t \in [0, 1]$

It works, but it looks awful.

Using our polar decomposition we define $Q(t)$ and $P(t)$ and we get :

$A(t) = Q(t) P(t)$

Looks better now.

## Translations

Not a linear transformation. It's an affine transformation. So it gets a bit difficult to mix translations + linear transformations.

But we can use a 4D shear to make 3D translations linear!