#include <util.h>
#include <cmdline.h>

static int is_space(char c){
    return c <= ' ';
}

int parseopt(const char *cmdline, const char *opt, char *value, int bufsize) {
    enum {
        wordstartsearch,
        optcmp,
        optskip,
        copying,
    } state = wordstartsearch;

    char c;
    int len = -1;
    char *valptr = NULL;
    const char *optptr = NULL;

    while((c = *cmdline++)){
        switch(state){
            case wordstartsearch:
                if(is_space(c))
                    break;

                state = optcmp;
                optptr = opt;

            case optcmp:
                if(!*optptr && c == '='){
                    len = 0;
                    valptr = value;
                    state = copying;
                } else if (is_space(c)){
                    state = wordstartsearch;
                } else if (c != *optptr++){
                    state = optskip;
                }
                break;

            case optskip:
                if(is_space(c))
                    state = wordstartsearch;
                break;

            case copying:
                if(is_space(c)) {
                    state = wordstartsearch;
                } else {
                    if (len < bufsize - 1)
                        *valptr++ = c;
                    len++;
                }
                break;
        }
    }

    if(bufsize)
        *valptr = '\0';

    return len;
}

int parsebool(const char *cmdline, const char *opt){
    enum {
        wordstartsearch,
        optcmp,
        optskip,
    } state = wordstartsearch;

    const char *optptr = NULL;

    while(1){
        switch(state) {
            case wordstartsearch:
                if(!*cmdline)
                    return 0;
                else if (is_space(*cmdline))
                    break;
                state = optcmp;
                optptr = opt;

            case optcmp:
                if(!*optptr){
                    if(!*cmdline || is_space(*cmdline))
                        return 1;
                    else
                        state = optskip;
                }
                else if(!*cmdline)
                    return 0;
                else if (*cmdline != *(optptr++))
                    state = optskip;
                break;

            case optskip:
                if (!*cmdline)
                    return 0;
                if(is_space(*cmdline))
                    state = wordstartsearch;
                break;
        }
        cmdline++;
    }
}

