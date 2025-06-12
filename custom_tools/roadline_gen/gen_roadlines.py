

new_lines = []

switch = 1              # 1 is on
switch_where = 1        # 0 is draw

y = -5 #x = 4*y
m = 3
cnt = 0
cnt_s = 0
y_temp = 0

def balance():
    global cnt_s, y_temp, switch
    if not switch:
        return
    if (cnt_s % 2) == 0:
        y_temp -= 2
    else:
        y_temp -= 1
    cnt_s += 1

def gen():
    global cnt, y, m, new_lines, y_temp
    if (cnt % 2) == 0:
        y_temp = y
        if switch == 1 and switch_where == 0:
            balance()
        new_lines.append(f"{{DRAW, {{{y_temp*4},{y_temp}}}}},\n")
    else:
        y_temp = y
        if switch == 1 and switch_where == 1:
            balance()
        new_lines.append(f"{{MOVE, {{{y_temp*4},{y_temp}}}}},\n")
    y = y - m
    cnt += 1
    





if __name__ == "__main__":
    
    for i in range(15):
        gen()


    with open('output_rl.txt', 'w') as file:
        for l in new_lines:
            file.write(l)