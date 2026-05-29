# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-src"
  "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-build"
  "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix"
  "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/tmp"
  "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
  "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src"
  "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
