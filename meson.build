project('resource-test', 'c')

windows = import('windows')
res = windows.compile_resources('resource.rc')
executable('check', 'main.c', res)
