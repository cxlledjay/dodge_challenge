


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

if __name__ == "__main__":
    y_arr = []
    frames = 80

    for x in range (frames):
        a = 210 / (-frames * frames)
        num = a * (x+frames) * (x-frames) - 178
        num_rounded = int(num)
        y_arr.append(num_rounded)

    n1_arr = []
    n2_arr = []

    # convert to data structure
    for num in y_arr:
        n1 = num
        n2 = 0
        if n1 < -128:
            n1 = -128
            n2 = num+128
        n1_arr.append(n1)
        n2_arr.append(n2)
        
    sc_arr = []
    for y in y_arr:
        sc = -0.25 * y + 14
        sc_rounded = int(sc)
        sc_arr.append(sc_rounded)
        

    print(f"frames: {frames}\n")
    print("EY_TO_RY1: \n")
    print(n1_arr)
    print("\n\n\nEY_TO_RY2: \n")
    print(n2_arr)
    print("\n\n\nEY_TO_SCALE: \n")
    print(sc_arr)
