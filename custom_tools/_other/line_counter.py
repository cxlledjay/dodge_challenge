# just for fun program to count all lines i've written in this project


# keep track of all lines
all_lines = 0

# define root directories to count all files in:
root_dirs = ["custom_tools", "source/game_source", "source/game_include"]

# iterate through root dirs
import os
for root_dir in root_dirs:
    path = "../../" + root_dir

    # iterate trough all files
    for subdir, dirs, files in os.walk(path):
        for file in files:

            #count lines
            with open(os.path.join(subdir, file), "rb") as f:
                num_lines = sum(1 for _ in f)
                all_lines += num_lines
                print(str(num_lines) + "\t-\t" + os.path.join(subdir, file))

print("---------------------------------------------------------------------\n")
print(str(all_lines) + "\t-\tsum")
