
from txtengine import search_lines
from datetime import datetime
filename = '2024-05-23.log'
substr = 'a04e7103fcc14184a0f19f7ab02f54da'

st_time = datetime.now()
list(search_lines(filename.encode('utf-8'), [substr.encode('utf-8')] ))
ed_time = datetime.now()
print(ed_time-st_time)