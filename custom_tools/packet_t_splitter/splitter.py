#very dirt .__.


new_lines = []

def oor(val): #out of range check
    if val > 127 or val < -128:
        return True
    else:
        return False


if __name__ == "__main__":
    # Open the file in read mode
    with open('input.txt', 'r') as file:
        # Read each line in the file
        for line in file:
            # Print each line
            if "{" not in line:
                new_lines.append(line)
            else:
                cmd = "MOVE"
                if "DRAW" in line:
                    cmd = "DRAW"

                tiled = line.split(',')
                coords = []
                for substr in tiled:
                    if "DRAW" in substr or "MOVE" in substr:
                        continue
                    else:
                        substr = substr.replace(" ", "")
                        substr = substr.replace("{", "")
                        substr = substr.replace("}", "")
                        if substr != '\n':
                            coords.append(substr)
                #split
                y = int(coords[0])
                x = int(coords[1])

                if oor(y) or oor(x):
                    #split
                    if ((y % 2) == 1) or ((x % 2) == 1):
                        # odd numbers
                        y_ut = 0
                        x_ut = 0
                        if ((y % 2) == 1):
                            y_ut = 1
                            y = y-1
                        if ((x % 2) == 1):
                            x_ut = 1
                            x = x-1
                        y = int(y/2)
                        x = int(x/2)
                        new_lines.append(f"{{{cmd}, {{{y},{x}}}}},\n")
                        new_lines.append(f"{{{cmd}, {{{y+y_ut},{x+x_ut}}}}},\n")
                        
                    else:
                        y = int(y/2)
                        x = int(x/2)
                        new_lines.append(f"{{{cmd}, {{{y},{x}}}}},\n")
                        new_lines.append(f"{{{cmd}, {{{y},{x}}}}},\n")
                else:
                    new_lines.append(f"{{{cmd}, {{{y},{x}}}}},\n")
                        
        file.close()
    
    
    with open('output.txt', 'w') as file:
        for l in new_lines:
            file.write(l)
                