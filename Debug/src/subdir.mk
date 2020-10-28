################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/backpack_cost_response.cpp \
../src/backpack_cost_slice.cpp \
../src/backpack_response.cpp \
../src/backpack_slicable_stone.cpp \
../src/bad_from_string.cpp \
../src/battle.cpp \
../src/calculator_response.cpp \
../src/cup_task.cpp \
../src/graph_adjacency_list_to_matrix.cpp \
../src/graph_check_tree_subgraph.cpp \
../src/graph_connectivity_components.cpp \
../src/graph_cycle_check.cpp \
../src/graph_cycle_check_with_answer.cpp \
../src/graph_dfs_with_steps.cpp \
../src/graph_matrix_to_adjacency_list.cpp \
../src/graph_maxtirx_to_verticies_list.cpp \
../src/graph_oriented_cycle_check_with_answer.cpp \
../src/graph_pq_horse.cpp \
../src/graph_reverse_graph_edges.cpp \
../src/graph_topological_sort.cpp \
../src/graph_topological_sort_check.cpp \
../src/graph_topological_sort_check_uniq.cpp \
../src/graph_verticies_list_to_adjacency_list.cpp \
../src/graph_verticies_list_to_matrix.cpp \
../src/graph_waves.cpp \
../src/grasshopper_k_response.cpp \
../src/grasshopper_response.cpp \
../src/horse.cpp \
../src/icescating.cpp \
../src/knight_response.cpp \
../src/map_reduce.cpp \
../src/map_reduce_async.cpp \
../src/meta_part_1.cpp \
../src/meta_part_2.cpp \
../src/meta_part_3.cpp \
../src/no_throw.cpp \
../src/queen.cpp \
../src/queen_response.cpp \
../src/remove_nth.cpp \
../src/rook.cpp \
../src/rook_response.cpp \
../src/sport_p_cows.cpp \
../src/stepik_ya.cpp \
../src/tortilla.cpp \
../src/tortilla_2.cpp \
../src/tortilla_response.cpp 

OBJS += \
./src/backpack_cost_response.o \
./src/backpack_cost_slice.o \
./src/backpack_response.o \
./src/backpack_slicable_stone.o \
./src/bad_from_string.o \
./src/battle.o \
./src/calculator_response.o \
./src/cup_task.o \
./src/graph_adjacency_list_to_matrix.o \
./src/graph_check_tree_subgraph.o \
./src/graph_connectivity_components.o \
./src/graph_cycle_check.o \
./src/graph_cycle_check_with_answer.o \
./src/graph_dfs_with_steps.o \
./src/graph_matrix_to_adjacency_list.o \
./src/graph_maxtirx_to_verticies_list.o \
./src/graph_oriented_cycle_check_with_answer.o \
./src/graph_pq_horse.o \
./src/graph_reverse_graph_edges.o \
./src/graph_topological_sort.o \
./src/graph_topological_sort_check.o \
./src/graph_topological_sort_check_uniq.o \
./src/graph_verticies_list_to_adjacency_list.o \
./src/graph_verticies_list_to_matrix.o \
./src/graph_waves.o \
./src/grasshopper_k_response.o \
./src/grasshopper_response.o \
./src/horse.o \
./src/icescating.o \
./src/knight_response.o \
./src/map_reduce.o \
./src/map_reduce_async.o \
./src/meta_part_1.o \
./src/meta_part_2.o \
./src/meta_part_3.o \
./src/no_throw.o \
./src/queen.o \
./src/queen_response.o \
./src/remove_nth.o \
./src/rook.o \
./src/rook_response.o \
./src/sport_p_cows.o \
./src/stepik_ya.o \
./src/tortilla.o \
./src/tortilla_2.o \
./src/tortilla_response.o 

CPP_DEPS += \
./src/backpack_cost_response.d \
./src/backpack_cost_slice.d \
./src/backpack_response.d \
./src/backpack_slicable_stone.d \
./src/bad_from_string.d \
./src/battle.d \
./src/calculator_response.d \
./src/cup_task.d \
./src/graph_adjacency_list_to_matrix.d \
./src/graph_check_tree_subgraph.d \
./src/graph_connectivity_components.d \
./src/graph_cycle_check.d \
./src/graph_cycle_check_with_answer.d \
./src/graph_dfs_with_steps.d \
./src/graph_matrix_to_adjacency_list.d \
./src/graph_maxtirx_to_verticies_list.d \
./src/graph_oriented_cycle_check_with_answer.d \
./src/graph_pq_horse.d \
./src/graph_reverse_graph_edges.d \
./src/graph_topological_sort.d \
./src/graph_topological_sort_check.d \
./src/graph_topological_sort_check_uniq.d \
./src/graph_verticies_list_to_adjacency_list.d \
./src/graph_verticies_list_to_matrix.d \
./src/graph_waves.d \
./src/grasshopper_k_response.d \
./src/grasshopper_response.d \
./src/horse.d \
./src/icescating.d \
./src/knight_response.d \
./src/map_reduce.d \
./src/map_reduce_async.d \
./src/meta_part_1.d \
./src/meta_part_2.d \
./src/meta_part_3.d \
./src/no_throw.d \
./src/queen.d \
./src/queen_response.d \
./src/remove_nth.d \
./src/rook.d \
./src/rook_response.d \
./src/sport_p_cows.d \
./src/stepik_ya.d \
./src/tortilla.d \
./src/tortilla_2.d \
./src/tortilla_response.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -D__GXX_EXPERIMENTAL_CXX0X__ -D__cplusplus=201402L -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


