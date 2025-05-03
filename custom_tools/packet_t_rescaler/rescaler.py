
new_lines = []

factor = 8

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
                y = int(coords[0]) * factor
                x = int(coords[1]) * factor
                new_lines.append(f"{{{cmd}, {{{y},{x}}}}},\n")
                        
        file.close()
    
    
    with open('output.txt', 'w') as file:
        for l in new_lines:
            file.write(l)
                