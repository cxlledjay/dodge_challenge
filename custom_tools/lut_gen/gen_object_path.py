


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
        sc = -0.25 * y + 14 # linear function
        sc_rounded = int(sc)
        sc_arr.append(sc_rounded)
        
    # reverse arrays, because ttl counts backwards
    y1_arr.reverse()
    y2_arr.reverse()
    xl_arr.reverse()
    xr_arr.reverse()
    sc_arr.reverse()

    # generate data structure
    
    def print_list(list):
        for i in range(frames):
            file.write(str(list[i]))
            if i < frames-1:
                file.write(", ")
            else:
                file.write("};\n")

    file.write("\n\n")
    file.write("const int \t\t\t\t"+get_var_name(stage, "Y1")+" = {")
    print_list(y1_arr)
    file.write("const int \t\t\t\t"+get_var_name(stage, "Y2")+" = {")
    print_list(y2_arr)
    file.write("const int \t\t\t\t"+get_var_name(stage, "XL")+" = {")
    print_list(xl_arr)
    file.write("const int \t\t\t\t"+get_var_name(stage, "XR")+" = {")
    print_list(xr_arr)
    file.write("const unsigned int \t\t"+get_var_name(stage, "SC")+" = {")
    print_list(sc_arr)
    file.write("\n\n\n")

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
            file.write("const int \t\t\t\t"+get_var_name(stage, "Y1")+";\n")
            file.write("const int \t\t\t\t"+get_var_name(stage, "Y2")+";\n")
            file.write("const int \t\t\t\t"+get_var_name(stage, "XL")+";\n")
            file.write("const int \t\t\t\t"+get_var_name(stage, "XR")+";\n")
            file.write("const unsigned int \t\t"+get_var_name(stage, "SC")+";\n")
            file.write("\n\n\n")
        
        file.write("#include \"../game.h\"\n")
        file.write("extern const unsigned int MOVING_OBJECT_TTL_LUT[STAGE_T_SIZE];\n")


def generate_source():
    with open('../../source/game_source/gen_data/gen_object_path.c', 'w') as file:
        file.write("#pragma once\n\n")
        file.write("/********************************************************************************************************\n")
        file.write(" *   THIS FILE WAS GENERATED          DO NOT EDIT!!! \n")
        file.write(" *   make changes in custom_tools/lut_gen/gen_object_path.py\n")
        file.write(" *\n")
        file.write(" *\n")
        file.write(" *   AUTHOR: laserbluejay / cxlledjay, 2025\n")
        file.write(" *******************************************************************************************************/\n")

        speed_per_stage = [196,168,140,119,98,84,77,70,56,42,28]
        for stage in range(11):
            generate_stage(stage,speed_per_stage[stage],file)

        file.write("#include \"../game.h\"\n")
        file.write("const unsigned int MOVING_OBJECT_TTL_LUT[STAGE_T_SIZE] =\n")
        file.write("{\n")
        for stage in range(11):
            file.write(f"\tTTL_ST{stage}-1")
            if stage < 11:
                file.write(",\n")
            else:
                file.write("\n")
        file.write("};\n")



generate_header()
generate_source()
