#include <util.h>

static int dectoint(char c, int *result){
    if(c >= '0' && c <= '9'){
        *result = c-'0';
        return 0;
    }
    return -1;
}

static int hextoint(char c, int *result){
    if(c >= '0' && c <= '9'){
        *result = c-'0';
        return 0;
    } else if (c >= 'A' && c <= 'F'){
        *result = c-'A'+10;
        return 0;
    } else if (c >= 'a' && c <= 'f'){
        *result = c-'a'+10;
        return 0;
    }
    return -1;
}

int atoi(const char *str, int *result) { 
    unsigned int base;
    int negate;

    int res, ret = 0, val = 0;
    char c;

    if(*str=='-'){
        negate=1;
        str++;
    } else {
        negate=0;
    }

    if(*str=='0' && (*(str+1)=='x' || *(str+1)=='X')){
        base = 16;
        str+=2;
    } else {
        base = 10;
    }

    if(!*str)
        return -1;

    while((c = *str++) != '\0'){
        res = base == 10 ? dectoint(c, &ret) : hextoint(c, &ret);
        if(res)
            return -1;
        val = val*base + ret;
    }

    *result = negate ? -val : val;
    return 0;
}

//Completely unoptimised
void *memcpy(void *dest, const void *src, int size){
	int i;
	for(i=0; i<size; i++)
		((char *)dest)[i] = ((char *)src)[i];
	return dest;
}

void *memset(void *dest, int val, int size){
	int i;
	for(i=0; i<size; i++)
		((char *)dest)[i] = val;
	return dest;
}

int strlen(const char *str){
	int i=0;
	while(str[i] != '\0')
		i++;
	return i;
}

char *strncpy(char *dest, const char *src, int size){
	int i;
	for(i=0; i<size && src[i] != 0; i++)
		dest[i] = src[i];
	for(; i<size; i++)
		dest[i] = '\0';
	return dest;
}

