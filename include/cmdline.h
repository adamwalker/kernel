#ifndef __CMDLINE_H
#define __CMDLINE_H

int parseopt(const char *cmdline, const char *opt, char *value, int bufsize);
int parsebool(const char *cmdline, const char *opt);

#endif
