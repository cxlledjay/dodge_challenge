
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
    '1' : "MOT_ENEMY_CAR1",
    '2' : "MOT_ENEMY_CAR2",
    'T' : "MOT_ENEMY_TRUCK",
    'B' : "MOT_ENEMY_BIKE",
    'F' : "MOT_FUELCAN",
    'E' : "MOT_EXTRALIFE",
    'M' : "MOT_ABILITY_MISSILE"
}





encoded_data = [] #input data

# read input file and save to encoded_data
def read_in():
    global encoded_data
    with open('in.txt', 'r') as in_file:
        # Read each line in the file
        current_array = "error"
        for line in in_file:
            if(line.startswith('#')):
                current_array = line.replace("#","")
            elif(not line.startswith("\n")):
                encoded_data.append([current_array,line[0],line[1],line[2]])

def write_out():
    global mot_map
    global encoded_data
    ed = encoded_data
    current_array = "ERROR"
    with open('out.txt', 'w') as out_file:

        arr_len = len(ed)
        for i in range(arr_len):
            if(ed[i][0] != current_array):
                # create new array
                current_array = ed[i][0]
                name = f"_SP_{current_array}"
                out_file.write(f"const spawn_entry_t {name}[] =\n{{")
             
            #  and print array
            left  = mot_map[ed[i][1]]
            mid   = mot_map[ed[i][2]]
            right = mot_map[ed[i][3]]
            if(i != arr_len-1):
                if(ed[i+1][0] != current_array):
                    # last one
                    out_file.write(f"\n\t{{.is_last = 1, .left = {left:<16}, .mid = {mid:<16}, .right = {right:<16}}}")
                    out_file.write("\n};\n\n")
                else:
                    # normal
                    out_file.write(f"\n\t{{.is_last = 0, .left = {left:<16}, .mid = {mid:<16}, .right = {right:<16}}},")
            else:
                #very last one
                out_file.write(f"\n\t{{.is_last = 1, .left = {left:<16}, .mid = {mid:<16}, .right = {right:<16}}}")
                out_file.write("\n};\n\n")

                








if __name__ == "__main__":
    read_in()
    write_out()