#ifndef PIN_H
#define PIN_H

/* States hold the current execution context */
typedef struct
{
} PIN_STATE;

/* Opens a source file and passes contents to PinDo */
int PinDoFile(char *filename);
/* Parses code and returns a Pin state */
int PinDo(char*);

#endif
