# labrenamer
Tool for incrementally renaming Windows PCs in multiple labs.

## Usage
When run, the tool mounts a networked SMB share called `deploynaming` on server `STORAGE` on mountpoint `Z:`. Then, it renames the PC with the current number in the file, increments it for the next PC, saves the counter and reboots the system.

## Input
On the SMB share there has to be a file called `labX.txt`, `X` being the lab's number. Changing the lab's number is done on line 7. Compile and run.
