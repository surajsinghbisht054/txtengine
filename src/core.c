#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int match_counter;
    char **lines;
    int error;
} ResultObject;

ResultObject c_search_lines(
    char *filepath,
    char **query_array,
    unsigned int query_size,
    unsigned int line_max_chars,
    unsigned int max_line_count,
    unsigned int enable_fetch_lines)
{
    ResultObject res;
    FILE *file_pointer;
    res.match_counter = 0;
    // blank space allocated for pointers
    res.lines = (char **)malloc(max_line_count * sizeof(char *));
    res.error = 0;

    // open file
    file_pointer = fopen(filepath, "r");
    if (!file_pointer)
    {
        res.error = -1;
        return res;
    }

    char line[line_max_chars];
    unsigned int match_found;
    while (fgets(line, sizeof(line), file_pointer))
    {
        match_found = 0;
        for (unsigned int i = 0; i < query_size; ++i)
        {
            if (strstr(line, query_array[i]))
            {
                match_found++;
                if (match_found == query_size)
                {
                    if (enable_fetch_lines)
                    {
                        res.lines[res.match_counter++] = strdup(line);
                    }else{
                        res.match_counter++;
                    }
                }
            }
            else
            {
                break;
            }
        }
        if (res.match_counter && !(res.match_counter < max_line_count))
        {
            break;
        }
    }

    fclose(file_pointer);
    return res;
}
