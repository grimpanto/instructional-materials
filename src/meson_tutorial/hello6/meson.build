project('hello6', 'cpp',
        license : ['proprietary', 'Boost'],
        version : '0.9.0',
        meson_version : '>0.46',
        default_options : 'cpp_std=c++17')


inc_dir = include_directories('include')
src = ['src/main.cpp', 'src/hello.cpp']

message('project name=' + meson.project_name())
message('project license=' + meson.project_license()[0] + ',' +
        meson.project_license()[1])

project_version = meson.project_version()

if project_version.version_compare('<1.0.0')
  warning('not production ready')
endif

message('project version=' + meson.project_version())
message('meson version=' + meson.version())

executable('hello',
           sources : src,
           include_directories : inc_dir)

message(meson.source_root())
