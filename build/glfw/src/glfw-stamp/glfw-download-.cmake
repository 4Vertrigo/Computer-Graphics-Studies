

set(command "/usr/bin/cmake;-P;/home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/tmp/glfw-gitclone.cmake")
execute_process(
  COMMAND ${command}
  RESULT_VARIABLE result
  OUTPUT_FILE "/home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/src/glfw-stamp/glfw-download-out.log"
  ERROR_FILE "/home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/src/glfw-stamp/glfw-download-err.log"
  )
if(result)
  set(msg "Command failed: ${result}\n")
  foreach(arg IN LISTS command)
    set(msg "${msg} '${arg}'")
  endforeach()
  set(msg "${msg}\nSee also\n  /home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/src/glfw-stamp/glfw-download-*.log")
  message(FATAL_ERROR "${msg}")
else()
  set(msg "glfw download command succeeded.  See also /home/vertrigo/Desktop/OPENGL/icmc-cg/build/glfw/src/glfw-stamp/glfw-download-*.log")
  message(STATUS "${msg}")
endif()
