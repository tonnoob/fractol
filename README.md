This project has been created as part of the 42 curriculum by osousa-d.*

# fractol

## Description

**fractol** is a graphical project that explores mathematical fractals, such as **Mandelbrot** and **Julia** sets.
It maps complex numbers to the screen and applies iterative calculations to determine whether each point belongs to the fractal, rendering the result in real time.

### Implementation Details
This implementation uses:
- A **minilibx** is a simple graphics library used to create windows, draw pixels, and handle user input;

---
### Compilation

At the root of the project, run:

```bash
make
```
---
## Instructions ##

After compiling the project, you must execute the **fractal** file with the arguments:

```bash
./fractal mandelbrot
```
or
```bash
./fractal julia "<real value> <imaginary value>"
```
Note: Julia parameters must be small values (e.g. 0.21 -0.921).
Large values cause the iteration to escape too quickly, resulting in a screen filled with a single color.

---
Invalid inputs

The arguments are not passed randomly; the following inputs are not allowed:

- Empty strings or strings containing only spaces
- Unknown fractal names
- Wrong number of arguments
- Arguments that are not numbers (for Julia parameters)
- A sign without a number
- Numbers attached to text
- Malformed numeric values
- Multiple decimal points
- Overflow / underflow values
- Values outside the representable range of double`
- Extra spaces splitting numbers

---
After running the program with the arguments, a window will open displaying the generated **fractal**.
(For the Julia fractal, try different values to visualize the various shapes that can be generated.)

You can use the `mouse scroll` to zoom in and out, and close the program by clicking the `X` button or pressing the `ESC` key.


## Resources ##

I used ChatGPT (https://chatgpt.com/) to help me understand the calculations used to generate the **fractol**, organize the project (deciding the next steps), and translate the `README` into English.