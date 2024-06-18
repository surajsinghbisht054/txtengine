#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char **lines;
    unsigned int match_counter;
    int error;
} ResultObject;

ResultObject search_text(
    char *filepath,
    char **query_array,
    unsigned int query_size,
    unsigned int line_max_chars,
    unsigned int max_line_count)
{
    ResultObject res;
    FILE *file_pointer;
    res.match_counter = 0;
    res.error = 0;
    // blank space allocated for pointers
    res.lines = (char **)malloc(max_line_count * sizeof(char *));
    
    // open file
    file_pointer = fopen(filepath, "r");
    if (!file_pointer)
    {
        res.error = -1;
        return res;
    }

    char line[line_max_chars];
    int match_found = 0;
    while (fgets(line, sizeof(line), file_pointer))
    {

        for (unsigned int i = 0; i < query_size; ++i)
        {
            if (strstr(line, query_array[i]))
            {
                match_found++;

            }
            else
            {
                break;
            }
        }
        if (match_found == query_size)
        {
            res.lines[res.match_counter++] = strdup(line);
        }
        if (!(res.match_counter < max_line_count))
        {
            break;
        }
    }

    fclose(file_pointer);
    return res;
}
