
#from txtengine import search_lines
from datetime import datetime
from typing import List

def search_lines(filepath:str, search_list:List[str]):
    with open(filepath, 'r') as fp:
        for line in fp.readlines():
            if all(substr in line for substr in search_list):
                yield line

filename = '2024-05-23.log'
substr = 'a04e7103fcc14184a0f19f7ab02f54da'
guid_tracker = "[guid_tracker]"
st_time = datetime.now()
# 2.8
list(search_lines(filename, [substr]))
ed_time = datetime.now()
print(ed_time-st_time)