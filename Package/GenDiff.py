# Copyright Greg Fuller (vacui.dev) all rights reserved

import os
import re

re_date = r"\d{4}-\d{2}-\d\d?"
re_time = r"\d\d?:\d\d?:\d\d?\.?\d*"
re_timestamp = f"{re_date}T{re_time}Z"


def removeTimestamps(infilename:str, outfilename:str):
    outlines = []
    with open(infilename, 'r') as infile:
        print(f"Removing timestamps from {infilename}")
        for line in infile.readlines():
            outlines.append(re.sub(re_timestamp, '', line))

    with open(outfilename, 'w') as outfile:
        outfile.writelines(sorted(outlines))
        
        
def calculateFolderSize(dir, subDirName:str, outfilename:str):
    subDir = os.path.join(dir, subDirName)
    subDirSize = 0
    for path, dirs, files in os.walk(subDir):
        for f in files:
            subDirSize += os.stat(os.path.join(path, f)).st_size
    subDirSizeMb = subDirSize/1024/1024
    with open(outfilename, 'w') as outfile:
        outfile.writelines([
            f"/{subDirName} size: \n",
            f"  {subDirSizeMb:.4f} MB ({subDirSize:,} Bytes)\n"
        ])


def main(dir:str):
    subdir = "Windows"
    for manifest in ["Manifest_NonUFSFiles_Win64", "Manifest_UFSFiles_Win64"]:
        in_filename = os.path.join(dir, subdir, f"{manifest}.txt")
        out_filename = os.path.join(dir, "Diff", f'{manifest}.txt')
        removeTimestamps(in_filename, out_filename)
    calculateFolderSize(dir, subdir, os.path.join(dir, "Diff", "foldersize.txt"))


if __name__ == "__main__":
    main(os.path.dirname(os.path.realpath(__file__)))

## EOF