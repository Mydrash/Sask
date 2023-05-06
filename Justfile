example NAME: build
  make -C examples/{{NAME}} clean {{NAME}}

run-example NAME: build
  make -C examples/{{NAME}} clean {{NAME}}
  LD_LIBRARY_PATH=examples/{{NAME}} ./examples/{{NAME}}/{{NAME}}

build:
  make -j $(nproc)
  
