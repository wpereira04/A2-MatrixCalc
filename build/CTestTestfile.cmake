# CMake generated Testfile for 
# Source directory: C:/Users/walte/source/repos/ECE3574/MatrixCalc
# Build directory: C:/Users/walte/source/repos/ECE3574/MatrixCalc/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(my_test "C:/Users/walte/source/repos/ECE3574/MatrixCalc/build/Debug/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/walte/source/repos/ECE3574/MatrixCalc/CMakeLists.txt;21;add_test;C:/Users/walte/source/repos/ECE3574/MatrixCalc/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(my_test "C:/Users/walte/source/repos/ECE3574/MatrixCalc/build/Release/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/walte/source/repos/ECE3574/MatrixCalc/CMakeLists.txt;21;add_test;C:/Users/walte/source/repos/ECE3574/MatrixCalc/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(my_test "C:/Users/walte/source/repos/ECE3574/MatrixCalc/build/MinSizeRel/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/walte/source/repos/ECE3574/MatrixCalc/CMakeLists.txt;21;add_test;C:/Users/walte/source/repos/ECE3574/MatrixCalc/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(my_test "C:/Users/walte/source/repos/ECE3574/MatrixCalc/build/RelWithDebInfo/my_test.exe")
  set_tests_properties(my_test PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/walte/source/repos/ECE3574/MatrixCalc/CMakeLists.txt;21;add_test;C:/Users/walte/source/repos/ECE3574/MatrixCalc/CMakeLists.txt;0;")
else()
  add_test(my_test NOT_AVAILABLE)
endif()
