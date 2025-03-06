project('vcs', 'cpp')

changeset = vcs_tag('hgchangeset',
                    input : 'src/version.h.in',
                    replace_string : '@CHANGESET@',
                    output : 'version.h',
                    command : ['hg', 'id', '-i'])

executable('hello', 'src/hello.cpp')
