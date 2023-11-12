<p align="center">
  <img width="512" height="512" src="https://raw.githubusercontent.com/heikkiseppanen/42-fdf/master/fdf.png">
</p>
<h1 align="center">
    FDF
</h1>
FDF is a simple line rasterizer that turns a rectangular map of height values into a wireframe render.

The code is written in accordance to the 42 School [Norm](https://github.com/42School/norminette/blob/master/pdf/en.norm.pdf).

# Build
```
make
```

# Usage

```
> cat map.txt
0 0 0
0 1 0
0 0 0

> fdf ./map.txt
```

# Input
- Left Mouse   : Translate while pressed
- Right Mouse  : Rotate along Y-axis while pressed
- Middle Mouse : Zoom while pressed
- P Key        : Switch between orthographic and perspective
