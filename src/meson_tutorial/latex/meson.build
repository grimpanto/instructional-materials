project('latexmk')

latexmk = find_program('latexmk')

pdf = custom_target('pdf',
                    build_by_default : true,
                    input : ['src/test.tex'],
                    output : ['test.pdf'],
                    command : [latexmk, '-pdf', '-pdflatex=xelatex --shell-escape %O %S', '@INPUT@'])
