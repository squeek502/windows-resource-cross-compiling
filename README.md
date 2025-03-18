# windows-resource-cross-compiling

A minimal project to test cross-compilation of Windows resources with [`resinator`](https://github.com/squeek502/resinator) and/or [`zig rc`](https://www.ryanliptak.com/blog/zig-is-a-windows-resource-compiler/) when using various build systems.

Just a skeleton right now, will be filled out as I figure things out.

## meson

### On Windows

```
meson setup builddir
cd builddir
meson compile
```

### On non-Windows systems

TODO
