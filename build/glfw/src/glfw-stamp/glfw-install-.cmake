

set(command "${make};install")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/src/glfw-stamp/glfw-install-out.log"
  ERROR_FILE "/home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/src/glfw-stamp/glfw-install-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/src/glfw-stamp/glfw-install-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "glfw install command succeeded.  See also /home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/src/glfw-stamp/glfw-install-*.log")
  message(STATUS "${msg}")
endif()
