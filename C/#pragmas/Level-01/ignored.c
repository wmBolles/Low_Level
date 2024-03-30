#include <stdio.h>

#pragma GCC diagnostic push     // Push a new fn label
#pragma GCC diagnostic ignored "-Wimplicit-int" // ignored main return value
#pragma GCC diagnostic ignored "-Wint-conversion" // ignored var = NULL

main(void)
<%
    int     var = NULL; // Here is Another Warning
    return   01;
%>
#pragma GCC diagnostic pop // close the label