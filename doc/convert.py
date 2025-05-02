
new_lines = []

if __name__ == "__main__":
    # Open the file in read mode
    with open('vectrex_ram.h', 'r') as file:
        # Read each line in the file
        for line in file:
            # Print each line
            if(line.startswith('/') or line.find('/') == -1):
                new_lines.append(line)
            else:
                semicol_nr = 0
                cnt = 0
                for c in line:
                    if c == '/':
                        break
                    elif c == ' ' or c == '\t':
                        semicol_nr = cnt
                    cnt += 1
                new_lines.append(line[:semicol_nr] + "; " + line[semicol_nr + 1:])
        file.close()
    
    with open('test1.h', 'w') as file:
        for l in new_lines:
            file.write(l)
                