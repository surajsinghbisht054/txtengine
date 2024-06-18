from libc.stdlib cimport malloc, free

# cythonize -i ccore.pyx
cdef extern from "core.c":
    ctypedef struct ResultObject:
        unsigned int line_counter
        char **lines
        int error
    
    cdef ResultObject search_text(char* filepath, char **c_query_list, int query_len, int line_size, int max_lines)
    
def search_lines(file_path:bytes, query_list:list[bytes]):
    cdef int query_len = len(query_list)
    cdef char **c_query_list = <char **>malloc(query_len*sizeof(char *))
    output = -1
    if (file_path and query_list) and (not c_query_list is NULL):
        for i, v in enumerate(query_list):
            c_query_list[i]=v
        res = search_text(file_path, c_query_list, query_len, 8192, 2048*10)
        output = []
        for index in range(res.line_counter):
            output.append(res.lines[index])
        free(c_query_list)
    return output