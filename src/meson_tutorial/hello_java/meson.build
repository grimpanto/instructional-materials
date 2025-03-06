project('hello_java', 'java')

inc_dir = include_directories('src')

jar('hello', ['src/Hello.java', 'src/HelloWorld.java'],
    main_class : 'HelloWorld',
    java_args : ['-Xlint:unchecked'],
    include_directories : inc_dir)
