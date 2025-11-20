# Lecture 04

## Rasterization

Q: which pixels light up ?

## Ray tracing

Q: for each pixel, which primitives are seen ?

Very heavy calculations. Takes time.

## 3D image generation pipeline

Several stages:

- INPUTS: what do we want to draw ?
- STAGES: sequence of transformations from input->output
- OUTPUTS: the final image

Remember first lecture:

1. INPUT: vertices and edges
2. STAGE: perspective projection
3. STAGE: drawing lines
4. OUTPUT

## Rasterization Pipeline

- INPUT: 3D "primitives" (in reality, all triangles), with maybe additional attributes like color
- OUTPUT: bitmap image, with maybe depth, alpha...

The goal here is to understand the stages in between (handled by GPU).

### The rasterization pipeline converts ALL primitives to triangles, why ?

- Can approximate any shape
- Always planar
- Easy to interpolate data at corners ("barycentric coordinates")

If everything is a triangle, then we can just focus on having a very optimized way to draw them.

### Rough sketch of the pipeline

1. Transform/position objects in the world
2. Project objects onto the screen
3. Sample triangle coverage
4. Interpolate triangle attributes at covered samples
5. Sample texture maps / evaluate shaders
6. Combine samples into final image

### Let's draw some triangles on the screen

- Q1. What pixels does the triangle overlap ? (coverage)
- Q2. Which triangle is closest to the camera in each pixel ? (occlusion)

### The visibility problem in terms of ray

- COVERAGE: what scene geometry is hit by a ray from a pixel through the pinhole ?
- OCCLUSION: which object is the first hit along that ray ?

### Computing triangle coverage

"Which pixels does the triangle overlap ?"

- Our input is a projected position of vertices
- Our output needs to be a set of pixels

Whether a pixel should be turned on shouldn't be a simple "yes" or "no". The intensity of the pixel could depend on the total area of the pixel covered by a triangle for instance. Coverage also gets tricky when considering occlusion.

### Coverage via sampling

Let's view the coverage problem as a sampling problem.
We only look at some points of the triangle to get an idea of the problem then we sort of interpolate.
For instance for a function f(x): Lagrange interpolation.
However we need to agree on the sample rate in order to miss any important.

- Sampling: measurement of a signal
- Encode signal as discrete set of samples
- In principle, represent values at specific points

### For rasterization, what functions are we sampling ?

- `coverage(x,y) = 1 if triangle contains point(x,y) else 0`

Imagine a grid of points on a pixel and these points hold the info about the triangle that covers them.
What should we do with this array ?

## Aliasing

### Sampling and reconstruction

Say we have a continuous signal that we want to digitalize: array of numbers. Then we want to reconstruct it. How do we reconstruct the signal as accurately as possible ?

## Nyquist-Shannon Theorem

- Consider a band-limited signal: has no frequences above some threshold $\omega_0$
- Then the signal can be perfectly reconstructed if sampled with period $T = \frac{1}{2\omega_0}$
- and if interpolation is performed using a "sinc filter"
- a sinc filter is an ideal filter with no frequencies above cutoff (infinite extend!)
- $sinc(x) = \frac{1}{\pi x}sin(\pi x)$

So there is a theoretical way in which we can get perfect reconstruction!! But...

- Real signals are not band-limited in computer graphics
- Infinite extend of "ideal" reconstruction filter (sinc) is impractical for efficient implementations

### Imperfect sampling + imperfect reconstruction = image artifacts

### How can we reduce aliasing ?

- Aliasing is a fact of life: sampled representations with always fail to represent frequencies that are too high
- But we can do our best to try to match sampling and reconstruction
- If a pixel is a little square: the total light emitted should be the same as the total light in that pixel (integration)

## Back to our problem

- For each pixel of the image, how much of it is covered by the triangle
- Set a sampling rate
- 4 samples per pixel
- If 3 out of samples are on for 1 pixel, light up at 75% etc...