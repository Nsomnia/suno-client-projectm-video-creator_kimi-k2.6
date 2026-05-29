# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

if(EXISTS "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-gitclone-lastrun.txt" AND EXISTS "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-gitinfo.txt" AND
  "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-gitclone-lastrun.txt" IS_NEWER_THAN "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-gitinfo.txt")
  message(STATUS
    "Avoiding repeated git clone, stamp file is up to date: "
    "'/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-gitclone-lastrun.txt'"
  )
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"
            clone --no-checkout --config "advice.detachedHead=false" "https://github.com/nlohmann/json.git" "json-src"
    WORKING_DIRECTORY "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps"
    RESULT_VARIABLE error_code
  )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once: ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/nlohmann/json.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git"
          checkout "v3.11.3" --
  WORKING_DIRECTORY "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-src"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'v3.11.3'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git" 
            submodule update --recursive --init 
    WORKING_DIRECTORY "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-src"
    RESULT_VARIABLE error_code
  )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-gitinfo.txt" "/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
)
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/workspace/0aa6e209-2905-4611-bbd9-67b943f662a7/sessions/agent_fec0cf9f-a307-4cf8-ab2c-92fb10650614/build/_deps/json-subbuild/json-populate-prefix/src/json-populate-stamp/json-populate-gitclone-lastrun.txt'")
endif()
