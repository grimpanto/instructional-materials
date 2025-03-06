project('hello_junit', 'java')

jre = find_program('java')
junit_files = ':'.join(['../tests/junit-4.12.jar', '../tests/hamcrest-core-1.3.jar'])

inc_dir = include_directories('src')

sources = ['src/Hello.java', 'src/HelloWorld.java']
jar('hello', sources,
    main_class : 'HelloWorld',
    java_args : ['-Xlint:unchecked'],
    include_directories : inc_dir)

# test
test_sources = ['src/HelloWorld.java', 'tests/TestHelloWorld.java']
jar('hello_tests', test_sources,
    main_class : 'org.junit.runner.JUnitCore',
    include_directories : inc_dir,
    java_args : ['-cp', junit_files])
test('test1', jre,
     args : ['-cp', junit_files + ':hello_tests.jar', 'org.junit.runner.JUnitCore', 'TestHelloWorld'])
