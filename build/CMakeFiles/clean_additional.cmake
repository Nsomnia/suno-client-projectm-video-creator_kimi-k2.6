# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "_deps/spdlog-build/CMakeFiles/spdlog_autogen.dir/AutogenUsed.txt"
  "_deps/spdlog-build/CMakeFiles/spdlog_autogen.dir/ParseCache.txt"
  "_deps/spdlog-build/spdlog_autogen"
  "apps/aether/CMakeFiles/aether_autogen.dir/AutogenUsed.txt"
  "apps/aether/CMakeFiles/aether_autogen.dir/ParseCache.txt"
  "apps/aether/aether_autogen"
  "libs/audio/CMakeFiles/aether_audio_autogen.dir/AutogenUsed.txt"
  "libs/audio/CMakeFiles/aether_audio_autogen.dir/ParseCache.txt"
  "libs/audio/aether_audio_autogen"
  "libs/core/CMakeFiles/aether_core_autogen.dir/AutogenUsed.txt"
  "libs/core/CMakeFiles/aether_core_autogen.dir/ParseCache.txt"
  "libs/core/aether_core_autogen"
  "libs/network/CMakeFiles/aether_network_autogen.dir/AutogenUsed.txt"
  "libs/network/CMakeFiles/aether_network_autogen.dir/ParseCache.txt"
  "libs/network/aether_network_autogen"
  "libs/rendering/CMakeFiles/aether_rendering_autogen.dir/AutogenUsed.txt"
  "libs/rendering/CMakeFiles/aether_rendering_autogen.dir/ParseCache.txt"
  "libs/rendering/aether_rendering_autogen"
  "libs/ui/CMakeFiles/aether_ui_autogen.dir/AutogenUsed.txt"
  "libs/ui/CMakeFiles/aether_ui_autogen.dir/ParseCache.txt"
  "libs/ui/aether_ui_autogen"
  )
endif()
