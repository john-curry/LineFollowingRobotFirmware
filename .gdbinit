define reload
kill
monitor jtag_reset
load
end
set logging on
target extended localhost:4242
load
b main
c
b eval
c
delete breakpoints
b 22
c
