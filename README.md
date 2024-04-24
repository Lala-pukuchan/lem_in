# lem_in
## How to use generator
```
lem_in % ./generator --big-superposition > out
lem_in % cat out | grep Here
#Here is the number of lines required: 81
#Here is the number of lines required: 81
lem_in % make                
gcc -g -O0 -Wall -Werror -Wextra   -c -o src/main.o src/main.c
gcc -g -O0 -Wall -Werror -Wextra   -c -o src/room.o src/room.c
gcc -g -O0 -Wall -Werror -Wextra  src/main.o src/check.o src/room.o src/link.o src/path.o src/print.o src/edmondskarp.o src/ant.o libft/libft.a -I ./includes -I ./libft -o lem-in
lem_in % ./lem-in < out > res
lem_in % grep L res > lines  
lem_in % wc -l lines         
      90 lines
```