
from txtengine import search_lines
from datetime import datetime
from typing import List

filename = '2024-05-23.log'
substr = 'a04e7103fcc14184a0f19f7ab02f54da'
guid_tracker = "[guid_tracker]"
st_time = datetime.now()
# 2.8
print(list(search_lines(filename, [guid_tracker], only_count=True)))
ed_time = datetime.now()
print(ed_time-st_time)