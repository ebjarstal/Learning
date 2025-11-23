# Lecture05

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

