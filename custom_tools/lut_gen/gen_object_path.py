


"""

if __name__ == "__main__":
    LUT_SIZE = 210
    min_int = -128
    my_str1 = ""
    my_str2 = ""
    dv = 1
    last = 33
    overflow_i = 1000
    arr = []
    incr = 15
    i = 1
    l_num = 0

    while l_num > -178:
        if i % 21 == 0:
            my_str1 += "\n"
            my_str2 += "\n"
        l_num = last-dv
        last = l_num

        n1 = 0
        n2 = 0
        n1 = l_num
        arr.append(l_num) # for scale table
        if l_num <= min_int:
            n1 = min_int
            n2 = l_num-min_int

        rounded1 = int(n1)
        rounded2 = int(n2)
        my_str1 += f"{rounded1},"
        my_str2 += f"{rounded2},"
        if i % incr == 0:
            dv+=0.4
            incr -= 2
        i += 1


    print(my_str1)
    print("\n\n")
    print(my_str2)

    #32 - scale 6
    #28 - scale 7
    #24 - scale 8 ...
    arr_str = ""

    for y in arr:
        sc = -0.25 * y + 14
        sc_rounded = int(sc)
        arr_str += f"{sc_rounded},"

    print("\n\n")
    print(arr_str)
    print("\n\n")
    print(f"iterations = {i-1}")


"""
def get_var_name(stage : int, var_name : str):
    return f"_ST{int(stage)}_{var_name}_LUT[TTL_ST{int(stage)}]"

def get_var_name2(stage : int, var_name : str):
    return f"_ST{int(stage)}_{var_name}_LUT"


    
def print_list(list,count,file):
    for i in range(count):
        file.write(str(list[i]))
        if i < count-1:
            file.write(", ")
        else:
            file.write("};\n")

def print_array_entry(file, val, i, i_max):
    file.write(f"{val}")
    if(i < i_max-1):
        file.write(", ")


max_sc_possible = 37

def generate_stage(stage, frames, file):
    y_arr = []

    for x in range (frames):
        a = 210 / (-frames * frames)
        num = a * (x+frames) * (x-frames) - 178 # quadratic function
        num_rounded = int(num)
        y_arr.append(num_rounded)

    y1_arr = []
    y2_arr = []

    # convert to data structure
    for num in y_arr:
        n1 = num
        n2 = 0
        if n1 < -128:
            n1 = -128
            n2 = num+128
        y1_arr.append(n1)
        y2_arr.append(n2)

    # resulting x positions
    xl_arr = []
    xr_arr = []
    for y in y_arr:
        xl = (66/148) * y - 25.5 # linear function
        x = int(xl)
        xl_arr.append(x)
        xr_arr.append(-x)
        

    # resulting scaling
    sc_arr = []
    for y in y_arr:
        sc = -0.165 * y + 8 # linear function
        sc_rounded = int(sc)
        sc_arr.append(sc_rounded)
        
    # reverse arrays, because ttl counts backwards
    y1_arr.reverse()
    y2_arr.reverse()
    xl_arr.reverse()
    xr_arr.reverse()
    sc_arr.reverse()

    # generate data structure
    def print_list_alt(list):
        for i in range(frames):
            file.write(str(list[i]))
            if i < frames-1:
                file.write(", ")
            else:
                file.write("};\n")

    file.write("\n")
    file.write("const int \t\t\t\t"+get_var_name(stage, "Y1")+" = {")
    print_list_alt(y1_arr)
    file.write("const int \t\t\t\t"+get_var_name(stage, "Y2")+" = {")
    print_list_alt(y2_arr)
    file.write("const int \t\t\t\t"+get_var_name(stage, "XL")+" = {")
    print_list_alt(xl_arr)
    file.write("const int \t\t\t\t"+get_var_name(stage, "XR")+" = {")
    print_list_alt(xr_arr)
    file.write("const unsigned int \t\t"+get_var_name(stage, "SC")+" = {")
    print_list_alt(sc_arr)
    file.write("\n")

def generate_header():
    with open('../../source/game_include/gen_data/gen_object_path.h', 'w') as file:
        file.write("#pragma once\n\n")
        file.write("/********************************************************************************************************\n")
        file.write(" *   THIS FILE WAS GENERATED          DO NOT EDIT!!! \n")
        file.write(" *   make changes in custom_tools/lut_gen/gen_object_path.py\n")
        file.write(" *\n")
        file.write(" *\n")
        file.write(" *   AUTHOR: laserbluejay / cxlledjay, 2025\n")
        file.write(" *******************************************************************************************************/\n\n\n")

        speed_per_stage = [196,168,140,119,98,84,77,70,56,42,28]
        for stage in range(11):
            file.write(f"#define TTL_ST{stage} \t\t\t\t({speed_per_stage[stage]}u)\n")

        for stage in range(11):
            file.write("\n\n")
            file.write("extern const int \t\t\t\t"+get_var_name(stage, "Y1")+";\n")
            file.write("extern const int \t\t\t\t"+get_var_name(stage, "Y2")+";\n")
            file.write("extern const int \t\t\t\t"+get_var_name(stage, "XL")+";\n")
            file.write("extern const int \t\t\t\t"+get_var_name(stage, "XR")+";\n")
            file.write("extern const unsigned int \t\t"+get_var_name(stage, "SC")+";\n")
            file.write("\n\n\n")
        
        file.write("#include \"../game.h\"\n")
        file.write("extern const unsigned int MOVING_OBJECT_TTL_LUT[STAGE_T_SIZE];\n")

        file.write("\n\n/// --------------------< co l l i s i o n   i n t e r f a c e >--------------------\n\n")
        arr_arr = ["Y1","Y2","XL","XR"]
        for string in arr_arr:
            file.write(f"extern const int * const \t\t\tMOVING_OBJECT_{string}_LUT[STAGE_T_SIZE];\n")
        file.write(f"extern const unsigned int * const \tMOVING_OBJECT_SC_LUT[STAGE_T_SIZE];\n")
        
        file.write("\n\n/// --------------------< missile ability    i n t e r f a c e >--------------------\n")
        file.write("#define ABILITY_MISSILE_MAX_CNT\t\t(25u)\n\n")
        arr_arr = ["YY","XL","XR"]
        file.write(f"extern const int \t\t\tABILITY_MISSILE_YY_LUT[ABILITY_MISSILE_MAX_CNT];\n")
        file.write(f"extern const unsigned int \tABILITY_MISSILE_SC_LUT[ABILITY_MISSILE_MAX_CNT];\n")

    # generate hitboxes (for each object type), depending on scaling factor
    with open('../../source/game_include/gen_data/gen_object_hitbox.h', 'w') as file:
        file.write("#pragma once\n")
        file.write("#include \"game_include/object.h\"\n\n")
        file.write("/********************************************************************************************************\n")
        file.write(" *   THIS FILE WAS GENERATED          DO NOT EDIT!!! \n")
        file.write(" *   make changes in custom_tools/lut_gen/gen_object_path.py\n")
        file.write(" *\n")
        file.write(" *\n")
        file.write(" *   AUTHOR: laserbluejay / cxlledjay, 2025\n")
        file.write(" *******************************************************************************************************/\n\n\n")

        global max_sc_possible
        file.write(f"extern const int \t\t MO_SC_TO_BB_X_HALFED[MOT_COUNT-1][{max_sc_possible}];\n")
        file.write(f"extern const int \t\t  MO_SC_TO_BB_Y[MOT_COUNT-1][{max_sc_possible}];\n")


def generate_source():
    speed_per_stage = [196,168,140,119,98,84,77,70,56,42,28]
    with open('../../source/game_source/gen_data/gen_object_path.c', 'w') as file:
        file.write("#include \"../../game_include/gen_data/gen_object_path.h\"\n\n")
        file.write("/********************************************************************************************************\n")
        file.write(" *   THIS FILE WAS GENERATED          DO NOT EDIT!!! \n")
        file.write(" *   make changes in custom_tools/lut_gen/gen_object_path.py\n")
        file.write(" *\n")
        file.write(" *\n")
        file.write(" *   AUTHOR: laserbluejay / cxlledjay, 2025\n")
        file.write(" *******************************************************************************************************/\n")

        for stage in range(11):
            generate_stage(stage,speed_per_stage[stage],file)

        file.write("#include \"../../game_include/game.h\"\n")
        file.write("const unsigned int MOVING_OBJECT_TTL_LUT[STAGE_T_SIZE] =\n")
        file.write("{\n")
        for stage in range(11):
            file.write(f"\tTTL_ST{stage}-1")
            if stage < 10:
                file.write(",\n")
            else:
                file.write("\n")
        file.write("};\n")

        file.write("\n\n/// --------------------< co l l i s i o n   i n t e r f a c e >--------------------\n\n")

        arr_arr = ["Y1","Y2","XL","XR"]
        for string in arr_arr:
            file.write(f"const int * const \t\t\t\tMOVING_OBJECT_{string}_LUT[STAGE_T_SIZE] =\n")
            file.write("{\n")
            for stage in range(11):
                file.write("\t" + get_var_name2(stage, string))
                if stage < 10:
                    file.write(",\n")
                else:
                    file.write("\n")
            file.write("};\n\n")
        
        file.write("const unsigned int * const \t\tMOVING_OBJECT_SC_LUT[STAGE_T_SIZE] =\n")
        file.write("{\n")
        for stage in range(11):
            file.write("\t" + get_var_name2(stage, "SC"))
            if stage < 10:
                file.write(",\n")
            else:
                file.write("\n")
        file.write("};\n\n")

        file.write("\n\n/// --------------------< missile ability    i n t e r f a c e >--------------------\n\n")
        
        # generate paths
        frames = 25

        y_arr = []
        for x in range (frames):
            a = (112+32) / (-frames * frames)
            num = a * (x+frames) * (x-frames) - 112 # quadratic function
            num_rounded = int(num)
            y_arr.append(num_rounded)
            

        # resulting scaling
        sc_arr = []
        for y in y_arr:
            sc = -0.165 * y + 8 # linear function
            sc_rounded = int(sc)
            sc_arr.append(sc_rounded)



        # write to file
        def print_list_alt(list):
            for i in range(frames):
                file.write(str(list[i]))
                if i < frames-1:
                    file.write(", ")
                else:
                    file.write("};\n")

        file.write("\n")
        file.write("const int \t\t\t\tABILITY_MISSILE_YY_LUT[ABILITY_MISSILE_MAX_CNT] = {")
        print_list_alt(y_arr)
        file.write("const unsigned int \t\tABILITY_MISSILE_SC_LUT[ABILITY_MISSILE_MAX_CNT] = {")
        print_list_alt(sc_arr)

        
    # generate hitboxes (for each object type), depending on scaling factor
    with open('../../source/game_source/gen_data/gen_object_hitbox.c', 'w') as file:
        file.write("#include \"../../game_include/gen_data/gen_object_hitbox.h\"\n\n")
        file.write("/********************************************************************************************************\n")
        file.write(" *   THIS FILE WAS GENERATED          DO NOT EDIT!!! \n")
        file.write(" *   make changes in custom_tools/lut_gen/gen_object_path.py\n")
        file.write(" *\n")
        file.write(" *\n")
        file.write(" *   AUTHOR: laserbluejay / cxlledjay, 2025\n")
        file.write(" *******************************************************************************************************/\n\n\n")

        global max_sc_possible
        enemy_hitbox_sc_xh_factors = [1.4, 1.4, 1.4, 0.55, 1, 1.6, 1.4]
        """ idx mapping
        MOT_ENEMY_CAR1 = 0,
        MOT_ENEMY_CAR2 = 1,
        MOT_ENEMY_TRUCK = 2,
        MOT_ENEMY_BIKE = 3,
        MOT_FUELCAN = 4,
        MOT_ABILITY_EXTRALIFE = 5,
        MOT_ABILITY_MISSILE = 6
        """
        file.write(f"const int \t\t\t\t MO_SC_TO_BB_X_HALFED[MOT_COUNT-1][{max_sc_possible}] = \n{{\n\t{{")
        
        cnt = len(enemy_hitbox_sc_xh_factors)
        for factor in enemy_hitbox_sc_xh_factors:
            file.write("\t")
            sc_xh_arr = []
            
            for i in range(max_sc_possible):
                x = i * factor
                xh_r = int(x/2)
                sc_xh_arr.append(xh_r)

            for i in range(max_sc_possible):
                file.write(str(sc_xh_arr[i]))
                if i < max_sc_possible-1:
                    file.write(", ")
                else:
                    cnt -= 1
                    if(cnt > 0):
                        file.write("},\n\t{")
                    else:
                        file.write("}\n};\n\n")



        enemy_hitbox_sc_y_factors = [0.85, 0.8, 1.1, 0.8, 1, 1.1, 1.3]
        """ idx mapping
        MOT_ENEMY_CAR1 = 0,
        MOT_ENEMY_CAR2 = 1,
        MOT_ENEMY_TRUCK = 2,
        MOT_ENEMY_BIKE = 3,
        MOT_FUELCAN = 4,
        MOT_ABILITY_EXTRALIFE = 5,
        MOT_ABILITY_MISSILE = 6
        """
        file.write(f"const int \t\t\t\t  MO_SC_TO_BB_Y[MOT_COUNT-1][{max_sc_possible}] = \n{{\n\t{{")
        
        cnt = len(enemy_hitbox_sc_y_factors)
        for factor in enemy_hitbox_sc_y_factors:
            file.write("\t")
            sc_y_arr = []

            for i in range(max_sc_possible):
                y = i * factor
                y_r = int(y)
                sc_y_arr.append(y_r)

            for i in range(max_sc_possible):
                file.write(str(sc_y_arr[i]))
                if i < max_sc_possible-1:
                    file.write(", ")
                else:
                    cnt -= 1
                    if(cnt > 0):
                        file.write("},\n\t{")
                    else:
                        file.write("}\n};\n\n")

    # generate player lane change speed tables
    with open('../../source/game_source/gen_data/gen_player_lanechange.c', 'w') as file:
        file.write("#include \"game_include/gen_data/gen_player_lanechange.h\"\n\n")
        file.write("/********************************************************************************************************\n")
        file.write(" *   THIS FILE WAS GENERATED          DO NOT EDIT!!! \n")
        file.write(" *   make changes in custom_tools/lut_gen/gen_object_path.py\n")
        file.write(" *\n")
        file.write(" *\n")
        file.write(" *   AUTHOR: laserbluejay / cxlledjay, 2025\n")
        file.write(" *******************************************************************************************************/\n\n\n")

        lc_steps = [16,12,8,5,3]
        step_from_stage = [0,0,0,1,1,1,2,2,3,3,4]
            
        max_x = 82

        lc_p1_frames = []
        lc_p2_frames = []
        cnt = 0

        for step in lc_steps:
            lc_p1 = int(step/2)
            lc_p2 = int(step/2)
            if step % 2 != 0:
                lc_p1 += 1
                
            lc_p1_frames.append(lc_p1)
            lc_p2_frames.append(lc_p2)

            file.write(f"#define LCS{cnt}_CNT_P1\t\t({lc_p1}u)\n")
            file.write(f"#define LCS{cnt}_CNT_P2\t\t({lc_p2}u)\n\n")

            cnt += 1
        file.write("\n\n\n")

        #calculate all lane changes
        #for each step
        cnt = 0
        for total_steps in lc_steps:

            left_mid = []
            mid_right = []
            right_mid = []
            mid_left = []

            delta = max_x / (total_steps+2) #float percision

            #for left -> mid -------
            for i in range(total_steps):
                x = -max_x + ((1+i)*delta) #get all values in between max_x and 0
                left_mid.append(int(x)) #round here

            #step1
            file.write(f"const int\t\t _LCS{cnt}_LM_P1[LCS{cnt}_CNT_P1] = {{")
            for i in range(lc_p1_frames[cnt]):
                print_array_entry(file, left_mid[(lc_p1_frames[cnt]-1)-i], i, lc_p1_frames[cnt])
            file.write(" };\n")
            #step2
            file.write(f"const int\t\t _LCS{cnt}_LM_P2[LCS{cnt}_CNT_P2] = {{")
            for i in range(lc_p2_frames[cnt]):
                print_array_entry(file, left_mid[(lc_p1_frames[cnt]+lc_p2_frames[cnt]-1)-i], i, lc_p2_frames[cnt])
            file.write(" };\n")
            

            #for mid -> right -------
            for i in range(total_steps):
                x = 0 + ((1+i)*delta) #get all values in between max_x and 0
                mid_right.append(int(x)) #round here

            #step1
            file.write(f"const int\t\t _LCS{cnt}_MR_P1[LCS{cnt}_CNT_P1] = {{")
            for i in range(lc_p1_frames[cnt]):
                print_array_entry(file, mid_right[(lc_p1_frames[cnt]-1)-i], i, lc_p1_frames[cnt])
            file.write(" };\n")
            #step2
            file.write(f"const int\t\t _LCS{cnt}_MR_P2[LCS{cnt}_CNT_P2] = {{")
            for i in range(lc_p2_frames[cnt]):
                print_array_entry(file, mid_right[(lc_p1_frames[cnt]+lc_p2_frames[cnt]-1)-i], i, lc_p2_frames[cnt])
            file.write(" };\n")
            

            #for right -> mid -------
            for i in range(total_steps):
                x = max_x - ((1+i)*delta) #get all values in between max_x and 0
                right_mid.append(int(x)) #round here

            #step1
            file.write(f"const int\t\t _LCS{cnt}_RM_P1[LCS{cnt}_CNT_P1] = {{")
            for i in range(lc_p1_frames[cnt]):
                print_array_entry(file, right_mid[(lc_p1_frames[cnt]-1)-i], i, lc_p1_frames[cnt])
            file.write(" };\n")
            #step2
            file.write(f"const int\t\t _LCS{cnt}_RM_P2[LCS{cnt}_CNT_P2] = {{")
            for i in range(lc_p2_frames[cnt]):
                print_array_entry(file, right_mid[(lc_p1_frames[cnt]+lc_p2_frames[cnt]-1)-i], i, lc_p2_frames[cnt])
            file.write(" };\n")
            

            #for mid -> left -------
            for i in range(total_steps):
                x = 0 - ((1+i)*delta) #get all values in between max_x and 0
                mid_left.append(int(x)) #round here

            #step1
            file.write(f"const int\t\t _LCS{cnt}_ML_P1[LCS{cnt}_CNT_P1] = {{")
            for i in range(lc_p1_frames[cnt]):
                print_array_entry(file, mid_left[(lc_p1_frames[cnt]-1)-i], i, lc_p1_frames[cnt])
            file.write(" };\n")
            #step2
            file.write(f"const int\t\t _LCS{cnt}_ML_P2[LCS{cnt}_CNT_P2] = {{")
            for i in range(lc_p2_frames[cnt]):
                print_array_entry(file, mid_left[(lc_p1_frames[cnt]+lc_p2_frames[cnt]-1)-i], i, lc_p2_frames[cnt])
            file.write(" };\n")



            # next step
            file.write("\n")
            cnt += 1

        # connect the dots
        for phase in range(2):
            phase += 1
            file.write(f"const player_lane_change_t player_lane_change_phase{phase} =\n{{\n\t")
            file.write(".FRAME_CNT =\n\t{\n\t\t")
            for game_stage in range(11):
                print_array_entry(file, f"LCS{step_from_stage[game_stage]}_CNT_P{phase}" , game_stage, 11)
            file.write(f"\n\t}},\n\t.animation_tick = &_player_lanechange_tick_phase{phase},")
            file.write("\n\t.x_LUT =\n\t{")
            file.write("\n\t\t.left_to_mid =")
            file.write("\n\t\t{\n\t\t\t")
            for game_stage in range(11):
                print_array_entry(file, f"_LCS{step_from_stage[game_stage]}_LM_P{phase}" , game_stage, 11)
            file.write("\n\t\t},")
            file.write("\n\t\t.mid_to_right =")
            file.write("\n\t\t{\n\t\t\t")
            for game_stage in range(11):
                print_array_entry(file, f"_LCS{step_from_stage[game_stage]}_MR_P{phase}" , game_stage, 11)
            file.write("\n\t\t},")
            file.write("\n\t\t.right_to_mid =")
            file.write("\n\t\t{\n\t\t\t")
            for game_stage in range(11):
                print_array_entry(file, f"_LCS{step_from_stage[game_stage]}_RM_P{phase}" , game_stage, 11)
            file.write("\n\t\t},")
            file.write("\n\t\t.mid_to_left =")
            file.write("\n\t\t{\n\t\t\t")
            for game_stage in range(11):
                print_array_entry(file, f"_LCS{step_from_stage[game_stage]}_ML_P{phase}" , game_stage, 11)
            file.write("\n\t\t}\n\t}\n};\n\n")




        



generate_header()
generate_source()
