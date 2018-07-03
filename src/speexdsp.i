// speexdsp.i


%module speexdsp

%begin %{
#define SWIG_PYTHON_STRICT_BYTE_CHAR
%}

%include "std_string.i"

%{
#include "echo_canceller.h"
%}

%include "echo_canceller.h"

