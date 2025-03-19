# windows-resource-cross-compiling

A minimal project to test cross-compilation of Windows resources with [`resinator`](https://github.com/squeek502/resinator) and/or [`zig rc`](https://www.ryanliptak.com/blog/zig-is-a-windows-resource-compiler/) when using various build systems.

## meson

Note: This needs a `resinator` built with commit [`48aef18`](https://github.com/squeek502/resinator/commit/48aef1880e4c540fef363218b434dba1a90c0f5a) included.

### Setting the `WINDRES` environment variable

If the linker you're using can convert `.res` files to COFF object files:
- `WINDRES=resinator`

If the linker you're using cannot convert `.res` files to COFF object files:
- `WINDRES="resinator windres"`
- `WINDRES="resinator /:output-format coff"`

### Using a cross-file

Example cross-files are provided in the `meson-cross` directory:

If the linker you're using can convert `.res` files to COFF object files:
- `--cross-file meson-cross/rc.txt`

If the linker you're using cannot convert `.res` files to COFF object files:
- `--cross-file meson-cross/windres.txt`
- `--cross-file meson-cross/coff.txt`

(note: the example cross files use `zig cc` which supports `.res` -> COFF `.obj` conversion, so any of them will work)

### Building

```sh
# if you have set WINDRES appropriately
meson setup builddir
# or
meson setup builddir --cross-file=<your-cross-file.txt>
```

then

```
cd builddir
meson compile
```
