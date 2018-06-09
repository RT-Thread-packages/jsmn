from building import * 

# get current dir path
cwd = GetCurrentDir()

# init src and inc vars
src = []
inc = []

# add jsmn common include
inc = inc + [cwd + '/inc']

# add jsmn basic code
src = src + [cwd + '/src/jsmn.c']

# add jsmn example code
if GetDepend('JSMN_USING_EXAMPLE'):
    src = src + [cwd + '/examples/example_jsmn.c']

# add test common include
inc = inc + [cwd + '/test']    
    
# add test code
if GetDepend('JSMN_USING_TEST'):
    src = src + [cwd + '/test/tests.c']    

# add group to IDE project
group = DefineGroup('jsmn', src, depend = ['PKG_USING_JSMN'], CPPPATH = inc)

Return('group')