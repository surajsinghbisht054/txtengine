from typing import List
from libc.stdlib cimport malloc, free
# # cythonize -i ccore.pyx

cdef extern from "core.c":
    ctypedef struct ResultObject:
        unsigned int match_counter
        char **lines
        int error
    
    cdef ResultObject c_search_lines(
        char *filepath,
        char **query_array,
        unsigned int query_size,
        unsigned int line_max_chars,
        unsigned int max_line_count,
        unsigned int enable_fetch_lines
    )
    

def search_lines(file_path:str, queries_array:List[str], only_count=False):
    cdef unsigned int query_len = len(queries_array)
    cdef unsigned int line_size = 2048*4
    cdef unsigned int max_lines = 2048*10
    
    cdef char **c_query_list = <char **>malloc(query_len*sizeof(char *))
    response = []
    if c_query_list is NULL:
        raise "#1 malloc fail"
    
    for key, value in enumerate((i.encode('utf-8') for i in queries_array)):
        c_query_list[key]=value


    res = c_search_lines(file_path.encode('utf-8'), c_query_list, query_len, line_size, max_lines, int(not only_count))
    
    if only_count:
        response.append(res.match_counter)
    else:        
        for index in range(res.match_counter):
            response.append(res.lines[index])
            free(res.lines[index])
    # free
    free(res.lines)
    free(c_query_list)
    return response
