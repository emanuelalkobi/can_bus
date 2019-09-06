cmake_minimum_required(VERSION 3.14)
project(can_bus C)

set(CMAKE_C_STANDARD 99)

add_executable(can_bus main.c data_frame_st.h data_frame_st.c wheel_speeds.c wheel_speeds.h brake_module.c brake_module.h powertrian.c powertrian.h queue.c queue.h create_report.c create_report.h simulation.c simulation.h)