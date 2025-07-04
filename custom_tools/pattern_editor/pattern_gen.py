
# input file syntax:
#
#
# moving_object_type_t is enumerated:
#
# enemy1 = 1, enemy2 = 2, ...
# ability = A
# fuel = F
# ... more to come?
#
#
# file format:
#
# 1st char = left lane, 2nd char = mid lane, 3rd char = right lane
# "-" is no spawn (=MOT_NULL)
# 
# example:
#
# --1 # ALWAYS LEAVE MIDDLE FREE IN FIRST SEQUENCE ENTRY!!! 
# 1-1 # make sure there is always only one lane swap required for next entry (otherwise game is unfair)
# -1-
# 
#
# you can look up all bindings in this dictionary:

mot_map = {
    '-' : "MOT_NULL",
    '1' : "MOT_ENEMY_1"
    # TODO: add all other possible mappings of moving_object_type_t (object.h)
}

encoded_data = [] #input data

# read input file and save to encoded_data
def read_in():
    global encoded_data
    with open('in.txt', 'r') as in_file:
        # Read each line in the file
        for line in in_file:
            encoded_data.append([line[0],line[1],line[2]])

def write_out(array_name):
    global mot_map
    global encoded_data
    ed = encoded_data
    with open('out.txt', 'w') as out_file:
        name = f"_SP_{array_name}"
        out_file.write(f"const spawn_entry_t {name}[] =\n{{")
        # write type definition
        arr_len = len(ed)
        for i in range(arr_len):
            left  = mot_map[ed[i][0]]
            mid   = mot_map[ed[i][1]]
            right = mot_map[ed[i][2]]
            if i != arr_len-1:
                out_file.write(f"\n\t{{.is_last = 0, .left = {left:<15}, .mid = {mid:<15}, .right = {right:<15}}},")
            else:
                out_file.write(f"\n\t{{.is_last = 1, .left = {left:<15}, .mid = {mid:<15}, .right = {right:<15}}}")
        out_file.write("\n};\n")








if __name__ == "__main__":
    read_in()
    write_out("alpha_4")