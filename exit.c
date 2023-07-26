#include "shell.h"

/**
 * myexit - exit the program
 * @line: command line.
 * @mynode: commands and arguments.
 * @n: line number.
 */
void myexit(node_t *line, node_t *mynode, int n)
{
  char *exit_n = "exit";
  int i = -1;

  if (_strcmp(mynode->str, exit_n) == 0)
  {
    if (mynode->next)
    {
      i = _atoi(mynode->next->str);
      if (i < 0)
      {
        _perror(n, mynode->str);
        write(1, ": ", 2);
        write(1, mynode->next->str, 10);
      }
      else
        errno = i;
    }
		freenode(line);
		freenode(mynode);
		exit(errno);
  }
}
